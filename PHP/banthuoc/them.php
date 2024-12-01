<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <form action="xuly.php" method="POST" enctype="multipart/form-data">
        
        <div>
            <p>Tên thuốc</p>
            <input type="text" name="tenthuoc" required>
        </div>
        <div>
            <p>Hình ảnh</p>
            <input type="file" name="hinhanh" required>
        </div>
        <div>
            <p>Giá tiền</p>
            <input type="text" name="giatien" required>
        </div>
        <div><input type="submit" name="them" value="Thêm"></div>
    </form>
</body>
</html>