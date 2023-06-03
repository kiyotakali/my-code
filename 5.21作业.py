from tkinter import *  
arr=[[0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0],
    [0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0],
    [0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0],
    [0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0],
    [0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0],
    [0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0],
    [0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0],
    [0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0],
    [0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0],
    [0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0],
    [0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0],
    [0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1],
    [1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
    [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
    [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
    [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],]

arr1=[[0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0],
    [0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0],
    [0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0],
    [0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0],
    [0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0],
    [0,0,0,1,1,0,0,0,0,0,0,0,1,1,0,0],
    [0,0,0,1,1,0,0,0,0,0,0,1,1,1,0,0],
    [0,0,1,1,0,1,0,0,0,0,0,1,0,1,1,0],
    [0,1,0,0,0,0,1,0,0,0,1,0,0,0,0,1],
    [0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0],
    [0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0],
    [0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0],
    [0,0,0,0,1,1,0,0,0,0,0,1,1,0,0,0],
    [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
    [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
    [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],]

arr2=[[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
    [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
    [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
    [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
    [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
    [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
    [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
    [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
    [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
    [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
    [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
    [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
    [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
    [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
    [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
    [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],]
visit=[[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
    [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
    [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
    [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
    [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
    [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
    [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
    [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
    [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
    [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
    [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
    [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
    [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
    [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
    [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
    [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],]
isalive_flag = 0
#深度优先搜索
def DFS(x, y):
        visit[x][y] = 1 
        directions = [[x - 1, y], [x + 1, y], [x, y - 1], [x, y + 1]] 
        for dx, dy in directions:
                if(dx < 0 or dx > 15 or dy < 0 or dy > 15):
                        continue 
                elif(visit[dx][dy] == 0): 
                        if arr2[dx][dy] == 0:
                                global isalive_flag
                                isalive_flag = 1
                                return 
                        elif arr2[dx][dy] == - arr2[x][y]:
                                continue 
                        elif arr2[dx][dy] == arr2[x][y]:
                                DFS(dx, dy) 
        return
# 清空搜索记录
def clear_visit():
    global visit
    global isalive_flag
    visit=[[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
    [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
    [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
    [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
    [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
    [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
    [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
    [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
    [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
    [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
    [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
    [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
    [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
    [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
    [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],
    [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],]
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
    for i in range(16):
        for j in range(16):
            if(arr2[i][j])== 0:
                continue
            elif(arr2[i][j]==count and is_alive(i, j) == 0):
                token_list.append([i, j])
    if len(token_list) != 0:        
        for i, j in token_list:
            if(count==1):
                arr2[i][j] = -1
                bnt=Button(windows,bg="black",command=lambda x=i, y=j: printc(x, y), width=5)
                bnt.grid(row=i, column=j) 
            elif(count==-1):
                arr2[i][j] = 1
                bnt=Button(windows,bg="white",command=lambda x=i, y=j: printc(x, y), width=5)
                bnt.grid(row=i, column=j) 

def judge_win():
       global arr2
       black=0
       white=0
       for i in range(16):
              for j in range(16):
                     if(arr[i][j]==1):
                            white+=1
                     elif(arr2[i][j]==-1):
                            black+=1
       if(black>=130):
              bnt=Button(windows,text="黑",bg="#e51c23",width=5)
              bnt.grid(row=30,column=15)
              bnt=Button(windows,text="方",bg="#e51c23",width=5)
              bnt.grid(row=30,column=25)
              bnt=Button(windows,text="获",bg="#e51c23",width=5)
              bnt.grid(row=30,column=35)
              bnt=Button(windows,text="胜",bg="#e51c23",width=5)
              bnt.grid(row=30,column=45)
              print("black win")
       elif(white>=126):
              bnt=Button(windows,text="白",bg="#e51c23",width=5)
              bnt.grid(row=30,column=15)
              bnt=Button(windows,text="方",bg="#e51c23",width=5)
              bnt.grid(row=30,column=25)
              bnt=Button(windows,text="获",bg="#e51c23",width=5)
              bnt.grid(row=30,column=35)
              bnt=Button(windows,text="胜",bg="#e51c23",width=5)
              bnt.grid(row=30,column=45)
              print("white win")
                                                       
def printc(i,j):
        global arr2
        global count
        if(count==-1):
                count=1
                arr2[i][j]=-1
                bnt=Button(windows,bg="black",command=lambda x=i, y=j: printc(x, y), width=5)
                bnt.grid(row=i, column=j) 
                take_out()
                judge_win()
        else:
                count=-1
                arr2[i][j]=1
                bnt=Button(windows,bg="white",command=lambda x=i, y=j: printc(x, y), width=5)
                bnt.grid(row=i, column=j)
                take_out() 
                judge_win()
windows=Tk()
windows.geometry("200x200")   
windows.title("窗口") 
#绘制一个名为窗口的窗口并设定大小
for i in range(1,16):
        for j in range(1,16):
                if(arr2[i][j]==0):
                        bnt=Button(windows,bg="#ffa000",command=lambda x=i, y=j: printc(x, y), width=5)
                        bnt.grid(row=i, column=j) 
#利用循环依次建立button绘制成4*4的网格
def printa():
        for i in range(1,16):
                for j in range(1,16):
                        if(arr[i][j]==0):
                               bnt=Button(windows,bg="white",command=lambda x=i, y=j: printc(x, y), width=5)
                               bnt.grid(row=i, column=j) 
                        else:
                                bnt=Button(windows,bg="black",command=lambda x=i, y=j: printc(x, y), width=5)
                                bnt.grid(row=i, column=j)  

def printb():
        for i in range(1,16):
                for j in range(1,16):
                        if(arr1[i][j]==0):
                               bnt=Button(windows,bg="white",command=lambda x=i, y=j: printc(x, y), width=5)
                               bnt.grid(row=i, column=j) 
                        else:
                                bnt=Button(windows,bg="black",command=lambda x=i, y=j: printc(x, y), width=5)
                                bnt.grid(row=i, column=j)  
bnt=Button(windows,text="交",bg="white",command=printb,width=5)
bnt.grid(row=20,column=5)
bnt=Button(windows,text="大",bg="white",command=printa,width=5)
bnt.grid(row=20,column=10)
windows.mainloop() 
