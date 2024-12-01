<h1 align= "center">DANH SÁCH SINH VIÊN KHOA CNTT</h1>
<?php
    $kn = mysqli_connect('localhost','root','thanhlan','qlsinhvien');
        if(!$kn){
            echo "kết nối thất bại";
        }
    $sql= "SELECT * FROM sinhvien";
    $kq = mysqli_query($kn, $sql);

        if(!$kq){
            echo "lỗi truy vấn";
        }

    if(mysqli_num_rows($kq)>0){

    
?>
    <table width ="900" border="1px"  align="center">
        <tr>
            <td>Mã Sinh Viên</td>
            <td>Họ tên</td>
            <td>Giới tính</td>
            <td>Hình ảnh</td>
            <td>Quê quán</td>
            <td>Thực hiện</td>
            <?php
                
                while($row = mysqli_fetch_array($kq)){    
                    $masv=$row[0];         
            ?>
            <tr>
                <td><?php echo $row['id']; ?></td>
                <td><?php echo $row['hoten']; ?></td>
                <td><?php echo $row['gioitinh']; ?></td>
                <td width="100"><img width="100%" height="80" src="img/<?php echo $row['hinhanh']; ?>"> </td>
                <td><?php echo $row['quequan']; ?></td>
                <td><?php echo "<a href = 'them.php?id=$masv'>Thêm</a>|<a href = 'sua.php?id=$masv'>Sửa</a> | <a href = 'xoa.php?id=$masv'>Xóa</a> | <a href = 'tim.php?id=$masv'>Tìm Kiếm</a>" ?> </td>
            </tr>
            <?php } ?>
        </tr>
    </table>
<?php
    }
?>