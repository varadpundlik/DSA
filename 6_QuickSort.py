#sample input - 98.7 34.5 65.3 23.5 87.6 100.0 32.6 45.7 88.65 
class Array:
    
    arr=list(map(float,input("Enter the percentage of all students").split()))
    n=len(arr)
    low=0;
    high=n-1
    
    def partition(self,arr,high,low):
        pivot=arr[high]
        i=low-1
        for j in range(low,high):
            if(arr[j]<pivot):
                i+=1
                arr[i],arr[j]=arr[j],arr[i]
        arr[high],arr[i+1]=arr[i+1],arr[high]
        return i+1
    
    def quick_sort(self,arr,low,high):
        if(low<high):
            pi=self.partition(arr, high, low)
            self.quick_sort(arr, low, pi-1)
            self.quick_sort(arr, pi+1, high)
             
    
print("student ranklist")
a=Array()
a.quick_sort(a.arr, a.low, a.high)
k=a.n-1
for i in range(1,6):
    print("rank",i,":",a.arr[k])
    k-=1