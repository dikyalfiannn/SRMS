#include "utils.h"
#include <sstream> 
#include <limits> 

using namespace std;


vector<string> pecahString(const string& s, char pemisah) {
    vector<string> hasil;
    string bagian;
    istringstream aliranString(s);
    while (getline(aliranString, bagian, pemisah)) {
        hasil.push_back(bagian);
    }
    return hasil;
}


void bersihkanLayar() {
    cout << "\033[2J\033[1;1H" << flush;
}


void bersihkanInputBuffer() {
    if (cin.fail()) {
        cin.clear(); 
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}


void tekanEnterUntukLanjut() {
    cout << "\nTekan Enter untuk melanjutkan...";
    bersihkanInputBuffer();
}