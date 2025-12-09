#include "admin.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip> 
#include <cstdlib> 
#include <cstdio> 

#include "../utils/utils.h"
#include "../stokbaju/stokbaju.h" // <-- PENTING: Include file baru

using namespace std;

// ==========================================================
// --- FUNGSI KELOLA DOKTER (Kode Awal Kamu) ---
// ==========================================================
void lihatSemuaDokter() { 
    bersihkanLayar();
    cout << "--- Menampilkan Daftar Dokter ---" << endl << endl;
    ifstream berkas("data_dokter.txt"); 
    if (!berkas.is_open()) {
        cout << "Gagal membuka file data_dokter.txt!" << endl;
        tekanEnterUntukLanjut();
        return;
    }
    cout << left << setw(10) << "ID"
         << left << setw(30) << "Nama Dokter"
         << left << setw(20) << "Spesialisasi" << endl;
    cout << string(60, '-') << endl; 
    string baris;
    int jumlahDokter = 0;
    const int MAX_FIELDS = 3;
    string data[MAX_FIELDS];
    while (getline(berkas, baris)) {
        int jumlahField = pecahString(baris, '|', data, MAX_FIELDS);
        if (jumlahField == 3) {
            cout << left << setw(10) << data[0]
                 << left << setw(30) << data[1]
                 << left << setw(20) << data[2]
                 << endl;
            jumlahDokter++;
        }
    }
    berkas.close();
    if (jumlahDokter == 0) {
        cout << "Belum ada data dokter yang tersimpan." << endl;
    }
    cout << endl;
    tekanEnterUntukLanjut();
}

void tambahDokterBaru() {
    bersihkanLayar();
    cout << "--- Tambah Data Dokter Baru ---" << endl << endl;
    ofstream berkas("data_dokter.txt", ios::app); 
    if (!berkas.is_open()) {
        cout << "Gagal membuka file data_dokter.txt!" << endl;
        tekanEnterUntukLanjut();
        return;
    }
    string id, nama, spesialisasi;
    cout << "Masukkan ID Dokter (contoh: D004): ";
    getline(cin, id);
    cout << "Masukkan Nama Lengkap Dokter: ";
    getline(cin, nama);
    cout << "Masukkan Spesialisasi Dokter: ";
    getline(cin, spesialisasi);
    berkas << id << "|" << nama << "|" << spesialisasi << endl;
    berkas.close();
    cout << "\nData dokter baru berhasil ditambahkan!" << endl;
    tekanEnterUntukLanjut();
}

void updateDokter() {
    bersihkanLayar();
    cout << "--- Update Data Dokter ---" << endl << endl;
    lihatSemuaDokter(); 
    string idUpdate;
    cout << "Masukkan ID Dokter yang ingin di-update: ";
    getline(cin, idUpdate);
    ifstream berkasAsli("data_dokter.txt");
    ofstream berkasSementara("temp.txt"); 
    if (!berkasAsli.is_open() || !berkasSementara.is_open()) {
        cout << "Gagal memproses file!" << endl;
        tekanEnterUntukLanjut();
        return;
    }
    string baris;
    bool ditemukan = false;
    const int MAX_FIELDS = 3;
    string data[MAX_FIELDS];
    while (getline(berkasAsli, baris)) {
        int jumlahField = pecahString(baris, '|', data, MAX_FIELDS);
        if (jumlahField == 3 && data[0] == idUpdate) {
            ditemukan = true;
            string namaBaru, spesialisasiBaru;
            cout << "Data Ditemukan. Masukkan data baru:" << endl;
            cout << "Nama Dokter (Lama: " << data[1] << "): ";
            getline(cin, namaBaru);
            cout << "Spesialisasi (Lama: " << data[2] << "): ";
            getline(cin, spesialisasiBaru);
            berkasSementara << idUpdate << "|" << namaBaru << "|" << spesialisasiBaru << endl;
        } else {
            berkasSementara << baris << endl;
        }
    }
    berkasAsli.close();
    berkasSementara.close(); 
    if (ditemukan) {
        remove("data_dokter.txt"); 
        rename("temp.txt", "data_dokter.txt"); 
        cout << "\nData dokter berhasil di-update!" << endl;
    } else {
        remove("temp.txt"); 
        cout << "\nID Dokter " << idUpdate << " tidak ditemukan." << endl;
    }
    tekanEnterUntukLanjut();
}

