<?php
    $kn = mysqli_connect('localhost','root','thanhlan','sinhvien');
        if(!$kn){
            echo "Kết nối thất bại ";

        }
    $masv = $_POST['masv'];
    $tensv = $_POST['tensv'];
    $toan = $_POST['toan'];
    $ly = $_POST['ly'];
    $hoa = $_POST['hoa'];

    $sql = "UPDATE thuchanh SET HoTen = '$tensv', Toan = '$toan', Ly='$ly', Hoa ='$hoa'
            where Masv= $masv";

    mysqli_query($kn, $sql) or die('Lỗi truy vấn');
            header('location:hienthi.php');
?>