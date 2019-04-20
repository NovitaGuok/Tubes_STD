#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED
#include "mahasiswa.h"
#include "kelas.h"
#include <iostream>
#include <cstdlib>
using namespace std;

struct relasi{
    string ketLulus;
};

typedef relasi infotypeRelasi;

typedef struct elmRelasi *adrRelasi;

struct elmRelasi{
    infotypeRelasi info;
    adrRelasi next;
    adrRelasi prev;
    adrMhs mhs;
    adrKelas kelas;
};

struct listRelasi{
    adrRelasi first;
    adrRelasi last;
};

#include "relasi.h"
#include <cstdlib>
#include <iostream>
using namespace std;

adrRelasi createElmRelasi(adrMhs M, adrKelas K, infotypeRelasi ketLulus);
void createListRelasi(listRelasi &L);
bool isEmptyRelasi(listRelasi L);
void insertFirstRelasi(listRelasi &L, adrRelasi P);
void insertAfterRelasi(listRelasi &L, adrRelasi Prec, adrRelasi P);
void insertLastRelasi(listRelasi &L, adrRelasi P, adrKelas &K);
void deleteFirstRelasi(listRelasi &L, adrRelasi &P, adrKelas &K);
void deleteAfterRelasi(listRelasi &L, adrRelasi Prec, adrRelasi &P, adrKelas &K);
void deleteLastRelasi(listRelasi &L, adrRelasi &P, adrKelas &K);
void printKelasMhs(listRelasi LRelasi, listMhs LMhs, listKelas LKelas);
void printKelulusanMhs(listRelasi LRelasi, adrMhs M);
void modus(listRelasi LRelasi, listMhs LMhs, listKelas LKelas);
void tidakLulus(listRelasi LRelasi, adrKelas K);
void printMhsKelas(listRelasi LRelasi, adrMhs M);

#endif // RELASI_H_INCLUDED
