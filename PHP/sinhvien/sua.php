<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Sửa</title>
</head>
<body>
    <?php
        $kn= mysqli_connect('localhost','root','thanhlan','qlsinhvien');
        if(!$kn){
            echo " kết nối thất bại";
        }
        $masv = $_GET['id'];
            $sql = "SELECT* FROM sinhvien WHERE id='$masv'";
            $kq= mysqli_query($kn, $sql);
            $row= mysqli_fetch_assoc($kq);
        if(isset($_POST['capnhat'])){
             $hoten=$_POST['hoten'];
            $gioitinh=$_POST['gioitinh'];
        
            $hinhanh= $_FILES['hinhanh']['name'];
            $hinhanh_tmp_name=$_FILES['hinhanh']['tmp_name'];
        
            $quequan=$_POST['quequan'];
        
            $sql = "UPDATE sinhvien SET hoten='$hoten', gioitinh='$gioitinh', hinhanh='$hinhanh', quequan='$quequan' where id=".$masv;
            mysqli_query($kn, $sql) or die('Lỗi truy vấn');
            move_uploaded_file($hinhanh_tmp_name, 'img/'.$hinhanh);
                header('location:trangchu.php');
        }
           

        
    ?>
    <form method="POST" enctype="multipart/form-data">
        Tên sinh viên: <input type="text" name="hoten" value="<?php echo $row['hoten'];?>"> <br>
        Giới tính: <input type="text" name="gioitinh" value="<?php echo $row['gioitinh'];?>"> <br>
        Hình ảnh: 
        <span><img src="img/<?php echo $row['hinhanh'];?>" alt="" width="50px" heigth="50px"></span>
        <input type="file" name="hinhanh" value="<?php echo $row['hinhanh'];?>"> <br>
        Quê quán: <input type="text" name="quequan" value="<?php echo $row['quequan'];?>"> <br>
        <input type="submit" name="capnhat" value="Cập nhật">
    </form>
</body>
</html>