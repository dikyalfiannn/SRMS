#pragma once
#include <string>

void initStokBaju();
void pushBaju(std::string jenisBaju);
std::string popBaju();
void displayStackBaju();
// isStackBajuKosong() tidak perlu lagi di-declare jika kita hanya pakai satu file