<?php
    $connect = mysqli_connect('localhost','root','','nhanvien');
    if(!$connect){
        echo "Lỗi kết nối".mysqli_connect_error();
        exit();
    }
    $manv = $_POST['manv'];
    $hoten = $_POST['hoten'];
    $hinhanh = $_POST['hinhanh'];
    $xeploai = $_POST['xeploai'];
    $luongngay = $_POST['luongngay'];
    $ngaycong = $_POST['ngaycong'];
    $query = "UPDATE nhanvien set hoten='$hoten', hinhanh='$hinhanh', xeploai='$xeploai',luongngay='$luongngay',ngaycong='$ngaycong' where manv='$manv'";
    mysqli_query($connect, $query);
    header("location:hienthi.php");
?>