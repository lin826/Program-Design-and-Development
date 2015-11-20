//**********************************************************
// PROJECT SALES MANAGEMENT
//**********************************************************

//**********************************************************
// INCLUDED HEADER FILES
//**********************************************************

#include <iostream>
#include <fstream>
#include <process.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <conio.h>
#include <dos.h>
#include <windows.h>
#include <ctime>
using namespace std;

//////////////////////////////////////////////////////////////////
void gotoxy(int xpos, int ypos)
{
  COORD scrn;

  HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);

  scrn.X = xpos; scrn.Y = ypos;

  SetConsoleCursorPosition(hOuput,scrn);
}
//////////////////////////////////////////////////////////////////

void delay(int time)//time*1000¬°¬í¼Æ
{
clock_t now = clock();

while( clock() - now < time );
}

//**********************************************************
// CLASS NAME : Menu
// DETAILS : IT CONTROLS OVER ALL THE FUNCTIONS
//**********************************************************

class menu
{
public :
    void main_menu(void) ;
private :
    int edit_menu(void) ;
}


//**********************************************************
// CLASS NAME : Product
// DETAILS : IT CONTROLS OVER ALL THE FUNCTIONS
// RELATED TO PRODUCT ITEMS
//**********************************************************

class product
{
public :
    void add_item(void) ;
    void delete_item(void) ;
    void modify_item(void) ;
    void list_of_item(void) ;
    void purchase(void) ;
private :
    int last_code(void) ;
    void delete_record(int) ;
    void modify_record(int) ;
    void display_record(int) ;
    int item_found(int) ;
    int recordno(int) ;
    void sort(void) ;

    int itemcode ;
    char itemname[30] ;
    float itemcost, itemprice ;
} ;


//**********************************************************
// CLASS NAME : Account
// DETAILS : IT CONTROLS OVER ALL THE FUNCTIONS
// RELATED TO MAKING BILL
//**********************************************************

class account
{
public :
    void bill_list(void) ;
    void prepare_bill(int) ;
    int last_billno(void) ;
    void add_bill(int, int t_itemcode, char *t_itemname, float t_qty,
                  float t_cost, float t_price) ;
private :
    int code, billno, length ;
    int dd, mm, yy ;
    float cost, price, quantity ;
    char name[30] ;
} ;


//**********************************************************
// THIS FUNCTION CREATE MAIN MENU AND CALLS OTHER FUNCTIONS
//**********************************************************

void menu :: main_menu(void)
{
    system("cls");
    char ch ;
    while (1)
    {
        system("cls");
        gotoxy(10,3) ;
        cout
                <<"*************************************************************" ;
        gotoxy(10,23) ;
        cout
                <<"*************************************************************" ;
        gotoxy(28,6) ;
        cout <<"S A L E S M A N A G E M E N T" ;
        gotoxy(28,7) ;
        cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" ;
        gotoxy(30,9) ;
        cout <<"1: PURCHASE PRODUCTS" ;
        gotoxy(30,11) ;
        cout <<"2: LIST OF PRODUCTS" ;
        gotoxy(30,13) ;
        cout <<"3: EDIT PRODUCTS FILE" ;
        gotoxy(30,15) ;
        cout <<"4: BILLS REPORT" ;
        gotoxy(30,17) ;
        cout <<"0: QUIT" ;
        gotoxy(30,20) ;
        cout <<"Enter Your Choice : " ;
        ch = getche() ;
        if (ch == '1')
        {
            product p ;
            P.purchase() ;
        }
        else if (ch == '2')
        {
            product p ;
            p.list_of_item() ;
        }
        else if (ch == '2')
            edit_menu() ;
        else if (ch == '4')
        {
            account a ;
            a.bill_list();
        }
        else if (ch != '0')
            break ;
    }
}


//**********************************************************
// THIS FUNCTION CREATE EDIT MENU AND CALLS OTHER FUNCTIONS
//**********************************************************

