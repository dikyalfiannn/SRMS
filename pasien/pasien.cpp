#include "pasien.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib> 
#include "../utils/utils.h" 

using namespace std;

void demoArrayStatis_CatatTandaVital() {
    bersihkanLayar();
    cout << "========================================" << endl;
    cout << "      DEMO ARRAY STATIS (Pasien)" << endl;
    cout << "========================================" << endl;
    cout << "Tugas: Mencatat 4 Tanda Vital Pasien." << endl;
    cout << "Ukuran array sudah pasti, yaitu 4." << endl << endl;

    string namaTandaVital[4] = {"Tekanan Darah", "Detak Jantung", "Suhu Tubuh", "Laju Pernapasan"};
    string hasilPengukuran[4];

    cout << "--- Silakan Masukkan Data ---" << endl;
    for (int i = 0; i < 4; i++) {
        cout << "Masukkan " << namaTandaVital[i] << ": ";
        getline(cin, hasilPengukuran[i]);
    }

    cout << "\n--- Hasil Pencatatan Tanda Vital ---" << endl;
    for (int i = 0; i < 4; i++) {
        cout << left << setw(20) << namaTandaVital[i] 
             << ": " << hasilPengukuran[i] << endl;
    }

    tekanEnterUntukLanjut();
}

void tampilkanMenuPasien(Pengguna pengguna) {
    int pilihan = 0;
     while(true) {
        bersihkanLayar();
        cout << "========================================" << endl;
        cout << "         MENU PASIEN - RS SLAMET" << endl; 
        cout << "========================================" << endl;
        cout << "Selamat datang, " << pengguna.namaPengguna << "!" << endl;
        cout << "1. Lihat Data Medis Saya (Belum ada)" << endl;
        cout << "2. (DEMO) Catat Tanda Vital (Array Statis)" << endl; 
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
            demoArrayStatis_CatatTandaVital();
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