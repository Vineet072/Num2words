a=['ONE','TWO','THREE','FOUR','FIVE','SIX','SEVEN','EIGHT','NINE','TEN','ELEVEN','TWELVE','THIRTEEN','FOURTEEN','FIFTEEN','SIXTEEN','SEVENTEEN','EIGHTEEN','NINETEEN']
b=['TWENTY','THIRTY','FORTY','FIFTY','SIXTY','SEVENTY','EIGHTY','NINETY']
c=['HUNDRED','THOUSAND','LAKH','CRORE']
e=int(input())
d=[]


#Crore
f=(e%10**9)//(10**7)
if f<20 and f>0:
    d.extend([a[f-1],c[3]])
elif f>19:
    if f%10==0:
        d.extend([b[f//10-2],c[3]])
    elif f%10>0:
        d.extend([b[f//10-2],a[-1+f%10],c[3]])


#Lakh        
f=(e%10**7)//(10**5)
if f<20 and f>0:
    d.extend([a[f-1],c[2]])
elif f>19:
    if f%10==0:
        d.extend([b[f//10-2],c[2]])
    elif f%10>0:
        d.extend([b[f//10-2],a[-1+f%10],c[2]])


#Thousand
f=(e%100000)//1000
if f<20 and f>0:
    d.extend([a[f-1],c[1]])
elif f>19:
    if f%10==0:
        d.extend([b[f//10-2],c[1]])
    elif f%10>0:
        d.extend([b[f//10-2],a[-1+f%10],c[1]])


#Hundred
if (e%1000)//100>0:
    d.extend([a[-1+(e%1000)//100],c[0]])


#<100
f=e%100
if f<20 and f>0:
    d.append(a[f-1])
elif f>19:
    if f%10==0:
        d.append(b[f//10-2])
    elif f%10>0:
        d.extend([b[f//10-2],a[-1+f%10]])
print(*d)