import math as m   
p=int(input("Enter a prime number p>>>>"))
q=int(input("Enter a prime number q>>>>"))
n=p*q
phi=(p-1)*(q-1)
print(phi)
e=0
for i in range(2,phi):
   e=i
   if(m.gcd(e,phi)==1 and (e!=p) and(e!=q)):
       break
print("Public Key:"+str(e))
k=0
d=0
for i in range(1,10):
    k=i
    temp=((k*phi)+1)/e
    if(temp.is_integer()==True):
        d=temp
        break
d=int(d)
print("Private Key:"+str(d))
m=int(input("Enter the Plaintext Number>>>"))
c=(m**e)%n
print("Encrypted Cipher Text>>"+str(c))
p1=(c**d)%n
print("Decrypted Plain Text>>"+str(p1))
print("--------------DIGITAL SIGNATURE--------------------")
a=int(input("Enter the Digital Signature>>>"))
c1=(a**d)%n
print("Encrypted Cipher Digital Signature>>"+str(c1))
p11=(c1**e)%n
print("Decrypted Plain Digital Signature>>"+str(p11))
