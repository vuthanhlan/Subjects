<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Sửa</title>
</head>
<body>
    <?php
        $kn = mysqli_connect('localhost','root','thanhlan','sinhvien');
        if(!$kn){
            echo "Kết nối thất bại";
        }
        $masv = $_GET['id'];
            $sql = "SELECT * FROM thuchanh WHERE Masv = $masv";
            $kq = mysqli_query($kn, $sql) or die('lỗi truy vấn');
                        $row= mysqli_fetch_array($kq);
    ?>
    <h1>Thông tin sinh viên</h1>
    <form action="xl_sua.php" method = "POST">
        Mã sinh viên: <input type="text" name="masv" value="<?php echo $row['Masv']; ?>"> <br>
        Tên sinh viên: <input type="text" name="tensv" value="<?php echo $row['HoTen']; ?>"> <br>
        Điểm toán: <input type="text" name="toan" value="<?php echo $row['Toan']; ?>"> <br>
        Điểm lý: <input type="text" name="ly" value="<?php echo $row['Ly']; ?>"> <br>
        Điểm Hóa: <input type="text" name="hoa" value="<?php echo $row['Hoa']; ?>"> <br>
        <input type="submit" value= "Cập nhật sinh viên">
    </form>
</body>
</html>