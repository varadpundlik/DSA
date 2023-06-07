class term:
    coef=0
    power=0
    def __init__(self,c,p):
        self.coef=c
        self.power=p
    
    def printTerm(self):
        if(self.power==0):
            print("(",self.coef,")",end=" ")
        elif(self.power==1):
            print("(",self.coef,"x",")",end=" ")
        else:
            print("(",self.coef,"x^",self.power,")",end=" ")
        
class polynomial:
    def __init__(self):
        self.poly=[]
        n=int(input("Enter the no. of non-zero terms in polynomial"))
        for i in range(n):
            c=int(input("Coefficient"))
            p=int(input("Power"))
            t=term(c,p)
            self.poly.append(t)
            
    def printPoly(self):
        for i in range(len(self.poly)):
            self.poly[i].printTerm()
            if(i!=len(self.poly)-1):
                print("+",end=" ")


def addPoly(p1,p2):
    p3=[]
    i=0
    j=0
    while(i<len(p1.poly) and j<len(p1.poly)):
        if(p1.poly[i].power>p2.poly[j].power):
            p3.append(p2.poly[j])
            j+=1
        elif(p1.poly[i].power<p2.poly[j].power):
            p3.append(p1.poly[i])
            i+=1
        else:
            t=term(p1.poly[i].coef+p2.poly[j].coef,p1.poly[i].power)
            p3.append(t)     
    while(i<len(p1.poly)):
        p3.append(p1.poly[i])
        i+=1
        
    while(j<len(p2.poly)):
        p3.append(p2.poly[j])
        j+=1
        
    for i in p3:
        i.printTerm()
        if(i!=len(p3)-1):
            print("+",end=" ")

p1=polynomial()
p1.printPoly()

p2=polynomial()
p2.printPoly()

addPoly(p1, p2)