from tkinter import*
from tkinter import ttk
from tkinter import messagebox
import random
from datetime import date
import time
import sqlite3

root=Tk()
root.title("Cafe Management System")
root.geometry("1000x650")
root.resizable(width=False,height=False)
root.configure(bg="#220D0B")

logo = PhotoImage(file="logo.png")
rightcup = PhotoImage(file="rightcup.png")
leftcup = PhotoImage(file="leftcup.png")
#**************************************CheckButton variables*******************************************************

menu1chkVar = IntVar()
menu2chkVar = IntVar()
menu3chkVar = IntVar()
menu4chkVar = IntVar()
menu5chkVar = IntVar()
menu6chkVar = IntVar()
menu7chkVar = IntVar()
menu8chkVar = IntVar()
menu9chkVar = IntVar()
menu10chkVar = IntVar()
menu11chkVar = IntVar()
menu12chkVar = IntVar()

#******************************Entry Variables******************************************************************
nameVar=StringVar()
menu1Var = IntVar()
menu2Var  = IntVar()
menu3Var  = IntVar()
menu4Var  = IntVar()
menu5Var  = IntVar()
menu6Var  = IntVar()
menu7Var  = IntVar()
menu8Var  = IntVar()
menu9Var  = IntVar()
menu10Var  = IntVar()
menu11Var  = IntVar()
menu12Var  = IntVar()

#************************************FUNCTIONS***********************************************************************
def exit():
    ans=messagebox.askyesno("Cafe Bloom","Are you sure you want to exit?")
    if ans:
        root.destroy()
def CheckBtn_Value():
    if (menu1chkVar.get())==1:
        menu1Entry.configure(state=NORMAL)
    elif menu1chkVar.get()==0:
        menu1Entry.configure(state=DISABLED)
        menu1Var.set("0")

    if (menu2chkVar.get())==1:
        menu2Entry.configure(state=NORMAL)
    elif menu2chkVar.get()==0:
        menu2Entry.configure(state=DISABLED)
        menu2Var.set("0")

    if (menu3chkVar.get())==1:
        menu3Entry.configure(state=NORMAL)
    elif menu3chkVar.get()==0:
        menu3Entry.configure(state=DISABLED)
        menu3Var.set("0")

    if (menu4chkVar.get())==1:
        menu4Entry.configure(state=NORMAL)
    elif menu4chkVar.get()==0:
        menu4Entry.configure(state=DISABLED)
        menu4Var.set("0")

    if (menu5chkVar.get())==1:
        menu5Entry.configure(state=NORMAL)
    elif menu5chkVar.get()==0:
        menu5Entry.configure(state=DISABLED)
        menu5Var.set("0")

    if (menu6chkVar.get())==1:
        menu6Entry.configure(state=NORMAL)
    elif menu6chkVar.get()==0:
        menu6Entry.configure(state=DISABLED)
        menu6Var.set("0")

    if (menu7chkVar.get())==1:
        menu7Entry.configure(state=NORMAL)
    elif menu7chkVar.get()==0:
        menu7Entry.configure(state=DISABLED)
        menu7Var.set("0")

    if (menu8chkVar.get())==1:
        menu8Entry.configure(state=NORMAL)
    elif menu8chkVar.get()==0:
        menu8Entry.configure(state=DISABLED)
        menu8Var.set("0")  

    if (menu9chkVar.get())==1:
        menu9Entry.configure(state=NORMAL)
    elif menu9chkVar.get()==0:
        menu9Entry.configure(state=DISABLED)
        menu9Var.set("0")  

    if (menu10chkVar.get())==1:
        menu10Entry.configure(state=NORMAL)
    elif menu10chkVar.get()==0:
        menu10Entry.configure(state=DISABLED)
        menu10Var.set("0")  

    if (menu11chkVar.get())==1:
        menu11Entry.configure(state=NORMAL)
    elif menu11chkVar.get()==0:
        menu11Entry.configure(state=DISABLED)
        menu11Var.set("0")  

    if (menu12chkVar.get())==1:
        menu12Entry.configure(state=NORMAL)
    elif menu12chkVar.get()==0:
        menu12Entry.configure(state=DISABLED)
        menu12Var.set("0")           
