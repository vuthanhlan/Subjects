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

    $mathuoc=$_POST['mathuoc'];
    $tim= "SELECT * FROM tbl_thuoc WHERE  mathuoc='$mathuoc'";
    $kq= mysqli_query($kn, $tim);
    $row= mysqli_fetch_array($kq);

    
?>
<form action="tim_xl.php" method="POST" enctype="multipart/form-data">
    <table border="1" align="center">
        <tr>
            <td>Mã thuốc</td>
            <td>Tên thuốc</td>
            <td>Hình ảnh</td>
            <td>Giá tiền</td>
        </tr>
        <tr>
            <td><?php echo $row[0]; ?></td>
            <td><?php echo $row[1]; ?></td>
            <td><img src="images/<?php echo $row[2];?>" alt="" width="80" height="80"></td>
            <td><?php echo $row[3]; ?></td>
        </tr>
        </table>
        <a href="trangchu.php">HOME</a>
    </form>
</body>
</html>
