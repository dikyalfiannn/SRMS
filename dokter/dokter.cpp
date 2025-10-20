#include "dokter.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <cstdio> // Untuk remove/rename

// Kita perlu "keluar" dari folder dokter (../) untuk menemukan folder utils dan pasien
#include "../utils/utils.h"
// Kita juga panggil pasien.h untuk fungsi lihatSemuaPasien (jika sudah direfactor)
// Tapi untuk sekarang, kita copy-paste saja logikanya biar gampang

using namespace std;


// ==========================================================
// --- FUNGSI UNTUK MELIHAT PASIEN (Copy dari Admin) ---
// ==========================================================
// Dokter juga perlu melihat daftar pasien
void lihatSemuaPasienVersiDokter() {
    bersihkanLayar();
    cout << "--- Menampilkan Daftar Pasien ---" << endl << endl;
    ifstream berkas("data_pasien.txt"); 

    if (!berkas.is_open()) {
        cout << "Gagal membuka file data_pasien.txt!" << endl;
        tekanEnterUntukLanjut();
        return;
    }

    cout << left << setw(10) << "ID"
         << left << setw(25) << "Nama Pasien"
         << left << setw(20) << "Keluhan"
         << left << setw(15) << "Status"
         << left << setw(20) << "Diagnosa" << endl;
    cout << string(90, '-') << endl; 

    string baris;
    int jumlahPasien = 0;
    while (getline(berkas, baris)) {
        vector<string> data = pecahString(baris, '|');
        if (data.size() == 5) { 
            cout << left << setw(10) << data[0]
                 << left << setw(25) << data[1]
                 << left << setw(20) << data[2]
                 << left << setw(15) << data[3]
                 << left << setw(20) << data[4]
                 << endl;
            jumlahPasien++;
        }
    }
    berkas.close();
    if (jumlahPasien == 0) {
        cout << "Belum ada data pasien yang tersimpan." << endl;
    }
    cout << endl;
    tekanEnterUntukLanjut();
}

// ==========================================================
// --- FUNGSI BARU: Dokter Menulis Diagnosa ---
// ==========================================================
// Ini adalah fungsi 'Update' khusus untuk dokter
void tulisDiagnosa() {
    bersihkanLayar();
    cout << "--- Tulis/Update Diagnosa Pasien ---" << endl << endl;
    
    // Tampilkan data pasien dulu biar dokter bisa pilih ID
    lihatSemuaPasienVersiDokter(); 

    string idUpdate;
    cout << "Masukkan ID Pasien yang ingin diberi diagnosa: ";
    getline(cin, idUpdate);

    ifstream berkasAsli("data_pasien.txt");
    ofstream berkasSementara("temp.txt"); 

    if (!berkasAsli.is_open() || !berkasSementara.is_open()) {
        cout << "Gagal memproses file!" << endl;
        tekanEnterUntukLanjut();
        return;
    }

    string baris;
    bool ditemukan = false;
    while (getline(berkasAsli, baris)) {
        vector<string> data = pecahString(baris, '|');
        
        // Cari pasien berdasarkan ID
        if (data.size() == 5 && data[0] == idUpdate) {
            ditemukan = true;
            string diagnosaBaru;

            cout << "Data Pasien Ditemukan: " << data[1] << endl;
            cout << "Diagnosa Lama: " << data[4] << endl;
            cout << "Masukkan Diagnosa Baru: ";
            getline(cin, diagnosaBaru);

            // Tulis ulang barisnya, tapi ganti diagnosanya
            // data[0] = ID, data[1] = Nama, data[2] = Keluhan, data[3] = Status
            berkasSementara << data[0] << "|" << data[1] << "|" << data[2] << "|" << data[3] << "|" << diagnosaBaru << endl;
        } else {
            // Jika bukan target, tulis baris lama apa adanya
            berkasSementara << baris << endl;
        }
    }

    berkasAsli.close();
    berkasSementara.close(); 

    if (ditemukan) {
        remove("data_pasien.txt");
        rename("temp.txt", "data_pasien.txt");
        cout << "\nDiagnosa untuk pasien " << idUpdate << " berhasil di-update!" << endl;
    } else {
        remove("temp.txt"); 
        cout << "\nID Pasien " << idUpdate << " tidak ditemukan." << endl;
    }
    tekanEnterUntukLanjut();
}


// ==========================================================
// --- MENU UTAMA DOKTER (Diperbarui) ---
// ==========================================================
void tampilkanMenuDokter(Pengguna pengguna) {
    int pilihan = 0;
    while(true) {
        bersihkanLayar();
        cout << "========================================" << endl;
        cout << "         MENU DOKTER - RS WYU" << endl;
        cout << "========================================" << endl;
        cout << "Selamat datang, " << pengguna.namaPengguna << "!" << endl;
        cout << "1. Lihat Semua Data Pasien" << endl;
        cout << "2. Tulis/Update Diagnosa Pasien" << endl;
        cout << "3. Logout" << endl;
        cout << "----------------------------------------" << endl;
        cout << "Pilihan Anda (1-3): ";
        cin >> pilihan;
        bersihkanInputBuffer();

        switch (pilihan) {
        case 1: 
            lihatSemuaPasienVersiDokter();
            break;
        case 2:
            tulisDiagnosa();
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