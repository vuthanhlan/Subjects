<?php
include_once '../lib/session.php';
Session::checkSession('staff');
$role_id = Session::get('role_id');
if ($role_id == 3) {
    # code...
} else {
    header("Location:../index.php");
}
include_once '../classes/order.php';

if (isset($_GET['orderId'])) {
    $order = new order();
    $result = $order->spamOrder($_GET['orderId']);
    if ($result) {
        echo '<script type="text/javascript">alert("Thành công!"); window.location.href = "orderlist.php";</script>';
    } else {
        echo '<script type="text/javascript">alert("Thất bại!"); history.back();</script>';
    }
}