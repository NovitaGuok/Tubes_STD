#ifndef MAHASISWA_H_INCLUDED
#define MAHASISWA_H_INCLUDED
#include <stdlib.h>
#include <iostream>
using namespace std;

struct mahasiswa{
    string nim;
    string namaMhs;
};
typedef mahasiswa infotypeMhs;

typedef struct elmMhs *adrMhs;

struct elmMhs{
    adrMhs next;
    adrMhs prev;
    infotypeMhs info;
};

struct listMhs{
    adrMhs first;
    adrMhs last;
};

adrMhs createElmMhs(string nim, string nama);
void createListMhs(listMhs &L);
bool isEmptyMhs(listMhs L);
void insertFirstMhs(listMhs &L, string nim, string nama);
void insertAfterMhs(listMhs &L, adrMhs Prec, adrMhs P);
void insertLastMhs(listMhs &L, string nim, string nama);
void deleteFirstMhs(listMhs &L, adrMhs &P);
void deleteAfterMhs(listMhs &L, adrMhs Prec, adrMhs &P);
void deleteLastMhs(listMhs &L, adrMhs &P);
adrMhs searchMhs(listMhs L, string nim);
void printMhs(listMhs L);

#endif // MAHASISWA_H_INCLUDED
