#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <ctime>
#include<math.h>
#include<random>
#include <vector>
using namespace std;

#define biggist 0x3f3f3f3f
#define white 1 //敌方为1
#define black -1//我方为-1

bool dfs_air_visit[9][9] = { {0} };
const int cx[] = { -1,0,1,0 };
const int cy[] = { 0,-1,0,1 };

bool inline inBorder(int x, int y) { return x >= 0 && y >= 0 && x < 9 && y < 9; }

bool inline dfs_air(int board[9][9], int fx, int fy)
{
	dfs_air_visit[fx][fy] = true;
	bool flag = false;
	for (int dir = 0; dir < 4; dir++)
	{
		int dx = fx + cx[dir], dy = fy + cy[dir];
		if (inBorder(dx, dy))
		{
			if (board[dx][dy] == 0)
				flag = true;
			if (board[dx][dy] == board[fx][fy] && !dfs_air_visit[dx][dy])
				if (dfs_air(board, dx, dy))
					flag = true;
		}
	}
	return flag;
}

//true: available
bool inline judgeAvailable(int board[9][9], int fx, int fy, int col)
{
	if (!inBorder(fx, fy))
		return false;
	if (board[fx][fy] != 0)
		return false;
	board[fx][fy] = col;
	memset(dfs_air_visit, 0, sizeof(dfs_air_visit));
	if (!dfs_air(board, fx, fy))
	{
		board[fx][fy] = 0;
		return false;
	}
	for (int dir = 0; dir < 4; dir++)
	{
		int dx = fx + cx[dir], dy = fy + cy[dir];
		if (inBorder(dx, dy))
		{
			if (board[dx][dy] && !dfs_air_visit[dx][dy])
				if (!dfs_air(board, dx, dy))
				{
					board[fx][fy] = 0;
					return false;
				}
		}
	}
	board[fx][fy] = 0;
	return true;
}

double inline getValue(int board[9][9], int color)
{
	double ans = 0;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (judgeAvailable(board, i, j, color))
			{
				ans++;
			}
		}
	}
	return ans;
}

class McTree
{
public:
	double value;//对改点的权值进行评估
	double UCB;//用ucb公式，得到该点的ucb值
	McTree* parent;
	int myboard[9][9];
	McTree* child[81];//最多只有八十一个点可以下
	int childmove[81][2];//表示孩子的行棋
	int childNum;//实际分支数
	int maxChildNum;//最大分支数
	int color;//为white或者black
	int* count;//遍历的总次数
	int times;//遍历到该节点的次数
	McTree(int board[9][9], McTree* parent, int color, int opMove[2], int* count)
	{
		this->parent = parent;
		this->color = color;
		this->count = count;
		this->value = 0;
		this->UCB = 0;
		this->times = 0;
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++)
			{
				myboard[i][j] = board[i][j];
			}
		}
		if (inBorder(opMove[0], opMove[1]))
		{
			this->myboard[opMove[0]][opMove[1]] = this->color;
		}
		this->times = 0;
		this->childNum = 0;
		this->maxChildNum = 0;
		getAvailablePos(-this->color);
	}
	double getUCB()
	{
		return (this->value / double(this->times) + 0.2 * sqrt(log(double(*count)) / double(this->times)));
	}
	void getAvailablePos(int color)//判断一点是否可以放棋
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				if (judgeAvailable(this->myboard, i, j, color))
				{

					this->childmove[this->maxChildNum][0] = i;
					this->childmove[this->maxChildNum][1] = j;
					this->maxChildNum++;
				}
			}
		}
		return;
	}
	double getValue(int color)
	{
		double ans = 0;
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				if (judgeAvailable(this->myboard, i, j, color))
				{
					ans++;
				}
			}
		}
		return ans;
	}

	McTree* trans()
	{
		if (this->maxChildNum == 0)//已到达叶子节点
			return this;
		if (this->maxChildNum > this->childNum)//可继续拓展
		{
			McTree* node = new McTree(this->myboard, this, -this->color, childmove[this->childNum], this->count);
			this->child[this->childNum] = node;
			this->childNum++;
			return node;
		}
		//说明所有节点已经探索完成
		double maxUCB = -biggist;
		int bigchild = 0;
		for (int i = 0; i < this->maxChildNum; i++)
		{
			this->child[i]->UCB = child[i]->getUCB();
			if (maxUCB < this->child[i]->UCB)
			{
				bigchild = i;
				maxUCB = this->child[i]->UCB;
			}
		}
		return this->child[bigchild]->trans();
	}

	double expect()
	{
		return getValue(this->color) - getValue(-this->color);
	}

	void backup(double val)//回传估值
	{
		McTree* cur = this;
		while (cur != NULL)
		{
			if (cur->color == this->color)
			{
				cur->value += val;
			}
			else
			{
				cur->value -= val;
			}
			cur->times++;
			cur = cur->parent;
		}
		return;
	}
};

int main()
{
	FILE* stream;
	freopen64(&stream, "in.txt", "r", stdin);
	int board[9][9] = { {0} };
	srand((unsigned)time(0));
	srand(clock());
	int begin = clock();
	int timeout = (int)(0.985 * (double)CLOCKS_PER_SEC);
	int x, y, n;
	cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		cin >> x >> y; if (x != -1) board[x][y] = 1;	//对方
		cin >> x >> y; if (x != -1) board[x][y] = -1; //我方
	}
	//若flag为false，则我方为黑棋，若为true，则我方为白棋
	cin >> x >> y;  if (x != -1) { board[x][y] = 1; }//对方
	int count = 0;
	int op_move[2] = { -1,-1 };
	McTree* root;
	root = new McTree(board, NULL, white, op_move, &count);
	while (clock() - begin < timeout)
	{
		count++;
		McTree* node = root->trans();
		if (!node)
			break;
		double val = node->expect();
		node->backup(val);
	}
	int num = 0;
	int ans[81][2] = { 0,0 };
	double best = -biggist;

	for (int i = 0; i < root->childNum; i++)
	{
		if (root->child[i]->value > best)
		{
			best = root->child[i]->value;
			ans[0][0] = root->childmove[i][0];
			ans[0][1] = root->childmove[i][1];
			num = 1;
		}
		else if (root->child[i]->value == best)
		{
			ans[num][0] = root->childmove[i][0];
			ans[num][1] = root->childmove[i][1];
			num++;
		}
	}
	int res = rand() % num;
	cout << ans[res][0] << " " << ans[res][1] << endl;
	return 0;
}
