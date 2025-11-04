#include "utils.h"

using namespace std;

int pecahString(const std::string& s, char pemisah, std::string hasil[], int maxUkuran) {
    string bagian = "";
    int i = 0;

    for (size_t c = 0; c < s.length(); ++c) {
        if (s[c] != pemisah) {
            bagian += s[c];
        } else {
            if (i < maxUkuran) {
                hasil[i] = bagian;
                i++;
            }
            bagian = "";
            if (i >= maxUkuran) {
                break;
            }
        }
    }

    if (i < maxUkuran) {
        hasil[i] = bagian;
        i++;
    }

    return i;
}

void bersihkanLayar() {
    cout << "\033[2J\033[1;1H" << flush;
}

void bersihkanInputBuffer() {
    if (cin.fail()) {
        cin.clear(); 
    }
    cin.ignore(10000, '\n');
}

void tekanEnterUntukLanjut() {
    cout << "\nTekan Enter untuk melanjutkan...";
    bersihkanInputBuffer();
}