<?php
    include "./connect.php";

    $MaKH=$_GET['id'];
    $sql="delete from khachhang where MaKH='$MaKH'";
    $kq = mysqli_query($kn, $sql) or die("loi truy van");
    header('location:hienthi.php');
?>