def Receipt():
    m1=menu1Var.get()
    m2=menu2Var.get()
    m3=menu3Var.get()
    m4 =menu4Var.get()
    m5 =menu5Var.get()
    m6=menu6Var.get()
    m7=menu7Var.get()
    m8=menu8Var.get()
    m9=menu9Var.get()
    m10=menu10Var.get()
    m11=menu11Var.get()
    m12=menu12Var.get()
    totalQty=m1+m2+m3+m4+m5+m6+m7+m8+m9+m10+m11+m12

    if len(nameVar.get())==0:
        messagebox.showwarning("Cafe Bloom","Place Order & enter name to generate receipt...")
    else:
        today=date.today()
        timee = time.strftime("%H:%M")
        todayDate=today.strftime("%d/%m/%Y")
        receiptTxt.delete(0, END)
        x = random.randint(10908, 500876)
        billNo = str(x)
        receiptTxt.insert(END,"                     Cafe Bloom")
        receiptTxt.insert(END,"      Merced 307, Santiago 8320115 Chile")
        receiptTxt.insert(END,"                  Phone:020-23088866")
        receiptTxt.insert(END,"------------------------------------------------------------")
        receiptTxt.insert(END,"                    Name : "+nameVar.get())
        receiptTxt.insert(END,"Bill : "+billNo + "        " +todayDate+"           "+timee)
        receiptTxt.insert(END,"------------------------------------------------------------")
        receiptTxt.insert(END,"Item              Qty.        Cost of item")
        receiptTxt.insert(END,"------------------------------------------------------------")

        if menu1Var.get()>0:
            receiptTxt.insert(END,"Americano       "+str(m1)+"           "+str(m1*220))
        if menu2Var.get()>0:
            receiptTxt.insert(END,"Cappuccino      "+str(m2)+"           "+str(m2*200))
        if menu3Var.get()>0:
            receiptTxt.insert(END,"Espresso        "+str(m3)+"           "+str(m3*150))
        if menu4Var.get()>0:
            receiptTxt.insert(END,"Latte           "+str(m4)+"           "+str(m4*150))
        if menu5Var.get()>0:   
            receiptTxt.insert(END,"Choclate        "+str(m5)+"           "+str(m5*140))
        if menu6Var.get()>0:
            receiptTxt.insert(END,"Mocha           "+str(m6)+"           "+str(m6*350))
        if menu7Var.get()>0:
            receiptTxt.insert(END,"Glace           "+str(m7)+"           "+str(m7*245))
        if menu8Var.get()>0:
            receiptTxt.insert(END,"Hot Choclate    "+str(m8)+"           "+str(m8*200))
        if menu9Var.get()>0:
            receiptTxt.insert(END,"Macchiato       "+str(m9)+"           "+str(m9*250))
        if menu10Var.get()>0:
            receiptTxt.insert(END,"Corto           "+str(m10)+"           "+str(m10*200))
        if menu11Var.get()>0:   
            receiptTxt.insert(END,"Iced Coffee     "+str(m11)+"           "+str(m11*175))
        if menu12Var.get()>0:
            receiptTxt.insert(END,"Irish Coffee    "+str(m12)+"           "+str(m12*245))

        totalPrice=0
        totalPrice=(220*m1)+(200*m2)+(150*m3)+(150*m4)+(140*m5)+(350*m6)\
        +(245*m7)+(200*m8)+(250*m9)+(200*m10)+(175*m11)+(245*m12)
        gstAmt=(totalPrice*(18/100))/100
        gstAmt=round(gstAmt,2)
        netPrice=int(totalPrice+gstAmt)

        receiptTxt.insert(END,"------------------------------------------------------------")
        receiptTxt.insert(END,"Total     = "+str(totalPrice)+"/-")
        receiptTxt.insert(END,"GST       = "+str(gstAmt))
        receiptTxt.insert(END,"Net Total = "+str(netPrice)+"/-")
        receiptTxt.insert(END,"------------------------------------------------------------")
    return (totalQty)
