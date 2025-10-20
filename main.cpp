#include <iostream>
#include <string>

// Panggil "daftar isi" (.h) dari SEMUA modul
#include "utils/utils.h"
#include "login/login.h"
#include "admin/admin.h"
#include "dokter/dokter.h"
#include "perawat/perawat.h"
#include "apoteker/apoteker.h"
#include "pasien/pasien.h"

using namespace std;

int main() {
    // 1. Buat data awal (bikin file .txt)
    buatDataAwal();

    // 2. Loop utama program
    while (true) {
        bersihkanLayar();
        
        // 3. Tampilkan Halaman Login
        Pengguna penggunaSaatIni = halamanLogin(); 

        // 4. Cek apakah login berhasil
        if (penggunaSaatIni.sudahLogin) {
            
            // 5. Arahkan ke Menu yang Sesuai (Otorisasi)
            
            if (penggunaSaatIni.peran == "ADMIN") {
                tampilkanMenuAdmin(penggunaSaatIni);
            } else if (penggunaSaatIni.peran == "DOKTER") {
                tampilkanMenuDokter(penggunaSaatIni);
            } else if (penggunaSaatIni.peran == "PERAWAT") {
                tampilkanMenuPerawat(penggunaSaatIni);
            } else if (penggunaSaatIni.peran == "APOTEKER") {
                tampilkanMenuApoteker(penggunaSaatIni);
            } else if (penggunaSaatIni.peran == "PASIEN") {
                tampilkanMenuPasien(penggunaSaatIni);
            } else {
                cout << "Error: Peran tidak dikenal!" << endl;
                tekanEnterUntukLanjut();
            }

            // 6. Logout
            // Setelah fungsi menu (misal: tampilkanMenuAdmin) selesai,
            // itu artinya user memilih 'Logout'.
            // Program akan kembali ke 'while (true)' dan menampilkan
            // halaman login lagi.
        }
    }

    return 0;
}