void hapusDokter() {
    bersihkanLayar();
    cout << "--- Hapus Data Dokter ---" << endl << endl;
    lihatSemuaDokter(); 
    string idHapus;
    cout << "Masukkan ID Dokter yang ingin dihapus: ";
    getline(cin, idHapus);
    ifstream berkasAsli("data_dokter.txt");
    ofstream berkasSementara("temp.txt");
    if (!berkasAsli.is_open() || !berkasSementara.is_open()) {
        cout << "Gagal memproses file!" << endl;
        tekanEnterUntukLanjut();
        return;
    }
    string baris;
    bool ditemukan = false;
    const int MAX_FIELDS = 3;
    string data[MAX_FIELDS];
    while (getline(berkasAsli, baris)) {
        int jumlahField = pecahString(baris, '|', data, MAX_FIELDS);
        if (jumlahField == 3 && data[0] == idHapus) {
            ditemukan = true;
        } else {
            berkasSementara << baris << endl;
        }
    }
    berkasAsli.close();
    berkasSementara.close();
    if (ditemukan) {
        remove("data_dokter.txt"); 
        rename("temp.txt", "data_dokter.txt"); 
        cout << "\nData dokter berhasil dihapus!" << endl;
    } else {
        remove("temp.txt"); 
        cout << "\nID Dokter " << idHapus << " tidak ditemukan." << endl;
    }
    tekanEnterUntukLanjut();
}

void menuKelolaDokter() {
    int pilihan = 0;
    while (true) {
        bersihkanLayar();
        cout << "--- Kelola Data Dokter ---" << endl;
        cout << "1. Lihat Semua Dokter" << endl;
        cout << "2. Tambah Dokter Baru" << endl;
        cout << "3. Update Data Dokter" << endl; 
        cout << "4. Hapus Data Dokter" << endl;  
        cout << "5. Kembali ke Menu Admin" << endl; 
        cout << "--------------------------" << endl;
        cout << "Pilihan Anda (1-5): ";
        cin >> pilihan;
        bersihkanInputBuffer(); 
        switch (pilihan) {
        case 1: lihatSemuaDokter(); break;
        case 2: tambahDokterBaru(); break;
        case 3: updateDokter(); break;
        case 4: hapusDokter(); break;
        case 5: return; 
        default: cout << "Pilihan tidak valid." << endl; tekanEnterUntukLanjut(); break;
        }
    }
}