def Total():
    m1=menu1Var.get()
    m2=menu2Var.get()
    m3=menu3Var.get()
    m4 =menu4Var.get()
    m5 =menu5Var.get()
    m6=menu6Var.get()
    m7=menu7Var.get()
    m8=menu8Var.get()
    m9=menu9Var.get()
    m10=menu10Var.get()
    m11=menu11Var.get()
    m12=menu12Var.get()
    totalPrice=0
    totalPrice=(220*m1)+(200*m2)+(150*m3)+(150*m4)+(140*m5)+(350*m6)\
    +(245*m7)+(200*m8)+(250*m9)+(200*m10)+(175*m11)+(245*m12)
    gstAmt=(totalPrice*(18/100))/100
    gstAmt=round(gstAmt,2)
    netPrice=int(totalPrice+gstAmt)
    if len(nameVar.get())==0:
        messagebox.showwarning("Cafe Bloom","Place Order & enter name to generate total...")
    else:
        today=date.today()
        timee = time.strftime("%H:%M")
        todayDate=today.strftime("%d/%m/%Y")
        receiptTxt.delete(0, END)
        x = random.randint(10908, 500876)
        billNo = str(x)
        receiptTxt.insert(END,"                      Cafe Bloom")
        receiptTxt.insert(END,"      Merced 307, Santiago 8320115 Chile")
        receiptTxt.insert(END,"                "+"Phone:020-23088866")
        receiptTxt.insert(END,"-------------------------------------------------------------")
        receiptTxt.insert(END,"                    Name : "+nameVar.get())
        receiptTxt.insert(END,"Bill : "+billNo + "        " +todayDate+"        "+timee)
        receiptTxt.insert(END,"-------------------------------------------------------------")
        
        receiptTxt.insert(END,"Total = "+str(totalPrice)+"/-")
        receiptTxt.insert(END,"GST = "+str(gstAmt))
        receiptTxt.insert(END,"Net Total = "+str(netPrice)+"/-")
    return (netPrice)
def reset():
    nameVar.set("")
    menu1Var.set(0)
    menu2Var.set(0)
    menu3Var.set(0)
    menu4Var.set(0)
    menu5Var.set(0)
    menu6Var.set(0)
    menu7Var.set(0)
    menu8Var.set(0)
    menu9Var.set(0)
    menu10Var.set(0)
    menu11Var.set(0)
    menu12Var.set(0)

    menu1chkVar.set(0)
    menu2chkVar.set(0)
    menu3chkVar.set(0)
    menu4chkVar.set(0)
    menu5chkVar.set(0)
    menu6chkVar.set(0)
    menu7chkVar.set(0)
    menu8chkVar.set(0)
    menu9chkVar.set(0)
    menu10chkVar.set(0)
    menu11chkVar.set(0)
    menu12chkVar.set(0)

    menu1Entry.configure(state=DISABLED)
    menu2Entry.configure(state=DISABLED)
    menu3Entry.configure(state=DISABLED)
    menu4Entry.configure(state=DISABLED)
    menu5Entry.configure(state=DISABLED)
    menu6Entry.configure(state=DISABLED)
    menu7Entry.configure(state=DISABLED)
    menu8Entry.configure(state=DISABLED)
    menu9Entry.configure(state=DISABLED)
    menu10Entry.configure(state=DISABLED)
    menu11Entry.configure(state=DISABLED)
    menu12Entry.configure(state=DISABLED)

    receiptTxt.delete(0,END)
def AddData():
    if len(nameVar.get())==0:
        messagebox.showinfo("Cafe Bloom","Place Order to add data")
    else:
        ans=messagebox.askyesno("Cafe Bloom","Do you want to add data in database?")
        name=nameVar.get()
        total=Total()
        orders=Receipt()
        today=date.today()
        timee = time.strftime("%H:%M")
        dateT=today.strftime("%d/%m/%Y")
        if ans:
            cont=sqlite3.connect("Cafe.db")
            cur=cont.cursor()
            cur.execute("CREATE TABLE IF NOT EXISTS CafeData(id INTEGER PRIMARY KEY,Name text, \
                Orders text,Total text,Time text,Date text)")
            cur.execute("INSERT INTO CafeData VALUES(NULL,?,?,?,?,?)",(name,orders,total,timee,dateT))
            cont.commit()
            cont.close()
            messagebox.showinfo("Cafe Bloom","Data added successfully!!")
        reset()
