public class Laptop {
    private String id;
    private String nama;
    private int harga;
    private int stok;

    // Constructor
    public Laptop(String id, String nama, int harga, int stok) {
        this.id = id;
        this.nama = nama;
        this.harga = harga;
        this.stok = stok;
    }

    // Getter & Setter
    public String getId() {
        return id;
    }

    public void setId(String id) {
        this.id = id;
    }

    public String getNama() {
        return nama;
    }

    public void setNama(String nama) {
        this.nama = nama;
    }

    public int getHarga() {
        return harga;
    }

    public void setHarga(int harga) {
        if (harga >= 0) {
            this.harga = harga;
        }
    }

    public int getStok() {
        return stok;
    }

    public void setStok(int stok) {
        this.stok = stok;
    }

    public void showData() {
        System.out.println("ID   : " + id);
        System.out.println("|    Nama : " + nama);
        System.out.println("|    Harga: " + harga);
        System.out.println("|    Stok : " + stok);
    }
}
