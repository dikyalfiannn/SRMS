#include "login.h"
#include <iostream>
#include <fstream> // Untuk baca/tulis file
#include <vector>

// Kita perlu "keluar" dari folder login (../) untuk menemukan folder utils
#include "../utils/utils.h"

using namespace std;

// Fungsi internal untuk cek file
void periksaDanBuatFile(const string& namaFile, const string& isiDefault) {
    ifstream berkas(namaFile);
    if (!berkas.good()) { // .good() mengecek apakah file ada
        berkas.close();
        ofstream berkasKeluar(namaFile);
        berkasKeluar << isiDefault;
        berkasKeluar.close();
    }
    berkas.close();
}

// Implementasi fungsi seeding data
// Implementasi fungsi seeding data
// Implementasi fungsi seeding data
void buatDataAwal() {
    // Skema: namaPengguna|kataSandi|peran
    periksaDanBuatFile("users.txt",
        "admin|admin123|ADMIN\n"
        "drbudi|dokter1|DOKTER\n"
        "susterani|perawat1|PERAWAT\n"
        "aptbudi|apoteker1|APOTEKER\n"
        "pasienono|pasien1|PASIEN\n"
    );

    // Skema: id|nama|spesialisasi
    periksaDanBuatFile("data_dokter.txt", 
        "D001|Dr. Budi Santoso|Jantung\n"
        "D002|Dr. Ani Wijaya|Anak\n"
        "D003|Dr. Guntur Setiawan|Mata\n"
    );

    // Skema: id|nama|keluhan|status|diagnosa
    periksaDanBuatFile("data_pasien.txt", 
        "P001|Siti Aminah|Demam Tinggi|DIRAWAT|Belum ada\n"
        "P002|Ahmad Dhani|Pusing|PULANG|Vertigo\n"
    );

    // --- PERUBAHAN DI SINI ---
    // Skema: id|nama_obat|stok|harga
    periksaDanBuatFile("data_obat.txt", 
        "OB001|Paracetamol|100|5000\n"
        "OB002|Amoxicillin|50|15000\n"
    );
    // -------------------------
}


// Implementasi fungsi login
Pengguna halamanLogin() {
    Pengguna pengguna = {"", "", false}; // Pengguna default (gagal login)
    string inputNama, inputSandi;

    cout << "========================================" << endl;
    cout << "   SELAT DATANG DI SISTEM RS WYU" << endl;
    cout << "========================================" << endl;
    cout << "Silakan login:" << endl;
    
    cout << "Username: " << flush; // Tambahkan << flush
    getline(cin, inputNama);
    
    cout << "Password: " << flush; // Tambahkan << flush
    getline(cin, inputSandi);

    ifstream berkas("users.txt");
    string baris;

    if (!berkas.is_open()) {
        cout << "Error: Gagal membuka file users.txt!" << endl;
        return pengguna;
    }

    // Baca file users.txt baris per baris
    while (getline(berkas, baris)) {
        vector<string> dataPengguna = pecahString(baris, '|'); 

        // Pastikan formatnya benar (username|password|role)
        if (dataPengguna.size() == 3) {
            string namaTersimpan = dataPengguna[0];
            string sandiTersimpan = dataPengguna[1];
            string peranTersimpan = dataPengguna[2];

            // Bandingkan input user dengan data di file
            if (inputNama == namaTersimpan && inputSandi == sandiTersimpan) {
                pengguna.namaPengguna = namaTersimpan;
                pengguna.peran = peranTersimpan;
                pengguna.sudahLogin = true;
                berkas.close();
                return pengguna; // Login berhasil, kembalikan data pengguna
            }
        }
    }

    berkas.close();
    
    // Jika loop selesai dan tidak ada yang cocok
    bersihkanLayar();
    cout << "Login Gagal! Username atau Password salah." << endl;
    tekanEnterUntukLanjut();
    return pengguna; // Kembalikan pengguna default (gagal login)
}