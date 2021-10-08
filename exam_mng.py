from os import name, system
from colorama import Fore, Back, Style, init
import platform
import mysql.connector
import tempfile
import win32api
import win32print
#***********************************************************************************************************************#
def cls():
   system('cls')
def initdb():
   db = mysql.connector.connect(user='root', password='', host='localhost', database='school')
   cr = db.cursor()
   sql="INSERT INTO serial(admno) VALUES ('%d')"%(1)
   try:
      cr.execute(sql)
      db.commit()
      print("DataBase Initialized Successfully")
   except:
      db.rollback()
def checkdb():
   db = mysql.connector.connect(user='root', password='', host='localhost',)
   cr = db.cursor()
   cr.execute("create database if not exists school")
def checktbl():
   db = mysql.connector.connect(user='root', password='', host='localhost', database='school')
   cr = db.cursor()
   cr.execute("create table if not exists serial(admno int)")
   cr.execute("create table if not exists student(admno int primary key, sname varchar(30), dob date, cls varchar(10), addr varchar(50))")
   cr.execute("create table if not exists exam(admno int, marks int, subject varchar(200), term varchar(15), year int)")
   cr.execute("select count(admno) from serial")
   dset=cr.fetchone()
   if(dset[0]==0):
      initdb()
   else:
      print("DataBase Verified Successfully")
#***********************************************************************************************************************#

def selection():
   db = mysql.connector.connect(user='root', password='', host='localhost', database='school')
   cursor = db.cursor()
   init()
   cls()
   print(Style.RESET_ALL)
   print(Fore.WHITE + Back.RED + "----------------------------------------------")
   print("      WELCOME TO SCHOOL MANAGEMENT SYSTEM     ")
   print("----------------------------------------------")
   print("           1. STUDENT MANAGEMENT              ")
   print("           2. EXAM MANAGEMENT                 ")
   print("           3. QUIT PROJECT                    ")
   print(Style.RESET_ALL)
   ch=int(input("          Enter ur choice (1-3) : "))
   if ch==1:
      func_stud()
   elif ch==2:
      func_exam()
   elif ch==3:
      exit()
   else:
      selection()

def func_stud():
   cls()
   print(Fore.WHITE + Back.BLUE + '                                              ')
   print('     WELCOME TO STUDENT MANAGEMENT SYSTEM     ')
   print('                                              ')
   print('          1. NEW ADMISSIONS                   ')
   print('          2. SEARCH STUDENT DETAILS           ')
   print('          3. VIEW ALL RECORDS                 ')
   print('          4. UPDATE RECORDS                   ')
   print('          5. DELETE RECORDS                   ')
   print('          6. Go BACK to MAIN MENU             ')
   print(Style.RESET_ALL)
   c=int(input("       Enter ur choice (1-6) : "))
   if c==1:
      insert1()
   elif c==2:
      search1()
   elif c==3:
      display1()
   elif c==4:
      update1()
   elif c==5:
      delete1()
   elif c==6:
      selection()
   else:
      func_stud()
   func_stud()

def func_exam():
   cls()
   print(Fore.WHITE + Back.BLUE + '                                              ')
   print('      WELCOME TO EXAM MANAGEMENT SYSTEM      ')
   print('         1. NEW MARKS ENTRY                  ')
   print('         2. SEARCH MARKS / RESULTS           ')
   print('         3. UPDATE MARKS ENTRY               ')
   print('         4. PRINT REPORT CARD                ')
   print('         5. Go BACK to MAIN MENU             ')
   print(Style.RESET_ALL)
   c=int(input("       Enter ur choice (1-4) : "))
   if c==1:
      insert2()
   elif c==2:
      display2()
   elif c==3:
      update2()
   elif c==4:
      report2()
   elif c==5:
      selection()
   else:
      func_exam()
   func_exam()
#***********************************************************************************************************#

