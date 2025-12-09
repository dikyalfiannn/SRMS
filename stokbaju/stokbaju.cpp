#include "stokbaju.h"
#include <iostream>
#include <string> // Pastikan string di-include
#include "../utils/utils.h"

using namespace std;

// === PERUBAHAN UTAMA: IMPLEMENTASI STACK MENGGUNAKAN ARRAY ===

// Ukuran maksimum Stack Baju (Array Statis)
const int MAX_BAJU = 100;

// Array untuk menyimpan data baju
string keranjangBaju[MAX_BAJU];

// Variabel 'puncak' (top) bertindak sebagai INDEKS elemen paling atas
// Jika tumpukan kosong, nilainya -1
int puncak = -1; 

// === OPERASI STACK ===

void initStokBaju() {
    // Reset puncak ke -1 (Stack kosong)
    puncak = -1; 
}

// OPERASI STACK: Push (Memasukkan Baju ke Puncak Array)
void pushBaju(string jenisBaju) {
    // 1. Cek apakah Stack sudah penuh (Stack Overflow)
    if (puncak >= MAX_BAJU - 1) {
        cout << "\n[GAGAL] Tumpukan baju sudah penuh (Maks " << MAX_BAJU << " baju)." << endl;
        return;
    }

    // 2. Naikkan indeks puncak
    puncak++;
    
    // 3. Masukkan data ke array di posisi puncak yang baru
    keranjangBaju[puncak] = jenisBaju;

    cout << "\nBaju '" << jenisBaju << "' berhasil dimasukkan ke tumpukan (Stack) di indeks " << puncak << "." << endl;
}

// OPERASI STACK: Pop (Mengambil Baju dari Puncak Array)
string popBaju() {
    // 1. Cek apakah Stack kosong (Stack Underflow)
    if (puncak == -1) {
        return "kosong";
    }

    // 2. Ambil data dari posisi puncak saat ini
    string bajuDiambil = keranjangBaju[puncak];
    
    // 3. Turunkan indeks puncak (Data lama masih ada di array, tapi tidak bisa diakses lagi)
    puncak--;

    // 4. Kembalikan nama baju yang diambil
    return bajuDiambil;
}

// OPERASI STACK: Display (Menampilkan dari Puncak ke Dasar)
void displayStackBaju() {
    bersihkanLayar();
    cout << "--- Daftar Tumpukan Baju Medis (STACK LIFO / Array) ---" << endl;

    // Cek apakah Stack kosong
    if (puncak == -1) {
        cout << "Tumpukan baju kosong." << endl;
        return;
    }

    cout << "Ukuran Tumpukan Saat Ini: " << puncak + 1 << " / " << MAX_BAJU << endl;
    cout << string(40, '-') << endl;

    // Loop dari Puncak (indeks tertinggi) sampai 0 (dasar)
    for (int i = puncak; i >= 0; i--) {
        if (i == puncak) {
             cout << "[PUNCAK] -> ";
        } else {
             cout << "         ";
        }
        cout << "[" << i << "] " << keranjangBaju[i] << endl;
    }
    cout << string(40, '-') << endl;
    cout << "DASAR" << endl;
}
