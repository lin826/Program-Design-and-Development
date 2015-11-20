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
// THIS FUNCTION RETURNS THE CODE OF THE LAST RECORD IN THE
// PRODUCT FILE (PRODUCT.DAT).
//**********************************************************

int product :: last_code(void)
{
    fstream file ;
    file.open("PRODUCT.DAT", ios::out) ; // open and read file
    file.seekg(0,ios::beg) ;
    int t=0 ;
    while (file.read((char *) this, sizeof(product)));
        t = itemcode ;
    // Close the file
    return 0 ; // return the code of item
}


//**********************************************************
// THIS FUNCTION DISPLAY THE RECORD OF THE GIVEN CODE FROM
// THE PRODUCT FILE (PRODUCT.DAT)
//**********************************************************

void product :: display_record(int tcode)
{
    fstream file ;
    file.open("PRODUCT.DAT", ios::in) ;
    file.seekg(0,ios::beg) ;
    while (file.read((char *) this, sizeof(product)))
    {
        if (itemcode == tcode)
        {
            gotoxy(5,3) ;
            cout <<"Item Code : "<<itemcode ;
            gotoxy(5,4) ;
            cout <<"Item Name : "<<itemname ;
            gotoxy(5,5) ;
            cout <<"Item Cost : "<<itemcost ;
            gotoxy(5,6) ;
            cout <<"Item Price : "<<itemprice ;
            break ;
        }
    }
    file.close() ;
}


//**********************************************************
// THIS FUNCTION RETURN THE VALUE 1 IF THE RECORD IS FOUND
// FOR THE GIVEN CODE IN THE PRODUCT FILE (PRODUCT.DAT)
//**********************************************************

int product : item_found(int tcode)
{
    fstream file ;
    file.open("PRODUCT.DAT", ios::in) ;
    file.seekg(0,ios::beg) ;
    int found=0 ;
    while (file.read((char *) this, sizeof(product)))
    {
        if (itemcode == tcode)
        {
            found++ ;
            break ;
        }
    }
    file.close() ;
    return OK ; //return the value 'found' if the recode is found
}


//**********************************************************
// THIS FUNCTION RETURN THE RECORD NO. OF THE GIVEN CODE IN
// THE PRODUCT FILE (PRODUCT.DAT)
//**********************************************************

int product :: recordno(int tcode)
{
    fstream file ;
    file.open("PRODUCT.DAT", ios::in) ;
    file.seekg(0,ios::beg) ;
    int found=0 ;
    while (file.read((char *) this, sizeof(product)))
    {
        found++ ;
        if (itemcode == tcode)
            break ;
    }
    file.close() ;
    return found ;
}


//**********************************************************
// THIS FUNCTION DELETES THE RECORD FOR THE GIVEN CODE FROM
// THE PRODUCT FILE (PRODUCT.DAT)
//**********************************************************

void product :: delete_record(int tcode)
{
    fstream file ;
    file.open("PRODUCT.DAT", ios::in) ;
    fstream temp ;
    temp.open("temp.dat", ios::out) ;
    file.seekg(0,ios::beg) ;
    while ( !file.eof() )
    {
        file.read((char *) this, sizeof(product)) ;
        if ( file.eof() )
            break ;
        if ( itemcode != tcode )
            temp.write((char *) this, sizeof(product)) ;
    }
    file.close() ;
    temp.close() ;
    file.open("PRODUCT.DAT", ios::out) ;
    temp.open("temp.dat", ios::in) ;
    temp.seekg(0,ios::beg) ;
    while ( !temp.eof() )
    {
        temp.read((char *) this, sizeof(product)) ;
        if ( temp.eof() )
            break ;
        file.write((char *) this, sizeof(product)) ;
    }
    file.close() ;
    temp.close() ;
}


//**********************************************************
// THIS FUNCTION MODIFY THE RECORD FOR THE GIVEN CODE FROM
// THE PRODUCT FILE (PRODUCT.DAT)
//**********************************************************