def insert1():
   db = mysql.connector.connect(user='root', password='', host='localhost',database='school')
   cr = db.cursor()
   cr.execute("select admno from serial")
   dset=cr.fetchone()
   admno=int(dset[0])
   print("Admission Number        :",admno)
   sname=input("Enter Student Name      : ")
   dob=input("Enter D.O.B.(yyyy-mm-dd): ")
   cls=input("Enter Class of Admission: ")
   addr=input("Enter Address           : ")
   csr1 = db.cursor()
   csr2 = db.cursor()
   csr3 = db.cursor()
   csr3.execute("select count(admno) from student where sname='"+sname+"' and dob='"+dob+"' and cls='"+cls+"' and addr='"+addr+"'")
   r=csr3.fetchone()
   if(r[0]>0):
      print(Back.BLACK+Fore.RED+Style.BRIGHT+"--------------- SIMILAR ENTRY Exists Already -------------")
   else:
      sql="INSERT INTO student(admno,sname,dob,cls,addr) VALUES ('%d','%s','%s','%s','%s')"%(admno,sname,dob,cls,addr)
      try:
         csr1.execute(sql)
         csr2.execute("update serial set admno=admno+1")
         db.commit()
         print(Fore.GREEN+'---------------NEW RECORD Successfully Added-----------------------')
      except:
         db.rollback()
   x=input('_______________Press ENTER to Continue_____________________________')
   db.close()   
#**************************************************************************************************************#

def display1():
   i=0
   try:
      db = mysql.connector.connect(user='root', password='', host='localhost',database='school')
      cursor = db.cursor()
      sql = "SELECT * FROM student"
      cursor.execute(sql)
      results = cursor.fetchall()
      print(Back.BLACK+Fore.GREEN+Style.BRIGHT+'\nAdm.No.\tStudentName\t\tD.O.B.\t\tClass\tAddress')
      print('-----------------------------------------------------------------')
      for c in results:
         i+=1
         blank=''
         admno=c[0]
         sname=c[1]
         dob=c[2]
         cls=c[3]
         addr=c[4]
         if(len(sname)<8):
            blank=' '*(8-len(sname))
         print ("%d\t%s%s\t\t%s\t%s\t%s" % (admno,sname,blank,dob,cls,addr))
      print(Back.BLACK+Fore.WHITE+'---------------- Total Records = ',i,' ----------------------------')
   except Exception as e:
      print ("Error: ", e)
   x=input('_______________Press ENTER to Continue_____________________________')
   db.close()
#**************************************************************************************************************#

def search1():
   numb=input("Enter Admission Number / Name to Search : ")
   try:
      i=0
      db = mysql.connector.connect(user='root', password='', host='localhost',database='school')
      cursor = db.cursor()
      if(numb.isnumeric()):
         sql = "SELECT * FROM student WHERE admno="+numb
      else:
         sql = "SELECT * FROM student WHERE sname like '%"+numb+"%'"
      cursor.execute(sql)
      results = cursor.fetchall()      
      print(Back.BLACK+Fore.GREEN+Style.BRIGHT+'\nAdm.No.\tStudentName\t\tD.O.B.\t\tClass\tAddress')
      print('-----------------------------------------------------------------')
      for c in results:
         i+=1
         blank=''
         admno=c[0]
         sname=c[1]
         dob=c[2]
         cls=c[3]
         addr=c[4]
         if(len(sname)<8):
            blank=' '*(8-len(sname))
         print ("%d\t%s%s\t\t%s\t%s\t%s" % (admno,sname,blank,dob,cls,addr))
      print(Back.BLACK+Fore.WHITE+'---------------- Total Records = ',i,' ----------------------------')
   except Exception as e:
      print ("Error: ", e)
   x=input('_______________Press ENTER to Continue_____________________________')
   db.close()
#*************************************************************************************************************#

def update1():
   numb=input("Enter Admission Number to Update : ")
   try:
      db = mysql.connector.connect(user='root', password='', host='localhost',database='school')
      cursor = db.cursor()
      sql = "SELECT * FROM student where admno="+numb
      cursor.execute(sql)
      rs = cursor.fetchone()
      if(not rs):
         print(Back.BLACK+Fore.GREEN+'---------------No Such Records Found--------------------')
      else:
         admno=rs[0]
         sname=rs[1]
         dob=rs[2]
         cls=rs[3]
         addr=rs[4]
         print(Back.BLACK+Fore.YELLOW+"\nAdmission Number : ",admno)
         print(Back.BLACK+Fore.YELLOW+"Name : ",sname)
         sn=input(Back.BLACK+Fore.WHITE+"      New Name   : ")
         print(Back.BLACK+Fore.YELLOW+"DOB  : ",dob)
         do=input(Back.BLACK+Fore.WHITE+"      New D.O.B. : ")
         print(Back.BLACK+Fore.YELLOW+"Class: ",cls)
         cs=input(Back.BLACK+Fore.WHITE+"      New Class  : ")
         print(Back.BLACK+Fore.YELLOW+"Addr.: ",addr)
         ad=input(Back.BLACK+Fore.WHITE+"      New Addr.  : ")
         if(sn==""):
            sn=sname
         if(do==""):
            do=dob
         if(cs==""):
            cs=cls
         if(ad==""):
            ad=addr
         try:
            sql = "UPDATE student SET sname='%s', dob='%s', cls='%s', addr='%s' where admno=%d" % (sn,do,cs,ad,admno)
            cursor.execute(sql)
            db.commit()
            print(Back.BLACK+Fore.GREEN+'---------------RECORD Updated Successfully --------------------')
         except Exception as e:
            print (e)
            db.rollback()
   except Exception as e:
      print ("Error: ", e)
   x=input(Back.BLACK+Fore.WHITE+'_______________Press ENTER to Continue_____________________________')
   db.close()
