#pragma once
#include <iostream>
#include <string>

struct Pengguna {
    std::string namaPengguna;
    std::string peran;
    bool sudahLogin;
};

int pecahString(const std::string& s, char pemisah, std::string hasil[], int maxUkuran);
void bersihkanLayar();
void tekanEnterUntukLanjut();
void bersihkanInputBuffer();