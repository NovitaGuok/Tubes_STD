#ifndef KELAS_H_INCLUDED
#define KELAS_H_INCLUDED
#include <stdlib.h>
#include <iostream>
using namespace std;

struct kelas{
    int jmlMhs;
    string kode;
    string namaKelas;
};
typedef kelas infotypeKelas;

typedef struct elmKelas *adrKelas;

struct elmKelas{
    adrKelas next;
    adrKelas prev;
    infotypeKelas info;
};

struct listKelas{
    adrKelas first;
    adrKelas last;
};

adrKelas createElmKelas(string kode, string namaKelas);
void createListKelas(listKelas &L);
bool isEmptyKelas(listKelas L);
void insertFirstKelas(listKelas &L, string kode, string namaKelas);
void insertAfterKelas(listKelas &L, adrKelas Prec, adrKelas P);
void insertLastKelas(listKelas &L, string kode, string namaKelas);
void deleteFirstKelas(listKelas &L, adrKelas &P);
void deleteAfterKelas(listKelas &L, adrKelas Prec, adrKelas &P);
void deleteLastKelas(listKelas &L, adrKelas &P);
adrKelas searchKelas(listKelas L, string kode);
void printKelas(listKelas L);

#endif // KELAS_H_INCLUDED