#*******************************************************************************************************************#

def delete1():
   numb=input("Enter Admission Number to Delete : ")
   try:
      db = mysql.connector.connect(user='root', password='', host='localhost',database='school')
      cursor = db.cursor()
      sql = "SELECT * FROM student where admno="+numb
      cursor.execute(sql)
      rs = cursor.fetchone()
      if(not rs):
         print(Fore.GREEN+'---------------No Such Records Found--------------------')
      else:
         admno=rs[0]
         sname=rs[1]
         cls=rs[3]
         print(Fore.BLUE+Style.BRIGHT+"Record Found as- ",sname," [",admno,"] of Class:",cls)
         try:
           sql = "delete from student where admno=%s" % (numb)
           ans=input(Fore.RED+Style.BRIGHT+"Are you sure you want to delete the record(y/n) : ")
           if(ans=='y' or ans=='Y'):
              cursor.execute(sql)
              db.commit()
              print(Fore.GREEN+'---------------RECORD DELETED Successfully --------------------')
         except Exception as e:
            print (e)
            db.rollback()
   except Exception as e:
      print("Error: ",e)
   x=input('_______________Press ENTER to Continue_____________________________')
   db.close()
#**********************************************************************************************************************#

def calc_percent(ss):
   s=c=0
   for x in ss.split(","):
      l=len(x.strip())-1
      m=""
      while(x[l].isnumeric()):
         m=x[l]+m
         l=l-1
      s=s+int(m)
      c=c+1
   return(s/c)
#-----------------------------------------------------------------------------------------------
def insert2():
   scount=0
   ss=""
   numb=input("Enter Admission Number for Exam Entry : ")
   try:
      db = mysql.connector.connect(user='root', password='', host='localhost',database='school')
      cursor = db.cursor()
      cursor2 = db.cursor()
      sql = "SELECT * FROM student where admno="+numb
      cursor.execute(sql)
      results = cursor.fetchone()
      if(not results):
         print(Fore.GREEN+'---------------No Such Records Found--------------------')
      else:
         admno=int(results[0])
         sname=results[1]
         cls=results[3]
         print("Adm.No.:",admno,"\tName :",sname,"\tClass :",cls)
         cursor.execute("select max(term),year from exam where admno="+str(admno)+" and year=(select max(year) from exam)")
         result = cursor.fetchone()
         if(len(result)==0 or result[0]==None):
            print(Fore.BLUE+Style.BRIGHT+"No Exam Record Found")
         else:
            print(Fore.BLUE+Style.BRIGHT+"Last Exam Taken: ",result[0]," - ",result[1])
         print(Back.GREEN+Fore.WHITE+'____________________New Exam Entry___________________________')
         tt=input(Back.BLACK+Fore.WHITE+'Enter TERM (Term1/Term2)     : ')
         yy=int(input(Back.BLACK+Fore.WHITE+'Enter YEAR  for exam         : '))
         print(Back.BLACK+Fore.YELLOW+Style.BRIGHT+'Enter Marks for SUBJECTS APPEARED Only')
         for sx in subject:
            scount+=1
            sm=input(Back.BLACK+Fore.WHITE+sx+'  : ')
            if(sm!=""):
               if(scount>1):
                  ss=ss+","+sx+"="+sm
               else:
                  ss=ss+sx+"="+sm
         mm=calc_percent(ss)
         print(Back.BLACK+Fore.WHITE+'Percentage of Marks Obtained : ',mm)
         csr1 = db.cursor()
         csr2 = db.cursor()
         csr2.execute("select count(marks) from exam where admno="+str(admno)+" and year="+str(yy)+" and term='"+str(tt)+"'")
         check = csr2.fetchone()
         if(int(check[0])==0):
            sql="INSERT INTO exam VALUES("+str(admno)+","+str(mm)+",'"+str(ss)+"','"+str(tt)+"',"+str(yy)+")"
            try:
               csr1.execute(sql)
               db.commit()
               print(Back.BLACK+Fore.GREEN+'-------------- NEW EXAM Entry Successfully Added -----------------')
            except:
               db.rollback()
         else:
            print(Back.BLACK+Fore.YELLOW+"------------------- Entry ALREADY EXISTS -------------------")
   except Exception as e:
      print ("Error: ", e)
   x=input(Back.BLACK+Fore.WHITE+'_______________Press ENTER to Continue_____________________________')
   db.close()
         
