<?php
include "./connect.php";

$MaKH = $_GET['id'];
$sql = "select * from khachhang where MaKH='$MaKH'";
$kq = mysqli_query($kn, $sql) or die("loi truy van");
$row = mysqli_fetch_array($kq);

if(isset($_POST['save'])){
    $MaKH=$_POST['MaKH'];
    $TenKH=$_POST['TenKH'];

    $file_name="";
    if(isset($_FILES['file'])){
        $file=$_FILES['file'];
        $file_name=$file['name'];
        move_uploaded_file($file['tmp_name'],"./upload/$HinhAnh");
    }

    $Sodien=$_POST['Sodien'];
    $Hinhthuc=$_POST['Hinhthuc'];

    $sql="update khachhang set TenKH='$TenKH', HinhAnh='$file_name', Sodien='$Sodien', Hinhthuc='$Hinhthuc' where MaKH='$MaKH'";
    $kq = mysqli_query($kn, $sql) or die("loi truy van");
    header('location:hienthi.php');
}

?>

<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>

<body>
    <table border="1" style="border-collapse: collapse; width:50%" align="center">
        <form method="post" enctype="multipart/form-data">
            <tr>
                <td>MaKH</td>
                <td><input type="text" name="MaKH" value="<?= $row['MaKH'] ?>"></td>
            </tr>
            <tr>
                <td>TenKH</td>
                <td><input type="text" name="TenKH" value="<?= $row['TenKH'] ?>"></td>
            </tr>
            <tr>
                <td>HinhAnh</td>
                <td>
                    <img width="100px" height="100px" src="./upload/<?= $row['HinhAnh'] ?>">
                    <input type="file" name="file" id="">
                </td>
            </tr>
            <tr>
                <td>Sodien</td>
                <td><input type="text" name="Sodien" value="<?= $row['Sodien'] ?>"></td>
            </tr>
            <tr>
                <td>Hinhthuc</td>
                <td><input type="text" name="Hinhthuc" value="<?= $row['Hinhthuc'] ?>"></td>
            </tr>
            <tr>
                <td colspan="2" style="text-align: center;"><button type="submit" name="save" id="">Lưu</button></td>
            </tr>
        </form>
    </table>
</body>

</html>