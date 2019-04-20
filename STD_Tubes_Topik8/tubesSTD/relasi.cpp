#include "relasi.h"

adrRelasi createElmRelasi(adrMhs M, adrKelas K, infotypeRelasi ketLulus){
    adrRelasi Q = new elmRelasi;
    Q->mhs = M;
    Q->kelas = K;
    Q->info = ketLulus;
    Q->next = NULL;
    Q->prev = NULL;
    return Q;
}

void createListRelasi(listRelasi &L){
    L.first = NULL;
    L.last = NULL;
}

bool isEmptyRelasi(listRelasi L){
    return L.first==NULL && L.last==NULL;
}

void insertFirstRelasi(listRelasi &L, adrRelasi P){
    if(isEmptyRelasi(L)){
        L.first = P;
        L.last = P;
    } else {
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
    }
}

void insertAfterRelasi(listRelasi &L, adrRelasi Prec, adrRelasi P){
    P->next = Prec->next;
    P->next->prev = P;
    Prec->next = P;
    P->prev = P;
}

void insertLastRelasi(listRelasi &L, adrRelasi P, adrKelas &K){
//    adrRelasi P = createElmRelasi(M, K, x);
    if(isEmptyRelasi(L)){
        L.first = P;
        L.last = P;
        P->kelas->info.jmlMhs++;
    } else {
        L.last->next = P;
        P->prev = L.last;
        L.last = P;
        P->kelas->info.jmlMhs++;
    }
}

void deleteFirstRelasi(listRelasi &L, adrRelasi &P, adrKelas &K){
    if(L.first==NULL){
        cout << "Mahasiswa tidak mengambil mata kuliah tersebut" << endl;
    } else if(L.first==L.last){
        P = L.first;
        L.first = NULL;
        L.last = NULL;
        P->kelas->info.jmlMhs--;
    } else {
        P = L.first;
        L.first = P->next;
        L.first->prev = NULL;
        P->next = NULL;
        P->kelas->info.jmlMhs--;
    }
}

void deleteAfterRelasi(listRelasi &L, adrRelasi Prec, adrRelasi &P, adrKelas &K){
    if(L.first==NULL){
        cout << "???" << endl;
    } else if(L.first==L.last){
        P = L.first;
        L.first = NULL;
        L.last = NULL;
        P->kelas->info.jmlMhs--;
    } else {
        Prec->next = P->next;
        P->next->prev = Prec;
        P->next = NULL;
        P->prev = NULL;
        P->kelas->info.jmlMhs--;
    }
}

void deleteLastRelasi(listRelasi &L, adrRelasi &P, adrKelas &K){
    if(L.first==NULL){
        cout << "Mahasiswa tidak mengambil mata kuliah tersebut" << endl;
    } else if(L.first==L.last){
        P = L.first;
        L.first = NULL;
        L.last = NULL;
        P->kelas->info.jmlMhs--;
    } else {
        P = L.last;
        adrRelasi Q = L.last->prev;
        Q->next = NULL;
        P->prev = NULL;
        L.last = Q;
        P->kelas->info.jmlMhs--;
    }
}

bool adaRelasi(listRelasi L, adrMhs M, adrKelas K){
    adrRelasi Q = L.first;
    while(Q->next!=NULL && Q->mhs!=M && Q->kelas!=K){
        Q = Q->next;
    }
    if(Q->mhs==M && Q->kelas==K){
        return true;
    } else {
        return false;
    }
}

//void genInsertMhs(listMhs &L, string nim, string nama){
//    if(isEmptyMhs(L)){
//        insertFirstMhs(L, nim, nama);
//    } else {
//        string x = nim;
//        string y = L.first->info.nim;
//        bool P = x > y;
//        cout << x << " " << y << " " << P;
//        if(x > y){
//            insertLastMhs(L, nim, nama);
//        } else if(x < y){
//            insertFirstMhs(L, nim, nama);
//        } else {
//            adrMhs R = L.first;
//            while(R->next!=NULL && R->info.nim!=nim){
//                R = R->next;
//            }
//            if(R->info.nim == nim){
//                if(R->info.namaMhs != nama){
//                    char x;
//                    cout << "NIM sudah ada, ingin update data(mengubah nama)?" << endl;
//                    cout << "Jawab(y/n): ";
//                    cin >> x;
//                    if(x == 'y' || x == 'Y'){
//                        R->info.namaMhs = nama;
//                        system("cls");
//                    } else if (x == 'n' || x == 'N'){
//                        R->info.namaMhs = R->info.namaMhs;
//                    }
//                }
//            } else {
//                adrMhs P;
//                createElmMhs(P, nim, nama);
//                adrMhs Q = L.first;
//                while(Q!=NULL && nim>Q->info.nim){
//                    Q = Q->next;
//                }
//                adrMhs Prec = Q->prev;
//                insertAfterMhs(L, Prec, P);
//            }
//        }
//    }
//}

