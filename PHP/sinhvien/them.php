<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Thêm</title>
</head>
<body>
    <h1>Thêm sinh viên</h1>
    <form action="them_xl.php" method="POST" enctype="multipart/form-data">
        Tên sinh viên: <input type="text" name="hoten"> <br>
        Giới tính: <input type="text" name="gioitinh"> <br>
        Hình ảnh: <input type="file" name="hinhanh" value="Chọn ảnh"> <br>
        Quê quán: <input type="text" name="quequan"> <br>
        <input type="submit" value="Thêm">
    </form>

</body>
</html>