<?php
include '../lib/session.php';
include '../classes/categories.php';
Session::checkSession('staff');
$role_id = Session::get('role_id');
if ($role_id == 3) {
    # code...
} else {
    header("Location:../index.php");
}

if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    $categories = new categories();
    if (isset($_POST['block'])) {
        $result = $categories->block($_POST['id']);
        if ($result) {
            echo '<script type="text/javascript">alert("Khóa danh mục thành công!");</script>';
        } else {
            echo '<script type="text/javascript">alert("Khóa danh mục thất bại!");</script>';
        }
    } else if (isset($_POST['active'])) {
        $result = $categories->active($_POST['id']);
        if ($result) {
            echo '<script type="text/javascript">alert("Kích hoạt danh mục thành công!");</script>';
        } else {
            echo '<script type="text/javascript">alert("Kích hoạt danh mục thất bại!");</script>';
        }
    } else {
        echo '<script type="text/javascript">alert("Có lỗi xảy ra!");</script>';
        die();
    }
}

$categories = new categories();
$list = $categories->getAllAdmin((isset($_GET['page']) ? $_GET['page'] : 1));
$pageCount = $categories->getCountPaging();
?>

<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="./css/style.css">
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/5.15.4/css/all.min.css">
    <script src="https://use.fontawesome.com/2145adbb48.js"></script>
    <script src="https://kit.fontawesome.com/a42aeb5b72.js" crossorigin="anonymous"></script>
    <title>Danh sách danh mục</title>
</head>

<body>
    <nav>
        <input type="checkbox" id="check">
        <label for="check" class="checkbtn">
            <i class="fas fa-bars"></i>
        </label>
        <label class="logo"><a href="index.php">STAFF</a></label>
        <ul>
            <li><a href="productlist.php" >Quản lý Sản phẩm</a></li>
            <li><a href="categoriesList.php" class="active">Quản lý danh mục</a></li>
            <li><a href="orderlist.php" id="order">Quản lý Đơn hàng</a></li>
            <li><a href="index.php">Chuyển về trang chủ</a></li>
        </ul>
    </nav>
    <div class="title">
        <h1>Danh sách danh mục</h1>
    </div>
    <div class="control-container">
        <div class="addNew">
            <a href="add_category.php">Thêm mới</a>
        </div>
        <div class="c-search">
            <input type="text" placeholder="Nhập tên danh mục">
            <button type="submit"><i class="fas fa-search"></i></button>
        </div>
    </div>
    <div class="container">
        <?php $count = 1;
        if ($list) { ?>
            <table class="list">
                <tr>
                    <th>STT</th>
                    <th>Tên danh mục</th>
                    <th>Trạng thái</th>
                    <th>Thao tác</th>
                </tr>
                <?php foreach ($list as $key => $value) { ?>
                    <tr>
                        <td><?= $count++ ?></td>
                        <td><?= $value['name'] ?></td>
                        <td><?= ($value['status']) ? "Active" : "Block" ?></td>
                        <td>
                            <?php
                            if ($value['status']) { ?>
                                <form action="categoriesList.php" method="post">
                                    <input type="text" name="id" hidden value="<?= $value['id'] ?>" style="display: none;">
                                    <input type="submit" value="Khóa" name="block">
                                </form>
                            <?php } else { ?>
                                <form action="categoriesList.php" method="post">
                                    <input type="text" name="id" hidden value="<?= $value['id'] ?>" style="display: none;">
                                    <input type="submit" value="Mở" name="active">
                                </form>
                            <?php } ?>
                        </td>
                    </tr>
                <?php } ?>
            </table>
        <?php } else { ?>
            <h3>Chưa có danh mục nào...</h3>
        <?php } ?>
        <div class="pagination">
            <a href="categoriesList.php?page=<?= (isset($_GET['page'])) ? (($_GET['page'] <= 1) ? 1 : $_GET['page'] - 1) : 1 ?>">&laquo;</a>
            <?php
            for ($i = 1; $i <= $pageCount; $i++) {
                if (isset($_GET['page'])) {
                    if ($i == $_GET['page']) { ?>
                        <a class="active" href="categoriesList.php?page=<?= $i ?>"><?= $i ?></a>
                    <?php } else { ?>
                        <a href="categoriesList.php?page=<?= $i ?>"><?= $i ?></a>
                    <?php  }
                } else { ?>
                    <a href="categoriesList.php?page=<?= $i ?>"><?= $i ?></a>
                <?php  } ?>
            <?php }
            ?>
            <a href="categoriesList.php?page=<?= (isset($_GET['page'])) ? $_GET['page'] + 1 : 2 ?>">&raquo;</a>
        </div>
    </div>
    </div>
    
    <footer>
        <p class="copyright">copy by PK-SHOP.com 2023</p>
    </footer>
</body>

</html>