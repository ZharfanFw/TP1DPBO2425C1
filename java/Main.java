import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    // Fungsi search
    public static void searchLaptop(ArrayList<Laptop> inventory, String id) {
        boolean found = false;

        for (Laptop l : inventory) {
            if (l.getId().equals(id)) {
                System.out.println("====================================================");
                System.out.println("---              DATA LAPTOP DITEMUKAN           ---");
                System.out.println("====================================================");
                l.showData();
                System.out.println("====================================================\n");
                found = true;
                break;
            }
        }

        if (!found) {
            System.out.println("====================================================");
            System.out.println("---     Laptop dengan ID " + id + " tidak ditemukan!     ---");
            System.out.println("====================================================\n");
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        ArrayList<Laptop> inventory = new ArrayList<>();
        int kondisi;

        System.out.println("=====================================================================");
        System.out.println("=====================================================================");
        System.out.println("====    _           _        _ __  _____       _         _ __    ====");
        System.out.println("====   | |    __ _ | | __ _ | '_ \\|_   _| ___ | |_  ___ | '_ \\   ====");
        System.out.println("====   | |__ / _` || |/ _` || .__/  | |  / _ \\|  _|/ _ \\| .__/   ====");
        System.out.println("====   |____|\\__/_||_|\\__/_||_|     |_|  \\___/ \\__|\\___/|_|      ====");
        System.out.println("====                                                             ====");
        System.out.println("=====================================================================");
        System.out.println("=====================================================================\n");

        do {
            System.out.println("====================================================");
            System.out.println("====                    Menu                    ====");
            System.out.println("====  1. Tambahkan Laptop ke list               ====");
            System.out.println("====  2. Tampilkan list laptop yang tersedia    ====");
            System.out.println("====  3. Modifikasi laptop di dalam list        ====");
            System.out.println("====  4. Hapus laptop di dalam list             ====");
            System.out.println("====  5. Cari laptop                            ====");
            System.out.println("====                  (0)EXIT                   ====");
            System.out.println("====================================================");
            System.out.print("| >>> Masukkan Opsi disini: ");
            kondisi = sc.nextInt();
            sc.nextLine(); // clear buffer

            if (kondisi == 1) {
                System.out.println("====================================================");
                System.out.println("---             MASUKKAN DATA LAPTOP             ---");
                System.out.println("====================================================");

                System.out.print("| >>> Masukkan ID: ");
                String id = sc.nextLine();
                System.out.print("| >>> Masukkan Nama: ");
                String nama = sc.nextLine();
                System.out.print("| >>> Masukkan Harga: ");
                int harga = sc.nextInt();
                System.out.print("| >>> Masukkan Stok: ");
                int stok = sc.nextInt();
                sc.nextLine();

                inventory.add(new Laptop(id, nama, harga, stok));
                System.out.println("====================================================");
                System.out.println("---       Data Laptop berhasil dimasukkan!       ---");
                System.out.println("====================================================\n");
            } 
            else if (kondisi == 2) {
                System.out.println("====================================================");
                System.out.println("---                  LIST LAPTOP                 ---");
                System.out.println("====================================================");

                if (inventory.isEmpty()) {
                    System.out.println("| >>> Belum ada data laptop dalam list!");
                } else {
                    for (int i = 0; i < inventory.size(); i++) {
                        System.out.print("| " + (i + 1) + ". ");
                        inventory.get(i).showData();
                    }
                }
                System.out.println("====================================================\n");
            } 
            else if (kondisi == 3) {
                System.out.print("| >>> Masukkan ID Laptop yang akan diupdate: ");
                String id = sc.nextLine();

                boolean found = false;
                for (Laptop l : inventory) {
                    if (l.getId().equals(id)) {
                        System.out.print("| >>> Masukkan Nama baru: ");
                        String nama = sc.nextLine();
                        System.out.print("| >>> Masukkan Harga baru: ");
                        int harga = sc.nextInt();
                        System.out.print("| >>> Masukkan Stok baru: ");
                        int stok = sc.nextInt();
                        sc.nextLine();

                        l.setNama(nama);
                        l.setHarga(harga);
                        l.setStok(stok);
                        found = true;
                        System.out.println("====================================================");
                        System.out.println("---        Data Laptop berhasil diupdate!        ---");
                        System.out.println("====================================================\n");
                        break;
                    }
                }
                if (!found) {
                    System.out.println("Laptop dengan ID " + id + " tidak ditemukan!\n");
                }
            } 
            else if (kondisi == 4) {
                System.out.print("| >>> Masukkan ID laptop yang ingin dihapus: ");
                String id = sc.nextLine();

                boolean removed = inventory.removeIf(l -> l.getId().equals(id));

                if (removed) {
                    System.out.println("====================================================");
                    System.out.println("---         Data Laptop berhasil dihapus!        ---");
                    System.out.println("====================================================\n");
                } else {
                    System.out.println("Laptop dengan ID " + id + " tidak ditemukan!\n");
                }
            } 
            else if (kondisi == 5) {
                System.out.print("| >>> Masukkan ID laptop yang ingin dicari: ");
                String id = sc.nextLine();
                searchLaptop(inventory, id);
            } 
            else if (kondisi == 0) {
                System.out.println("====================================================");
                System.out.println("---                PROGRAM SELESAI               ---");
                System.out.println("====================================================");
            } 
            else {
                System.out.println("====================================================");
                System.out.println("---              INPUT TIDAK VALID               ---");
                System.out.println("====================================================\n");
            }
        } while (kondisi != 0);

        sc.close();
    }
}
