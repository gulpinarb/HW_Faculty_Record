
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "fileoperations.h"
#include "record.h"

using  namespace std;

void Dosya:: ekle(faculty_record* ykptr)
{
	fseek(pFile,0,SEEK_END);
	fwrite(ykptr,sizeof(faculty_record),1,pFile);
    
}

void Dosya::olustur()
{
	dosyaAdi ="FacultyRecords.txt";
	pFile = fopen(dosyaAdi,"r+");
	if(!pFile)
	{
		if(!(pFile=fopen(dosyaAdi,"w+")))
        {
            cerr<<"file can not be opened"<<endl;
            exit(1);
        }
        
	}
    
    
}


void Dosya::kapat()
{
	fclose(pFile);
}

int  Dosya:: ara(const char* tofind)
{
	faculty_record stRecordToFind;
	int counter =0;
	bool bAll = false;
	int ifoundNumber =0;
    char strall ='*';
    
	if(strcmp(tofind,&strall) == 0)
	{
		bAll= true;
	}
    
	fseek(pFile,0,SEEK_SET);
	while(!feof(pFile))
	{
		counter++;
		fread(&stRecordToFind,sizeof(faculty_record),1,pFile);
		if(feof(pFile)) break;
		if(!bAll && strncmp((const char*)&stRecordToFind.fname,tofind,sizeof(tofind)) != 0) continue;
        cout<<"------------------------"<<endl;
		cout<<counter<<".Record Information"<<endl;
        cout<<"First Name:"<<stRecordToFind.fname<<endl;
        cout<<"Last Name"<<stRecordToFind.lname<<endl;
        cout<<"Phone:"<<stRecordToFind.phone<<endl;
        cout<<"Office: "<<stRecordToFind.office<<endl;
        cout<<"Department Name:"<<stRecordToFind.dept<<endl;
        cout<<"------------------------"<<endl;
		ifoundNumber++;
    }
    
    return ifoundNumber;
}

void Dosya::guncelle(int kayitno,faculty_record* newptr )
{
    
	fseek(pFile,(kayitno-1)*sizeof(faculty_record),SEEK_SET);
	fwrite(newptr,sizeof(faculty_record),1,pFile);
    
}
#if 0
void Dosya::bettersil(int kayitno)
{
	Dosya tempDosya;
    
    faculty_record tmpTelK;
    
	char* tmpdosyaAdi ="tmppFile.txt";
	tempDosya.pFile = fopen(tmpdosyaAdi,"r+");
    if(!tempDosya.pFile)
    {
        if(!(tempDosya.pFile=fopen(dosyaAdi,"w+")))
        {
            //cerr<<"file can not be opened"<<endl;
            exit(1);
        }
        
    }
    
    
    int count =0;
	while(!feof(tempDosya.pFile))
	{
		fread(&tmpTelK,sizeof(faculty_record),1,pFile);
        if (count != kayitno)
        {
            tempDosya.ekle(&tmpTelK);
			//fwrite(&tmpTelK,sizeof(faculty_record),1,tempDosya.pFile);
        }
        
	}
    
	free (pFile);
	pFile = tempDosya.pFile;
}
#endif

void Dosya::sil(int kayitno)
{
    
    faculty_record emptyRec = {"",""};
    
	fseek(pFile,(kayitno-1)*sizeof(faculty_record),SEEK_SET);
	fwrite(&emptyRec,sizeof(faculty_record),1,pFile);
    
}

void Dosya::Erase(int kayitno)
{
    
    faculty_record sttmpRecord;
    int counter =0;
    
	FILE* ptmpFile = fopen("tmpFacultyRecords.txt","r+");
	if(!pFile)
	{
		if(!(pFile=fopen("tmpFacultyRecords.txt","w+")))
        {
            exit(1);
        }
        
	}
    fseek(pFile,0,SEEK_SET);
    fseek(ptmpFile,0,SEEK_SET);
   	while(!feof(pFile))
	{
		fread(&sttmpRecord,sizeof(faculty_record),1,pFile);
		if(feof(pFile)) break;

        if (kayitno != counter)
        {
            fwrite(&sttmpRecord,sizeof(faculty_record),1,ptmpFile);
            ++counter;
        }
    }
    fseek(pFile,0,SEEK_SET);
    fseek(ptmpFile,0,SEEK_SET);
    
    while(!feof(pFile))
	{
		fread(&sttmpRecord,sizeof(faculty_record),1,ptmpFile);
		if(feof(pFile)) break;
        fwrite(&sttmpRecord,sizeof(faculty_record),1,pFile);

    }
    remove("tmpFacultyRecords.txt");
 
    
}