def DisplayData():
    newroot = Tk()
    newroot.title("Cafe Bloom Records")
    newroot.geometry("450x300")

    y = Scrollbar(newroot,orient=VERTICAL)
    y.pack(side=RIGHT,fill=Y)

    dataview = ttk.Treeview(newroot,height=15,columns=("Column1","Column2","Column3",\
        "Column4","Column5"),yscrollcommand=y.set)

    dataview.column("#0",width=40,minwidth=30,anchor="c")
    dataview.column("Column1",width=80,minwidth=30,anchor="c")
    dataview.column("Column2",width=50,minwidth=30,anchor="c")
    dataview.column("Column3",width=60,minwidth=30,anchor="c")
    dataview.column("Column4",width=80,minwidth=30,anchor="c")
    dataview.column("Column5",width=70,minwidth=30,anchor="c")

    dataview.heading("#0",text="No.")
    dataview.heading("Column1",text="Name")
    dataview.heading("Column2",text="Orders")
    dataview.heading("Column3",text="Total")
    dataview.heading("Column4",text="Time")
    dataview.heading("Column5",text="Date")

    dataview.pack(side=TOP,fill=X)
    y.config(command=dataview.yview)
    cont=sqlite3.connect("Cafe.db")
    cur=cont.cursor()
    cur.execute("SELECT * FROM CafeData")
    data=cur.fetchall()
    for i in data:
        dataview.insert("","end",text=str(i[0]),values=(str(i[1]),str(i[2]),str(i[3])+"/-",str(i[4]),str(i[5])))
    
    newroot.mainloop()
#************************************MENUCARD FRAME,HEADING AND LABELS******************************************************************

mainFrame = Frame(root,width=1000,height=650,bd=6,relief=SUNKEN,bg="#220D0B").place(x=0,y=0)

logoImage = Label(mainFrame,image=logo,bd=4,relief=SUNKEN).place(x=220,y=10)
rightcupImage = Label(mainFrame,image=rightcup,bd=2,relief=SUNKEN).place(x=745,y=13)
leftcupImage = Label(mainFrame,image=leftcup,bd=2,relief=SUNKEN).place(x=135,y=13)

menucardFrame = Frame(mainFrame,width=600,height=540,bd=6,relief=SUNKEN,bg="#bf8040",highlightthickness=2,highlightbackground="#ffcc00",highlightcolor="#ffcc00")
menucardFrame.place(x=0,y=100)

menuLbl = Label(mainFrame,text="Bloom MenuCard",font="msserif 20 bold",bg="#bf8040").place(x=0,y=110)

#**********************************************Checkbuttons******************************************************************
menu1Chk = Checkbutton(mainFrame,text="Americano",variable=menu1chkVar,font="msserif 17 bold",bg="#bf8040",onvalue=1,offvalue=0,command=CheckBtn_Value).place(x=30,y=160)
menu2Chk = Checkbutton(mainFrame,text="Cappuccino",variable=menu2chkVar,font="msserif 17 bold",bg="#bf8040",onvalue=1,offvalue=0,command=CheckBtn_Value).place(x=30,y=200)
menu3Chk = Checkbutton(mainFrame,text="Espresso",variable=menu3chkVar,font="msserif 17 bold",bg="#bf8040",onvalue=1,offvalue=0,command=CheckBtn_Value).place(x=30,y=240)
menu4Chk = Checkbutton(mainFrame,text="Latte",variable=menu4chkVar,font="msserif 17 bold",bg="#bf8040",onvalue=1,offvalue=0,command=CheckBtn_Value).place(x=30,y=280)
menu5Chk = Checkbutton(mainFrame,text="Choclate",variable=menu5chkVar,font="msserif 17 bold",bg="#bf8040",onvalue=1,offvalue=0,command=CheckBtn_Value).place(x=30,y=320)
menu6Chk = Checkbutton(mainFrame,text="Mocha",variable=menu6chkVar,font="msserif 17 bold",bg="#bf8040",onvalue=1,offvalue=0,command=CheckBtn_Value).place(x=30,y=360)
menu7Chk = Checkbutton(mainFrame,text="Glace",variable=menu7chkVar,font="msserif 17 bold",bg="#bf8040",onvalue=1,offvalue=0,command=CheckBtn_Value).place(x=30,y=400)
menu8Chk = Checkbutton(mainFrame,text="Hot Choclate",variable=menu8chkVar,font="msserif 17 bold",bg="#bf8040",onvalue=1,offvalue=0,command=CheckBtn_Value).place(x=30,y=440)
menu9Chk = Checkbutton(mainFrame,text="Macchiato",variable=menu9chkVar,font="msserif 17 bold",bg="#bf8040",onvalue=1,offvalue=0,command=CheckBtn_Value).place(x=30,y=480)
menu10Chk = Checkbutton(mainFrame,text="Corto",variable=menu10chkVar,font="msserif 17 bold",bg="#bf8040",onvalue=1,offvalue=0,command=CheckBtn_Value).place(x=30,y=520)
menu11Chk = Checkbutton(mainFrame,text="Iced Coffee",variable=menu11chkVar,font="msserif 17 bold",bg="#bf8040",onvalue=1,offvalue=0,command=CheckBtn_Value).place(x=30,y=560)
menu12Chk = Checkbutton(mainFrame,text="Irish Coffee",variable=menu12chkVar,font="msserif 17 bold",bg="#bf8040",onvalue=1,offvalue=0,command=CheckBtn_Value).place(x=30,y=600)

