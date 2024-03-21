print("1. For Morse to Words\n2. For Words to Morse")
a=int(input())
A=[chr(i) for i in range(65,65+26)]
B=[str(i) for i in range(10)]
C=['.-','-...','-.-.','-..','.','..-.','--.','....','..','.---','-.-','.-..','--','-.','---','.--.','--.-','.-.','...','-','..-','...-','.--','-..-','-.--','--..']
D=['-----','.----','..---','...--','....-','.....','-....','--...','---..','----.']
A.extend(B)
C.extend(D)
b=input("Enter the string to be converted:")
b=b.upper()
e=""
if a==1:
    c=b.split('/')
    d=[]
    for i in c:
        d.extend([i.split()])
    for k in d:
        for j in k:
            e=e+A[C.index(j)]
        e=e+" "
    print(e)
elif a==2:
    f=""
    for i in b:
        if i==' ':
            f=f+'/'
        else:
            f=f+C[A.index(i)]
            f=f+" "
    print(f)