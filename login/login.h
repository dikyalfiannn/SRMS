#pragma once
#include <string>
#include "../utils/utils.h" // Butuh struct Pengguna

// Fungsi untuk 'seeding' data awal jika file .txt tidak ada
void buatDataAwal();

// Menampilkan halaman login dan memvalidasi
Pengguna halamanLogin();