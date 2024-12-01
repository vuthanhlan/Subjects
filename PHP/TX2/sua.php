<!DOCTYPE html>
<html>
<head>
<title>Sửa thông tin</title>
<style>

</style>
</head>
<body>
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
    ?>
    <h1>Sửa thông tin nhân viên</h1>
    <form action="xl_sua.php" method="post">
        Mã nhân viên:        <input type="text" name="manv" value="<?php echo $row['manv']; ?>"><br>
        Họ tên:    <input type="text" name="hoten" value="<?php echo $row['hoten']; ?>"><br>
        Hình ảnh:  <input type="file" name="hinhanh" value="<?php echo $row['hinhanh']; ?>"><br>
        Xếp loại:  <input type="text" name="xeploai" value="<?php echo $row['xeploai']; ?>"><br>
        Lương ngày:  <input type="text" name="luongngay" value="<?php echo $row['luongngay']; ?>"><br>
        Ngày công:  <input type="text" name="ngaycong" value="<?php echo $row['ngaycong']; ?>"><br>
        <input type="submit" value="Cập nhật">
    </form>
</body>

</html>