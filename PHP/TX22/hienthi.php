<?php
include "./connect.php";

$sql = "SELECT * FROM khachhang";
$kq = mysqli_query($kn, $sql) or die("loi truy van");
$row = mysqli_fetch_array($kq);
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
                <th>MaKH</th>
                <th>TenKH</th>
                <th>HinhAnh</th>
                <th>Sodien</th>
                <th>Hinhthuc</th>
                <th>ThanhToan</th>
                <th>ThucHien</th>
            </tr>

            <?php
            while ($row = mysqli_fetch_array($kq)) {
                $giadien = 0;
                $thanhtoan = 0;
                if ($row['Hinhthuc'] == "Kd") {
                    $thanhtoan = 3500 * $row['Sodien'];
                } elseif ($row['Hinhthuc'] == "Gd") {
                    $thanhtoan = 2500 * $row['Sodien'];
                }

                ?>
                <tr>
                    <td><?= $row['MaKH'] ?></td>
                    <td><?= $row['TenKH'] ?></td>
                    <td>
                        <img width="100px" height="100px" src="./upload/<?= $row['HinhAnh'] ?>">
                    </td>
                    <td><?= $row['Sodien'] ?></td>
                    <td><?= $row['Hinhthuc'] ?></td>
                    <td><?= $thanhtoan ?></td>
                    <td>
                        <a href="sua.php?id=<?= $row['MaKH'] ?>">Sửa</a> |
                        <a href="xoa.php?id=<?= $row['MaKH'] ?>">Xóa</a>
                    </td>
                </tr>
                <?php
            }
            ?>
        </form>
    </table>
</body>

</html>