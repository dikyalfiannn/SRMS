#pragma once
#include <iostream>
#include <string>
#include <vector>

// Struct untuk menyimpan data pengguna yang login
struct Pengguna {
    std::string namaPengguna;
    std::string peran;
    bool sudahLogin;
};

// --- Deklarasi Fungsi Pembantu ---

// Memecah string pakai pemisah (delimiter)
std::vector<std::string> pecahString(const std::string& s, char pemisah);

// Membersihkan layar konsol
void bersihkanLayar();

// Jeda program, tunggu user tekan Enter
void tekanEnterUntukLanjut();

// Membersihkan sisa input di buffer
void bersihkanInputBuffer();