#************************************ENTRIES************************************************************************

menu1Entry = Entry(mainFrame,textvariable=menu1Var,width=4,bg="#bf8040",font="verdana 16 bold",bd=4,relief=RAISED,state=DISABLED)
menu1Entry.place(x=500,y=160)

menu2Entry = Entry(mainFrame,textvar=menu2Var,width=4,bg="#bf8040",font="verdana 16 bold",bd=4,relief=RAISED,state=DISABLED)
menu2Entry.place(x=500,y=200)

menu3Entry = Entry(mainFrame,textvar=menu3Var,width=4,bg="#bf8040",font="verdana 16 bold",bd=4,relief=RAISED,state=DISABLED)
menu3Entry.place(x=500,y=240)

menu4Entry = Entry(mainFrame,textvar=menu4Var,width=4,bg="#bf8040",font="verdana 16 bold",bd=4,relief=RAISED,state=DISABLED)
menu4Entry.place(x=500,y=280)

menu5Entry = Entry(mainFrame,textvar=menu5Var,width=4,bg="#bf8040",font="verdana 16 bold",bd=4,relief=RAISED,state=DISABLED)
menu5Entry.place(x=500,y=320)

menu6Entry = Entry(mainFrame,textvar=menu6Var,width=4,bg="#bf8040",font="verdana 16 bold",bd=4,relief=RAISED,state=DISABLED)
menu6Entry.place(x=500,y=360)

menu7Entry = Entry(mainFrame,textvar=menu7Var,width=4,bg="#bf8040",font="verdana 16 bold",bd=4,relief=RAISED,state=DISABLED)
menu7Entry.place(x=500,y=400)

menu8Entry = Entry(mainFrame,textvar=menu8Var,width=4,bg="#bf8040",font="verdana 16 bold",bd=4,relief=RAISED,state=DISABLED)
menu8Entry.place(x=500,y=440)

menu9Entry = Entry(mainFrame,textvar=menu9Var,width=4,bg="#bf8040",font="verdana 16 bold",bd=4,relief=RAISED,state=DISABLED)
menu9Entry.place(x=500,y=480)

menu10Entry = Entry(mainFrame,textvar=menu10Var,width=4,bg="#bf8040",font="verdana 16 bold",bd=4,relief=RAISED,state=DISABLED)
menu10Entry.place(x=500,y=520)

menu11Entry = Entry(mainFrame,textvar=menu11Var,width=4,bg="#bf8040",font="verdana 16 bold",bd=4,relief=RAISED,state=DISABLED)
menu11Entry.place(x=500,y=560)

menu12Entry = Entry(mainFrame,textvar=menu12Var,width=4,bg="#bf8040",font="verdana 16 bold",bd=4,relief=RAISED,state=DISABLED)
menu12Entry.place(x=500,y=600)

