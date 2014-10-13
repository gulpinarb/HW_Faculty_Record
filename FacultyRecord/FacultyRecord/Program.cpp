//
//  Program.cpp
//  HW_Faculty_Record
//
//  Created by Pınar on 16/09/14.
//
//
#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <ctype.h>

#include "fileoperations.h"

#define AD_UZUNLUK 15
#define DEPT_NAME_LEN 5


using namespace std;

typedef Dosya VeriYapisi;

VeriYapisi recordFile;

void menuYazdir();
bool islemYap(char);
void kayitAraByDept();
void kayitAraByFirstName();
void kayitEkle();
void kayitSil();
void kayitGuncelle();
void kayitYazdir();

int main()
{
    recordFile.olustur();
    bool bitir = false;
    char secim ;
    while (!bitir)
    {
        menuYazdir();
        cin>>secim;
        bitir=islemYap(secim);
        
    }
    
    recordFile.kapat();
    return  EXIT_SUCCESS;
}


void menuYazdir()
{
	system("clear");
	cout<<endl<<endl;
	cout<<"Faculty Record Application"<<endl;
	cout<<"Choose An Option"<<endl;
	cout<<"A:Add a New Record"<<endl;
	cout<<"S:Search Record By Department"<<endl;
	cout<<"F:Search Record By First Name"<<endl;
	cout<<"R:Delete Record"<<endl;
    cout<<"P:Print All Records"<<endl;
	cout<<"U:Update  Record"<<endl;
	cout<<"E:Exit"<<endl;;
	cout<<endl;
	cout<<"Enter Your Option {A, S, F, R, P, U, E}: "<<endl;
    
}
bool islemYap(char secim)
{
	bool bitir = false;
	switch (secim)
	{
        case 'A':
        case 'a':
            kayitEkle();
            break;
        case 'S':
        case 's':
            kayitAraByDept();
            break;
        case 'F':
        case 'f':
            kayitAraByFirstName();
            break;
        case 'U':
        case 'u':
            kayitGuncelle();
            break;
        case 'R':
        case 'r':
            kayitSil();
            break;
        case 'P':
        case 'p':
            kayitYazdir();
            break;
        case 'E':
        case 'e':
            cout<<"Are you sure that you want to terminate the program? (Y/N):";
            cin>> secim;
            if (secim == 'y'|| secim == 'Y')
                bitir = true;
            break;
        default:
            cout<< "You made an invalid choice"<<endl;
            cout <<"Please try again  {A, S, F, R, P, U, E}:  ";
            cin >> secim;
            bitir =islemYap(secim);
            break;
            
	}
    
    return bitir;
    
}
void kayitAraByFirstName()
{
	char ad[AD_UZUNLUK];
	cout<<"Please enter the name of the person you want to search (press '*' for\
    listing all):";
	cin.ignore(1000,'\n');
	cin.getline(ad,AD_UZUNLUK);
	if(recordFile.ara(ad) == 0)
		cout<<"Can not be found"<<endl;
	getchar();
    
}
void kayitAraByDept()
{
	char deptName[DEPT_NAME_LEN];
	cout<<"Please enter the department name of the person you want to search ";
	cin.ignore(1000,'\n');
	cin.getline(deptName,AD_UZUNLUK);
	if(recordFile.ara(deptName) == 0)
		cout<<"Can not be found"<<endl;
	getchar();
    
}
void kayitEkle()
{
	faculty_record stNewRecord;
	cout << "Please enter the information of the person you want to save " << endl;
	cout << "First Name : " ;
	cin.ignore(1000,'\n');
	cin.getline(stNewRecord.fname,AD_UZUNLUK);
    cout << "Last Name : " ;
	cin.ignore(1000,'\n');
	cin.getline(stNewRecord.lname,AD_UZUNLUK);
	cout << "Phone number :";
	cin>>stNewRecord.phone;
    cout << "Office :";
	cin>>stNewRecord.office;
    cout << "Department Name : " ;
	cin.ignore(1000,'\n');
	cin.getline(stNewRecord.dept,DEPT_NAME_LEN);
    
	recordFile.ekle(&stNewRecord);
	cout << "Record has been added" << endl;
	getchar();
    
}
void kayitSil()
{
    char ad[AD_UZUNLUK];
    int secim;
    cout<< "Please enter the name of the person you want to delete (press '*' for\
    listing all):" <<endl;
    cin.ignore(1000,'\n');
    cin.getline(ad,AD_UZUNLUK);
    int kayitsayisi = recordFile.ara(ad);
    
    if (kayitsayisi == 0)
    {
        cout<<"Record can not be found"<<endl;
        
    }
    else
    {
        if(kayitsayisi == 1)
        {
            
            cout << "Record has been found." << endl;
            cout << "Please enter the index of the record if you want to delete \
            this contact (Press -1 to exit without deletion): " ;
            
        }
        else
            cout << "Please enter the index of the record that you want to delete\
            (Press -1 to exit without deletion): " ;
        
        cin >> secim;
        if(secim==-1) return;
        recordFile.sil(secim);
        cout << "Record has been deleted" <<endl;
        
        
        
        
    }
    
    getchar();
    
}
void kayitGuncelle()
{
	char ad[AD_UZUNLUK];
	int secim;
	cout << "Please enter the name of the person you want to update (press '*' for\
	listing all):" << endl;
	cin.ignore(1000, '\n');
	cin.getline(ad,AD_UZUNLUK);
	int kisisayisi=recordFile.ara(ad);
	if(kisisayisi==0){
        cout << "Record can not be found" << endl;
	}
	else {
        if (kisisayisi==1){cout << "Record has been found." << endl;
            cout << "Please enter the index of the record if you want to update\
            this record(Press -1 to exit without updating) " ;
        }
        else
            cout << "Please enter the index of the record that you want to update\
            (Press -1 to exit without updating): " ;
        cin >> secim;
        if(secim==-1) return;
        faculty_record stNewRecord;
        cout << "Please enter the up-to-date information" << endl;
        cout << "First Name : " ;
        cin.ignore(1000,'\n');
        cin.getline(stNewRecord.fname,AD_UZUNLUK);
        cout << "Last Name:" ;
        cin.ignore(1000,'\n');
        cin.getline(stNewRecord.lname,AD_UZUNLUK);
        cout << "Phone number :";
        cin>>stNewRecord.phone;
        cout << "Office :";
        cin>>stNewRecord.office;
        cout << "Department Name : " ;
        cin.ignore(1000,'\n');
        cin.getline(stNewRecord.dept,DEPT_NAME_LEN);
        recordFile.guncelle(secim,&stNewRecord);
        cout << "Record has been updated successfully" <<endl;
	}
	getchar();
};


void kayitYazdir()
{
    recordFile.ara("*");
	getchar();
};






