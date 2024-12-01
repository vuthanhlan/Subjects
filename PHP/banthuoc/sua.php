<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <?php
        include('config.php');
        $sql = "SELECT * FROM tbl_thuoc WHERE mathuoc='$_GET[id]'";
        $kq= mysqli_query($kn,$sql);
        $row = mysqli_fetch_array($kq);
    ?>
    <form action="xuly.php" method="POST" enctype="multipart/form-data">
    <div>
            <p>Mã thuốc</p>
            <input type="text" name="mathuoc" value="<?php echo $row[0];?>">
        </div>
        <div>
            <p>Tên thuốc</p>
            <input type="text" name="tenthuoc" value="<?php echo $row[1];?>">
        </div>
        <div>
            <p>Hình ảnh</p>
            <input type="file" name="hinhanh" value="<?php echo $row[2];?>">
        </div>
        <div>
            <p>Giá tiền</p>
            <input type="text" name="giatien" value="<?php echo $row[3];?>">
        </div>
        <div><input type="submit" name="sua" value="Sửa"></div>
    </form>
</body>
</html>