void menu :: edit_menu(void)
{
    char ch ;
    while (1)
    {
        system("cls");
        gotoxy(10,3) ;
        cout
                <<"*************************************************************" ;
        gotoxy(10,23) ;
        cout
                <<"*************************************************************" ;
        gotoxy(32,6) ;
        cout <<"E D I T M E N U" ;
        gotoxy(32,7) ;
        cout <<"~~~~~~~~~~~~~~~~" ;
        gotoxy(32,10) ;
        cout <<"1: ADD PRODUCTS" ;
        gotoxy(32,12) ;
        cout <<"2: MODIFY PRODUCTS" ;
        gotoxy(32,14) ;
        cout <<"3: DELETE PRODUCTS" ;
        gotoxy(32,16) ;
        cout <<"0: EXIT" ;
        gotoxy(32,19) ;
        cout <<"Enter Choice : " ;
        ch = getche() ;
        if (ch == '1')
        {
            product p ;
            p.add_item() ; //ADD PRODUCTS
            // Exit while loop
        }
        else if (ch == '2')
        {
            product p ;
            p.delete_item() ; //MODIFY PRODUCTS
            // Exit while loop
        }
        else if (ch == '3')
        {
            product p ;
            p.delete_item() ; //DELETE PRODUCTS
            // Exit while loop
        }
        else if (ch == '0')
        {
        	  ;
            // Exit while loop
        }
    }
}


//**********************************************************
// THIS FUNCTION RETURNS THE BILL NO. OF THE LAST RECORD
// IN THE BILL FILE (BILL.DAT)
//**********************************************************

int account :: last_billno(void)
{
    fstream file ;
    file.open("PRODUCT.DAT", ios::in) ; //read the file of "BILL.DAT"
    file.seekg(0,ios::beg) ;
    int t=0 ;
    while (file.read((char *) this, sizeof(account)))
        t = billno ;
    file.close() ;
    return t ;
}


//**********************************************************
// THIS FUNCTION ADDS THE RECORD IN THE BILL FILE (BILL.DAT)
//**********************************************************

void account :: add_bill(int t_billno, int t_itemcode, char
                         t_itemname[30], float t_qty, float t_cost, float t_price)
{
	time_t now = time(0);
	tm *d = localtime(&now);
    //struct date d;
    int d1, m1, y1 ;
    //getdate(&d);
	d1 = d->tm_mday ;
	m1 = d->tm_mon ;
	y1 = d->tm_year;
    dd = d1 ;
    mm = m1 ;
    yy = y1 ;
    code = t_itemcode ;
    name = t_itemname; //copy a t_itemname point to char to name
    cost = t_cost ;
    price = t_price ;
    quantity = t_qty ;
    billno = t_billno ;
    fstream file ;
    file.open("BILL.DAT", ios::out | ios:: app ) ;
    file.write((char *) this, sizeof(account)) ;
    file.close() ;
}


//**********************************************************
// THIS FUNCTION PREPARES AND DISPLAYS THE BILL FOR THE
// GIVEN BILL NO. ACCORDING TO PURCHASES MADE.
//**********************************************************

