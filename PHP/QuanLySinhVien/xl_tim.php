<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <?php
        $kn=mysqli_connect('localhost','root', 'thanhlan','sinhvien');
        
        if(!$kn){
            echo "kết nối thất bại";
        }

        $masv = $_POST['masv'];
        $sql = " SELECT * FROM thuchanh WHERE Masv= '$masv'";
        $kq = mysqli_query($kn, $sql) or die('Lỗi truy vấn ');
            $row = mysqli_fetch_row($kq);
    ?>

    <form action="xl_tim.php" method = "POST">
        Mã sinh viên: <input type="text" name="masv" value="<?php echo $row[0];?>"> <br>
        Tên sinh viên: <input type="text" name="tensv" value ="<?php echo $row[1];?>"> <br>
        Điểm toán: <input type="text" name="toan" value = "<?php echo $row[2];?>"> <br>
        Điểm lý: <input type="text" name="ly" value = "<?php echo $row[3];?>"> <br>
        Điểm Hóa: <input type="text" name="hoa" value = "<?php echo $row[4];?>"> <br>
        <input type="submit" value="Tìm kiếm sinh viên">
    </form>
    <a href="hienthi.php">Home</a>
</body>
</html>