void printKelasMhs(listRelasi LRelasi, listMhs LMhs, listKelas LKelas){
    adrKelas K = LKelas.first;
    int i = 1;
    while(K!=NULL){
        cout << i << ". " << K->info.namaKelas << ": " << endl;
        if(K->info.jmlMhs==0){
            cout << "   Tidak ada mahasiswa yang mengambil mata kuliah ini." << endl;
        }
        adrRelasi R = LRelasi.first;
        while(R!=NULL){
            if(R->kelas==K){
                adrMhs M = LMhs.first;
                while(M!=NULL){
                    if(R->mhs==M){
                        cout << "   -> " << R->mhs->info.namaMhs << endl;
                    }
                    M = M->next;
                }
            }
            R = R->next;
        }
        cout << endl;
        i++;
        K = K->next;
    }
}

void modus(listRelasi LRelasi, listMhs LMhs, listKelas LKelas){
    adrKelas K = LKelas.first;
    if(K==NULL){
        cout << "Tidak ada mata kuliah yang terdaftar." << endl;
    } else {
        cout << "List mata kuliah yang paling banyak diambil: " << endl;
        int maks = 0;
        adrRelasi R = LRelasi.first;
        while(R!=NULL){
            if(R->kelas->info.jmlMhs > maks){
                maks = R->kelas->info.jmlMhs;
            }
            R = R->next;
        }
        adrKelas K = LKelas.first;
        int i = 1;
        while(K!=NULL){
            if(K->info.jmlMhs==maks){
                cout << i << ". " << K->info.namaKelas << endl;
                i++;
            }
            K = K->next;
        }
        cout << "dengan jumlah mahasiswa per mata kuliah adalah " << maks << endl;
    }
}

void printKelulusanMhs(listRelasi LRelasi, adrMhs M){
    adrRelasi Q = LRelasi.first;
//    cout << "         STATUS KELULUSAN MAHASISWA" << endl;
//    cout << "=============================================" << endl;
    cout << "Nama \t : " << M->info.namaMhs << endl;
    cout << "NIM  \t : " << M->info.nim << endl;
    cout << "---------------------------------------------" << endl;
    while(Q!=NULL){
        if(Q->mhs==M){
            cout << Q->kelas->info.namaKelas << "\t: ";
            if(Q->info.ketLulus == "-"){
                cout << "belum ada status kelulusan." << endl;
            } else if(Q->info.ketLulus == "Y" || Q->info.ketLulus == "y"){
                cout << "LULUS." << endl;
            } else if(Q->info.ketLulus == "N" || Q->info.ketLulus == "n"){
                cout << "TIDAK LULUS." << endl;
            }
        }
        Q = Q->next;
    }
}

void tidakLulus(listRelasi LRelasi, adrKelas K){
    adrRelasi R =LRelasi.first;
    int i = 1;
    cout << "Daftar mahasiswa yang tidak lulus mata kuliah " << K->info.namaKelas << ": " << endl;
    while(R!=NULL){
        if(R->info.ketLulus=="n" && R->kelas==K){
            cout << i << ". " << R->mhs->info.namaMhs << endl;
            i++;
        }
        R = R->next;
    }
    if(i==1){
        cout << "Tidak ada mahasiswa yang tidak lulus mata kuliah ini." << endl;
    }
}

void printMhsKelas(listRelasi LRelasi, adrMhs M){
    adrRelasi Q = LRelasi.first;
    int i = 1;
    while(Q!=NULL){
        if(Q->mhs==M){
            cout << i << ". Kode\t:" << Q->kelas->info.kode << endl;
            cout << "   Mata kuliah\t: " << Q->kelas->info.namaKelas << endl;
            i++;
        }
        Q = Q->next;
    }
}
