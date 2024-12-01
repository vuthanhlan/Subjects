<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
<?php
        $kn=mysqli_connect('localhost','root', 'thanhlan','qlsinhvien');
        
        if(!$kn){
            echo "kết nối thất bại";
        }

        $masv = $_POST['masv'];
        $sql = " SELECT * FROM sinhvien WHERE id= '$masv'";
        $kq = mysqli_query($kn, $sql) or die('Lỗi truy vấn ');
            $row = mysqli_fetch_array($kq);
    ?>
    <form action="tim_xl.php" method="POST" enctype="multipart/form-data">
        <table width="900" border="1px" align="center">
            <tr>
                <td>Mã Sinh Viên</td>
                <td>Họ tên</td>
                <td>Giới tính</td>
                <td>Hình ảnh</td>
                <td>Quê quán</td>
            </tr>
            <tr>
                <td><?php echo $row['id']; ?></td>
                <td><?php echo $row['hoten']; ?></td>
                <td><?php echo $row['gioitinh']; ?></td>
                <td width="100"><img width="100%" height="80" src="img/<?php echo $row['hinhanh']; ?>"> </td>
                <td><?php echo $row['quequan']; ?></td>
            </tr>
        </table>
    </form>
    <a href="trangchu.php">HOME</a>
</body>
</html>