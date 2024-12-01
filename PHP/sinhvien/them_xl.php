<?php
    $kn= mysqli_connect('localhost','root','thanhlan','qlsinhvien');
        if(!$kn){
            echo "kết nối thất bại";
        }
        $masv= $_POST['masv'];
        $hoten= $_POST['hoten'];
        $gioitinh=$_POST['gioitinh'];
        // chỉ lấy tên hình ảnh gửi lên database
        $hinhanh= $_FILES['hinhanh']['name'];
        // lấy đường dẫn của ảnh
        $hinhanh_tmp_name = $_FILES['hinhanh']['tmp_name'];
        $quequan=$_POST['quequan'];
        
        $sql= "INSERT INTO sinhvien VALUES ('$masv','$hoten','$gioitinh','$hinhanh','$quequan')";
        
        $kq= mysqli_query($kn,$sql) or die ('Lỗi truy vấn');
        move_uploaded_file($hinhanh_tmp_name, 'img/'.$hinhanh);
            header('location:trangchu.php');
        

    ?>