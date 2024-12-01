<?php
	$servername = "localhost";
	$username="root";
	$password="";
	$database="nhanvien";

	$connect = new mysqli($servername, $username, $password, $database);
	if(!$connect){
		echo "Có lỗi kết nối".mysqli_connect_error();
		exit();
	}
?>
<!DOCTYPE html>
<html>
<head>
<title>Quản lý nhân viên</title>
</head>

<body>
	<h1 style="color: red; text-align:center;">Quản lý nhân viên</h1>
	<?php
		$query = 'select * from nhanvien';
		$kq = mysqli_query($connect,$query);
		if(!$kq){
			echo "Lỗi truy vấn!";
		}
		if(mysqli_num_rows($kq) > 0){
			echo '<table width="900px"; border="1"; align="center";>';
			echo '<tr style="text-align:center">';
			echo '<td>MaNV</td>';
			echo '<td>Ho ten</td>';
			echo '<td>Hinh anh</td>';
			echo '<td>Xep loai</td>';
			echo '<td>Luong ngay</td>';
            echo '<td>Ngay cong</td>';
            echo '<td>Tong luong</td>';
			echo '<td>Thuc hien</td>';
			echo '</tr>';
			{
				while($row = mysqli_fetch_row($kq)){
					$manv = $row[0];
					$hoten = $row[1];
					$hinhanh = $row[2];
					$xeploai = $row[3];
					$luongngay = $row[4];
                    $ngaycong = $row[5];
                    if($xeploai == 'A'){
                        $thuong = 500000;
                    }
                    else if($xeploai == 'B'){
                        $thuong = 300000;
                    }
                    else{
                        $thuong = 0;
                    }
                    $tongluong = $luongngay*$ngaycong + $thuong;
                    

					echo '<tr style="text-align:center">';
					echo "<td>$manv</td>";
					echo "<td>$hoten</td>";
					echo "<td><img src='image/$hinhanh' width='80px' height='80px'></td>";
                    echo "<td>$xeploai</td>";
                    echo "<td>$luongngay</td>";
                    echo "<td>$ngaycong</td>";
                    echo "<td>$tongluong</td>";
					echo "<td><a href='sua.php?id=$manv'>Sửa </a>|
					<a href='xl_xoa.php?id=$manv'>Xóa</a></td>";
					echo "</tr>";
				}
			}
			echo "</table>";
		}
	?>
</body>

</html>