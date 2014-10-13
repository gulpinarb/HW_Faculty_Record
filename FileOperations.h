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
    char *dosyaadi;
    FILE *teldefteri;
    void olustur();
    void kapat();
    void ekle(Tel_Kayit *);
    int ara(char []);
    void sil(int kayitno);
    void guncelle(int kayitno, Tel_Kayit *);
#endif


