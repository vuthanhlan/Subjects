<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Xóa</title>
</head>
<body>
    <?php
        $kn = mysqli_connect('localhost','root','thanhlan','sinhvien');
            if(!$kn){
                echo 'kết nối thất bại';
            }
        $masv = $_GET['id'];
        $sql = "DELETE FROM thuchanh WHERE Masv = '$masv'";
        $kq = mysqli_query($kn,$sql) or die ('Lỗi truy vấn');
                    header('location:hienthi.php');
    ?>
</body>
</html>