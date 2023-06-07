football=list(map(str,input("Football Players : ").split()))
cricket=list(map(str,input("Cricket Players : ").split()))
badminton=list(map(str,input("Badminton Players : ").split()))

def intersection(a,b):
    c=[]
    for i in a:
        if i in b:
            c.append(i)
    return c

def union(a,b):
    c=[]
    for i in a:
        if i not in c:
            c.append(i)
    for i in b:
        if i not in c:
            c.append(i)
    return c

def tascA():
    print("Intersectiojn of cricket and badminton",intersection(cricket,badminton))

def tascB():
    ans2=[]
    for i in union(cricket,badminton):
        if i not in intersection(cricket,badminton):
            ans2.append(i)
    print("Students playing either cricket or badminton but not both",ans2)

def tascC():
    ans3=[]
    for i in football:
        if i not in union(cricket,badminton):
            ans3.append(i)
    print("students who play neither cricket nor badminton",ans3)

def tascD():
    ans4=[]
    for i in intersection(cricket,football):
        if i not in badminton:
            ans4.append(i)
    print("Number of students who play cricket and football but not badminton",ans4)

while(True):

    print("----Set operations----")
    print("Enter corrosponding letter to that task")
    print("task 1 = Students playing both cricket and badminton")
    print("task 2 = Students playing either cricket or badminton but not both")
    print("task 3 = Students who play neither cricket nor badminton")
    print("task 4 = Students who play cricket and football but not badminton")
    print("Enter 5 to exit")

    res=int(input())

    if res==1:tascA()
    elif res==2:tascB()
    elif res==3:tascC()
    elif res==4:tascD()
    elif res==5:break
    else : print("invalid responce")