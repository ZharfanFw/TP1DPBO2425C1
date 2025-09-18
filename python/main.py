from laptop import Laptop


def search_laptop(inventory, id):
    found = False
    for laptop in inventory:
        if laptop.id == id:
            print("=" * 52)
            print("---              DATA LAPTOP DITEMUKAN           ---")
            print("=" * 52)
            laptop.show_data()
            print("=" * 52 + "\n")
            found = True
            break
    if not found:
        print("=" * 52)
        print(f"---     Laptop dengan ID {id} tidak ditemukan!     ---")
        print("=" * 52 + "\n")


def main():
    inventory = []

    print("=" * 69)
    print("=" * 69)
    print("====    _           _        _ __  _____       _         _ __    ====")
    print("====   | |    __ _ | | __ _ | '_ \\|_   _| ___ | |_  ___ | '_ \\   ====")
    print("====   | |__ / _` || |/ _` || .__/  | |  / _ \\|  _|/ _ \\| .__/   ====")
    print("====   |____|\\__/_||_|\\__/_||_|     |_|  \\___/ \\__|\\___/|_|      ====")
    print("====                                                             ====")
    print("=" * 69)
    print("=" * 69 + "\n")

    while True:
        print("=" * 52)
        print("====                    Menu                    ====")
        print("====  1. Tambahkan Laptop ke list               ====")
        print("====  2. Tampilkan list laptop yang tersedia    ====")
        print("====  3. Modifikasi laptop di dalam list        ====")
        print("====  4. Hapus laptop di dalam list             ====")
        print("====  5. Cari laptop                            ====")
        print("====                  (0)EXIT                   ====")
        print("=" * 52)
        kondisi = input("| >>> Masukkan Opsi disini: ").strip()
        print()

        if kondisi == "1":
            print("=" * 52)
            print("---             MASUKKAN DATA LAPTOP             ---")
            print("=" * 52)
            id = input("| >>> Masukkan ID: ").strip()
            nama = input("| >>> Masukkan Nama: ").strip()
            harga = int(input("| >>> Masukkan Harga: ").strip())
            stok = int(input("| >>> Masukkan Stok: ").strip())
            inventory.append(Laptop(id, nama, harga, stok))
            print("=" * 52)
            print("---       Data Laptop berhasil dimasukkan!       ---")
            print("=" * 52 + "\n")

        elif kondisi == "2":
            print("=" * 52)
            print("---                  LIST LAPTOP                 ---")
            print("=" * 52)
            if not inventory:
                print("| >>> Belum ada data laptop dalam list!")
            else:
                for idx, laptop in enumerate(inventory, 1):
                    print(f"| {idx}. ", end="")
                    laptop.show_data()
            print("=" * 52 + "\n")

        elif kondisi == "3":
            id = input("| >>> Masukkan ID Laptop yang akan diupdate: ").strip()
            found = False
            for laptop in inventory:
                if laptop.id == id:
                    nama = input("| >>> Masukkan Nama baru: ").strip()
                    harga = int(input("| >>> Masukkan Harga baru: ").strip())
                    stok = int(input("| >>> Masukkan Stok baru: ").strip())
                    laptop.nama = nama
                    laptop.harga = harga
                    laptop.stok = stok
                    found = True
                    print("=" * 52)
                    print("---        Data Laptop berhasil diupdate!        ---")
                    print("=" * 52 + "\n")
                    break
            if not found:
                print("=" * 52)
                print(f"---     Laptop dengan ID {id} tidak ditemukan!     ---")
                print("=" * 52 + "\n")

        elif kondisi == "4":
            id = input("| >>> Masukkan ID laptop yang ingin dihapus: ").strip()
            removed = False
            for laptop in inventory:
                if laptop.id == id:
                    inventory.remove(laptop)
                    removed = True
                    print("=" * 52)
                    print("---         Data Laptop berhasil dihapus!        ---")
                    print("=" * 52 + "\n")
                    break
            if not removed:
                print("=" * 52)
                print(f"---     Laptop dengan ID {id} tidak ditemukan!     ---")
                print("=" * 52 + "\n")

        elif kondisi == "5":
            id = input("| >>> Masukkan ID laptop yang ingin dicari: ").strip()
            search_laptop(inventory, id)

        elif kondisi == "0":
            print("=" * 52)
            print("---                PROGRAM SELESAI               ---")
            print("=" * 52 + "\n")
            break

        else:
            print("=" * 52)
            print("---              INPUT TIDAK VALID               ---")
            print("=" * 52 + "\n")


if __name__ == "__main__":
    main()
