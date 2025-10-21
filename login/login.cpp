#include "login.h"
#include <iostream>
#include <fstream> 
#include <vector>

#include "../utils/utils.h"

using namespace std;

void periksaDanBuatFile(const string& namaFile, const string& isiDefault) {
    ifstream berkas(namaFile);
    if (!berkas.good()) { 
        berkas.close();
        ofstream berkasKeluar(namaFile);
        berkasKeluar << isiDefault;
        berkasKeluar.close();
    }
    berkas.close();
}


// Implementasi fungsi seeding data
void buatDataAwal() {
    // Skema: namaPengguna|kataSandi|peran
    periksaDanBuatFile("users.txt",
        "admin|admin123|ADMIN\n"
        "drbudi|dokter1|DOKTER\n"
        "susterani|perawat1|PERAWAT\n"
        "aptbudi|apoteker1|APOTEKER\n"
        "pasienono|pasien1|PASIEN\n"
        "resepsionis|resepsionis123|RESEPSIONIS\n" // <-- BARU
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

    // Skema: id|nama_obat|stok|harga
    periksaDanBuatFile("data_obat.txt", 
        "OB001|Paracetamol|100|5000\n"
        "OB002|Amoxicillin|50|15000\n"
    );
}


Pengguna halamanLogin() {
    Pengguna pengguna = {"", "", false}; 
    string inputNama, inputSandi;

    cout << "========================================" << endl;
    cout << "   SELAT DATANG DI SISTEM RS SLAMET" << endl;
    cout << "========================================" << endl;
    cout << "Silakan login:" << endl;
    
    cout << "Username: " << flush; 
    getline(cin, inputNama);
    
    cout << "Password: " << flush; 
    getline(cin, inputSandi);

    ifstream berkas("users.txt");
    string baris;

    if (!berkas.is_open()) {
        cout << "Error: Gagal membuka file users.txt!" << endl;
        return pengguna;
    }

    while (getline(berkas, baris)) {
        vector<string> dataPengguna = pecahString(baris, '|'); 

        if (dataPengguna.size() == 3) {
            string namaTersimpan = dataPengguna[0];
            string sandiTersimpan = dataPengguna[1];
            string peranTersimpan = dataPengguna[2];

            if (inputNama == namaTersimpan && inputSandi == sandiTersimpan) {
                pengguna.namaPengguna = namaTersimpan;
                pengguna.peran = peranTersimpan;
                pengguna.sudahLogin = true;
                berkas.close();
                return pengguna; 
            }
        }
    }

    berkas.close();
    
    bersihkanLayar();
    cout << "Login Gagal! Username atau Password salah." << endl;
    tekanEnterUntukLanjut();
    return pengguna; 
}