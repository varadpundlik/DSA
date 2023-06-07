class String:
    def longest(self):
        s1=input("Enter a string ")
        ln=0
        lnwrd=None
        init=0
        for i in range(len(s1)):
            if s1[i]==" ":
                if ln<len(s1[init:i]):
                    ln=max(ln,len(s1[init:i]))
                    lnwrd=s1[init:i]
                    init=i
        print(lnwrd,ln)

    def freq(self):
        s1=input("Enter a string " )
        l=input("Enter a letter to check its freqency ")
        cnt=0
        for i in s1:
            if i==l: cnt+=1
        print(cnt)

    def palindrome(self):
        s1=input("Enter a string ")
        st=0
        en=len(s1)-1
        while(en>st):
            if s1[st]!=s1[en]:
                print("Not palindrome")
                return
            st+=1
            en-=1
        print("Palindrome")

  
    def substrIndex(self):
        s1=input("Enter a string ")
        sub=input("Enter a string to check its first occurence ")
        for i in range(len(s1)):
            if sub==s1[i:i+len(sub)]:
                print("first occurance at ",i)
                return
        print("Does not exist in string")
    
    
    def occurence(self):  
        s1=input("Enter a string ")
        ls=[]
        init=0
        word=None
        for i in range(len(s1)):
            if s1[i]==" ":
                if init==0:
                    word=s1[init:i]
                else: word=s1[init+1:i]
                ls.append(word)
                init=i
            else: word=s1[init+1:i+1]
            ls.append(s1[init+1:])
        se=set(ls)
        for i in se:
            print("count of ",i," : ",ls.count(i))
                        
s=String()
while(True):  
    print()  
    print("*"*10,"String Operations","*"*10)
    print("Enter 1 to check longest word in a string ")
    print("Enter 2 to obtain frequency of a letter in a string")
    print("Enter 3 to check if a string is paindrome or not")
    print("Enter 4 to obtain first occurance of a substring in string")
    print("Enter 5 to obtain word count of each word in the string")
    print("Enter 6 to exit")
    print()
    n=int(input())
    if n==1:
        s.longest()
    elif n==2:
        s.freq()
    elif n==3:
        s.palindrome()
    elif n==4:
        s.substrIndex()
    elif n==5:
        s.occurence()
    elif n==6:
        break
    else:
        print("Invalid input")