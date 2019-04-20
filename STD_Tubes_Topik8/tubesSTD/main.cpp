#include <cstdlib>
#include "mahasiswa.h"
#include "kelas.h"
#include "relasi.h"
#include "lainnya.h"

void judul(){
    cout << "============Tubes STD -- Topik 8=============" << endl;
    cout << "Novita(1301184101) -- Rizkyta S.A(1301184305)" << endl;
    cout << "=============================================" << endl;
}

int main(){
    int x, edit;
    char y;
    listMhs LMhs;
    listKelas LKelas;
    listRelasi LRelasi;
    string nama, nim, kode, namaKelas, l;
    infotypeRelasi ketLulus;
    createListMhs(LMhs);
    createListKelas(LKelas);
    createListRelasi(LRelasi);
    x = 1;
    while(x != 0 || y == 'y' || y == 'Y'){
        system("cls");
        judul();
        cout << "1. Tambah data mahasiswa" << endl;
        cout << "2. Tambah data mata kuliah" << endl;
        cout << "3. Hapus data mahasiswa" << endl;
        cout << "4. Hapus data mata kuliah" << endl;
        cout << "5. Acc mata kuliah" << endl;
        cout << "6. Tampil mata kuliah dengan mahasiswanya" << endl;
        cout << "7. Mata kuliah yang paling banyak diambil" << endl;
        cout << "8. Tampil kelulusan mahasiswa" << endl;
        cout << "9. Tampil mahasiswa yang tidak lulus" << endl;
        cout << "10. Edit data mahasiswa" << endl;
        cout << "11. Edit data mata kuliah" << endl;
        cout << "0. Keluar" << endl;

        cout << "Pilihan: ";
        cin >> x;
        switch(x){
        case 1:
            system("cls");
            judul();
            cout << "              INSERT MAHASISWA" << endl;
            cout << "=============================================" << endl;
            cout << "NIM \t : ";
            cin >> nim;
            cout << "Nama \t : ";
            cin >> nama;
            adrMhs M;
            M = searchMhs(LMhs, nim);
            if(M!=NULL && M->info.namaMhs==nama){
                system("cls");
                judul();
                cout << "Mahasiswa sudah terdaftar." << endl;
            } else if(M!=NULL && M->info.namaMhs!=nama){
                system("cls");
                judul();
                cout << "NIM sudah terdaftar oleh mahasiswa lain." << endl;
            } else {
                insertLastMhs(LMhs, nim, nama);
            }
            break;
        case 2:
            system("cls");
            judul();
            cout << "              INSERT MATA KULIAH" << endl;
            cout << "=============================================" << endl;
            cout << "Kode mata kuliah \t : ";
            cin >> kode;
            cout << "Nama mata kuliah \t : ";
            cin >> namaKelas;
            adrKelas K;
            K = searchKelas(LKelas, kode);
            if(K!=NULL && K->info.namaKelas==namaKelas){
                system("cls");
                judul();
                cout << "Mata kuliah sudah terdaftar." << endl;
            } else if(K!=NULL && K->info.namaKelas!=namaKelas){
                system("cls");
                judul();
                cout << "Kode mata kuliah sudah terdaftar oleh mata kuliah lain." << endl;
            } else {
                insertLastKelas(LKelas, kode, namaKelas);
            }
            break;
        case 3:
            system("cls");
            judul();
            cout << "              DELETE MAHASISWA" << endl;
            cout << "=============================================" << endl;
            adrMhs P, precMhs, PP;
            PP = LMhs.first;
            if(PP==NULL){
                cout << "Tidak ada mahasiswa yang terdaftar." << endl;
            } else {
                cout << "---------------------------------------------" << endl;
                printMhs(LMhs);
                cout << "---------------------------------------------" << endl;
                cout << "NIM mahasiswa yang ingin dihapus: ";
                cin >> nim;
                P = searchMhs(LMhs,nim);
                if(P!=NULL){
                    adrRelasi R = LRelasi.first;
                    while(R!=NULL){
                        if(R->mhs->info.nim==nim){
                            if(R==LRelasi.first){
                                deleteFirstRelasi(LRelasi, R, K);
                            } else if(R==LRelasi.last){
                                deleteLastRelasi(LRelasi, R, K);
                            } else {
                                adrRelasi Prec = R->prev;
                                deleteAfterRelasi(LRelasi, Prec, R, K);
                            }
                        }
                        R = R->next;
                    }
                    if(P==LMhs.first){
                        deleteFirstMhs(LMhs, P);
                    } else if(P==LMhs.last){
                        deleteLastMhs(LMhs, P);
                    } else {
                        precMhs = P->prev;
                        deleteAfterMhs(LMhs, precMhs, P);
                    }
                } else {
                    cout << "Tidak ada mahasiswa dengan NIM " << nim;
                }
            }
            break;
        case 4:
            system("cls");
            judul();
            cout << "              DELETE MATA KULIAH" << endl;
            cout << "=============================================" << endl;
            adrKelas KK;
            KK = LKelas.first;
            if(KK==NULL){
                cout << "Tidak ada mata kuliah yang terdaftar." << endl;
            } else {
                cout << "---------------------------------------------" << endl;
                printKelas(LKelas);
                cout << "---------------------------------------------" << endl;
                cout << "Kode mata kuliah yang ingin dihapus: ";
                cin >> kode;
                adrRelasi R;
                R = LRelasi.first;
                while(R!=NULL){
                    if(R->kelas->info.kode==kode){
                        if(R==LRelasi.first){
                            deleteFirstRelasi(LRelasi, R, K);
                        } else if(R==LRelasi.last){
                            deleteLastRelasi(LRelasi, R, K);
                        } else {
                            adrRelasi precRelasi = R->prev;
                            deleteAfterRelasi(LRelasi, precRelasi, R, K);
                        }
                    }
                    R = R->next;
                }
                adrKelas K, precKelas;
                K = searchKelas(LKelas,kode);
                if(K!=NULL){
                    if(K==LKelas.first){
                        deleteFirstKelas(LKelas, K);
                    } else if(K==LKelas.last){
                        deleteLastKelas(LKelas, K);
                    } else {
                        precKelas = K->prev;
                        deleteAfterKelas(LKelas, precKelas, K);
                    }
                } else {
                    cout << "Tidak ada mata kuliah dengan kode " << kode;
                }
            }
            break;
        case 5:
            system("cls");
            judul();
            cout << "               ACC MATA KULIAH" << endl;
            cout << "=============================================" << endl;
            cout << "NIM mahasiswa              : ";
            cin >> nim;
            cout << "Mata kuliah yang diambil   : ";
            cin >> kode;
//            l = "a";
//            do{
                cout << "Status kelulusan(y/n/-)    : ";
                cin >> l;
//            }
//
//            while(l!="y" || l!="n" || l!="Y" || l!="N" || l!="-");
            ketLulus.ketLulus = l;
            M = searchMhs(LMhs, nim);
            K = searchKelas(LKelas, kode);
            if(M==NULL && K==NULL){
                system("cls");
                judul();
                cout << "               ACC MATA KULIAH" << endl;
                cout << "=============================================" << endl;
                cout << "Mahasiswa dan mata kuliah tidak terdaftar." << endl;
            } else if(M==NULL && K!=NULL){
                system("cls");
                judul();
                cout << "               ACC MATA KULIAH" << endl;
                cout << "=============================================" << endl;
                cout << "Mahasiswa tidak terdaftar." << endl;
            } else if(M!=NULL && K==NULL){
                system("cls");
                judul();
                cout << "               ACC MATA KULIAH" << endl;
                cout << "=============================================" << endl;
                cout << "Mata kuliah tidak terdaftar." << endl;
            } else {
                int count;
                adrKelas Q;
                adrRelasi RR = LRelasi.first;
                if(RR!=NULL){
                    adrRelasi R = LRelasi.first;
                    count = 0;
                    if(LRelasi.first!=LRelasi.last){

                        while(R!=NULL){
                            if(R->kelas==K && R->mhs==M)
                            count++;
                            R = R->next;
                        }
                    }
                    if(count >= 1){
                        system("cls");
                        judul();
                        cout << "               ACC MATA KULIAH" << endl;
                        cout << "=============================================" << endl;
                        cout << "Mata kuliah sudah di acc mahasiswa." << endl;
                    } else {
                        RR = createElmRelasi(M, K, ketLulus);
                        insertLastRelasi(LRelasi, RR, Q);
                    }
                } else {
                    RR = createElmRelasi(M, K, ketLulus);
                    insertLastRelasi(LRelasi, RR, Q);
                }
            }
            break;
        case 6:
            system("cls");
            judul();
            cout << "        DAFTAR MATA KULIAH-MAHASISWA" << endl;
            cout << "=============================================" << endl;
            adrRelasi R;
            R = LRelasi.first;
            if(R==NULL){
                cout << "Data kosong." << endl;
            } else {
                printKelasMhs(LRelasi, LMhs, LKelas);
            }
            break;
        case 7:
            system("cls");
            judul();
            cout << "   MATA KULIAH YANG PALING BANYAK DIAMBIL" << endl;
            cout << "=============================================" << endl;
            R = LRelasi.first;
            if(R==NULL){
                cout << "Data kosong." << endl;
            } else {
                modus(LRelasi, LMhs, LKelas);
            }
            break;
        case 8:
            system("cls");
            judul();
            cout << "  MELIHAT STATUS KELULUSAN PER MATA KULIAH" << endl;
            cout << "=============================================" << endl;
            M = LMhs.first;
            K = LKelas.first;
            if(M==NULL && K==NULL){
                cout << "Data kosong." << endl;
            } else if(M==NULL && K!=NULL){
                cout << "Tidak ada mahasiswa yang terdaftar." << endl;
            } else if(M!=NULL && K==NULL){
                cout << "Tidak ada mata kuliah yang terdaftar." << endl;
            } else {
                cout << "Masukkan NIM: ";
                cin >> nim;
                M = searchMhs(LMhs, nim);
                if(M==NULL){
                    system("cls");
                    judul();
                    cout << "  MELIHAT STATUS KELULUSAN PER MATA KULIAH" << endl;
                    cout << "=============================================" << endl;
                    cout << "Mahasiswa tidak terdaftar." << endl;
                } else {
                    system("cls");
                    judul();
                    cout << "  MELIHAT STATUS KELULUSAN PER MATA KULIAH" << endl;
                    cout << "=============================================" << endl;
                    printKelulusanMhs(LRelasi, M);
                }
            }
            break;
        case 9:
            system("cls");
            judul();
            cout << "         MAHASISWA YANG TIDAK LULUS" << endl;
            cout << "=============================================" << endl;
            M = LMhs.first;
            K = LKelas.first;
            if(M==NULL && K==NULL){
                cout << "Data kosong." << endl;
            } else if(M==NULL && K!=NULL){
                cout << "Tidak ada mahasiswa yang terdaftar." << endl;
            } else if(M!=NULL && K==NULL){
                cout << "Tidak ada mata kuliah yang terdaftar." << endl;
            } else {
                cout << "Masukkan kode mata kuliah: ";
                cin >> kode;
                K = searchKelas(LKelas, kode);
                if(K==NULL){
                    system("cls");
                    judul();
                    cout << "         MAHASISWA YANG TIDAK LULUS" << endl;
                    cout << "=============================================" << endl;
                    cout << "Mata kuliah tidak terdaftar." << endl;
                } else {
                    system("cls");
                    judul();
                    cout << "         MAHASISWA YANG TIDAK LULUS" << endl;
                    cout << "=============================================" << endl;
                    tidakLulus(LRelasi, K);
                }
            }
            break;
        case 10:
            adrMhs MM;
            MM = LMhs.first;
            if(MM==NULL){
                system("cls");
                judul();
                cout << "             EDIT DATA MAHASISWA" << endl;
                cout << "=============================================" << endl;
                cout << "Tidak ada mahasiswa yang terdaftar." << endl;
            } else {
                system("cls");
                judul();
                cout << "             EDIT DATA MAHASISWA" << endl;
                cout << "=============================================" << endl;
                cout << "---------------------------------------------" << endl;
                printMhs(LMhs);
                cout << "---------------------------------------------" << endl;
                cout << "NIM mahasiswa yang ingin di-edit: ";
                cin >> nim;
                M = searchMhs(LMhs, nim);
                if(M==NULL){
                    system("cls");
                    judul();
                    cout << "             EDIT DATA MAHASISWA" << endl;
                    cout << "=============================================" << endl;
                    cout << "Mahasiswa tidak terdaftar." << endl;
                } else {
                    system("cls");
                    judul();
                    cout << "             EDIT DATA MAHASISWA" << endl;
                    cout << "=============================================" << endl;
                    cout << "---------------------------------------------" << endl;
                    while(MM!=NULL){
                        if(MM->info.nim==nim){
                            cout << "NIM\t: " << MM->info.nim << endl;
                            cout << "Nama\t: " << MM->info.namaMhs << endl;
                        }
                        MM = MM->next;
                    }
                    cout << "---------------------------------------------" << endl;
                    cout << endl;
                    cout << "Opsi edit: " << endl;
                    cout << "1. Edit nama" << endl;
                    cout << "2. Hapus mata kuliah" << endl;
                    cout << "Jawab(1/2): ";
                    cin >> edit;
                    if(edit==1){
                        system("cls");
                        judul();
                        cout << "             EDIT DATA MAHASISWA" << endl;
                        cout << "=============================================" << endl;
                        cout << "Masukkan nama: ";
                        cin >> nama;
                        M->info.namaMhs = nama;
                    } else if(edit==2){
                        system("cls");
                        judul();
                        cout << "             EDIT DATA MAHASISWA" << endl;
                        cout << "=============================================" << endl;
                        cout << "Daftar mata kuliah yang telah diambil: " << endl;
                        printMhsKelas(LRelasi, M);
                        cout << "---------------------------------------------" << endl;
                        adrKelas KK = LKelas.first;
                        if(KK==NULL){
                            system("cls");
                            judul();
                            cout << "             EDIT DATA MAHASISWA" << endl;
                            cout << "=============================================" << endl;
                            cout << "Tidak ada mata kuliah yang terdaftar." << endl;
                        } else if(KK!=NULL) {
                            system("cls");
                            judul();
                            cout << "             EDIT DATA MAHASISWA" << endl;
                            cout << "=============================================" << endl;
                            cout << "---------------------------------------------" << endl;
                            printMhsKelas(LRelasi, M);
                            cout << "---------------------------------------------" << endl;
                            cout << "Masukkan kode mata kuliah yang ingin dihapus: ";
                            cin >> kode;
                            adrKelas K = searchKelas(LKelas, kode);
                            if(K==NULL){
                                system("cls");
                                judul();
                                cout << "             EDIT DATA MAHASISWA" << endl;
                                cout << "=============================================" << endl;
                                cout << "Mata kuliah tidak terdaftar." << endl;
                            } else {
                                adrRelasi R;
                                R = LRelasi.first;
                                if(R!=NULL){
                                    R = LRelasi.first;
                                    while(R!=NULL && R->mhs!=M){
                                        R = R->next;
                                    }
                                    if(R->kelas==K && R->mhs==M){
                                        if(R==LRelasi.first){
                                            deleteFirstRelasi(LRelasi, R, K);
                                        } else if(R==LRelasi.last){
                                            deleteLastRelasi(LRelasi, R, K);
                                        } else {
                                            adrRelasi precRelasi = R->prev;
                                            deleteAfterRelasi(LRelasi, precRelasi, R, K);
                                        }
                                    }
                                } else {
                                    system("cls");
                                    judul();
                                    cout << "             EDIT DATA MAHASISWA" << endl;
                                    cout << "=============================================" << endl;
                                    cout << "Mahasiswa tidak mengambil mata kuliah tersebut." << endl;
                                }
                            }
                        }
                    }
                }
            }
            break;
        case 11:
            system("cls");
            judul();
            cout << "            EDIT DATA MATA KULIAH" << endl;
            cout << "=============================================" << endl;
            K = LKelas.first;
            if(K==NULL){
                cout << "Tidak ada mata kuliah yang terdaftar." << endl;
            } else {
                printKelas(LKelas);
                cout << "---------------------------------------------" << endl;
                cout << "*Anda hanya dapat mengedit nama mata kuliah." << endl;
                cout << "---------------------------------------------" << endl;
                cout << endl;
                cout << "Masukkan kode mata kuliah yang akan diedit: ";
                cin >> kode;
                K = searchKelas(LKelas, kode);
                if(K==NULL){
                    cout << "Mata kuliah tidak terdaftar." << endl;
                } else {
                    system("cls");
                    judul();
                    cout << "            EDIT DATA MATA KULIAH" << endl;
                    cout << "=============================================" << endl;
                    cout << "Masukkan nama mata kuliah: ";
                    cin >> namaKelas;
                    K->info.namaKelas = namaKelas;
                }
            }

            break;
        case 12:
            system("cls");
            printMhs(LMhs);
            break;
        case 13:
            system("cls");
            printKelas(LKelas);
            break;
        case 0: exit(0);
        }

        cout << endl;
        cout << "Masih ingin menjalankan program?" << endl;
        cout << "Jawab(y/n): ";
        cin >> y;
        if (y == 'n' || y == 'N'){
            cout << "Bye..." << endl;
            exit(0);
        }
    }
}