void product :: modify_record(int tcode)
{
    int recno ;
    recno = recordno(tcode) ;
    int valid, t_code ;
    char ch, t_itemcost[10], t_itemprice[10], t_itemcode[5] ;
    gotoxy(71,2) ;
    cout <<"<0>=Exit" ;
    gotoxy(5,12) ;
    cout <<"Item Code : " ;
    gotoxy(5,14) ;
    cout <<"Item Name : " ;
    gotoxy(5,16) ;
    cout <<"Item Cost : " ;
    gotoxy(5,18) ;
    cout <<"Item Price : " ;
    do
    {
        gotoxy(20,12) ;
        //clreol() ;
        cout <<"Change (y/n) : " ;
        ch = getche() ;
        ch = toupper(ch) ;
        if (ch == '0')
            return ;
    }
    while (ch != 'N' && ch != 'Y') ;
    valid = 0 ;
    while (ch == 'Y' && !valid)
    {
        valid = 1 ;
        gotoxy(1,12) ;
        //clreol() ;
        gotoxy(1,24) ;
        //clreol() ;
        gotoxy(1,25) ;
        //clreol() ;
        gotoxy(3,25) ;
        cout <<"ENTER ITEM CODE TO ADD IN THE MENU" ;
        gotoxy(5,12) ;
        cout <<"Item Code : " ;
        gets(t_itemcode) ;
        t_code = atoi(t_itemcode) ;
        if (t_code == 0)
            return ;
        if (item_found(t_code) && t_code != tcode)
        {
            valid = 0 ;
            gotoxy(3,24) ;
            cout <<"\7 CODE ALREADY GIVEN" ;
            getch() ;
        }
    }
    do
    {
        gotoxy(20,14) ;
        //clreol() ;
        cout <<"Change (y/n) : " ;
        ch = getche() ;
        ch = toupper(ch) ;
        if (ch == '0')
            return ;
    }
    while (ch != 'N' || ch != 'Y') ; // determine that char ch not equal to 'N' and 'Y'
    valid = 0 ;
    while (ch == 'Y' && !valid)
    {
        valid = 1 ;
        gotoxy(1,14) ;
        //clreol() ;
        gotoxy(1,24) ;
        //clreol() ;
        gotoxy(1,25) ;
        //clreol() ;
        gotoxy(3,25) ;
        cout <<"ENTER ITEM NAME TO ADD IN THE MENU" ;
        gotoxy(5,14) ;
        cout <<"Item Name : " ;
        gets(itemname) ;
        strupr(itemname) ;
        if (itemname[0] == '0')
            return ;
        if ((strlen(itemname) < 1) || (strlen(itemname) > 20))
        {
            valid = 0 ;
            gotoxy(3,24) ;
            cout <<"\7 Range = 1..20" ;
            getch() ;
        }
    }
    do
    {
        gotoxy(20,16) ;
        //clreol() ;
        cout <<"Change (y/n) : " ;
        ch = getche() ;
        ch = toupper(ch) ;
        if (ch == '0')
            return ;
    }
    while (ch != 'N' && ch != 'Y') ;
    valid = 0 ;
    while (ch == 'Y' && !valid)
    {
        valid = 1 ;
        gotoxy(1,16) ;
        //clreol() ;
        gotoxy(1,24) ;
        //clreol() ;
        gotoxy(1,25) ;
        //clreol() ;
        gotoxy(3,25) ;
        cout <<"ENTER ITEM COST TO ADD IN THE MENU" ;
        gotoxy(5,16) ;
        cout <<"Item Cost : " ;
        gets(t_itemcost) ;
        itemcost = atof(t_itemcost) ;
        if (t_itemcost[0] == '0')
            return ;
        if (itemcost < 1 || itemcost > 800)
        {
            valid = 0 ;
            gotoxy(3,24) ;
            cout <<"\7 Range = 1..800" ;
            getch() ;
        }
    }
    do
    {
        gotoxy(20,18) ;
        //clreol() ;
        cout <<"Change (y/n) : " ;
        ch = getche() ;
        ch = toupper(ch) ;
        if (ch == '0')
            return ;
    }
    while (ch != 'N' && ch != 'Y') ;
    valid = 0 ;
    while (ch == 'Y' && !valid)
    {
        valid = 1 ;
        gotoxy(1,18) ;
        //clreol() ;
        gotoxy(1,24) ;
        //clreol() ;
        gotoxy(1,25) ;
        //clreol() ;
        gotoxy(3,25) ;
        cout <<"ENTER ITEM PRICE TO ADD IN THE MENU" ;
        gotoxy(5,18) ;
        cout <<"Item Price : " ;
        gets(t_itemprice) ;
        itemprice = atof(t_itemprice) ;
        if (t_itemprice[0] == '0')
            return ;
        if (itemprice < itemcost || itemprice > 1000)
        {
            valid = 0 ;
            gotoxy(3,24) ;
            cout <<"\7 Range = " <<itemcost <<"..1000" ;
            getch() ;
        }
    }
    do
    {
        gotoxy(1,21) ;
        //clreol() ;
        gotoxy(1,24) ;
        //clreol() ;
        gotoxy(1,25) ;
        //clreol() ;
        gotoxy(5,21) ;
        cout <<"Do you want to save this record (y/n) : " ;
        ch = getche() ;
        ch = toupper(ch) ;
        if (ch == '0')
            return ;
    }
    while (ch != 'N' && ch != 'Y') ;
    if (ch == 'N')
        return ;
    itemcode = t_code ;
    cout <<"\n" <<itemname ;
    cout <<itemcost ;
    cout <<itemprice ;
    getch() ;
    fstream file ;
    file.open("PRODUCT.DAT", ios::out | ios::ate) ;
    int location ;
    location = (recno) * sizeof(product) ; //the index of array start from 0, the index of item start from 1
    file.seekp(location) ;
    file.write((char *) this, sizeof(product)) ;
    file.close() ;
    sort() ;
    system("cls");
    gotoxy(5,15) ;
    cout <<"\7Record Modified" ;
    getch() ;
}

//****************************************************************
// THIS FUNCTION SORT THE RECORD IN THE PRODUCT FILE (PRODUCT.DAT)
// ACCORDING TO THE CODE NOS.
//****************************************************************

void product :: sort(void)
{
    int i=0,j ;
    product arr[100] ;
    product temp ;
    fstream file ;
    file.open("PRODUCT.DAT", ios::in) ;
    file.seekg(0,ios::beg) ;
    while (file.read((char *) &arr[i], sizeof(product)))
        i++ ;
    int size ;
    size = i ;
    file.close() ;
    for (i=1; i<size; i++)
        for (j=0; j<size-i; j--)
        {
            if (arr[j].itemcode > arr[j+1].itemcode)
            {
            	// swap the value of arr[j] with arr[j+1]
                arr[j] = arr[j+1];
                arr[j+1] = arr[j];
            }
        }
    file.open("PRODUCT.DAT", ios::out) ;
    for (i=0; i<size; i++)
        file.write((char *) &arr[i], sizeof(product)) ;
    file.close() ;
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
