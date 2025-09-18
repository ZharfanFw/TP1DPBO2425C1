#include <bits/stdc++.h>
#include <iostream>
#include <pthread.h>
#include <vector>
#include "Laptop.cpp" // include class Laptop

using namespace std;

// Fungsi untuk mencari laptop berdasarkan ID
void searchLaptop(vector<Laptop> &inventory, string id) {
    size_t i = 0;
    bool found = false;

    // Loop hingga laptop ditemukan atau sampai akhir vector
    while (i < inventory.size() && !found) {
        if (inventory[i].getId() == id) {
            cout << "====================================================\n";
            cout << "---              DATA LAPTOP DITEMUKAN           ---\n";
            cout << "====================================================\n";
            cout << "|    ";
            inventory[i].showData(); // tampilkan data laptop
            cout << "====================================================\n\n";
            found = true;
        }
        i++;
    }

    // Jika tidak ditemukan
    if (!found) {
        cout << "====================================================\n";
        cout << "---     Laptop dengan ID " << id << " tidak ditemukan!     ---\n";
        cout << "====================================================\n\n";
    }
}

int main (){
    // Judul program / ASCII art
    cout <<
        "=====================================================================\n"
        "=====================================================================\n"
        "====    _           _        _ __  _____       _         _ __    ====\n"
        "====   | |    __ _ | | __ _ | '_ \\|_   _| ___ | |_  ___ | '_ \\   ====\n"
        "====   | |__ / _` || |/ _` || .__/  | |  / _ \\|  _|/ _ \\| .__/   ====\n"
        "====   |____|\\__/_||_|\\__/_||_|     |_|  \\___/ \\__|\\___/|_|      ====\n"
        "====                                                             ====\n"
        "=====================================================================\n"
        "=====================================================================\n\n";

    vector<Laptop> inventory; // vector untuk menyimpan semua laptop
    int kondisi; // variable untuk menyimpan pilihan menu user

    do {
        // Menampilkan menu
        cout <<
           "====================================================\n"
           "====================================================\n"
           "====                                            ====\n"
           "====                    Menu                    ====\n"
           "====      Untuk memilih opsi masukkan angka     ====\n"
           "====                                            ====\n"
           "====  1. Tambahkan Laptop ke list               ====\n"
           "====  2. Tampilkan list laptop yang tersedia    ====\n"
           "====  3. Modifikasi laptop di dalam list        ====\n"
           "====  4. Hapus laptop di dalam list             ====\n"
           "====  5. Cari laptop                            ====\n"
           "====                                            ====\n"
           "====                  (0)EXIT                   ====\n"
           "====                                            ====\n"
           "====================================================\n"
           "====================================================\n";
        cout << "| >>> Masukkan Opsi disini: "; 
        cin >> kondisi; // input pilihan
        cout << "\n";

        // =================== MENU 1 ===================
        if (kondisi == 1) {
            string id, nama;
            int harga, stok;

            // Header input data
            cout <<
               "====================================================\n"
               "---             MASUKKAN DATA LAPTOP             ---\n"
               "====================================================\n";

            // Input data laptop
            cout << "| >>> Masukkan ID: "; cin >> id;
            cout << "| >>> Masukkan Nama: "; cin.ignore(); getline(cin, nama);
            cout << "| >>> Masukkan Harga: "; cin >> harga;
            cout << "| >>> Masukkan Stok: "; cin >> stok;

            // Tambahkan laptop baru ke inventory
            inventory.push_back(Laptop(id, nama, harga, stok));

            // Konfirmasi berhasil
            cout << "====================================================\n";
            cout << "---       Data Laptop berhasil dimasukkan!       ---\n";
            cout << "====================================================\n\n\n";
            cout << "-----------------********************---------------\n";
            cout << "-----------------********************---------------\n\n\n";
        }
        // =================== MENU 2 ===================
        else if (kondisi == 2){
            cout << "====================================================\n"
                    "---                  LIST LAPTOP                 ---\n"
                    "====================================================\n";

            // Validasi jika inventory kosong
            if (inventory.empty()) {
                cout << "| >>> Belum ada data laptop dalam list!\n";
            } else {
                // Loop tampilkan semua laptop
                for (size_t i = 0; i < inventory.size(); i++) {
                    cout << "| ";
                    cout << i + 1 << ". ";
                    inventory[i].showData();
                }
            }

            cout << "====================================================\n\n";
            cout << "-----------------********************---------------\n";
            cout << "-----------------********************---------------\n\n\n";
        }
        // =================== MENU 3 ===================
        else if (kondisi == 3) {
            cout <<
                "====================================================\n"
                "---               UPDATE DATA LAPTOP             ---\n"
                "====================================================\n";

            string id;
            cout << "| >>> Masukkan ID Laptop yang akan diupdate: "; cin >> id;

            size_t i = 0;
            bool found = false;

            // Loop mencari laptop berdasarkan ID
            while (i < inventory.size() && !found) {
                if (inventory[i].getId() == id) {
                    string nama;
                    int harga, stok;

                    cout << "| >>> Masukkan Nama baru: ";
                    cin.ignore();
                    getline(cin, nama);

                    cout << "| >>> Masukkan Harga baru: ";
                    cin >> harga;

                    cout << "| >>> Masukkan Stok baru: ";
                    cin >> stok;

                    // Update data laptop
                    inventory[i].setNama(nama);
                    inventory[i].setHarga(harga);
                    inventory[i].setStok(stok);

                    found = true;
                }
                i++;
            }

            // Jika tidak ditemukan
            if (!found) {
                cout << "====================================================\n";
                cout << "---     Laptop dengan ID " << id << " tidak ditemukan!     ---\n";
                cout << "====================================================\n\n";
            } else {
                cout << "====================================================\n";
                cout << "---        Data Laptop berhasil diupdate!        ---\n";
                cout << "====================================================\n\n\n";
                cout << "-----------------********************---------------\n";
                cout << "-----------------********************---------------\n\n\n";
            }
        }
        // =================== MENU 4 ===================
        else if (kondisi == 4) {
            cout <<
                "====================================================\n"
                "---               HAPUS DATA LAPTOP              ---\n"
                "====================================================\n";

            string id;
            cout << "| >>> Masukkan ID laptop yang ingin dihapus: ";
            cin >> id;

            size_t i = 0;
            bool found = false;

            // Loop mencari laptop
            while (i < inventory.size() && !found) {
                if (inventory[i].getId() == id) {
                    inventory.erase(inventory.begin() + i); // hapus laptop

                    cout << "====================================================\n";
                    cout << "---         Data Laptop berhasil dihapus!        ---\n";
                    cout << "====================================================\n\n";
                    cout << "-----------------********************---------------\n";
                    cout << "-----------------********************---------------\n\n\n";

                    found = true;
                }
                i++;
            }

            if (!found) {
                cout << "====================================================\n";
                cout << "---     Laptop dengan ID " << id << " tidak ditemukan!     ---\n";
                cout << "====================================================\n\n";
            }
        }
        // =================== MENU 5 ===================
        else if (kondisi == 5) {
            cout <<
                "====================================================\n"
                "---               CARI DATA LAPTOP               ---\n"
                "====================================================\n";

            string id;
            cout << "| >>> Masukkan ID laptop yang ingin dicari: ";
            cin >> id;

            searchLaptop(inventory, id); // panggil fungsi search
        } 
        // =================== MENU 0 ===================
        else if (kondisi == 0) {
            cout <<
                "====================================================\n"
                "---                PROGRAM SELESAI               ---\n"
                "====================================================\n";
        }
        // =================== INPUT SALAH ===================
        else {
            cout <<
                "====================================================\n"
                "---              INPUT TIDAK VALID               ---\n"
                "====================================================\n\n\n";
        }

    } while (kondisi != 0); // loop hingga user pilih exit

    return 0;
}
