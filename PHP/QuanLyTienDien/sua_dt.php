<?php
    include('config.php');

    $check_makh= "SELECT * FROM khachhang";
    $kq=mysqli_query($kn,$check_makh);
    $row= mysqli_fetch_array($kq);
    if(isset($_POST['capnhat'])){
        $makh=$_POST['makh'];
        $tenkh=$_POST['tenkh'];
        $hinhanh=$_FILES['hinhanh']['name'];
        $hinhanh_tmp_name=$_FILES['hinhanh']['tmp_name'];
        $sodien=$_POST['sodien'];
        $hinhthuc=$_POST['hinhthuc'];   
        $sql="UPDATE khachhang SET makh='$makh',tenkh='$tenkh',hinhanh='$hinhanh',sodien='$sodien',hinhthuc='$hinhthuc' where makh='$makh'";
        $kq= mysqli_query($kn,$sql);
        move_uploaded_file($hinhanh_tmp_name,'imgs/'.$hinhanh);
        header('location:hienthi.php');
    }
?>
<form method="POST" enctype="multipart/form-data">
    Mã khách hàng: <input type="text" name="makh" value="<?php echo $row[0];?>" required> <br>
    Tên khách hàng: <input type="text" name="tenkh" value="<?php echo $row[1];?>" required> <br>
    Hình ảnh: <input type="file" name="hinhanh" value="<?php echo $row[2];?>" required> <br>
    Số điện: <input type="text" name="sodien" value="<?php echo $row[3];?>" required> <br>
    hình thức: <input type="text" name="hinhthuc" value="<?php echo $row[4];?>" required> <br>
    <input type="submit" name="capnhat" value="Cập nhật">
</form>