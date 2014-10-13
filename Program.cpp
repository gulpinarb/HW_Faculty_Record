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

#include <fileoperations.h>

using namespace std;

typedef Dosya VeriYapisi;

VeriYapisi Defter;

void menuYazdir();
bool islemYap(char);
void kayitAra();
void kayitEkle();
void kayitSil();
void kayitGuncelle();

int main()
{
    Defter.olustur();
    bool bitir = false;
    char secim ;
    while (!bitir)
    {
        menuYazdir();
        cin>>secim;
        bitir=islemYap(secim);
        
    }
    
    Defter.kapat();
    return  EXIT_SUCCESS;
}


void menuYazdir()
{
	system("clear");
	cout<<endl<<endl;
	cout<<"Phone Book Application"<<endl;
	cout<<"Choose An Option"<<endl;
	cout<<"A:Search Record"<<endl;
	cout<<"E:Add Record"<<endl;
	cout<<"G:Update  Record"<<endl;
	cout<<"S:Delete Record"<<endl;
	cout<<"C:Exit"<<endl;;
	cout<<endl;
	cout<<"Enter Your Option {A, E, G, S, C}: "<<endl;
    
}
bool islemYap(char secim)
{
	bool bitir = false;
	switch (secim)
	{
        case 'A':
        case 'a':
            kayitAra();
            break;
        case 'E':
        case 'e':
            kayitEkle();
            break;
        case 'G':
        case 'g':
            kayitGuncelle();
            break;
        case 'S':
        case 's':
            kayitSil();
            break;
        case 'C':
        case 'c':
            cout<<"Are you sure that you want to terminate the program? (E/H):";
            cin>> secim;
            if (secim == 'e'|| secim == 'E')
                bitir = true;
            break;
        default:
            cout<< "You made an invalid choice"<<endl;
            cout <<"Please try again  {A, E, G, S, C}:  ";
            cin >> secim;
            bitir =islemYap(secim);
            break;
            
	}
    
    return bitir;
    
}
void kayitAra()
{
	char ad[AD_UZUNLUK];
	cout<<"Please enter the name of the person you want to search (press '*' for\
    listing all):";
	cin.ignore(1000,'\n');
	cin.getline(ad,AD_UZUNLUK);
	if(Defter.ara(ad) == 0)
		cout<<"Can not be found"<<endl;
	getchar();
    
}
void kayitEkle()
{
	TelKayit stYeniKayit;
	cout << "Please enter the information of the person you want to save " << endl;
	cout << "Name : " ;
	cin.ignore(1000,'\n');
	cin.getline(stYeniKayit.ad,AD_UZUNLUK);
	cout << "Phone number :";
	cin>>setw(TELNO_UZUNLUK)>>stYeniKayit.telNo;
	Defter.ekle(&stYeniKayit);
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
    int kayitsayisi = Defter.ara(ad);
    
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
        Defter.bettersil(secim);
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
	int kisisayisi=Defter.ara(ad);
	if(kisisayisi==0){
        cout << "Record can not be found" << endl;
	}
	else {
        if (kisisayisi==1){cout << "Record has been found." << endl;
            cout << "Please enter the index of the record if you want to update\
            this contact (Press -1 to exit without updating) " ;
        }
        else
            cout << "Please enter the index of the record that you want to update\
            (Press -1 to exit without updating): " ;
        cin >> secim;
        if(secim==-1) return;
        TelKayit yenikayit;
        cout << "Please enter the up-to-date information" << endl;
        cout << "Name : " ;
        cin.ignore(1000, '\n');
        cin.getline(yenikayit.ad,AD_UZUNLUK);
        cout << "Phone number :";
        cin >> setw(TELNO_UZUNLUK) >> yenikayit.telNo;
        Defter.guncelle(secim,&yenikayit);
        cout << "Record has been updated successfully" <<endl;
	}
	getchar();
};






