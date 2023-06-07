#sample array 98.7 34.5 65.3 23.5 87.6 100.0 32.6 45.7 88.65 
class Array:
    def insertion_sort(self):
        arr=list(map(float,input("Enter the percentage of all students").split()))
        n=len(arr)
        for i in range(1,n):
            key=arr[i]
            j=i-1
            while j>=0 and key<arr[j]:
                arr[j+1]=arr[j]
                j-=1
                arr[j+1]=key
        k=n-1;
        j=1
        while(j<=5):
            print("rank",j,": ",arr[k])
            k-=1
            j+=1
        
    def shell_sort(self):
        arr=list(map(float,input("Enter the percentage of all students").split()))
        n=len(arr)
        interval=n//2
        while interval>0 :
            j=0
            for i in range(interval,n):
                if(arr[j]>arr[i]):
                    arr[i],arr[j]=arr[j],arr[i]
                j+=1
            interval//=2
        k=n-1;
        j=1
        while(j<=5):
            print("rank",j,": ",arr[k])
            k-=1
            j+=1
while(True):
    print('*'*10,"Percentage Sorting Program",'*'*10)
    print("Enter 1 To sort percentage with Insertion sort")    
    print("Enter 2 To sort percentage with Shell sort")
    print("Enter 3 to Exit from the program")
    
    res=int(input())
    
    if(res==1):
        a=Array()
        a.insertion_sort() 
        
    elif(res==2):
        a=Array()
        a.shell_sort()
         
    elif(res==3):
        break
    
    else:
        continue  