import random
import string
passlen = int(input("enter the length of password"))
ran=''.join(random.choices(string.punctuation + string.digits + string.ascii_letters,k=passlen))
print(ran)
