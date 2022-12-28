
p = 455470209427676832372575348833

def gcd(a, b):
    if b == 0:
        return a
    else:
        return gcd(b,a%b)

def power(a,n):
    ans = 1
    while n:
        if n % 2 == 0:
            a = ((a%p) * (a%p))
            n = n // 2
        else:
            ans = ((ans % p) * (a % p))%p
            n = n - 1
    
    return ans

def inv(a):
    return power(a,p-2)

def mul(a, b):
    return (a%p * b%p)%p

a1 = 429
a2 = 1973
a3 = 7596

m1 = 431955503618234519808008749742
m2 = 176325509039323911968355873643
m3 = 98486971404861992487294722613

g1 = mul(m2, inv(m1)) 
g2 = mul(m3, inv(m1))
p1 = 1544
p2 = 7167


def gcdExtended(a, b): 
    if a == 0 :  
        return b,0,1
             
    gcd,x1,y1 = gcdExtended(b%a, a)
    x = y1 - (b//a) * x1 
    y = x1 
     
    return gcd,x,y

c,x,y = gcdExtended(p1,p2)
k1 = 0
k2 = 0
print("x = ",x,", y = ",y)
if x < 0:
    k1 = pow(inv(g1),-x)
else:
    k1 = pow(g1,x)

if y < 0:
    k2 = pow(inv(g2), -y)
else:
    k2 = pow(g2,y)

g = mul(k1,k2)
print("g = ",g)

g_inv = inv(g)
g_inv_pow = pow(g_inv, a1)
password = mul(m1, g_inv_pow)
print("password = ", password)