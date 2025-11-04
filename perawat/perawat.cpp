#include "perawat.h"
#include <iostream>
#include <cstdlib> 
#include "../utils/utils.h"

using namespace std;

void tampilkanMenuPerawat(Pengguna pengguna) {
    int pilihan = 0;
    while(true) {
        bersihkanLayar();
        cout << "========================================" << endl;
        cout << "         MENU PERAWAT - RS SLAMET" << endl;
        cout << "========================================" << endl;
        cout << "Selamat datang, " << pengguna.namaPengguna << "!" << endl;
        cout << "1. Lihat Semua Pasien" << endl;
        cout << "2. Update Status Pasien" << endl;
        cout << "3. Logout" << endl;
        cout << "----------------------------------------" << endl;
        cout << "Pilihan Anda (1-3): ";
        cin >> pilihan;
        bersihkanInputBuffer();

        switch (pilihan) {
        case 1:
            cout << "Fitur ini belum dibuat." << endl;
            tekanEnterUntukLanjut();
            break;
        case 2:
            cout << "Fitur ini belum dibuat." << endl;
            tekanEnterUntukLanjut();
            break;
        case 3:
            cout << "Logout berhasil. Tekan Enter untuk kembali ke halaman login." << endl;
            system("pause"); 
            return; 
        default:
            cout << "Pilihan tidak valid." << endl;
            tekanEnterUntukLanjut();
            break;
        }
    }
}