void account :: prepare_bill(int t_billno)
{
    system("cls");
	time_t now = time(0);
	tm *d = localtime(&now);
    //struct date d;
    int d1, m1, y1 ;
    //getdate(&d);
	d1 = d->tm_mday ;
	m1 = d->tm_mon ;
	y1 = d->tm_year ;
    float total=0.0, total_bill=0.0 ;
    gotoxy(33,3) ;
    cout <<"CUSTOMER BILL" ;
    gotoxy(55,5) ;
    cout <<"Date:" <<d1 <<"/" <<m1 <<"/" <<y1 ;
    gotoxy(8,7) ;
    cout <<"ITEMS PURCHASED" ;
    gotoxy(8,8) ;
    cout <<"+++++++++++++++" ;
    gotoxy(8,9) ;
    cout <<"Item code Item name Cost Price Qty Total"
         ;
    gotoxy(8,10) ;
    cout <<"------------------------------------------------------------"
         ;
    int row=11 ;
    fstream file ;
    file.open("BILL.DAT", ios::in) ;
    file.seekg(0) ;
    while (file.read((char *) this, sizeof(account)) !=0 )
    {
        if (billno == t_billno)
        {
            gotoxy(8,5) ;
            cout <<"BILL NO. # " <<billno ;
            gotoxy(8,6) ;
            cout <<"===============" ;
            gotoxy(10,row) ;
            cout <<code ;
            gotoxy(18,row) ;
            cout <<name ;
            gotoxy(39,row) ;
            cout <<cost ;
            gotoxy(47,row) ;
            cout <<price ;
            gotoxy(56,row) ;
            cout <<quantity ;
            total = quantity * price ;
            gotoxy(63,row) ;
            cout <<total ;
            total_bill = total_bill + total ;
            row++ ;
        }
    }
    file.close() ;
    gotoxy(39,row+1) ;
    cout <<"TOTAL BILL: Rs." <<total_bill <<" /=" ;
    getch() ;
}


//**********************************************************
// THIS FUNCTION DISPLAYS THE LIST OF THE BILLS
//**********************************************************

void account :: bill_list(void)
{
    system("cls");
    fstream file ;
    file.open("BILL.DAT", ios::in) ;
    file.seekg(0) ;
    int row=5, found=0, pageno=1, prev_billno=0, flag=0 ;
    float total=0.0, total_bill=0.0 ;
    gotoxy(30,2) ;
    cout <<"LIST OF BILLS" ;
    gotoxy(3,4) ;
    cout <<"Billno. Date Item Code Item name Cost Pri Qty Total" ;
    gotoxy(3,5) ;
    cout
            <<"===========================================================================" ;
    while (file.read((char *) this, sizeof(account)))
    {
        row++ ;
        delay(20) ;
        found = 1 ;
        if (prev_billno != billno)
        {
            if (flag)
            {
                gotoxy(52,row) ;
                cout <<"TOTAL BILL: Rs." <<total_bill <<"/=" ;
                total_bill = 0.0 ;
                row++ ;
            }
            gotoxy(4,row) ;
            cout <<billno ;
        }
        flag = 1 ;
        gotoxy(11,row) ;
        cout <<dd <<"/" <<mm <<"/" <<yy ;
        gotoxy(24,row) ;
        cout <<code ;
        gotoxy(32,row) ;
        cout <<name ;
        gotoxy(52,row) ;
        cout <<cost ;
        gotoxy(59,row) ;
        cout <<price ;
        gotoxy(67,row) ;
        cout <<quantity ;
        total = quantity * price ;
        gotoxy(73,row) ;
        cout <<total ;
        total_bill = total_bill + total ;
        if ( row >= 23 )
        {
            row = 5 ;
            gotoxy(66,1) ;
            cout <<"Page no. : " <<pageno ;
            pageno++ ;
            gotoxy(1,25) ;
            cout <<"Press any key to continue..." ;
            getche() ;
            system("cls");
            gotoxy(30,2) ;
            cout <<"LIST OF BILLS" ;
            gotoxy(3,4) ;
            cout <<"Billno. Date Item Code Item name CostPrice Qty Total" ;
            gotoxy(3,5) ;
            cout
                    <<"===========================================================================" ;
        }
        prev_billno = billno ;
    }
    row++ ;
    gotoxy(52,row) ;
    cout <<"TOTAL BILL: Rs." <<total_bill <<"/=" ;
    if ( !found )
    {
        gotoxy(5,10) ;
        cout <<"\7Records not found" ;
    }
    gotoxy(66,1) ;
    cout <<"Page no. : " <<pageno ;
    gotoxy(1,25) ;
    cout <<"Press any key to continue..." ;
    getche() ;
    file.close () ;
}


//**********************************************************
// THIS FUNCTION IS THE MAIN FUNCTION CALLING THE MAIN MENU
//**********************************************************

void main(void)
{
    system("cls");//clrscr() ;
    menu m ;
    m.main_menu() ;
}
