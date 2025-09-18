#include <iostream>
#include <string>
using namespace std;

class Laptop{
private:
  string id;
  string nama;
  int harga;
  int stok;

public:
  // Constructor untuk instansiasi
  Laptop(string id, string nama, int harga, int stok) {
    this->id = id;
    this->nama = nama;
    this->harga = harga;
    this->stok = stok;
  }

  // Getter id & Setter nama
  string getId() {
    return id;
  }

  void setId(string id) {
    this->id = id;
  }

  // Getter nama & Setter nama
  string getNama() {
    return nama;
  }

  void setNama(string nama) {
    this->nama = nama;
  }

  // Getter harga & Setter harga
  int getHarga() {
    return harga;
  } 

  void setHarga(int harga) {
    if (harga >= 0) {
      this->harga = harga;
    }
  }

  // Getter stok
  int getStok() {
    return stok;
  }

  void setStok(int stok) {
    this->stok = stok;
  }

  void showData() {
    cout << "ID   : " << id   << "\n"
         << "|    Nama : " << nama << "\n"
         << "|    Harga: " << harga << "\n"
         << "|    Stok : " << stok << "\n";
}

  // Destruktor
  ~Laptop() {}
};
