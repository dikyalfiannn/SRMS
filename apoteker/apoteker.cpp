#include "apoteker.h"
#include <iostream>
#include <string>
#include <vector>
#include "../utils/utils.h" 

using namespace std;

void demoArrayDinamis_KeranjangObat() {
    bersihkanLayar();
    cout << "========================================" << endl;
    cout << "    DEMO ARRAY DINAMIS (Apoteker)" << endl;
    cout << "========================================" << endl;
    cout << "Tugas: Membuat resep obat." << endl;
    cout << "Jumlah obat tidak pasti (bisa 1, bisa 5)." << endl << endl;

    vector<string> keranjangObat;
    string inputObat;

    cout << "--- Silakan Masukkan Obat ---" << endl;
    while (true) {
        cout << "Masukkan nama obat (atau ketik 'selesai' untuk berhenti): ";
        getline(cin, inputObat);

        if (inputObat == "selesai") {
            break; 
        }

        keranjangObat.push_back(inputObat); 
        cout << "'" << inputObat << "' telah ditambahkan ke resep." << endl;
    }

    cout << "\n--- Daftar Obat dalam Resep ---" << endl;
    
    if (keranjangObat.size() == 0) {
        cout << "Resep kosong." << endl;
    } else {
        cout << "Total ada " << keranjangObat.size() << " obat:" << endl;
        for (const string& obat : keranjangObat) {
            cout << "- " << obat << endl;
        }
    }

    tekanEnterUntukLanjut();
}

void tampilkanMenuApoteker(Pengguna pengguna) {
    int pilihan = 0;
    while(true) {
        bersihkanLayar();
        cout << "========================================" << endl;
        cout << "         MENU APOTEKER - RS SLAMET      " << endl;
        cout << "========================================" << endl;
        cout << "Selamat datang, " << pengguna.namaPengguna << "!" << endl;
        cout << "1. Lihat Stok Obat (Belum ada)" << endl;
        cout << "2. Update Stok Obat (Belum ada)" << endl;
        cout << "3. Buat Resep (Array Dinamis)" << endl; 
        cout << "4. Logout" << endl; 
        cout << "----------------------------------------" << endl;
        cout << "Pilihan Anda (1-4): ";
        cin >> pilihan;
        bersihkanInputBuffer();

        switch (pilihan) {
        case 1:
        case 2:
            cout << "Fitur ini belum dibuat." << endl;
            tekanEnterUntukLanjut();
            break;
        case 3:
            demoArrayDinamis_KeranjangObat();
            break;
        case 4:
            return; 
        default:
            cout << "Pilihan tidak valid." << endl;
            tekanEnterUntukLanjut();
            break;
        }
    }
}