// --- FUNGSI KELOLA PASIEN (Kode Awal Kamu) ---
void lihatSemuaPasien() {
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

void tambahPasienBaru() {
    bersihkanLayar();
    cout << "--- Tambah Data Pasien Baru ---" << endl << endl;
    ofstream berkas("data_pasien.txt", ios::app); 
    if (!berkas.is_open()) {
        cout << "Gagal membuka file data_pasien.txt!" << endl;
        tekanEnterUntukLanjut();
        return;
    }
    string id, nama, keluhan, status, diagnosa;
    cout << "Masukkan ID Pasien (contoh: P003): ";
    getline(cin, id);
    cout << "Masukkan Nama Pasien: ";
    getline(cin, nama);
    cout << "Masukkan Keluhan Awal: ";
    getline(cin, keluhan);
    cout << "Masukkan Status (DIRAWAT/PULANG): ";
    getline(cin, status);
    cout << "Masukkan Diagnosa Awal (kosongi jika belum ada): ";
    getline(cin, diagnosa);
    if (diagnosa.empty()) {
        diagnosa = "Belum ada";
    }
    berkas << id << "|" << nama << "|" << keluhan << "|" << status << "|" << diagnosa << endl;
    berkas.close();
    cout << "\nData pasien baru berhasil ditambahkan!" << endl;
    tekanEnterUntukLanjut();
}

void updatePasien() {
    bersihkanLayar();
    cout << "--- Update Data Pasien ---" << endl << endl;
    lihatSemuaPasien(); 
    string idUpdate;
    cout << "Masukkan ID Pasien yang ingin di-update: ";
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
            string namaBaru, keluhanBaru, statusBaru, diagnosaBaru;
            cout << "Data Ditemukan. Masukkan data baru:" << endl;
            cout << "Nama (Lama: " << data[1] << "): ";
            getline(cin, namaBaru);
            cout << "Keluhan (Lama: " << data[2] << "): ";
            getline(cin, keluhanBaru);
            cout << "Status (Lama: " << data[3] << "): ";
            getline(cin, statusBaru);
            cout << "Diagnosa (Lama: " << data[4] << "): ";
            getline(cin, diagnosaBaru);
            berkasSementara << idUpdate << "|" << namaBaru << "|" << keluhanBaru << "|" << statusBaru << "|" << diagnosaBaru << endl;
        } else {
            berkasSementara << baris << endl;
        }
    }
    berkasAsli.close();
    berkasSementara.close(); 
    if (ditemukan) {
        remove("data_pasien.txt"); 
        rename("temp.txt", "data_pasien.txt"); 
        cout << "\nData pasien berhasil di-update!" << endl;
    } else {
        remove("temp.txt"); 
        cout << "\nID Pasien " << idUpdate << " tidak ditemukan." << endl;
    }
    tekanEnterUntukLanjut();
}

void hapusPasien() {
    bersihkanLayar();
    cout << "--- Hapus Data Pasien ---" << endl << endl;
    lihatSemuaPasien(); 
    string idHapus;
    cout << "Masukkan ID Pasien yang ingin dihapus: ";
    getline(cin, idHapus);
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
        if (jumlahField == 5 && data[0] == idHapus) {
            ditemukan = true;
        } else {
            berkasSementara << baris << endl;
        }
    }
    berkasAsli.close();
    berkasSementara.close();
    if (ditemukan) {
        remove("data_pasien.txt"); 
        rename("temp.txt", "data_pasien.txt"); 
        cout << "\nData pasien berhasil dihapus!" << endl;
    } else {
        remove("temp.txt"); 
        cout << "\nID Pasien " << idHapus << " tidak ditemukan." << endl;
    }
    tekanEnterUntukLanjut();
}

void menuKelolaPasien() {
    int pilihan = 0;
    while (true) {
        bersihkanLayar();
        cout << "--- Kelola Data Pasien ---" << endl;
        cout << "1. Lihat Semua Pasien" << endl;
        cout << "2. Tambah Pasien Baru" << endl;
        cout << "3. Update Data Pasien" << endl; 
        cout << "4. Hapus Data Pasien" << endl;  
        cout << "5. Kembali ke Menu Admin" << endl; 
        cout << "--------------------------" << endl;
        cout << "Pilihan Anda (1-5): ";
        cin >> pilihan;
        bersihkanInputBuffer(); 
        switch (pilihan) {
        case 1: lihatSemuaPasien(); break;
        case 2: tambahPasienBaru(); break;
        case 3: updatePasien(); break;
        case 4: hapusPasien(); break;
        case 5: return; 
        default: cout << "Pilihan tidak valid." << endl; tekanEnterUntukLanjut(); break;
        }
    }
}


// --- FUNGSI KELOLA OBAT (Kode Awal Kamu) ---
void lihatSemuaObat() {
    bersihkanLayar();
    cout << "--- Menampilkan Daftar Obat ---" << endl << endl;
    ifstream berkas("data_obat.txt"); 
    if (!berkas.is_open()) {
        cout << "Gagal membuka file data_obat.txt!" << endl;
        tekanEnterUntukLanjut();
        return;
    }
    cout << left << setw(10) << "ID"
         << left << setw(25) << "Nama Obat"
         << left << setw(15) << "Stok"
         << left << setw(15) << "Harga" << endl;
    cout << string(65, '-') << endl; 
    string baris;
    int jumlahObat = 0;
    const int MAX_FIELDS = 4;
    string data[MAX_FIELDS];
    while (getline(berkas, baris)) {
        int jumlahField = pecahString(baris, '|', data, MAX_FIELDS);
        if (jumlahField == 4) { 
            cout << left << setw(10) << data[0]
                 << left << setw(25) << data[1]
                 << left << setw(15) << data[2]
                 << left << setw(15) << data[3]
                 << endl;
            jumlahObat++;
        }
    }
    berkas.close();
    if (jumlahObat == 0) {
        cout << "Belum ada data obat yang tersimpan." << endl;
    }
    cout << endl;
    tekanEnterUntukLanjut();
}

