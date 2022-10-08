a=input('')
a=a*3
p=''
def shift(a):
    if a.islower()==True:
        return a.upper()
    if a=='1':
        return "!"
    if a=="2":
        return "@"
    if a=="3":
        return '#'
    if a=="4":
        return "$"
    if a=='5':
        return '%'
    if a=='6':
        return "^"
    if a=='7':
        return '&'
    if a=='8':
        return '*'
    if a=='9':
        return ("(")
    if a=='0':
        return(")")
   
def pointalpha(a):
    b=''
    for i in range(0,len(a)):
      b=b+str(ord(a[i])-96)
    return str((str(hex(int(b))).split('0x'))[1])
x=pointalpha(a)
for i in range(0,len(x)):
   if not i%2==0:
       p+=str(shift(x[i]))
   else:
       p+=str(x[i])
print(p)