#*************************************PRICE LABELS******************************************************************
menu1Price = Label(mainFrame,text="---------------------220/-",font="msserif 16 bold italic",bg="#bf8040").place(x=230,y=160)
menu2Price = Label(mainFrame,text="---------------------200/-",font="msserif 16 bold italic",bg="#bf8040").place(x=230,y=200)
menu3Price = Label(mainFrame,text="---------------------150/-",font="msserif 16 bold italic",bg="#bf8040").place(x=230,y=240)
menu4Price = Label(mainFrame,text="---------------------150/-",font="msserif 16 bold italic",bg="#bf8040").place(x=230,y=280)
menu5Price = Label(mainFrame,text="---------------------140/-",font="msserif 16 bold italic",bg="#bf8040").place(x=230,y=320)
menu6Price = Label(mainFrame,text="---------------------350/-",font="msserif 16 bold italic",bg="#bf8040").place(x=230,y=360)
menu7Price = Label(mainFrame,text="---------------------245/-",font="msserif 16 bold italic",bg="#bf8040").place(x=230,y=400)
menu8Price = Label(mainFrame,text="-------------------200/-",font="msserif 16 bold italic",bg="#bf8040").place(x=250,y=440)
menu9Price = Label(mainFrame,text="---------------------250/-",font="msserif 16 bold italic",bg="#bf8040").place(x=230,y=480)
menu10Price = Label(mainFrame,text="---------------------200/-",font="msserif 16 bold italic",bg="#bf8040").place(x=230,y=520)
menu11Price = Label(mainFrame,text="---------------------175/-",font="msserif 16 bold italic",bg="#bf8040").place(x=230,y=560)
menu12Price = Label(mainFrame,text="---------------------245/-",font="msserif 16 bold italic",bg="#bf8040").place(x=230,y=600)
#************************************RECEIPT FRAME,LABEL and TEXT*******************************************************************

receiptFrame = Frame(mainFrame,width=385,height=40,bd=6,relief=SUNKEN,bg="#bf8040",highlightthickness=2,highlightbackground="#ffcc00",highlightcolor="#ffcc00")
receiptFrame.place(x=603,y=135)

nameLbl = Label(mainFrame,text="Name : ",font="msserif 16 bold",fg="white",bg="#220D0B").place(x=605,y=102)
nameEntry = Entry(mainFrame,textvar=nameVar,width=15,font="verdana 13 bold",bd=2,relief=RAISED)
nameEntry.place(x=705,y=102)

yscrollbar = Scrollbar(receiptFrame,orient=VERTICAL)
yscrollbar.pack(side=RIGHT,fill=Y)
xscrollbar = Scrollbar(receiptFrame,orient=HORIZONTAL)
xscrollbar.pack(side=BOTTOM,fill=X)

receiptTxt = Listbox(receiptFrame,height=17,width=40,yscrollcommand=yscrollbar.set,\
font="verdana 10 bold",xscrollcommand=xscrollbar.set)
receiptTxt.pack()

yscrollbar.config(command=receiptTxt.yview)
xscrollbar.config(command=receiptTxt.xview)

#**********************************BUTTONS****************************************************************************

totalBtn = Button(mainFrame,text="Total",width=11,font="verdana 16 bold",bg="#bf8040",bd=4,relief=RAISED,\
highlightthickness=3,highlightbackground="#ffcc00",highlightcolor="#ffcc00",command=Total)
totalBtn.place(x=603,y=480)

receiptBtn = Button(mainFrame,text="Receipt",width=10,font="verdana 16 bold",bg="#bf8040",bd=4,relief=RAISED,\
highlightthickness=3,highlightbackground="#ffcc00",highlightcolor="#ffcc00",command=Receipt)
receiptBtn.place(x=805,y=480)

resetBtn = Button(mainFrame,text="Reset",width=11,font="verdana 16 bold",bg="#bf8040",bd=4,relief=RAISED,\
highlightthickness=3,highlightbackground="#ffcc00",highlightcolor="#ffcc00",command=reset)
resetBtn.place(x=603,y=530)

exitBtn = Button(mainFrame,text="Exit",width=10,font="verdana 16 bold",bg="#bf8040",bd=4,relief=RAISED,\
highlightthickness=3,highlightbackground="#ffcc00",highlightcolor="#ffcc00",command=exit)
exitBtn.place(x=805,y=530)

addDataBtn = Button(mainFrame,text="Add",width=11,font="verdana 16 bold",bg="#bf8040",bd=4,relief=RAISED,\
highlightthickness=3,highlightbackground="#ffcc00",highlightcolor="#ffcc00",command=AddData)
addDataBtn.place(x=603,y=580)

displayDataBtn = Button(mainFrame,text="Display",width=10,font="verdana 16 bold",bg="#bf8040",bd=4,relief=RAISED,\
highlightthickness=3,highlightbackground="#ffcc00",highlightcolor="#ffcc00",command=DisplayData)
displayDataBtn.place(x=805,y=580)

#*********************************************************************************************************************

root.mainloop()