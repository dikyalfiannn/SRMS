#include "pasien.h"
#include <iostream>
#include "../utils/utils.h" // Panggil utils

using namespace std;

void tampilkanMenuPasien(Pengguna pengguna) {
    int pilihan = 0;
     while(true) {
        bersihkanLayar();
        cout << "========================================" << endl;
        cout << "         MENU PASIEN - RS WYU" << endl;
        cout << "========================================" << endl;
        cout << "Selamat datang, " << pengguna.namaPengguna << "!" << endl;
        cout << "1. Lihat Data Medis Saya" << endl;
        cout << "2. Logout" << endl;
        cout << "----------------------------------------" << endl;
        cout << "Pilihan Anda (1-2): ";
        cin >> pilihan;
        bersihkanInputBuffer();

        switch (pilihan) {
        case 1:
            cout << "Fitur ini belum dibuat." << endl;
            tekanEnterUntukLanjut();
            break;
        case 2:
            return; // Kembali ke main.cpp
        default:
            cout << "Pilihan tidak valid." << endl;
            tekanEnterUntukLanjut();
            break;
        }
    }
}