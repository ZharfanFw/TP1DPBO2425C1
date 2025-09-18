<?php
session_start();

// Initialize inventory if not already
if (!isset($_SESSION['inventory'])) {
    $_SESSION['inventory'] = [];
}

// Handle form submission
if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    $id = $_POST['id'] ?? '';
    $nama = $_POST['nama'] ?? '';
    $harga = $_POST['harga'] ?? '';
    $stok = $_POST['stok'] ?? '';

    if ($id && $nama && is_numeric($harga) && is_numeric($stok)) {
        $_SESSION['inventory'][] = [
            'id' => $id,
            'nama' => $nama,
            'harga' => (int)$harga,
            'stok' => (int)$stok
        ];
        $message = "Laptop berhasil ditambahkan!";
    } else {
        $message = "Isi semua field dengan benar!";
    }
}
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Inventory Laptop</title>
    <style>
        body { font-family: Arial, sans-serif; padding: 20px; }
        table { border-collapse: collapse; width: 100%; margin-top: 20px; }
        th, td { border: 1px solid #333; padding: 8px; text-align: left; }
        th { background-color: #f2f2f2; }
        input[type=text], input[type=number] { width: 100%; padding: 6px; margin: 4px 0; }
        input[type=submit] { padding: 8px 16px; margin-top: 10px; }
        .message { margin: 10px 0; color: green; }
    </style>
</head>
<body>
    <h1>Inventory Laptop</h1>

    <?php if (!empty($message)) echo "<div class='message'>$message</div>"; ?>

    <form method="POST" action="">
        <label>ID Laptop:</label>
        <input type="text" name="id" required>

        <label>Nama Laptop:</label>
        <input type="text" name="nama" required>

        <label>Harga:</label>
        <input type="number" name="harga" required>

        <label>Stok:</label>
        <input type="number" name="stok" required>

        <input type="submit" value="Tambah Laptop">
    </form>

    <h2>Daftar Laptop</h2>
    <?php if (!empty($_SESSION['inventory'])): ?>
        <table>
            <tr>
                <th>No</th>
                <th>ID</th>
                <th>Nama</th>
                <th>Harga</th>
                <th>Stok</th>
            </tr>
            <?php foreach ($_SESSION['inventory'] as $index => $laptop): ?>
                <tr>
                    <td><?= $index + 1 ?></td>
                    <td><?= htmlspecialchars($laptop['id']) ?></td>
                    <td><?= htmlspecialchars($laptop['nama']) ?></td>
                    <td><?= $laptop['harga'] ?></td>
                    <td><?= $laptop['stok'] ?></td>
                </tr>
            <?php endforeach; ?>
        </table>
    <?php else: ?>
        <p>Belum ada data laptop.</p>
    <?php endif; ?>
</body>
</html>
