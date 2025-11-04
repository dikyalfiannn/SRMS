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

### Minggu 5: Circular Linked List (Jadwal Piket)
Menambahkan materi **Circular Linked List** untuk mengelola jadwal piket dokter (Round-Robin).

* **File Baru**: `jadwalpiket/` (modul baru).
* **File Update**: `resepsionis/resepsionis.cpp`, `.vscode/tasks.json`.
* **Kegunaan**:
    * Membuat modul `jadwalpiket/` yang berisi logika **Circular Linked List**.
    * Fitur ini dipanggil dari menu Resepsionis.
    * Saat "Tambah Pasien ke Antrean", program otomatis memanggil CLL (`tugaskanDokterBerikutnya()`) untuk membagi pasien ke dokter piket secara bergiliran (Round-Robin).
    * `displayJadwalPiket()` digunakan untuk melihat putaran piket.

### Minggu 3: Singly Linked List (Queue/Antrean)
Menambahkan materi **Singly Linked List** untuk mengelola antrean pasien (FIFO).

* **File Baru**: `antrean/` (modul baru), `resepsionis/` (role baru).
* **File Update**: `main.cpp`, `login/login.cpp`, `perawat/perawat.cpp`.
* **Kegunaan**:
    * Membuat modul `antrean/` (Singly Linked List) untuk **Antrean Pasien (FIFO)**.
    * Menambahkan role baru **Resepsionis** sebagai "pintu masuk" RS.
    * Resepsionis sekarang bertanggung jawab penuh atas antrean:
        1.  **`enqueue`**: Menambah pasien ke `tail` (belakang) antrean.
        2.  **`dequeue`**: Mengambil pasien dari `head` (depan) antrean.
        3.  **`display`**: Menampilkan semua isi antrean.

### Minggu 2: Demo Array Statis
Menambahkan demo materi **Array Statis** di menu Pasien dan Apoteker.

* **`pasien/pasien.cpp`**: Implementasi **Array Statis** (C-style `string[4]`) untuk 4 Tanda Vital.
* **`apoteker/apoteker.cpp`**: (Revisi) Demo yang tadinya `std::vector` diubah menjadi **Array Statis** (C-style `string[100]`) untuk Keranjang Resep, agar sesuai arahan (tanpa library modern).

### Minggu 1: Setup Awal, CRUD, & File I/O
* Setup struktur proyek multi-folder (satu folder per peran).
* Konfigurasi `.vscode/tasks.json` dan `launch.json` untuk compile (`F5`).
* Fitur login dasar (baca `users.txt`) dan `buatDataAwal()`.
* Fitur Admin (CRUD Dokter, Pasien, Obat, Akun) selesai.
* Fitur Dokter (Tulis Diagnosa) selesai.
* Perbaikan bug input buffer (`cin.ignore`) dan bug layar `cls`.
* (Revisi) Logika `pecahString` diubah ke manual (tanpa `<sstream>`) dan logika `remove/rename` diubah ke `<cstdio>` (tanpa `<filesystem>`).