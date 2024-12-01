<h1 align="center">ĐIỂM TỔNG KẾT CỦA SINH VIÊN</h1>
<?php
    $kn= mysqli_connect('localhost', 'root','thanhlan', 'sinhvien');
    if(!$kn){
        echo "ket noi that bai";
    }
    $sql = " SELECT * FROM thuchanh";
    $kq= mysqli_query($kn, $sql);
    if(!$kq){
        echo "lỗi truy vấn";
    }
    if(mysqli_num_rows($kq)>0){
        echo '<table width="900" border ="1" align="center">';
        echo "<tr>";
            echo '<td> Mã sinh viên</td>';
            echo '<td> Họ Tên Sinh viên </td>';
            echo '<td> Điểm Toán </td>';
            echo '<td> Điểm Lý </td>';
            echo '<td> Điểm Hóa </td>';
            echo '<td> Tổng điểm </td>';
            echo '<td> Kết quả </td>';
            echo '<td> Thực hiện </td>';
                while($row = mysqli_fetch_row($kq)){
                    $masv= $row[0];
                    $hoten=$row[1];
                    $toan= $row[2];
                    $ly = $row[3];
                    $hoa = $row[4];
                    $tongdiem= $toan *2 + $ly + $hoa;

                    if($tongdiem > 20){
                        $a = " được lên lơp";
                    }else{
                        $a= "ở lại lớp";
                    }
                    echo "<tr>";
                        echo "<td>$masv</td>";
                        echo "<td>$hoten</td>";
                        echo "<td>$toan</td>";
                        echo "<td>$ly</td>";
                        echo "<td>$hoa</td>";
                        echo "<td>$tongdiem</td>";
                        echo "<td>$a</td>";
                        echo "<td><a href = 'them.php?id=$masv'>Thêm</a> | <a href = 'sua.php?id=$masv'>Sửa</a> | <a href = 'xoa.php?id=$masv'>Xóa</a> | <a href = 'tim.php?id=$masv'>Tìn Kiếm</a></td> ";
                    echo "</tr>";
                }
        echo "</tr>";
        echo "</table>";
    }
?>

    
