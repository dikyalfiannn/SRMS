#include "apoteker.h"
#include <iostream>
#include "../utils/utils.h" // Panggil utils

using namespace std;

void tampilkanMenuApoteker(Pengguna pengguna) {
    int pilihan = 0;
    while(true) {
        bersihkanLayar();
        cout << "========================================" << endl;
        cout << "         MENU APOTEKER - RS WYU" << endl;
        cout << "========================================" << endl;
        cout << "Selamat datang, " << pengguna.namaPengguna << "!" << endl;
        cout << "1. Lihat Stok Obat" << endl;
        cout << "2. Update Stok Obat" << endl;
        cout << "3. Logout" << endl;
        cout << "----------------------------------------" << endl;
        cout << "Pilihan Anda (1-3): ";
        cin >> pilihan;
        bersihkanInputBuffer();

        switch (pilihan) {
        case 1:
        case 2:
            cout << "Fitur ini belum dibuat." << endl;
            tekanEnterUntukLanjut();
            break;
        case 3:
            return; // Kembali ke main.cpp
        default:
            cout << "Pilihan tidak valid." << endl;
            tekanEnterUntukLanjut();
            break;
        }
    }
}