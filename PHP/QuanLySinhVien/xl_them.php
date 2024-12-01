<?php
    $kn = mysqli_connect('localhost', 'root' , 'thanhlan','sinhvien');
    if(!$kn){
        echo "kết nối thất bại";
    }
    $masv = $_POST['masv'];
    $tensv = $_POST['tensv'];
    $toan = $_POST['toan'];
    $ly = $_POST['ly'];
    $hoa = $_POST['hoa'];
    $sql = "INSERT INTO thuchanh VALUES('$masv', '$tensv','$toan','$ly','$hoa')";

    $kq = mysqli_query($kn, $sql)  or die('Lỗi truy vấn');
        header('location:hienthi.php');
?>