#include "jadwalpiket.h"
#include <iostream>
#include "../utils/utils.h"

using namespace std;

// === TANDA LINKED LIST ===
// Struktur Node untuk Circular Linked List
struct NodePiket {
    string namaDokter;
    NodePiket* next;
};

// === TANDA LINKED LIST ===
// Pointer 'head' untuk awal & 'current' untuk giliran
NodePiket* head = nullptr;
NodePiket* current = nullptr;

// === TANDA LINKED LIST ===
// OPERASI CIRCULAR LINKED LIST: Inisialisasi
void initJadwalPiket() {
    // 1. Buat 3 node dokter
    NodePiket* dokter1 = new NodePiket;
    dokter1->namaDokter = "Dr. Budi (Piket)";

    NodePiket* dokter2 = new NodePiket;
    dokter2->namaDokter = "Dr. Ani (Piket)";

    NodePiket* dokter3 = new NodePiket;
    dokter3->namaDokter = "Dr. Guntur (Piket)";

    // 2. Sambungkan node-node
    dokter1->next = dokter2;
    dokter2->next = dokter3;
    
    // === TANDA LINKED LIST ===
    // 3. Sambungkan node terakhir kembali ke node pertama
    dokter3->next = dokter1; // <-- Ini yang bikin jadi CIRCULAR

    // 4. Set pointer utama
    head = dokter1;
    current = head; 
}

// === TANDA LINKED LIST ===
// OPERASI CIRCULAR LINKED LIST: Round-Robin (Advance Pointer)
string tugaskanDokterBerikutnya() {
    // Jika jadwal belum dibuat, buat dulu
    if (head == nullptr) {
        initJadwalPiket();
    }

    // 1. Ambil nama dokter yang piket sekarang
    string namaDokterPiket = current->namaDokter;

    // 2. Pindahkan pointer piket ke dokter berikutnya
    //    (Ini aman karena list-nya circular, tidak akan pernah nullptr)
    current = current->next;

    // 3. Kembalikan nama dokter
    return namaDokterPiket;
}

// === TANDA LINKED LIST ===
// OPERASI CIRCULAR LINKED LIST: Display (Traverse)
void displayJadwalPiket() {
    bersihkanLayar();
    cout << "--- Daftar Piket Dokter (Round-Robin) ---" << endl;

    if (head == nullptr) {
        initJadwalPiket();
    }

    // 1. Buat pointer sementara
    NodePiket* penunjuk = head;

    cout << "MULAI -> ";
    // 2. Gunakan loop do-while agar node pertama tercetak
    do {
        cout << "[" << penunjuk->namaDokter << "] -> ";
        // 3. Majukan penunjuk
        penunjuk = penunjuk->next;
    } while (penunjuk != head); // 4. Loop sampai kembali lagi ke head

    cout << "KEMBALI KE AWAL" << endl;
}