void tambahObatBaru() {
    bersihkanLayar();
    cout << "--- Tambah Data Obat Baru ---" << endl << endl;
    ofstream berkas("data_obat.txt", ios::app); 
    if (!berkas.is_open()) {
        cout << "Gagal membuka file data_obat.txt!" << endl;
        tekanEnterUntukLanjut();
        return;
    }
    string id, nama, stok, harga;
    cout << "Masukkan ID Obat (contoh: OB003): ";
    getline(cin, id);
    cout << "Masukkan Nama Obat: ";
    getline(cin, nama);
    cout << "Masukkan Jumlah Stok: ";
    getline(cin, stok);
    cout << "Masukkan Harga (contoh: 5000): ";
    getline(cin, harga);
    berkas << id << "|" << nama << "|" << stok << "|" << harga << endl;
    berkas.close();
    cout << "\nData obat baru berhasil ditambahkan!" << endl;
    tekanEnterUntukLanjut();
}

void updateObat() {
    bersihkanLayar();
    cout << "--- Update Data Obat ---" << endl << endl;
    lihatSemuaObat(); 
    string idUpdate;
    cout << "Masukkan ID Obat yang ingin di-update: ";
    getline(cin, idUpdate);
    ifstream berkasAsli("data_obat.txt");
    ofstream berkasSementara("temp.txt"); 
    if (!berkasAsli.is_open() || !berkasSementara.is_open()) {
        cout << "Gagal memproses file!" << endl;
        tekanEnterUntukLanjut();
        return;
    }
    string baris;
    bool ditemukan = false;
    const int MAX_FIELDS = 4;
    string data[MAX_FIELDS];
    while (getline(berkasAsli, baris)) {
        int jumlahField = pecahString(baris, '|', data, MAX_FIELDS);
        if (jumlahField == 4 && data[0] == idUpdate) {
            ditemukan = true;
            string namaBaru, stokBaru, hargaBaru;
            cout << "Data Ditemukan. Masukkan data baru:" << endl;
            cout << "Nama Obat (Lama: " << data[1] << "): ";
            getline(cin, namaBaru);
            cout << "Stok (Lama: " << data[2] << "): ";
            getline(cin, stokBaru);
            cout << "Harga (Lama: " << data[3] << "): ";
            getline(cin, hargaBaru);
            berkasSementara << idUpdate << "|" << namaBaru << "|" << stokBaru << "|" << hargaBaru << endl;
        } else {
            berkasSementara << baris << endl;
        }
    }
    berkasAsli.close();
    berkasSementara.close(); 
    if (ditemukan) {
        remove("data_obat.txt"); 
        rename("temp.txt", "data_obat.txt"); 
        cout << "\nData obat berhasil di-update!" << endl;
    } else {
        remove("temp.txt"); 
        cout << "\nID Obat " << idUpdate << " tidak ditemukan." << endl;
    }
    tekanEnterUntukLanjut();
}

