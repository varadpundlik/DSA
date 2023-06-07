class Sparce:
    row=0
    col=0
    val=0
    def __init__(self,r,c,v):
        self.row=r
        self.col=c
        self.val=v
    def spDisplay(self):
        print("<",self.row,self.col,self.val,">")
        
class SparceMartix:
    def __init__(self):
        self.matrix=[]
        n=int(input("Enter the non-zero elements in Sparce Martix"))
        for i in range(n):
            r1=int(input("row"))
            c1=int(input("column"))
            v1=int(input("value"))
            s=Sparce(r1,c1,v1)
            self.matrix.append(s)
    def display(self):
        for i in self.matrix:
            i.spDisplay()


def SPadd(m1,m2):
    m3=[]
    i=0
    j=0
    while(i<len(m1.matrix) and j<len(m2.matrix)):
        if(m1.matrix[i].row>m2.matrix[j].row):
            m3.append(m2.matrix[j])
            j+=1
        if(m1.matrix[i].row<m2.matrix[j].row):
            m3.append(m1.matrix[i])
            i+=1
        if(m1.matrix[i].row==m2.matrix[j].row):
            if(m1.matrix[i].col>m2.matrix[j].col):
                m3.append(j)
                j+=1
            if(m1.matrix[i].col>m2.matrix[j].col):
                m3.append(m1.matrix[i])
                i+=1
            else:
                t=Sparce(m1.matrix[i].row,m1.matrix[i].col,m1.matrix[i].val+m2.matrix[j].val)
                m3.append(t)
                i+=1
                j+=1       
    while(i<len(m1.matrix)):
        m3.append(m1.matrix[i])
        i+=1
        
    while(j<len(m2.matrix)):
        m3.append(m2.matrix[j])
        j+=1
        
    for i in m3:
        i.spDisplay()


m1=SparceMartix()
print("Sparce Matrix 1")
m1.display()

m2=SparceMartix()
print("Sparce Matrix 2")
m2.display()

print("Addition: ")
SPadd(m1,m2)