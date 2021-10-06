def encrypt(text,s):
   result = ""
   # transverse the plain text
   for i in range(len(text)):
      char = text[i]
      # Encrypt uppercase characters in plain text
      if (char.isupper()):
         result += chr((ord(char) + s-65) % 26 + 65)
      # Encrypt lowercase characters in plain text
      else:
         result += chr((ord(char) + s - 97) % 26 + 97)
      #return result
   print("Cipher is>>>>",result)
   return result
#check the above function
text = input("Enter the plaintext you want>>>>").upper().replace(" ","")
s = int(input("Enter the key please>>>"))
print ("Plain Text>>>>" + text)
print ("Shift pattern>>>> " + str(s))
#print ("Cipher>>>>" + encrypt(text,s))
message=encrypt(text,s)
#message = 'GIEWIVrGMTLIVrHIQS' #encrypted message
LETTERS = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
for key in range(len(LETTERS)):
   translated = ''
   for symbol in message:
      if symbol in LETTERS:
         num = LETTERS.find(symbol)
         num = num - key
         if num < 0:
            num = num + len(LETTERS)
         translated = translated + LETTERS[num]
      else:
         translated = translated + symbol
   print('Hacking key #%s>>>> %s' % (key, translated))
