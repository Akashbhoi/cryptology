#!/usr/bin/env python
# coding: utf-8

# In[2]:


def RSA(p, len_M):
    global e, C, ZmodN # Global variables
    
    temp = []
    for x in p:
        temp.append('{0:08b}'.format(ord(x)))

    bin_p = ''.join(temp)
    beta = 1
    eps = beta / 7
    flag = 0
    for length_M in range(0, len_M+1, 4):
        P.<M> = PolynomialRing(ZmodN)
        polynomial = ((int(bin_p, 2)<<length_M) + M)^e - C                   
        m = ceil(1**2 / (polynomial.degree() * (1/7))) # beta = 1, eps = 1/7
        t = floor(polynomial.degree() * m * ((1/beta) - 1))    
        X = ceil(N**((1**2/polynomial.degree()) - (1/7)))  

        roots = coppersmith(polynomial, N, beta, m, t, X) # Calling function coppersmith to get the roots

        if roots:
            print("The correct root is :", bin(roots[0])[2:])
            flag = 1
            break
    if flag==0:
        print('Solution not found')
    
def create_pols(polynomial, degree, x, m, X, modulus):
    
    lis = [] # Polynomials
    lis+=[(x * X)**j * modulus**(m - i) * polynomial(x * X)**i for i in range(m) for j in range(degree)]
    return lis

def cal_possible_roots(lis, degree, x, X, m, t, ZZ):
    y = degree * m + t
    lattice_B = Matrix(ZZ, y) # Lattice B

    for i in range(y):
        for j in range(i+1):
            lattice_B[i, j] = lis[i][j]
   
    lattice_B = lattice_B.LLL() # LLL

    polynomial = 0
    for i in range(y):
        polynomial += x**i * lattice_B[0, i] / X**i # shortest vector

    return polynomial.roots() # Stores the possible roots

def coppersmith(polynomial, modulus, beta, m, t, X):
    
    polynomial = polynomial.change_ring(ZZ)
	
    x = polynomial.change_ring(ZZ).parent().gen()
    degree = polynomial.degree()
   
    lis = create_pols(polynomial, degree, x, m, X, modulus)
	
    possible_roots = cal_possible_roots(lis, degree, x, X, m, t, ZZ)
    
    roots = [] # true roots
    for root in possible_roots:
        if root[0].is_integer():
            result = polynomial(ZZ(root[0]))
            if gcd(modulus, result) >= modulus^beta:
                roots+=[ZZ(root[0])]

    return roots

e = 5
N = 84364443735725034864402554533826279174703893439763343343863260342756678609216895093779263028809246505955647572176682669445270008816481771701417554768871285020442403001649254405058303439906229201909599348669565697534331652019516409514800265887388539283381053937433496994442146419682027649079704982600857517093
C = 12590100438072163303222893495008176186620550277643295391731683363909307946457129861257637802627365446277903091946286803959410701191316907563460553637836618250078939393887868657835003113428912201720371786476710641333600491946457205375021178943175954673185884518045079471036565607774776145160375354622703715944
ZmodN = Zmod(N);

if __name__ == "__main__":
    RSA("Bhois: This door has RSA encryption with exponent 5 and the password is", 200)


# In[ ]:




