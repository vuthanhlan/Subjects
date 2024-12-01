<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Quản lý tiền điện</title>
</head>
<body>
    <h1 align="center">DANH SÁCH QUẢN LÝ TIỀN ĐIỆN</h1>
    <?php 
        include('config.php') ;

        $sql= "SELECT * FROM khachhang";
        $kq= mysqli_query($kn,$sql);
        
    ?>
    <div class="sua_xoa">
        <div class="btn"><a href="sua.php">Sửa</a></div>
        <div class="btn"><a href="xoa.php">Xóa</a></div>
    </div>
    <table border="1" align="center">
        <tr>
            <td>Mã Khách hàng</td>
            <td>Tên Khách hàng</td>
            <td>Hình ảnh</td>
            <td>Số điện</td>
            <td>Hình thức</td>
            <td>Thanh toán</td>
        </tr>
        <?php
            while($row= mysqli_fetch_row($kq)){
                $hinhthuc=$row[4];
                $sodien= $row[3];
                if($hinhthuc == 'Kd'){
                    $giadien=35000;
                }
                elseif($hinhthuc== 'Gd'){
                    $giadien=2500;
                }else{
                    echo "Hình thức không hợp lệ";
                }
                $thanhtoan=$giadien *$sodien;
            ?>
        <tr>
            <td><?php echo $row[0];?></td>
            <td><?php echo $row[1];?></td>
            <td><img src="imgs/<?php echo $row[2];?>" alt="" width=80 height=80;></td>
            <td><?php echo $row[3];?></td>
            <td><?php echo $row[4];?></td>
            <td><?php echo $thanhtoan;?></td>
        </tr>
            <?php } ?>
            
    </table>
</body>
</html>