#***********************************************************************************************************************#

def display2():
   c=int(input(Back.RED+Fore.WHITE+Style.BRIGHT+"Press 1.To Search by Adm.No.\t2.To Search by Term\t3.To Search by Class : "))
   if(c==1):
      an=input(Back.BLACK+Back.BLUE+Style.BRIGHT+"Enter Addmission No. of Student : ")
      sql="select exam.*,student.sname,student.cls from exam,student where student.admno=exam.admno and student.admno="+an+" order by exam.year desc, exam.term desc"
   elif(c==2):
      tt=input(Back.BLACK+Back.BLUE+Style.BRIGHT+"Enter EXAM TERM   : ")
      yy=input(Back.BLACK+Back.BLUE+Style.BRIGHT+"Enter EXAM YEAR   : ")
      sql="select exam.*,student.sname,student.cls from exam,student where student.admno=exam.admno and exam.term='"+tt+"' and exam.year="+yy+" order by student.cls asc, student.admno asc"
   elif(c==3):
      cc=input(Back.BLACK+Back.BLUE+Style.BRIGHT+"Enter CLASS whose Results are Sought : ")
      sql="select exam.*,student.sname,student.cls from exam,student where student.admno=exam.admno and student.cls like '%"+cc+"%' order by exam.year desc, exam.term desc"
   else:
      sql=""
   try:
      i=0
      db = mysql.connector.connect(user='root', password='', host='localhost',database='school')
      cursor = db.cursor()
      cursor.execute(sql)
      results = cursor.fetchall()      
      print(Back.BLACK+Fore.GREEN+Style.BRIGHT+'\nAdm.No.\tStudentName\t\tClass.\tMarks\tExam')
      print('-----------------------------------------------------------------')
      for r in results:
         i+=1
         blank=''
         admno=r[0]
         marks=r[1]
         exam=str(r[3])+"-"+str(r[4])
         sname=r[5]
         cls=r[6]
         if(len(sname)<8):
            blank=' '*(8-len(sname))
         print ("%d\t%s%s\t\t%s\t%s\t%s" % (admno,sname,blank,cls,marks,exam))
      print(Back.BLACK+Fore.WHITE+'---------------- Total Records = ',i,' ----------------------------')
   except Exception as e:
      print ("Error: ", e)
   x=input(Back.BLACK+Fore.WHITE+'_______________Press ENTER to Continue_____________________________')
   db.close()
#***********************************************************************************************************************#

