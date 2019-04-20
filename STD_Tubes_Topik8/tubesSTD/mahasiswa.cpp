#include "mahasiswa.h"

adrMhs createElmMhs(string nim, string nama){
    adrMhs P = new elmMhs;
    P->info.nim = nim;
    P->info.namaMhs = nama;
    P->next = NULL;
    P->prev = NULL;
    return P;
}

void createListMhs(listMhs &L){
    L.first = NULL;
    L.last = NULL;
}

bool isEmptyMhs(listMhs L){
    return L.first==NULL && L.last==NULL;
}

//void insertFirstMhs(listMhs &L, string nim, string nama){
//    adrMhs P = createElmMhs(nim, nama);
//    if(isEmptyMhs(L)){
//        L.first = P;
//        L.last = P;
//    } else {
//        P->next = L.first;
//        L.first->prev = P;
//        L.first = P;
//    }
//}
//
//void insertAfterMhs(listMhs &L, adrMhs Prec, adrMhs P){
//    P->next = Prec->next;
//    P->next->prev = P;
//    Prec->next = P;
//    P->prev = P;
//}

void insertLastMhs(listMhs &L, string nim, string nama){
    adrMhs P = createElmMhs(nim, nama);
    if(isEmptyMhs(L)){
        L.first = P;
        L.last = P;
    } else {
        L.last->next = P;
        P->prev = L.last;
        L.last = P;
    }
}

void deleteFirstMhs(listMhs &L, adrMhs &P){
    if(L.first==NULL){
        cout << "Data mahasiswa kosong" << endl;
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

void deleteAfterMhs(listMhs &L, adrMhs Prec, adrMhs &P){
    if(L.first==NULL){
        cout << "Data mahasiswa kosong" << endl;
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

void deleteLastMhs(listMhs &L, adrMhs &P){
    if(L.first==NULL){
        cout << "Data mahasiswa kosong" << endl;
    } else if(L.first==L.last){
        P = L.first;
        L.first = NULL;
        L.last = NULL;
    } else {
        P = L.last;
        adrMhs Q = L.last->prev;
        Q->next = NULL;
        P->prev = NULL;
        L.last = Q;
    }
}

adrMhs searchMhs(listMhs L, string nim){
    adrMhs P = L.first;
    while(P!=NULL && P->info.nim!=nim){
        P = P->next;
    }
    return P;
}

void printMhs(listMhs L){
    adrMhs P = L.first;
    int i = 1;
    while(P!=NULL){
        cout << i << ". NIM\t: " << P->info.nim << endl;
        cout << "   Nama\t: " << P->info.namaMhs << endl;
        P = P->next;
        i++;
    }
}


