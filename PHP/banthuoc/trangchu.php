<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
    <style>
        .search {
            text-align: center;
            width: 100px;
            height: 30px;
            background-color: gray;
            margin-left:400px;
            margin-bottom:10px;
        }
        .search a{
            text-decoration: none;
            color: white;
            
        }
        .them_tim{
            display:flex;
        }

    </style>
</head>
<body>
    <h1 align="center">DANH SÁCH THUỐC</h1>

<?php
    include('config.php');
    $sql = "SELECT * FROM tbl_thuoc";
    $kq= mysqli_query($kn,$sql);
?>
<div class="them_tim">
    <div class="search"><a href="them.php">Thêm</a></div>
    <div class="search"><a  href="tim.php">Tìm kiếm</a></div>
    
</div>

<table border="1px" align="center">
    <tr>
        <td>Mã thuốc</td>
        <td>Tên thuốc</td>
        <td>Hình ảnh</td>
        <td>Giá tiền</td>
        <td>Thực hiện</td>
    </tr>
    <?php
        while($row= mysqli_fetch_row($kq)){     
    ?>
    <tr>
        <td><?php echo $row[0] ?></td>
        <td><?php echo $row[1] ?></td>
        <td><img src="images/<?php echo $row[2] ?>" alt="" width="80" height="80"></td>
        <td><?php echo $row[3] ?></td>
        <td><a href="sua.php?id=<?php echo $row[0]?>">Sửa</a> || <a href="xuly.php?id=<?php echo $row[0]?>">Xóa</a></td>
    </tr>
    <?php } ?>
</table>
</body>
</html>