def update2():
   an=input(Back.BLACK+Fore.BLUE+Style.BRIGHT+"Enter Addmission No. of Student : ")
   tt=input(Back.BLACK+Fore.BLUE+Style.BRIGHT+"Enter EXAM Term : ")
   yy=input(Back.BLACK+Fore.BLUE+Style.BRIGHT+"Enter EXAM Year : ")
   sql="select exam.*,student.sname,student.cls from exam,student where student.admno=exam.admno and exam.admno="+str(an)+" and exam.term='"+tt+"' and exam.year="+str(yy)
   try:
      db = mysql.connector.connect(user='root', password='', host='localhost',database='school')
      cursor = db.cursor()
      cursor.execute(sql)
      r=cursor.fetchone()
      if(not r):
         print(Back.RED+Fore.WHITE+Style.BRIGHT+"-------------------- No Such EXAM ENTRY Exists ----------------------")
      else:
         admno=r[0]
         marks=r[1]
         subj=r[2]
         term=r[3]
         year=r[4]
         sname=r[5]
         cls=r[6]
         print(Back.BLACK+Fore.YELLOW+"\nAdmission Number : ",admno)
         print(Back.BLACK+Fore.YELLOW+"Name  : ",sname)
         print(Back.BLACK+Fore.YELLOW+"Class : ",cls)
         print(Back.BLACK+Fore.YELLOW+"Term : ",term)
         tt=input(Back.BLACK+Fore.WHITE+"      New Term  : ")
         print(Back.BLACK+Fore.YELLOW+"Year  : ",year)
         yy=input(Back.BLACK+Fore.WHITE+"      New Year  : ")
         print(Back.BLACK+Fore.YELLOW+"Subjects  : ",subj)
         print(Back.BLACK+Fore.YELLOW+Style.BRIGHT+'Enter Marks for SUBJECTS APPEARED Only')
         for sx in subject:
            scount+=1
            sm=input(Back.BLACK+Fore.WHITE+sx+'  : ')
            if(sm!=""):
               if(scount>1):
                  ss=ss+","+sx+"="+sm
               else:
                  ss=ss+sx+"="+sm
         mm=calc_percent(ss)
         print(Back.BLACK+Fore.WHITE+"      New Percentage : ",mm)
         if(tt==""):
            tt=term
         if(yy==""):
            yy=year
         try:
            sql="UPDATE exam SET term='"+str(tt)+"', year="+str(yy)+", subject='"+str(ss)+"', marks="+str(mm)+" where admno="+str(admno)+" and term='"+str(term)+"' and year="+str(year)
            cursor.execute(sql)
            db.commit()
            print(Back.BLACK+Fore.GREEN+'---------------RECORD Updated Successfully --------------------')
         except Exception as e:
            print (e)
            db.rollback()
   except Exception as e:
      print ("Error: ", e)
   x=input(Back.BLACK+Fore.WHITE+'_______________Press ENTER to Continue_____________________________')
#***********************************************************************************************************************#

def report2():
   an=input(Back.BLACK+Fore.BLUE+Style.BRIGHT+"Enter Addmission No. of Student : ")
   tt=input(Back.BLACK+Fore.BLUE+Style.BRIGHT+"Enter EXAM Term : ")
   yy=input(Back.BLACK+Fore.BLUE+Style.BRIGHT+"Enter EXAM Year : ")
   sql="select exam.*,student.sname,student.cls from exam,student where student.admno=exam.admno and exam.admno="+str(an)+" and exam.term='"+tt+"' and exam.year="+str(yy)
   try:
      db = mysql.connector.connect(user='root', password='', host='localhost',database='school')
      cursor = db.cursor()
      cursor.execute(sql)
      r=cursor.fetchone()
      if(not r):
         print(Back.RED+Fore.WHITE+Style.BRIGHT+"-------------------- No Such EXAM ENTRY Exists ----------------------")
      else:
         admno=r[0]
         marks=r[1]
         subject=r[2]
         term=r[3]
         year=r[4]
         sname=r[5]
         cls=r[6]
         prtxt="\n--------------------------------------\n  Adm. Numb. : "+str(admno)+"\n  Name       : "+str(sname)+"\n  Class      : "+str(cls)
         prtxt+="\n  Term/Year  : "+str(term)+"-"+str(year)+"\n--------------------------------------"
         for x in subject.split(","):
            prtxt+="\n          "+str(x)
         prtxt+="\n--------------------------------------\n     Marks  = "+str(marks)+"%"+"\n--------------------------------------"
         print(Back.BLACK+Fore.YELLOW+Style.BRIGHT+prtxt)
   except Exception as e:
      print ("Error: ", e)
   cp=input(Back.BLACK+Fore.WHITE+'_______ Want a HARDCOPY of the Report Card [y/n] ______:');
   if(cp=='y' or cp=='Y'):
      filename = tempfile.mktemp (".txt")
      open (filename, "w").write (prtxt)
      win32api.ShellExecute (0,"print",filename,'/d:"%s"' % win32print.GetDefaultPrinter (),".",0)       
   x=input(Back.BLACK+Fore.WHITE+'_______________Press ENTER to Continue_____________________________')
   db.close()
#`````````````````````````````````````` MAIN PROGRAM STARTS HERE ```````````````````````````````````````````````````````#
subject = ['PHY','CHEM','MATH','BIO','ENG','COMP','PHED']
checkdb()
checktbl()
selection()
