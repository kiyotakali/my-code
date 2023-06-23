import random
from tkinter import *  
visit=[[2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2],
    [2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2],
    [2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2],
    [2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2],
    [2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2],
    [2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2],
    [2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2],
    [2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2],
    [2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2],
    [2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2],
    [2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2],
    [2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2],
    [2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2],
    [2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2],
    [2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2],
    [2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2],
    [2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2],
    [2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2],]
arr2=[[2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2],
    [2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2],
    [2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2],
    [2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2],
    [2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2],
    [2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2],
    [2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2],
    [2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2],
    [2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2],
    [2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2],
    [2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2],
    [2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2],
    [2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2],
    [2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2],
    [2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2],
    [2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2],
    [2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2],
    [2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2],]
isalive_flag = 0
#深度优先搜索
def DFS(x, y):
        global visit
        visit[x][y] = 1 
        directions = [[x - 1, y], [x + 1, y], [x, y - 1], [x, y + 1]] 
        for dx, dy in directions:
                if(visit[dx][dy] == 0): 
                        if arr2[dx][dy] == 0:
                                global isalive_flag
                                isalive_flag = 1
                                return 
                        elif( arr2[dx][dy] == - arr2[x][y] or arr2[dx][dy]==2):
                                continue 
                        elif arr2[dx][dy] == arr2[x][y]:
                                DFS(dx, dy) 
        return
# 清空搜索记录
def clear_visit():
    global visit
    global isalive_flag
    visit=[[2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2],
    [2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2],
    [2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2],
    [2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2],
    [2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2],
    [2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2],
    [2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2],
    [2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2],
    [2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2],
    [2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2],
    [2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2],
    [2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2],
    [2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2],
    [2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2],
    [2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2],
    [2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2],
    [2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2],
    [2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2],]
    isalive_flag = 0

#有无“气”的判断，有气返回1，无气返回0
def is_alive(x, y):
    isalive = 1 # 用于返回
    clear_visit()
    DFS(x, y)
    # 有“气”标志为0,则返回0,否则为1
    if isalive_flag == 0:
        isalive = 0
    clear_visit()
    return isalive

count=-1
#实现提子操作
def take_out():
    global count
    token_list = [] 
    for i in range(1,17):
        for j in range(1,17):
            if(arr2[i][j])== 0:
                continue
            elif(arr2[i][j]==count and is_alive(i, j) == 0):
                token_list.append([i, j])
    if len(token_list) != 0:        
        for i, j in token_list:
            if(count==1):
                arr2[i][j] = -1
                bnt=Button(windows,bg="#ffa000",command=lambda x=i, y=j: printc(x, y), width=5)
                bnt.grid(row=i, column=j) 
            elif(count==-1):
                arr2[i][j] = 1
                bnt=Button(windows,bg="#ffa000",command=lambda x=i, y=j: printc(x, y), width=5)
                bnt.grid(row=i, column=j) 

def judge_win():
       global arr2
       black=0
       white=0
       for i in range(1,17):
              for j in range(1,17):
                     if(arr2[i][j]==1):
                            white+=1
                     elif(arr2[i][j]==-1):
                            black+=1
       if(black>=130):
              bnt=Button(windows,text="黑方获胜",bg="#e51c23",width=5)
              bnt.grid(row=30,column=15)
       elif(white>=126):
              bnt=Button(windows,text="白方获胜",bg="#e51c23",width=5)
              bnt.grid(row=30,column=15)
              print("white win")  
def ai():
    global arr2
    global count
    count=-1
    r = random.randint(1, 16)
    c = random.randint(1, 16)
    while(arr2[r][c]!=0):
        r = random.randint(1, 16)
        c = random.randint(1, 16)
    bnt=Button(windows,bg="white",command=lambda x=r, y=c: printc(x, y), width=5)
    bnt.grid(row=r, column=c)  
    arr2[r][c]=1
    take_out()
    judge_win()       
def printc(i,j):
        global arr2
        global count
        if(arr2[i][j]!=0):
            bnt=Button(windows,text="这里下不了，换个地方吧",bg="#e51c23",width=20)
            bnt.grid(row=35,column=20)
        elif(arr2[i][j]==0):
                arr2[i][j]=-1
                count=1
                bnt=Button(windows,bg="black",command=lambda x=i, y=j: printc(x, y), width=5)
                bnt.grid(row=i, column=j) 
                take_out()
                judge_win()
                ai()
windows=Tk()
windows.geometry("200x200")   
windows.title("窗口") 
for i in range(1,17):
        for j in range(1,17):
            bnt=Button(windows,bg="#ffa000",command=lambda x=i, y=j: printc(x, y), width=5)
            bnt.grid(row=i, column=j) 
#利用循环依次建立button绘制成16*16的网格
def update_time():
    global timer_label, seconds
    seconds -= 1 # 倒计时减一秒
    timer_label.config(text=str(seconds)) # 更新标签显示
    if seconds > 0: # 如果倒计时大于0，继续计时
        timer_label.after(1000, update_time) # 1秒后再次执行此函数
    else: # 如果倒计时等于0，停止计时
        timer_label.config(text="Time's up!") # 显示提示信息

seconds = 600 # 初始倒计时为600秒
timer_label = Label(windows, text=str(seconds), font="black") # 创建一个标签显示倒计时
#timer_label.pack()
timer_label.grid(row=5, column=30,padx=(10, 20), pady=5)
timer_label.after(1000, update_time) # 1秒后执行update_time函数
windows.mainloop() 