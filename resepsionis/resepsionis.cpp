#include "resepsionis.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <cstdlib> 

#include "../utils/utils.h"
#include "../antrean/antrean.h" // Panggil "mesin" Linked List

using namespace std;

// ==========================================================
// --- FUNGSI 1: Cek Data Pasien Lama ---
// ==========================================================
void lihatSemuaPasienVersiResepsionis() {
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
// --- FUNGSI 2: Pendaftaran Pasien Baru ---
// ==========================================================
void registrasiPasienBaru() {
    bersihkanLayar();
    cout << "--- Pendaftaran Pasien Baru ---" << endl << endl;
    ofstream berkas("data_pasien.txt", ios::app); 
    if (!berkas.is_open()) {
        cout << "Gagal membuka file data_pasien.txt!" << endl;
        tekanEnterUntukLanjut();
        return;
    }

    string id, nama, keluhan;
    
    cout << "Masukkan ID Pasien (contoh: P003): ";
    getline(cin, id);
    cout << "Masukkan Nama Pasien: ";
    getline(cin, nama);
    cout << "Masukkan Keluhan Awal: ";
    getline(cin, keluhan);

    string status = "MENUNGGU";
    string diagnosa = "Belum ada";

    berkas << id << "|" << nama << "|" << keluhan << "|" << status << "|" << diagnosa << endl;
    berkas.close();

    cout << "\nPasien baru " << nama << " berhasil didaftarkan!" << endl;
    tekanEnterUntukLanjut();
}

// ==========================================================
// --- FUNGSI 3: Tambah Pasien ke Antrean (Enqueue) ---
// ==========================================================
void tambahPasienKeAntrean() {
    bersihkanLayar();
    cout << "--- Check-in Pasien ke Antrean ---" << endl << endl;
    
    ifstream berkas("data_pasien.txt"); 
    if (!berkas.is_open()) {
        cout << "Gagal membaca data pasien." << endl;
        tekanEnterUntukLanjut();
        return;
    }
    cout << "--- Daftar Pasien Terdaftar ---" << endl;
    cout << left << setw(10) << "ID" << left << setw(25) << "Nama Pasien" << endl;
    cout << string(35, '-') << endl;
    string baris;
    while (getline(berkas, baris)) {
        vector<string> data = pecahString(baris, '|');
        if (data.size() == 5) { 
            cout << left << setw(10) << data[0] << left << setw(25) << data[1] << endl;
        }
    }
    berkas.close();
    cout << "-------------------------------" << endl << endl;

    string idPasien;
    cout << "Masukkan ID Pasien yang masuk antrean (misal: P001): ";
    getline(cin, idPasien);
    
    enqueue(idPasien); // Panggil fungsi ENQUEUE dari modul Linked List
    
    tekanEnterUntukLanjut();
}


// ==========================================================
// --- MENU UTAMA RESEPSIONIS (DIUPDATE) ---
// ==========================================================
void tampilkanMenuResepsionis(Pengguna pengguna) {
    int pilihan = 0;
    while(true) {
        bersihkanLayar();
        cout << "========================================" << endl;
        cout << "       MENU RESEPSIONIS - RS SLAMET" << endl;
        cout << "========================================" << endl;
        cout << "Selamat datang, " << pengguna.namaPengguna << "!" << endl;
        cout << "1. Registrasi Pasien Baru" << endl;
        cout << "2. Cek Data Pasien Lama" << endl;
        cout << "3. (Antrean) Tambah Pasien (Enqueue)" << endl;
        cout << "4. (Antrean) Panggil Pasien (Dequeue)" << endl;
        cout << "5. (Antrean) Lihat Daftar Antrean (Display)" << endl;
        cout << "6. Penjadwalan Konsultasi (Belum ada)" << endl;
        cout << "7. Logout" << endl;
        cout << "----------------------------------------" << endl;
        cout << "Pilihan Anda (1-7): ";
        cin >> pilihan;
        bersihkanInputBuffer();

        switch (pilihan) {
        case 1:
            registrasiPasienBaru();
            break;
        case 2:
            lihatSemuaPasienVersiResepsionis();
            break;
        case 3:
            tambahPasienKeAntrean();
            break;
        case 4: {
            string idDipanggil = dequeue(); // Panggil fungsi DEQUEUE
            if (idDipanggil == "kosong") {
                cout << "Antrean sudah kosong." << endl;
            } else {
                cout << "Pasien berikutnya dipanggil: " << idDipanggil << endl;
            }
            tekanEnterUntukLanjut();
            break;
        }
        case 5:
            displayAntrean(); // Panggil fungsi DISPLAY
            tekanEnterUntukLanjut();
            break;
        case 6:
            cout << "Fitur ini sedang dalam pengembangan." << endl;
            tekanEnterUntukLanjut();
            break;
        case 7:
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