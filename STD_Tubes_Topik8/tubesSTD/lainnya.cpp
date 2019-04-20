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

void aksi(){
    int x;
    char y;
    listMhs LMhs;
    string nama, nim;
    createListMhs(LMhs);
    x = 1;
    while(x!=0){
        system("cls");
        judul();
        cout << "1. Tambah data mahasiswa" << endl;
        cout << "2. Tambah data mata kuliah" << endl;
        cout << "3. Hapus data mahasiswa" << endl;
        cout << "4. Hapus data mata kuliah" << endl;
        cout << "5. Acc mata kuliah" << endl;
        cout << "6. Tampil mata kuliah dan mahasiswa" << endl;
        cout << "7. Mata kuliah yang paling banyak diambil" << endl;
        cout << "8. Tampil kelulusan mahasiswa" << endl;
        cout << "9. Tampil mahasiswa yang tidak lulus" << endl;
        cout << "0. Keluar" << endl;

        cout << "Pilihan: ";
        cin >> x;
        switch(x){
        case 1:
            system("cls");
            judul();
            cout << "Nama   : ";
            cin >> nama;
            cout << "NIM    : ";
            cin >> nim;
            genInsertMhs(LMhs, nim, nama);
            break;
        case 2:
            system("cls");
            judul();
            break;
        case 3:
            system("cls");
            judul();
            break;
        case 4:
            system("cls");
            judul();
            break;
        case 5:
            system("cls");
            judul();
            break;
        case 6:
            //system("cls");
            //judul();
            print(LMhs);
            break;
        case 7:
            system("cls");
            judul();
            break;
        case 8:
            system("cls");
            judul();
            break;
        case 9:
            system("cls");
            judul();
            break;
        case 0: exit(0);
        }

        cout << "Masih ingin menjalankan program?" << endl;
        cout << "Jawab(y/n): ";
        cin >> y;
        if(y == 'y' || y == 'Y'){
            aksi();
        } else if (y == 'n' || y == 'N'){
            cout << "Bye..." << endl;
            exit(0);
        }
    }
}
