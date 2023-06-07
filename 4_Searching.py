class array:
    
    def linearSearch(self):
        arr=list(map(int,input("Enter student roll nos").split()))
        sr=int(input("Enter a roll no to search"))
        for i in range(len(arr)):
            if arr[i]==sr:
                print(sr,"is at index ",i)
                return;
        print(sr," Not found")
        
    def binerySearch(self):
        arr=list(map(int,input("Enter student roll nos ").split()))
        sr=int(input("Enter a roll no to search "))
        arr.sort()
        print("Sorted array",arr)
        st=0
        en=len(arr)-1
        while(en>st):
            mid=int((st+en)/2)
            if arr[mid]==sr:
                print(sr," is at index ",mid," in sorted array")
                return 
            elif(arr[mid]>sr):
                en=mid
            else:
                st=mid
        print(sr," not found")
        
    def sentinelSearch(self):
        arr=list(map(int,input("Enter student roll nos ").split()))
        sr=int(input("Enter a roll no to search "))
        temp=arr[-1]
        arr[-1]=sr
        i=0
        while(arr[i]!=arr[-1]):
            i+=1
        arr[-1]=temp
        if(i<len(arr)-1 or sr==arr[-1]):
            print(sr,"is at index ",i)
            return 
        print(sr," not found")
        return 
    
    def fibonacciSearch(self):
        arr=list(map(int,input("Enter student roll nos ").split()))
        sr=int(input("Enter a roll no to search "))
        arr.sort()
        t2=0
        t1=1
        t=t1+t2
        while t<len(arr):
            t2=t1
            t1=t
            t=t1+t2
        
        offset=-1
        while(t>1):
            if arr[offset+t2]==sr:
                print(sr,"  is at index ",offset+t2," in sorted array") 
                return 
            elif arr[offset+t2]>sr:
                t=t2
                t1=t1-t2
                t2=t-t1
            else:
                offset+=t2
                t=t1
                t1=t2
                t2=t-t1
        print(sr," not found")
        return
    
while(True):
    print("*"*10,"Array searching program","*"*10)
    print("Enter 1 to search an element using linear search")
    print("Enter 2 to search an element using binary search")  
    print("Enter 3 to search an element using sentinel search") 
    print("Enter 4 to search an element using fibonacci search") 
    print("Enter 5 to exit from the program")
    
    res=int(input())
    
    if res==1:
        a=array()
        a.linearSearch()
    elif res==2:
        a=array()
        a.binerySearch()
    elif res==3:
        a=array()
        a.sentinelSearch()
    elif res==4:
        a=array()
        a.fibonacciSearch()
    elif res==5:
        break
    else:
        continue 
    