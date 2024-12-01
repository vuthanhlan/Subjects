<?php
    include('config.php');
    $mathuoc = $_POST['mathuoc'];
    $tenthuoc = $_POST['tenthuoc'];
    $hinhanh= $_FILES['hinhanh']['name'];
    $hinhanh_tmp_name= $_FILES['hinhanh']['tmp_name'];
    $giatien =$_POST['giatien'];
    if(isset($_POST['them'])){
        $them = "INSERT INTO tbl_thuoc VALUES('$mathuoc','$tenthuoc','$hinhanh','$giatien')";
        $kq = mysqli_query($kn, $them);
        move_uploaded_file($hinhanh_tmp_name, 'images/'.$hinhanh);
        header('location:trangchu.php');
    }
    elseif(isset($_POST['sua'])){
        $sua= "UPDATE tbl_thuoc SET tenthuoc='$tenthuoc', hinhanh='$hinhanh', giatien='$giatien' WHERE mathuoc='$_POST[mathuoc]'" ;
        $kq = mysqli_query($kn,$sua);
        move_uploaded_file($hinhanh_tmp_name,'images/'.$hinhanh);
        header('location:trangchu.php');
    }
    else{
        $xoa= "DELETE FROM tbl_thuoc where mathuoc='$_GET[id]'";
        $kq = mysqli_query($kn,$xoa);
        header('location:trangchu.php');      
    }

?>
