#include "kelas.h"

adrKelas createElmKelas(string kode, string namaKelas){
    adrKelas P = new elmKelas;
    P->info.kode = kode;
    P->info.namaKelas = namaKelas;
    P->info.jmlMhs = 0;
    P->next = NULL;
    P->prev = NULL;
    return P;
}

void createListKelas(listKelas &L){
    L.first = NULL;
    L.last = NULL;
}

bool isEmptyKelas(listKelas L){
    return L.first==NULL && L.last==NULL;
}

void insertFirstKelas(listKelas &L, string kode, string namaKelas){
    adrKelas P = createElmKelas(kode, namaKelas);
    if(isEmptyKelas(L)){
        L.first = P;
        L.last = P;
    } else {
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
    }
}

void insertAfterKelas(listKelas &L, adrKelas Prec, adrKelas P){
    P->next = Prec->next;
    P->next->prev = P;
    Prec->next = P;
    P->prev = P;
}

void insertLastKelas(listKelas &L, string kode, string namaKelas){
    adrKelas P = createElmKelas(kode, namaKelas);
    if(isEmptyKelas(L)){
        L.first = P;
        L.last = P;
    } else {
        L.last->next = P;
        P->prev = L.last;
        L.last = P;
    }
}

void deleteFirstKelas(listKelas &L, adrKelas &P){
    if(L.first==NULL){
        cout << "Data kelas kosong" << endl;
    } else if(L.first==L.last){
        P = L.first;
        L.first = NULL;
        L.last = NULL;
    } else {
        P = L.first;
        L.first = P->next;
        L.first->prev = NULL;
        P->next = NULL;
    }
}

void deleteAfterKelas(listKelas &L, adrKelas Prec, adrKelas &P){
    if(L.first==NULL){
        cout << "Data mata kuliah kosong" << endl;
    } else if(L.first==L.last){
        P = L.first;
        L.first = NULL;
        L.last = NULL;
    } else {
        Prec->next = P->next;
        P->next->prev = Prec;
        P->next = NULL;
        P->prev = NULL;
    }
}

void deleteLastKelas(listKelas &L, adrKelas &P){
    if(L.first==NULL){
        cout << "Data kelas kosong" << endl;
    } else if(L.first==L.last){
        P = L.first;
        L.first = NULL;
        L.last = NULL;
    } else {
        P = L.last;
        adrKelas Q = L.last->prev;
        Q->next = NULL;
        P->prev = NULL;
        L.last = Q;
    }
}

adrKelas searchKelas(listKelas L, string kode){
    adrKelas P = L.first;
    while(P!=NULL && P->info.kode!=kode){
        P = P->next;
    }
    return P;
}

void printKelas(listKelas L){
    adrKelas P = L.first;
    int i = 1;
    while(P!=NULL){
        cout << i << ". Kode\t: " << P->info.kode << endl;
        cout << "   Nama mata kuliah\t: " << P->info.namaKelas << endl;
        cout << "   Jumlah mahasiswa\t: " << P->info.jmlMhs << endl;
        P = P->next;
    }
}
