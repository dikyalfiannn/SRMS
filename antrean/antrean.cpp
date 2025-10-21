#include "antrean.h"
#include <iostream>
#include "../utils/utils.h" // Butuh bersihkanLayar, dll.

using namespace std;

// Ini adalah struktur Node untuk Linked List
struct Node {
    string idPasien;
    Node* next;
};

// Pointer untuk menandai 'kepala' dan 'ekor' antrean
Node* kepala = nullptr;
Node* ekor = nullptr;

// Implementasi ENQUEUE (Tambah di Ekor/Belakang)
void enqueue(string idPasien) {
    // 1. Buat node baru
    Node* nodeBaru = new Node;
    nodeBaru->idPasien = idPasien;
    nodeBaru->next = nullptr;

    // 2. Cek apakah antrean kosong
    if (ekor == nullptr) {
        kepala = nodeBaru;
        ekor = nodeBaru;
    } else {
        // 3. Sambungkan ekor lama ke node baru
        ekor->next = nodeBaru;
        // 4. Jadikan node baru sebagai ekor
        ekor = nodeBaru;
    }

    cout << "\nPasien dengan ID " << idPasien << " berhasil masuk antrean." << endl;
}

// Implementasi DEQUEUE (Hapus dari Kepala/Depan)
string dequeue() {
    // 1. Cek jika antrean kosong
    if (kepala == nullptr) {
        return "kosong";
    }

    // 2. Simpan data pasien yang akan dipanggil
    string idPasienDipanggil = kepala->idPasien;
    
    // 3. Simpan node kepala lama untuk dihapus
    Node* nodeHapus = kepala;

    // 4. Pindahkan 'kepala' ke node berikutnya
    kepala = kepala->next;

    // 5. Jika setelah dihapus antrean jadi kosong,
    //    pastikan 'ekor' juga jadi nullptr
    if (kepala == nullptr) {
        ekor = nullptr;
    }

    // 6. Hapus node kepala lama dari memori
    delete nodeHapus;

    // 7. Kembalikan ID pasien yang dipanggil
    return idPasienDipanggil;
}

// Implementasi DISPLAY (Melihat Daftar Antrean)
void displayAntrean() {
    bersihkanLayar();
    cout << "--- Daftar Antrean Pasien Saat Ini ---" << endl;

    if (kepala == nullptr) {
        cout << "Antrean kosong." << endl;
        return;
    }

    Node* penunjuk = kepala;
    int nomor = 1;

    cout << "DEPAN -> ";
    while (penunjuk != nullptr) {
        cout << "[" << nomor << ". " << penunjuk->idPasien << "] -> ";
        penunjuk = penunjuk->next;
        nomor++;
    }
    cout << "BELAKANG" << endl;
}