class Matrix:
    r=0
    c=0
    def __init__(self):
        r=int(input("Enter the no of rows in matrix "))
        c=int(input("Enter the no of columns in matrix "))
        self.matrix=self.getMtx(r,c)
    
    def getMtx(self,r,c):
        matrix = [[None for j in range(c)] for i in range(r)]
        for i in range(r):
            for j in range(c):
                matrix[i][j] = int(input())
        return matrix
    
    def prntMtx(self):
        for i in range(len(self.matrix)):
            for j in range(len(self.matrix[i])):
                print(self.matrix[i][j],end=' ')
            print()

    def addMtx(self,m2):
        if self.r!=m2.r or self.c!=m2.c:
            print("Invalid Input")
            return 
        ans=[[None for j in range(len(self.matrix[i]))] for i in range(len(self.matrix))]
        for i in range(len(self.matrix)):
            for j in range(len(self.matrix[i])):
                ans[i][j]=(self.matrix[i][j]+m2.matrix[i][j])
        for i in range(len(self.matrix)):
            for j in range(len(self.matrix[i])):
                print(ans[i][j],end=" ")
            print()

    def subMtx(self,m2):
        if self.r!=m2.r or self.c!=m2.c:
            print("Invalid Input")
            return 
        ans=[[None for j in range(len(self.matrix[i]))] for i in range(len(self.matrix))]
        for i in range(len(self.matrix)):
            for j in range(len(self.matrix[i])):
                ans[i][j]=self.matrix[i][j]-m2.matrix[i][j]
        for i in range(len(self.matrix)):
            for j in range(len(self.matrix[i])):
                print(ans[i][j],end=" ")
            print()

    def mulMtx(self,m2):
        if self.r!=m2.c:
            print("Invalid Input")
            return 
        ans=[[None for j in range(len(self.matrix[i]))] for i in range(len(self.matrix))]
        for i in range(len(self.matrix)):
            for j in range(len(self.matrix[i])):
                ans[i][j]=0
                for k in range(len(self.matrix[i])):
                    ans[i][j]+=self.matrix[i][k]*m2.matrix[k][j]
        for i in range(len(self.matrix)):
            for j in range(len(self.matrix[i])):
                print(ans[i][j],end=" ")
            print()

    def transposeMtx(self):
        ans=[[None for j in range(len(self.matrix[i]))] for i in range(len(self.matrix))]
        for i in range(len(self.matrix)):
            for j in range(len(self.matrix[i])):
                ans[j][i]=self.matrix[i][j]
        for i in range(len(self.matrix)):
            for j in range(len(self.matrix[i])):
                print(ans[i][j],end=" ")
            print()
    
while(True):
    print()
    print("*"*10,"Matrices Operation","*"*10)
    print("Enter 1 for Addition of 2 matrices ")
    print("Enter 2 for subtraction of 2 matrices ")
    print("Enter 3 for Multiplication of 2 matrices ")
    print("Enter 4 to get transpose of a matrix")
    print("Enter 5 to exit from the program")
    
    res=int(input())
    
    if res==1:
        print("Matrix 1")
        m1=Matrix()
        m1.prntMtx()
        print("Matrix 2")
        m2=Matrix()
        m2.prntMtx()
        print("Addition ")
        m1.addMtx(m2)
        
    elif res==2:
        print("Matrix 1")
        m1=Matrix()
        m1.prntMtx()
        print("Matrix 2")
        m2=Matrix()
        m2.prntMtx()
        print("Subtraction ")
        m1.subMtx(m2)
        
    elif res==3:
        print("Matrix 1")
        m1=Matrix()
        m1.prntMtx()
        print("Matrix 2")
        m2=Matrix()
        m2.prntMtx()
        print("Multiplication ")
        m1.mulMtx(m2)
        
    elif res==4:
        print("Matrix 1")
        m1=Matrix()
        m1.prntMtx()
        print("Transpose")
        m1.transposeMtx()
        
    elif res==5:
        break
    else:
        print("Invalid Responce")
        