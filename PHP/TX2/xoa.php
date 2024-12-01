<?php
    $connect = mysqli_connect('localhost','root','','nhanvien');
    if(!$connect){
        echo "Lỗi kết nối ".mysqli_connect_error();
        exit();
    }
    $manv = $_GET['id'];
    $query = "delete from nhanvien where manv='$manv'";
    mysqli_query($connect,$query) or die("Lỗi truy vấn!");
    header("location:hienthi.php");
?>