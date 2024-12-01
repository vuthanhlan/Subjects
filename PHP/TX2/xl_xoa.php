<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <h1 style="color: red; text-align:center;">Xác nhận xóa</h1>
    
    <?php
        $connect = new mysqli("localhost","root","","nhanvien");
        if(!$connect){
                echo "Có lỗi kết nối".mysqli_connect_error();
                exit();
        }
        $manv = $_GET['id'];
        $sql = "select * from nhanvien where manv ='$manv'";
        $kq = mysqli_query($connect,$sql);
        $row = mysqli_fetch_array($kq);
        $manv = $row[0];
		$hoten = $row[1];
		$hinhanh = $row[2];
		$xeploai = $row[3];
		$luongngay = $row[4];
        $ngaycong = $row[5];
        echo "Mã nhân viên: $manv  <br>";
        echo "<tr><td>Họ tên:   $hoten </td></tr> <br>";
        echo "<tr><td>Hình ảnh:  <img src='image/$hinhanh' width='80px' height='80px'></td></tr> <br>";
        echo "<tr><td>Xếp loại:  $xeploai</td></tr> <br>";
        echo "<tr><td>Lương ngày:  $luongngay</td></tr> <br>";
        echo "<tr><td>Ngày công:  $ngaycong</td></tr> <br>";
        echo "<tr><td><a href='xoa.php?id=$manv' style='color: red; text-decoration: none'>Xóa</a></td></tr>";
    ?>
    
    
    
</body>
</html>
