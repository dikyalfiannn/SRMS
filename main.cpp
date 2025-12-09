#include <iostream>
#include <string>

#include "utils/utils.h"
#include "login/login.h"
#include "admin/admin.h"
#include "dokter/dokter.h"
#include "perawat/perawat.h"
#include "apoteker/apoteker.h"
#include "pasien/pasien.h"
#include "resepsionis/resepsionis.h" 
#include "stokbaju/stokbaju.h"

using namespace std;

int main() {
    buatDataAwal();

    while (true) {
        bersihkanLayar();
        
        Pengguna penggunaSaatIni = halamanLogin(); 

        if (penggunaSaatIni.sudahLogin) {
            
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
            } else if (penggunaSaatIni.peran == "RESEPSIONIS") { 
                tampilkanMenuResepsionis(penggunaSaatIni);
            } else {
                cout << "Error: Peran tidak dikenal!" << endl;
                tekanEnterUntukLanjut();
            }
        }
    }

    return 0;
}