<?php
    include('config.php');
    $makh= $_POST['makh'];
    $check_makh = "SELECT * FROM khachhang WHERE makh = '$makh'";
    $result = mysqli_query($kn, $check_makh);
        if(mysqli_fetch_row($result)==0){
            echo "không có khách hàng này";
?>
    <a style="background-color: gray; color: white; text-decoration:none;" href="xoa.php">Form</a>
<?php
        }else{
            if(isset($_POST['thuchien'])){
        
        $xoa = "DELETE FROM khachhang where makh='$makh'";
        $kq= mysqli_query($kn,$xoa);
        header('location:hienthi.php');
    }
        }

    
?>