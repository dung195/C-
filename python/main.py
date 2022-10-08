import math
def check(a):
    if(a<=0): return False
    x=a**(1/2)
    if(x-int(x)==0): return True
    return False
def main():
    c=int(input())
    for i in range(1,c):
        tmp=i*i
        if(check(tmp-c)==True):
            print("YES")
            print(i,end=" ")
            print(int(math.sqrt(tmp-c)))
            return 0
    print("NO")
main()