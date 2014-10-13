//
//  FileOperations.h
//  HW_Faculty_Record
//
//  Created by Pınar on 16/09/14.
//
//

#ifndef HW_Faculty_Record_FileOperations_h
#define HW_Faculty_Record_FileOperations_h


#include <stdio.h>
#include "record.h"

struct Dosya{
    char *dosyaAdi;
    FILE *pFile;
    void olustur();
    void kapat();
    void ekle(faculty_record *);
    int ara(const char* ptr);
    void sil(int kayitno);
    void Erase(int kayitno);
    void guncelle(int kayitno, faculty_record *);
  
};
#endif


