#include "dokter.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cstdlib> 
#include <cstdio> // <-- DIUBAH: Kembali ke <cstdio>

#include "../utils/utils.h"

using namespace std;

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
    const int MAX_FIELDS = 5;
    string data[MAX_FIELDS];
    while (getline(berkas, baris)) {
        int jumlahField = pecahString(baris, '|', data, MAX_FIELDS);
        if (jumlahField == 5) { 
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

void tulisDiagnosa() {
    bersihkanLayar();
    cout << "--- Tulis/Update Diagnosa Pasien ---" << endl << endl;
    
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
    const int MAX_FIELDS = 5;
    string data[MAX_FIELDS];
    while (getline(berkasAsli, baris)) {
        int jumlahField = pecahString(baris, '|', data, MAX_FIELDS);
        
        if (jumlahField == 5 && data[0] == idUpdate) {
            ditemukan = true;
            string diagnosaBaru;

            cout << "Data Pasien Ditemukan: " << data[1] << endl;
            cout << "Diagnosa Lama: " << data[4] << endl;
            cout << "Masukkan Diagnosa Baru: ";
            getline(cin, diagnosaBaru);

            berkasSementara << data[0] << "|" << data[1] << "|" << data[2] << "|" << data[3] << "|" << diagnosaBaru << endl;
        } else {
            berkasSementara << baris << endl;
        }
    }

    berkasAsli.close();
    berkasSementara.close(); 

    if (ditemukan) {
        remove("data_pasien.txt"); // <-- DIUBAH
        rename("temp.txt", "data_pasien.txt"); // <-- DIUBAH
        cout << "\nDiagnosa untuk pasien " << idUpdate << " berhasil di-update!" << endl;
    } else {
        remove("temp.txt"); // <-- DIUBAH
        cout << "\nID Pasien " << idUpdate << " tidak ditemukan." << endl;
    }
    tekanEnterUntukLanjut();
}


void tampilkanMenuDokter(Pengguna pengguna) {
    int pilihan = 0;
    while(true) {
        bersihkanLayar();
        cout << "========================================" << endl;
        cout << "         MENU DOKTER - RS SLAMET" << endl; 
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