void hapusObat() {
    bersihkanLayar();
    cout << "--- Hapus Data Obat ---" << endl << endl;
    lihatSemuaObat(); 
    string idHapus;
    cout << "Masukkan ID Obat yang ingin dihapus: ";
    getline(cin, idHapus);
    ifstream berkasAsli("data_obat.txt");
    ofstream berkasSementara("temp.txt");
    if (!berkasAsli.is_open() || !berkasSementara.is_open()) {
        cout << "Gagal memproses file!" << endl;
        tekanEnterUntukLanjut();
        return;
    }
    string baris;
    bool ditemukan = false;
    const int MAX_FIELDS = 4;
    string data[MAX_FIELDS];
    while (getline(berkasAsli, baris)) {
        int jumlahField = pecahString(baris, '|', data, MAX_FIELDS);
        if (jumlahField == 4 && data[0] == idHapus) {
            ditemukan = true;
        } else {
            berkasSementara << baris << endl;
        }
    }
    berkasAsli.close();
    berkasSementara.close();
    if (ditemukan) {
        remove("data_obat.txt"); 
        rename("temp.txt", "data_obat.txt"); 
        cout << "\nData obat berhasil dihapus!" << endl;
    } else {
        remove("temp.txt"); 
        cout << "\nID Obat " << idHapus << " tidak ditemukan." << endl;
    }
    tekanEnterUntukLanjut();
}

void menuKelolaObat() {
    int pilihan = 0;
    while (true) {
        bersihkanLayar();
        cout << "--- Kelola Data Obat ---" << endl;
        cout << "1. Lihat Semua Obat" << endl;
        cout << "2. Tambah Obat Baru" << endl;
        cout << "3. Update Data Obat" << endl; 
        cout << "4. Hapus Data Obat" << endl;  
        cout << "5. Kembali ke Menu Admin" << endl; 
        cout << "--------------------------" << endl;
        cout << "Pilihan Anda (1-5): ";
        cin >> pilihan;
        bersihkanInputBuffer(); 
        switch (pilihan) {
        case 1: lihatSemuaObat(); break;
        case 2: tambahObatBaru(); break;
        case 3: updateObat(); break;
        case 4: hapusObat(); break;
        case 5: return; 
        default: cout << "Pilihan tidak valid." << endl; tekanEnterUntukLanjut(); break;
        }
    }
}


// --- FUNGSI KELOLA PENGGUNA (Kode Awal Kamu) ---
void lihatSemuaPengguna() {
    bersihkanLayar();
    cout << "--- Menampilkan Daftar Akun Pengguna (users.txt) ---" << endl << endl;
    ifstream berkas("users.txt"); 
    if (!berkas.is_open()) {
        cout << "Gagal membuka file users.txt!" << endl;
        tekanEnterUntukLanjut();
        return;
    }
    cout << left << setw(20) << "Username"
         << left << setw(20) << "Password"
         << left << setw(15) << "Peran" << endl;
    cout << string(55, '-') << endl; 
    string baris;
    int jumlahPengguna = 0;
    const int MAX_FIELDS = 3;
    string data[MAX_FIELDS];
    while (getline(berkas, baris)) {
        int jumlahField = pecahString(baris, '|', data, MAX_FIELDS);
        if (jumlahField == 3) {
            cout << left << setw(20) << data[0]
                 << left << setw(20) << data[1]
                 << left << setw(15) << data[2]
                 << endl;
            jumlahPengguna++;
        }
    }
    berkas.close();
    if (jumlahPengguna == 0) {
        cout << "Belum ada data pengguna yang tersimpan." << endl;
    }
    cout << endl;
    tekanEnterUntukLanjut();
}

void tambahPenggunaBaru() {
    bersihkanLayar();
    cout << "--- Tambah Akun Pengguna Baru ---" << endl << endl;
    ofstream berkas("users.txt", ios::app);
    if (!berkas.is_open()) {
        cout << "Gagal membuka file users.txt!" << endl;
        tekanEnterUntukLanjut();
        return;
    }
    string username, password, peran;
    cout << "Masukkan Username baru: ";
    getline(cin, username);
    cout << "Masukkan Password baru: ";
    getline(cin, password);
    cout << "Masukkan Peran (ADMIN, DOKTER, PASIEN, dll): ";
    getline(cin, peran);
    berkas << username << "|" << password << "|" << peran << endl;
    berkas.close();
    cout << "\nAkun pengguna baru berhasil ditambahkan!" << endl;
    cout << "Sekarang " << username << " bisa login dengan password " << password << "." << endl;
    tekanEnterUntukLanjut();
}

