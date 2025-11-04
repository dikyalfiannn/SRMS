#include "apoteker.h"
#include <iostream>
#include <string>
// #include <vector> // <-- DIHAPUS
#include <cstdlib> 
#include "../utils/utils.h" 

using namespace std;

// REVISI: Fungsi ini diubah dari Array Dinamis (vector)
// menjadi Array Statis (array C-style)
void demoArrayStatis_KeranjangObat() {
    bersihkanLayar();
    cout << "========================================" << endl;
    cout << "    DEMO ARRAY STATIS (Apoteker)" << endl;
    cout << "========================================" << endl;
    cout << "Tugas: Membuat resep obat (versi array statis)." << endl;
    cout << "Array ini punya batas maksimal 100 obat." << endl << endl;

    // --- PERUBAHAN DI SINI ---
    const int MAX_OBAT = 100;
    string keranjangObat[MAX_OBAT];
    int jumlahObat = 0;
    // -------------------------

    string inputObat;

    cout << "--- Silakan Masukkan Obat ---" << endl;
    while (true) {
        cout << "Masukkan nama obat (atau ketik 'selesai' untuk berhenti): ";
        getline(cin, inputObat);

        if (inputObat == "selesai") {
            break; 
        }

        // --- PERUBAHAN DI SINI ---
        if (jumlahObat < MAX_OBAT) {
            keranjangObat[jumlahObat] = inputObat;
            jumlahObat++;
            cout << "'" << inputObat << "' telah ditambahkan ke resep." << endl;
        } else {
            cout << "Keranjang resep sudah penuh (Maks " << MAX_OBAT << " obat)." << endl;
            break; // Keluar loop jika penuh
        }
        // -------------------------
    }

    cout << "\n--- Daftar Obat dalam Resep ---" << endl;
    
    // --- PERUBAHAN DI SINI ---
    if (jumlahObat == 0) {
        cout << "Resep kosong." << endl;
    } else {
        cout << "Total ada " << jumlahObat << " obat:" << endl;
        // Ganti loop 'range-based' ke 'for' C-style
        for (int i = 0; i < jumlahObat; i++) {
            cout << "- " << keranjangObat[i] << endl;
        }
    }
    // -------------------------

    tekanEnterUntukLanjut();
}

void tampilkanMenuApoteker(Pengguna pengguna) {
    int pilihan = 0;
    while(true) {
        bersihkanLayar();
        cout << "========================================" << endl;
        cout << "         MENU APOTEKER - RS SLAMET" << endl; 
        cout << "========================================" << endl;
        cout << "Selamat datang, " << pengguna.namaPengguna << "!" << endl;
        cout << "1. Lihat Stok Obat (Belum ada)" << endl;
        cout << "2. Update Stok Obat (Belum ada)" << endl;
        cout << "3. (DEMO) Buat Resep (Array Statis)" << endl; // <-- DIUBAH
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
            demoArrayStatis_KeranjangObat(); // <-- DIUBAH
            break;
        case 4:
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