<?php
    $kn= mysqli_connect('localhost','root','thanhlan','qlsinhvien');
    if(!$kn){
        echo "kết nối thất bại ";
    }
    $masv = $_GET['id'];
    $sql = "DELETE FROM sinhvien WHERE id='$masv'";
    $kq= mysqli_query($kn, $sql) or die('Lỗi truy vấn');
        header('location:trangchu.php');
?>