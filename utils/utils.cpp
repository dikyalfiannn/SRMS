#include "utils.h"
#include <sstream> // Untuk stringstream
#include <limits>  // Untuk batas numerik

using namespace std;

// Implementasi fungsi pecahString
vector<string> pecahString(const string& s, char pemisah) {
    vector<string> hasil;
    string bagian;
    istringstream aliranString(s);
    while (getline(aliranString, bagian, pemisah)) {
        hasil.push_back(bagian);
    }
    return hasil;
}

// Implementasi fungsi bersihkanLayar
// Implementasi fungsi bersihkanLayar
void bersihkanLayar() {
    // system("cls"); // Perintah "cls" sering error di terminal VS Code
    
    // Gunakan ANSI escape code sebagai gantinya
    // \033[2J membersihkan seluruh layar
    // \033[1;1H memindahkan kursor ke baris 1, kolom 1
    cout << "\033[2J\033[1;1H" << flush;
}

// Implementasi fungsi bersihkanInputBuffer
// Implementasi fungsi bersihkanInputBuffer
void bersihkanInputBuffer() {
    // Cek jika 'cin' dalam status error
    // (Misal: user mengetik 'a' saat diminta angka)
    if (cin.fail()) {
        cin.clear(); // Menghapus status error
    }

    // Buang semua sisa karakter di buffer 
    // sampai ketemu baris baru ('\n')
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Implementasi fungsi tekanEnterUntukLanjut
// Implementasi fungsi tekanEnterUntukLanjut
// Implementasi fungsi tekanEnterUntukLanjut
void tekanEnterUntukLanjut() {
    cout << "\nTekan Enter untuk melanjutkan...";

    // Fungsi ini dipanggil setelah login gagal (dimana buffer
    // harusnya sudah bersih) ATAU setelah menu default (dimana
    // buffer mungkin kotor).
    
    // Panggilan ini akan membersihkan sisa 'junk' JIKA ADA,
    // ATAU akan MENUNGGU user menekan Enter jika buffer kosong.
    // Ini menyelesaikan kedua masalah.
    bersihkanInputBuffer();
}