void menuKelolaPengguna() {
    int pilihan = 0;
    while (true) {
        bersihkanLayar();
        cout << "--- Kelola Akun Pengguna ---" << endl;
        cout << "1. Lihat Semua Pengguna" << endl;
        cout << "2. Tambah Pengguna Baru" << endl;
        cout << "3. Kembali ke Menu Admin" << endl;
        cout << "-----------------------------" << endl;
        cout << "Pilihan Anda (1-3): ";
        cin >> pilihan;
        bersihkanInputBuffer(); 
        switch (pilihan) {
        case 1: lihatSemuaPengguna(); break;
        case 2: tambahPenggunaBaru(); break;
        case 3: return; 
        default: cout << "Pilihan tidak valid." << endl; tekanEnterUntukLanjut(); break;
        }
    }
}


// ==========================================================
// --- FUNGSI BARU: STACK BAJU MEDIS ---
// ==========================================================
void menuStokBajuMedis() {
    int pilihan = 0;
    // Panggil initStokBaju() yang sekarang mereset index array ke -1
    initStokBaju(); 
    while (true) {
        bersihkanLayar();
        cout << "--- Logistik: Stok Baju Medis (STACK ARRAY) ---" << endl;
        cout << "1. Masukkan Baju Kotor ke Tumpukan (PUSH)" << endl;
        cout << "2. Ambil Baju Paling Atas untuk Dicuci (POP)" << endl;
        cout << "3. Lihat Tumpukan Baju Saat Ini (DISPLAY)" << endl;
        cout << "4. Kembali ke Menu Admin" << endl;
        cout << "-----------------------------------------------" << endl;
        cout << "Pilihan Anda (1-4): ";
        cin >> pilihan;
        bersihkanInputBuffer(); 
        
        switch (pilihan) {
        case 1: {
            string jenis;
            cout << "Masukkan Jenis Baju (contoh: Jubah Dokter/Sprei Pasien): ";
            getline(cin, jenis);
            pushBaju(jenis);
            tekanEnterUntukLanjut();
            break;
        }
        case 2: {
            string baju = popBaju();
            if (baju != "kosong") {
                cout << "\nBaju yang diambil untuk dicuci: '" << baju << "'" << endl;
            } else {
                cout << "\nTumpukan baju kosong. Tidak ada yang bisa diambil." << endl;
            }
            tekanEnterUntukLanjut();
            break;
        }
        case 3: 
            displayStackBaju();
            tekanEnterUntukLanjut();
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


// --- MENU ADMIN UTAMA (DIUBAH UNTUK STACK) ---
void tampilkanMenuAdmin(Pengguna pengguna) {
    int pilihan = 0;
    while (true) {
        bersihkanLayar();
        cout << "========================================" << endl;
        cout << "         MENU ADMIN - RS SLAMET" << endl; 
        cout << "========================================" << endl;
        cout << "Selamat datang, " << pengguna.namaPengguna << "!" << endl;
        cout << "1. Kelola Data Dokter" << endl; 
        cout << "2. Kelola Data Pasien" << endl; 
        cout << "3. Kelola Data Obat" << endl; 
        cout << "4. Kelola Akun Pengguna" << endl; 
        cout << "5. Logistik: Stok Baju Medis (Stack)" << endl; // <-- FITUR BARU
        cout << "6. Logout" << endl; // <-- DIUBAH
        cout << "----------------------------------------" << endl;
        cout << "Pilihan Anda (1-6): "; // <-- DIUBAH
        
        cin >> pilihan;
        bersihkanInputBuffer(); 

        switch (pilihan) {
        case 1:
            menuKelolaDokter(); 
            break;
        case 2:
            menuKelolaPasien();
            break;
        case 3:
            menuKelolaObat(); 
            break;
        case 4:
            menuKelolaPengguna();
            break;
        case 5:
            menuStokBajuMedis(); // <-- Panggil fungsi baru (Stack)
            break;
        case 6:
            cout << "Logout berhasil. Tekan Enter untuk kembali ke halaman login." << endl;
            system("pause"); 
            return; 
        default:
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
            tekanEnterUntukLanjut();
            break;
        }
    }
}