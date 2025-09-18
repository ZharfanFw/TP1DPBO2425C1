class Laptop:
    def __init__(self, id, nama, harga, stok):
        self.id = id
        self.nama = nama
        self.harga = harga
        self.stok = stok

    def show_data(self):
        print(f"ID   : {self.id}")
        print(f"|    Nama : {self.nama}")
        print(f"|    Harga: {self.harga}")
        print(f"|    Stok : {self.stok}")
