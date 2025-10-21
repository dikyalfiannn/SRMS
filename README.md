# Proyek Sistem Manajemen RS (C++)

Tugas proyek C++ untuk mata kuliah Struktur Data. Program ini adalah sistem manajemen RS sederhana ("RS SLAMET") yang pakai file `.txt` sebagai database.

## Fitur Utama
* Login multi-peran (Admin, Dokter, Pasien, Apoteker, Perawat, Resepsionis).
* Menu Admin: CRUD penuh (Tambah, Lihat, Ubah, Hapus) untuk data Dokter, Pasien, dan Obat.
* Menu Admin: Menambah dan melihat akun pengguna (file `users.txt`).
* Menu Dokter: Melihat pasien dan menulis/update diagnosa.
* Menu Resepsionis: Mendaftar pasien baru, dan mengelola antrean (Linked List).

## Cara Pakai (via VS Code)
1.  Pastikan sudah install MinGW (g++) dan ada di PATH.
2.  Clone repo ini.
3.  Buka folder di VS Code.
4.  Tekan **F5**.

Program akan otomatis compile (`rumahsakit.exe`) dan jalan di terminal.

## Akun Login Awal (dari `users.txt`)
* **Admin:** `admin` / `admin123`
* **Dokter:** `drbudi` / `dokter1`
* **Resepsionis:** `resepsionis` / `resepsionis123`
* **Perawat:** `susterani` / `perawat1`
* **Apoteker:** `aptbudi` / `apoteker1`
* **Pasien:** `pasienono` / `pasien1`

---

## Catatan Perkembangan (Tugas Mingguan)

Catatan materi kuliah yang sudah diimplementasikan di proyek ini.

### Minggu 3: Linked List (Queue/Antrean)
Menambahkan materi **Linked List** untuk mengelola antrean pasien.

* **File Baru**: `antrean/` (modul baru), `resepsionis/` (role baru).
* **File Update**: `main.cpp`, `login/login.cpp`, `perawat/perawat.cpp`, `.vscode/tasks.json`.
* **Kegunaan**:
    * Membuat modul `antrean/` yang berisi logika **Singly Linked List** sebagai "mesin" Queue (Antrean).
    * Menambahkan role baru **Resepsionis** sebagai "pintu masuk" RS.
    * Resepsionis sekarang bertanggung jawab penuh atas antrean:
        1.  **`enqueue` (Tambah Antrean):** Menambah pasien ke `tail` (belakang) Linked List.
        2.  **`dequeue` (Panggil Antrean):** Mengambil pasien dari `head` (depan) Linked List.
        3.  **`display` (Lihat Antrean):** Menampilkan semua *node* di Linked List.

### Minggu 2: Array Statis & Dinamis
Menambahkan demo materi array di menu Pasien dan Apoteker.

* **Array Statis**:
    * **File**: `pasien/pasien.cpp` (Menu Pasien -> Pilihan 2)
    * **Fungsi**: `demoArrayStatis_CatatTandaVital()`
    * **Kegunaan**: Demo array C-style (`string namaTandaVital[4]`) yang ukurannya **tetap**. Dipakai untuk data yang jumlahnya sudah pasti.

* **Array Dinamis (`std::vector`)**:
    * **File**: `apoteker/apoteker.cpp` (Menu Apoteker -> Pilihan 3)
    * **Fungsi**: `demoArrayDinamis_KeranjangObat()`
    * **Kegunaan**: Demo `vector` C++ yang ukurannya **fleksibel**. Dipakai untuk data yang jumlahnya tidak pasti dan bisa ditambah terus (`.push_back()`).

### Minggu 1: Setup Awal, CRUD, & File I/O
* Setup struktur proyek multi-folder (satu folder per peran).
* Konfigurasi `.vscode/tasks.json` dan `launch.json` untuk compile (`F5`).
* Fitur login dasar (baca `users.txt`) dan `buatDataAwal()`.
* Fitur Admin (CRUD Dokter, Pasien, Obat, Akun) selesai.
* Fitur Dokter (Tulis Diagnosa) selesai.
* Perbaikan bug input buffer (`cin.ignore`) dan bug layar `cls`.