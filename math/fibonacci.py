import sys

MOD = int(1000000007)

#n = int(sys.stdin.readline())
f = open("/home/dessertion/wsl-programming/competitive-programming/input.txt","r")
n = int(f.read())
x,y = 1,1
mat = [1,1,1,0]
n -= 2
n %= 2000000016
while n>0:
    if n&1==1:
        tx = ((x*mat[0])%MOD+(y*mat[1])%MOD)%MOD
        ty = ((x*mat[2])%MOD+(y*mat[3])%MOD)%MOD
        x = tx
        y = ty
    n>>=1
    a = ((mat[0]*mat[0])%MOD+(mat[1]*mat[2])%MOD)%MOD
    b = ((mat[0]*mat[1])%MOD+(mat[1]*mat[3])%MOD)%MOD   
    c = ((mat[0]*mat[2])%MOD+(mat[2]*mat[3])%MOD)%MOD
    d = ((mat[1]*mat[2])%MOD+(mat[3]*mat[3])%MOD)%MOD
    mat[0]=a;mat[1]=b;mat[2]=c;mat[3]=d
    
print(x)