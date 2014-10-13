
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "include\fileoperations.h"
#include "include\record.h"

using namespace  std;

void Dosya::ekle(TelKayit* ykptr)
{
	fseek(teldefteri,0,SEEK_END);
	fwrite(ykptr,sizeof(TelKayit),1,teldefteri);
    
}

void Dosya::olustur()
{
	dosyaAdi ="teldefteri.txt";
	teldefteri = fopen(dosyaAdi,"r+");
	if(!teldefteri)
	{
		if(!(teldefteri=fopen(dosyaAdi,"w+")))
        {
            cerr<<"file can not be opened"<<endl;
            exit(1);
        }
        
	}
    
    
}


void Dosya::kapat()
{
	fclose(teldefteri);
}

int  Dosya::ara(const char* tofind)
{
	TelKayit stFoundTel;
	int counter =0;
	bool bAll = false;
	int ifoundNumber =0;
    char strall ='*';
    
	if(strcmp(tofind,&strall) == 0)
	{
		bAll= true;
	}
    
	fseek(teldefteri,0,SEEK_SET);
	while(!feof(teldefteri))
	{
		counter++;
		fread(&stFoundTel,sizeof(TelKayit),1,teldefteri);
		if(feof(teldefteri)) break;
		if(!bAll && strncmp((const char*)&stFoundTel.ad,tofind,sizeof(tofind)) != 0) continue;
        
		cout<<counter<<'.'<<stFoundTel.ad<<""<<stFoundTel.telNo<<endl;
		ifoundNumber++;
        
	}
    
    return ifoundNumber;
}

void Dosya::guncelle(int kayitno,TelKayit* newptr )
{
    
	fseek(teldefteri,(kayitno-1)*sizeof(TelKayit),SEEK_SET);
	fwrite(newptr,sizeof(TelKayit),1,teldefteri);
    
}
void Dosya::bettersil(int kayitno)
{
	Dosya tempDosya;
    
    TelKayit tmpTelK;
    
	char* tmpdosyaAdi ="tmpteldefteri.txt";
	tempDosya.teldefteri = fopen(tmpdosyaAdi,"r+");
    if(!tempDosya.teldefteri)
    {
        if(!(tempDosya.teldefteri=fopen(dosyaAdi,"w+")))
        {
            //cerr<<"file can not be opened"<<endl;
            exit(1);
        }
        
    }
    
    
    int count =0;
	while(!feof(tempDosya.teldefteri))
	{
		fread(&tmpTelK,sizeof(TelKayit),1,teldefteri);
        if (count != kayitno)
        {
            tempDosya.ekle(&tmpTelK);
			//fwrite(&tmpTelK,sizeof(TelKayit),1,tempDosya.teldefteri);
        }
        
	}
    
	free (teldefteri);
	teldefteri = tempDosya.teldefteri;
}

void Dosya::sil(int kayitno)
{
    
    TelKayit emptyRec = {"",""};
    
	fseek(teldefteri,(kayitno-1)*sizeof(TelKayit),SEEK_SET);
	fwrite(&emptyRec,sizeof(TelKayit),1,teldefteri);
    
}
//
//  fileoperations.cpp
//  HW_Faculty_Record
//
//  Created by Pınar on 16/09/14.
//
//

#include "fileoperations.h"
