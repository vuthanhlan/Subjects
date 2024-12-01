-- phpMyAdmin SQL Dump
-- version 5.2.0
-- https://www.phpmyadmin.net/
--
-- Máy chủ: 127.0.0.1
-- Thời gian đã tạo: Th6 14, 2023 lúc 01:50 PM
-- Phiên bản máy phục vụ: 10.4.24-MariaDB
-- Phiên bản PHP: 8.1.6

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Cơ sở dữ liệu: `pk_shop`
--

-- --------------------------------------------------------

--
-- Cấu trúc bảng cho bảng `cart`
--

CREATE TABLE `cart` (
  `id` int(11) NOT NULL,
  `userId` int(11) NOT NULL,
  `productId` int(11) NOT NULL,
  `qty` int(11) NOT NULL,
  `productName` varchar(100) NOT NULL,
  `productPrice` decimal(10,0) NOT NULL,
  `productImage` varchar(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Đang đổ dữ liệu cho bảng `cart`
--

INSERT INTO `cart` (`id`, `userId`, `productId`, `qty`, `productName`, `productPrice`, `productImage`) VALUES
(57, 35, 44, 1, 'Đế điện thoại xe hơi Vent mount Pro With MagSafe Belkin WIC002btGR Bạc', '1590000', '4377426429.jpg'),
(58, 35, 58, 1, 'Đế điện thoại xe hơi OSMIA CK-CH4 Xám', '120000', '6295923885.jpg'),
(59, 35, 64, 1, 'Dây đeo điện thoại OSMIA silicon CRS ', '30000', '362dbff9ea.jpg'),
(60, 35, 88, 1, 'Móc treo phích cắm JM HOOKWJM02', '40000', '8bfbae28f9.jpg'),
(61, 35, 101, 1, 'Tai nghe Bluetooth AirPods 3 Apple MME73 Trắng', '4490000', '968abb4093.jpeg'),
(62, 35, 98, 1, 'Túi chống nước 5 inch Cosano Trong suốt', '50000', 'e7f8e62c73.jpg'),
(117, 42, 28, 1, 'Adapter Sạc USB Hydrus ACL2018', '100000', 'b52eabed75.jpeg');

-- --------------------------------------------------------

--
-- Cấu trúc bảng cho bảng `categories`
--

CREATE TABLE `categories` (
  `id` int(11) NOT NULL,
  `name` varchar(255) NOT NULL,
  `status` tinyint(4) NOT NULL DEFAULT 1
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Đang đổ dữ liệu cho bảng `categories`
--

INSERT INTO `categories` (`id`, `name`, `status`) VALUES
(6, 'Sạc dự phòng', 1),
(7, 'Sạc, cáp', 1),
(8, 'Gậy chụp ảnh, Gimbal', 1),
(9, 'Giá đỡ điện thoại/ laptop', 1),
(10, 'Đế, móc điện thoại', 1),
(11, 'Túi chống nước', 1),
(12, 'Tai nghe', 1),
(13, 'Loa', 1);

-- --------------------------------------------------------

--
-- Cấu trúc bảng cho bảng `chatbot`
--

CREATE TABLE `chatbot` (
  `id` int(11) NOT NULL,
  `queries` varchar(255) NOT NULL,
  `replies` varchar(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Đang đổ dữ liệu cho bảng `chatbot`
--

INSERT INTO `chatbot` (`id`, `queries`, `replies`) VALUES
(1, 'hi|hello|hey|hy', 'Hello');

-- --------------------------------------------------------

--
-- Cấu trúc bảng cho bảng `orders`
--

CREATE TABLE `orders` (
  `id` int(11) NOT NULL,
  `userId` int(11) NOT NULL,
  `createdDate` date NOT NULL,
  `receivedDate` date DEFAULT NULL,
  `status` varchar(20) NOT NULL,
  `fullname` varchar(255) NOT NULL,
  `phoneNumber` varchar(100) NOT NULL,
  `address` varchar(500) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Đang đổ dữ liệu cho bảng `orders`
--

INSERT INTO `orders` (`id`, `userId`, `createdDate`, `receivedDate`, `status`, `fullname`, `phoneNumber`, `address`) VALUES
(1, 1, '2023-06-09', '2023-06-09', 'Complete', 'Nguyễn Thị B', '0987654321', 'Hồ Chí Minh'),
(2, 1, '2023-06-09', '2023-06-09', 'Complete', 'Trần Văn C', '0909090909', 'Đà Nẵng'),
(3, 1, '2023-06-09', '2023-06-09', 'Complete', 'Lê Thị D', '0912345678', 'Hải Phòng'),
(4, 1, '2023-06-09', '2023-06-09', 'Complete', 'Phạm Văn E', '0977123456', 'Cần Thơ'),
(6, 42, '2023-06-12', NULL, 'Processing', 'Nguyễn Văn F', '0987654321', 'Hà Nội'),
(7, 42, '2023-06-12', NULL, 'Processing', 'Trần Thị G', '0909090909', 'Đà Nẵng'),
(8, 42, '2023-06-12', NULL, 'Processing', 'Lê Văn H', '0912345678', 'Hải Phòng'),
(9, 42, '2023-06-12', NULL, 'Processing', 'Phạm Thị I', '0977123456', 'Cần Thơ'),
(10, 42, '2023-06-12', '2023-06-16', 'Delivered', 'Nguyễn Văn J', '0987654321', 'Hà Nội'),
(11, 42, '2023-06-12', '2023-06-12', 'Complete', 'Trần Thị K', '0909090909', 'Đà Nẵng'),
(12, 42, '2023-06-12', '2023-06-12', 'Complete', 'Lê Văn L', '0912345678', 'Hải Phòng'),
(14, 1, '2023-06-13', '2023-06-13', 'Complete', 'Phạm Thị M', '0977123456', 'Cần Thơ'),
(15, 1, '2023-06-14', NULL, 'Processing', 'Nguyễn Văn A', '0868206602', 'Hà Nội');

-- --------------------------------------------------------

--
-- Cấu trúc bảng cho bảng `order_details`
--

CREATE TABLE `order_details` (
  `id` int(11) NOT NULL,
  `orderId` int(11) NOT NULL,
  `productId` int(11) NOT NULL,
  `qty` int(11) NOT NULL,
  `productPrice` decimal(10,0) NOT NULL,
  `productName` varchar(100) NOT NULL,
  `productImage` varchar(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Đang đổ dữ liệu cho bảng `order_details`
--

INSERT INTO `order_details` (`id`, `orderId`, `productId`, `qty`, `productPrice`, `productName`, `productImage`) VALUES
(1, 1, 28, 5, '100000', 'Adapter Sạc USB Hydrus ACL2018', 'b52eabed75.jpeg'),
(2, 2, 28, 1, '100000', 'Adapter Sạc USB Hydrus ACL2018', 'b52eabed75.jpeg'),
(3, 3, 32, 1, '48000', 'Adapter Sạc USB 5W Hydrus CS-TC027 Trắng', 'cc84fda5cf.jpg'),
(4, 4, 28, 2, '100000', 'Adapter Sạc USB Hydrus ACL2018', 'b52eabed75.jpeg'),
(7, 6, 28, 1, '100000', 'Adapter Sạc USB Hydrus ACL2018', 'b52eabed75.jpeg'),
(8, 7, 28, 1, '100000', 'Adapter Sạc USB Hydrus ACL2018', 'b52eabed75.jpeg'),
(9, 8, 28, 1, '100000', 'Adapter Sạc USB Hydrus ACL2018', 'b52eabed75.jpeg'),
(10, 9, 28, 1, '100000', 'Adapter Sạc USB Hydrus ACL2018', 'b52eabed75.jpeg'),
(11, 10, 28, 1, '100000', 'Adapter Sạc USB Hydrus ACL2018', 'b52eabed75.jpeg'),
(12, 11, 28, 1, '100000', 'Adapter Sạc USB Hydrus ACL2018', 'b52eabed75.jpeg'),
(13, 11, 22, 1, '245000', 'Pin sạc dự phòng Polymer 10.000 mAh Hydrus PJ JP196', 'cbdb844350.jpg'),
(14, 12, 28, 1, '100000', 'Adapter Sạc USB Hydrus ACL2018', 'b52eabed75.jpeg'),
(17, 14, 22, 1, '245000', 'Pin sạc dự phòng Polymer 10.000 mAh Hydrus PJ JP196', 'cbdb844350.jpg'),
(18, 15, 22, 1, '245000', 'Pin sạc dự phòng Polymer 10.000 mAh Hydrus PJ JP196', 'cbdb844350.jpg');

-- --------------------------------------------------------

--
-- Cấu trúc bảng cho bảng `products`
--

CREATE TABLE `products` (
  `id` int(11) NOT NULL,
  `name` varchar(255) NOT NULL,
  `originalPrice` decimal(10,0) NOT NULL,
  `promotionPrice` decimal(10,0) NOT NULL,
  `image` varchar(50) NOT NULL,
  `createdBy` int(11) NOT NULL,
  `createdDate` date NOT NULL,
  `cateId` int(11) NOT NULL,
  `qty` int(11) NOT NULL,
  `des` varchar(1000) NOT NULL,
  `status` tinyint(1) NOT NULL,
  `soldCount` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Đang đổ dữ liệu cho bảng `products`
--

INSERT INTO `products` (`id`, `name`, `originalPrice`, `promotionPrice`, `image`, `createdBy`, `createdDate`, `cateId`, `qty`, `des`, `status`, `soldCount`) VALUES
(19, 'Pin sạc dự phòng 7500 mAh AVA+ LJ JP199', '350000', '199000', 'be2888a350.jpg', 1, '2023-05-18', 6, 9, '<b>Thông số kỹ thuật: </b>\n<br> - Hiệu suất sạc: 64%\n<br> - Dung lượng pin: 7.500 mAh\n<br> - Thời gian sạc đầy pin: 3 - 4 giờ (dùng Adapter 2A)7 - 8 giờ (dùng Adapter 1A)\n<br> - Nguồn vào: Micro USB: 5V - 2A\n<br> - Nguồn ra: USB: 5V - 2A\n<br> - Lõi pin: Li-Ion\n<br> - Công nghệ/Tiện ích: Đèn LED báo hiệu\n<br> - Kích thước: Dài 8.7 cm - Rộng 5.8 cm - Dày 2 cm\n<br> - Trọng lượng: 172 g\n<br> - Thương hiệu của: Thế Giới Di Động\n<br> - Sản xuất tại: Trung Quốc\n<br> - Hãng: AVA+.', 1, 0),
(20, 'Pin sạc dự phòng 7.500 mAh AVA+ DS005-PP', '350000', '190000', 'f9e9511a72.jpg', 1, '2023-05-18', 6, 15, '<b>Thông số kỹ thuật: </b>\r\n<br> - Hiệu suất sạc: 64%\r\n<br> - Dung lượng pin: 7.500 mAh\r\n<br> - Thời gian sạc đầy pin: 7 - 8 giờ (dùng Adapter 1A)3 - 4 giờ (dùng Adapter 2A)\r\n<br> - Nguồn vào: Micro USB: 5V - 2A\r\n<br> - Nguồn ra: USB: 5V - 2A\r\n<br> - Lõi pin: Li-Ion\r\n<br> - Công nghệ/Tiện ích: Đèn LED báo hiệu\r\n<br> - Kích thước: Dày 2 cm - Rộng 7 cm - Dài 8 cm\r\n<br> - Trọng lượng: 170 g\r\n<br> - Thương hiệu của: Thế Giới Di Động\r\n<br> - Sản xuất tại: Trung Quốc', 1, 0),
(21, 'Pin sạc dự phòng Polymer 10.000 mAh Hydrus PA CK01 ', '490000', '245000', 'df280f19b3.jpg', 1, '2023-05-18', 6, 16, '<b>Thông số kỹ thuật: </b>\r\n<br> - Hiệu suất sạc: 64%\r\n<br> - Dung lượng pin: 10.000 mAh\r\n<br> - Thời gian sạc đầy pin: 10 - 11 giờ (dùng Adapter 1A)5 - 6 giờ (dùng Adapter 2A)\r\n<br> - Nguồn vào: Micro USB: 5V - 2A\r\n<br> - Nguồn ra: USB: 5V - 2.1A\r\n<br> - Lõi pin: Polymer\r\n<br> - Công nghệ/Tiện ích: Đèn LED báo hiệu\r\n<br> - Kích thước: Dày 1.5 cm - Rộng 7.5 cm - Dài 14.5cm\r\n<br> - Trọng lượng: 233g\r\n<br> - Thương hiệu của: Thế Giới Di Động\r\n<br> - Sản xuất tại: Trung Quốc\r\n<br> - Hãng: Hydrus. Xem thông tin hãng', 1, 4),
(22, 'Pin sạc dự phòng Polymer 10.000 mAh Hydrus PJ JP196', '490000', '245000', 'cbdb844350.jpg', 1, '2023-05-18', 6, 2, '<b>Thông số kỹ thuật: </b>\r\n<br> - Hiệu suất sạc: 65%\r\n<br> - Dung lượng pin: 10.000 mAh\r\n<br> - Thời gian sạc đầy pin: 10 - 11 giờ (dùng Adapter 1A)\r\n<br> - Nguồn vào: 5 - 6 giờ (dùng Adapter 2A)\r\n<br> - Nguồn ra: Micro USB: 5V - 2A\r\n<br> - Lõi pin: USB: 5V - 2A\r\n<br> - Công nghệ/Tiện ích: Polymer\r\n<br> - Kích thước: Đèn LED báo hiệu\r\n<br> - Trọng lượng: Cao 13.5 cm - Rộng 6.7 cm - Dày 1.6 cm\r\n<br> - Thương hiệu của: 225 g\r\n<br> - Sản xuất tại: Thế Giới Di Động\r\n<br> - Hãng Trung Quốc', 1, 11),
(23, 'Pin sạc dự phòng Polymer 10.000mAh AVA+ JP208', '500000', '299000', '6551020c7f.jpg', 1, '2023-05-18', 6, 8, '<b>Thông số kỹ thuật: </b>\r\n<br> - Hiệu suất sạc: 64%\r\n<br> - Dung lượng pin: 10.000 mAh\r\n<br> - Thời gian sạc đầy pin: 10 - 11 giờ (dùng Adapter 1A)\r\n<br> - Nguồn vào: 6 - 7 giờ (dùng Adapter 5V - 2A)\r\n<br> - Nguồn ra: 5V - 2A\r\n<br> - Lõi pin: USB: 5V - 2A\r\n<br> - Công nghệ/Tiện ích: Polymer\r\n<br> - Kích thước: Đèn LED báo hiệu\r\n<br> - Trọng lượng: Dày 1.7 cm - Rộng 6.5 cm - Dài 13.5 cm\r\n<br> - Thương hiệu của: 225 g\r\n<br> - Sản xuất tại: Thế Giới Di Động\r\n<br> - Hãng Trung Quốc', 1, 0),
(24, 'Pin sạc dự phòng Polymer 10000mAh AVA+ DS006', '500000', '299000', 'dbe7bf9eb1.jpg', 1, '2023-05-18', 6, 20, '- Hiệu suất sạc: 64%\r\n- Dung lượng pin: 10.000 mAh\r\n- Thời gian sạc đầy pin: 10 - 11 giờ (dùng Adapter 1A)\r\n- Nguồn vào: 5 - 6 giờ (dùng Adapter 2A)\r\n- Nguồn ra: Micro USB: 5V - 2A\r\n- Lõi pin: USB: 5V - 2A\r\n- Công nghệ/Tiện ích: Polymer\r\n- Kích thước: Đèn LED báo hiệu\r\n- Trọng lượng: Dày 1.5 cm - Rộng 7 cm - Dài 14.5 cm\r\n- Thương hiệu của: 225 g\r\n- Sản xuất tại: Thế Giới Di Động\r\n- Hãng Trung Quốc', 1, 0),
(25, 'Pin sạc dự phòng Polymer 10.000 mAh AVA+ PJ JP192', '500000', '299000', '06624ef4d7.jpg', 1, '2023-05-18', 6, 22, '- Hiệu suất sạc: 64%\r\n- Dung lượng pin: 10.000 mAh\r\n- Thời gian sạc đầy pin: 10 - 11 giờ (dùng Adapter 1A)\r\n- Nguồn vào: 5 - 6 giờ (dùng Adapter 2A)\r\n- Nguồn ra: Micro USB: 5V - 2A\r\n- Lõi pin: USB: 5V - 2.4A\r\n- Công nghệ/Tiện ích: Polymer\r\n- Kích thước: Đèn LED báo hiệu\r\n- Trọng lượng: Dài 8.7 cm - Ngang 6 cm - Cao 2 cm\r\n- Thương hiệu của: 182 g\r\n- Sản xuất tại: Thế Giới Di Động\r\n- Hãng Trung Quốc', 1, 0),
(26, 'Pin sạc dự phòng Polymer 10000mAh Type C AVA+ PJ JP260 ', '550000', '329000', '1842f01391.jpg', 1, '2023-05-18', 6, 10, '- Hiệu suất sạc: 65% <br>\n- Dung lượng pin: 10.000 mAh <br>\n- Thời gian sạc đầy pin: 10 - 11 giờ (dùng Adapter 1A)<br>\n- Nguồn vào: 6 - 7 giờ (dùng Adapter 5V - 2A)<br>\n- Nguồn ra: Micro USB: 5V - 2A<br>\n- Lõi pin: Type C: 5V- 2.4A<br>\n- Công nghệ/Tiện ích: USB: 5V - 2.4A<br>\n- Kích thước: Polymer<br>\n- Trọng lượng: Đèn LED báo hiệu<br>\n- Thương hiệu của: Dày 2 cm <br>- Rộng 6.7 cm<br> - Dài 14.5 cm<br>\n- Sản xuất tại: 238g<br>\n- Hãng Thế Giới Di Động', 1, 0),
(27, 'Cáp Type C - Lightning 1m Apple MM0A3 Trắng', '590000', '501000', 'ac55bd19cb.jpeg', 1, '2023-05-19', 7, 100, '<b>Thông số kĩ thuật</b>\r\n<br> - Công nghệ/Tiện ích Hỗ trợ sạc nhanh\r\n<br> - Chức năng Sạc\r\n<br> - Đầu vào Truyền dữ liệu\r\n<br> - Đầu ra USB Type-C\r\n<br> - Độ dài dây Lightning\r\n<br> - Công suất tối đa 1 m\r\n<br> - Sản xuất tại 87 W\r\n<br> - Thương hiệu của Trung Quốc\r\n<br> - Hãng Mỹ', 1, 0),
(28, 'Adapter Sạc USB Hydrus ACL2018', '200000', '100000', 'b52eabed75.jpeg', 1, '2023-05-19', 7, 0, '<b>Thông số kĩ thuật</b>\r\n<br> - Model: ACL2018\r\n<br> - Chức năng: Sạc\r\n<br> - Đầu vào: 100-240V~50/60Hz, 0.35A\r\n<br> - Đầu ra: USB: 5V - 2.4A\r\n<br> - Dòng sạc tối đa: 12 W\r\n<br> - Kích thước: Dài 8.3 cm - Ngang 3.7 cm - Cao 2.5 cm\r\n<br> - Thương hiệu của: Thế Giới Di Động\r\n<br> - Sản xuất tại: Trung Quốc\r\n<br> - Hãng Hydrus.', 1, 64),
(30, 'Cáp Type C - Type C 1m Hydrus DS464', '200000', '100000', '4b9515e06f.jpeg', 1, '2023-05-19', 7, 98, '<b>Thông số kĩ thuật</b>\r\n<br> - Công nghệ/Tiện ích Hỗ trợ sạc nhanh\r\n<br> - Chức năng Sạc\r\n<br> - Đầu vào Truyền dữ liệu\r\n<br> - Đầu ra USB Type-C\r\n<br> - Độ dài dây Type C: 5V - 3A, 9V - 2A, 12V - 3A, 15V - 3A, 20V - 3A (Max 60W)\r\n<br> - Công suất tối đa 1 m\r\n<br> - Sản xuất tại 60 W\r\n<br> - Thương hiệu của Trung Quốc\r\n<br> - Hãng Thế Giới Di Động', 1, 2),
(31, 'Cáp Type C - Type C 2m Hydrus DS465', '200000', '80000', '29d1f8fd1e.jpeg', 1, '2023-05-20', 7, 99, '<b>Thông số kĩ thuật</b>\r\n<br> - Công nghệ/Tiện ích Hỗ trợ sạc nhanh\r\n<br> - Chức năng Sạc\r\n<br> - Đầu vào Truyền dữ liệu\r\n<br> - Đầu ra USB Type-C\r\n<br> - Độ dài dây Type C: 5V - 3A, 9V - 2A, 12V - 3A, 15V - 3A, 20V - 3A (Max 60W)\r\n<br> - Công suất tối đa 2 m\r\n<br> - Sản xuất tại 60 W\r\n<br> - Thương hiệu của Trung Quốc\r\n<br> - Hãng Thế Giới Di Động', 1, 1),
(32, 'Adapter Sạc USB 5W Hydrus CS-TC027 Trắng', '120000', '48000', 'cc84fda5cf.jpg', 1, '2023-05-20', 7, 20, '<b>Thông số kĩ thuật</b>\r\n<br> - Chức năng: Sạc\r\n<br> - Model: CS-TC027\r\n<br> - Đầu vào: 100-240V~50/60Hz, 0.2A\r\n<br> - Đầu ra: USB: 5V - 1A\r\n<br> - Dòng sạc tối đa: 5 W\r\n<br> - Kích thước: Dài 7.1 cm - Ngang 4 cm - Cao 1.9 cm\r\n<br> - Thương hiệu của: Thế Giới Di Động\r\n<br> - Sản xuất tại: Trung Quốc\r\n<br> - Hãng Hydrus. Xem thông tin hãng', 1, 2),
(33, 'Gimbal chống rung Zhiyun Smooth XS', '1370000', '1370000', 'ac471e68eb.jpg', 1, '2023-05-25', 8, 15, '<b>Thông số kĩ thuật:</b>\r\n<br> - Phù hợp với: Điện thoại từ 4.7 - 6.7 inch\r\n<br> - Kết nối: Bluetooth 5.0\r\n<br> - Trục chống rung: Trục cuộn\r\n<br> - Phạm vi góc quay: Trục quay\r\n<br> - Thời gian sử dụng: Trục cuộn 270 độ - Trục xoay 268 độ\r\n<br> - Chế độ: Dùng 4 giờ - Sạc 3 giờ\r\n<br> - Trọng lượng: Chế độ chân dung', 1, 0),
(34, 'Gimbal chống rung Moza Nano SE', '890000', '890000', '8f31bf8870.jpg', 1, '2023-05-25', 8, 14, '<b>Thông số kĩ thuật:</b>\r\n<br> - Phù hợp với: Điện thoại từ 4.7 - 6.7 inch\r\n<br> - Kết nối: Bluetooth 4.0\r\n<br> - Trục chống rung: Bluetooth 5.0\r\n<br> - Phạm vi góc quay: Trục cuộn\r\n<br> - Thời gian sử dụng: Trục cuộn 270 độ\r\n<br> - Chế độ: Dùng 10 giờ - Sạc 2.5 giờ\r\n<br> - Trọng lượng: Chế độ chân dung', 1, 1),
(35, 'Gậy chụp ảnh Bluetooth Tripod Xmobile K06 Đen', '300000', '300000', '6368f1fbc8.jpg', 1, '2023-05-25', 8, 25, '<b>Thông số kĩ thuật:</b>\r\n<br>- Phù hợp với: Điện thoại dưới 6 inch\r\n<br>- Kết nối: Bluetooth', 1, 0),
(36, 'Gậy Chụp Ảnh Bluetooth Cosano HD-P7', '150000', '150000', '4c40bb23e1.jpg', 1, '2023-05-25', 8, 30, '<b>Thông số kĩ thuật:</b>\r\n<br> - Tương thích: Điện thoại dưới 6 inch\r\n<br> - Thời gian sử dụng: 20 giờ\r\n<br> - Thời gian sạc đầy: 0.5 giờ\r\n<br> - Độ dài tối thiểu: 20 cm\r\n<br> - Độ dài tối đa: 80 cm\r\n<br> - Thương hiệu của: Trung Quốc\r\n<br> - Sản xuất tại: Trung Quốc', 1, 0),
(37, 'Gậy Chụp Ảnh Xmobile Hình Cô gái CSA005', '90000', '90000', '93005fbfe0.jpg', 1, '2023-05-25', 8, 50, '<b>Thông số kĩ thuật:</b>\r\n<br> - Phù hợp với: Điện thoại dưới 6 inch', 1, 0),
(38, 'Gậy Chụp Ảnh Osmia OW5', '70000', '70000', '7a631cb669.jpg', 1, '2023-05-25', 8, 100, '<b>Thông số kĩ thuật:</b>\r\n<br> - Phù hợp với: Điện thoại dưới 6 inch', 1, 0),
(39, 'Gậy Chụp Ảnh Mini Cosano CW1', '50000', '50000', '7c347eadda.jpg', 1, '2023-05-25', 8, 100, '<b>Thông số kĩ thuật:</b>\r\n<br> - Phù hợp với: Điện thoại dưới 6 inch', 1, 0),
(40, 'Gậy Chụp Ảnh Osmia OW4', '70000', '70000', '8d4973b1b3.jpg', 1, '2023-05-25', 8, 100, '<b>Thông số kĩ thuật:</b>\r\n<br> - Phù hợp với: Điện thoại dưới 6 inch', 1, 0),
(41, 'Gậy Chụp Ảnh Xmobile Hình Stitch CSA004', '90000', '90000', 'ce2d8b2ae6.jpg', 1, '2023-05-25', 8, 98, '<b>Thông số kĩ thuật:</b>\r\n<br> - Phù hợp với: Điện thoại dưới 6 inch', 1, 2),
(42, 'Gậy Chụp Ảnh Osmia OW2', '70000', '70000', 'e1afeccdd5.jpg', 1, '2023-05-25', 8, 100, '<b>Thông số kĩ thuật:</b>\r\n<br> - Phù hợp với: Điện thoại dưới 6 inch', 1, 0),
(43, 'Gậy Chụp Ảnh Xmobile Hình Kitty CSA003', '90000', '89999', 'a18a5dd51f.jpg', 1, '2023-05-25', 8, 100, '<b>Thông số kĩ thuật:</b>\r\n<br> - Phù hợp với: Điện thoại dưới 6 inch', 1, 0),
(44, 'Đế điện thoại xe hơi Vent mount Pro With MagSafe Belkin WIC002btGR Bạc', '1590000', '1590000', '4377426429.jpg', 1, '2023-05-25', 9, 50, '<b>Đặc điểm nổi bật</b>\r\n<br> - Thiết kế để gắn ở quạt gió trên ô tô.\r\n<br> - Thiết kế riêng cho dòng iPhone 12, kết nối Magsafe chắc chắn.\r\n<br> - Tương thích với ốp lưng MagSafe (được Apple công nhận).', 1, 0),
(45, 'Đế điện thoại xe hơi Vent mount Belkin F7U017BT Đen', '769000', '669000', '092b939367.jpg', 1, '2023-05-25', 9, 100, '<b>Đặc điểm nổi bật</b>\r\n<br> - Kiểu dáng nhỏ nhắn, phù hợp đa số các lỗ thông hơi trên ô tô. \r\n<br> - Sử dụng ở chế độ dọc hoặc ngang linh hoạt nhờ khả năng xoay 180 độ.\r\n<br> - Vừa vặn cho smartphone có màn hình tối đa 5.5 inch (bao gồm ốp điện thoại).\r\n<br> - Tích hợp giá đỡ cáp, thu gọn cáp sạc và sử dụng tiện lợi. ', 1, 0),
(46, 'Đế Laptop Rain Design RD10038 Nhôm Xám', '1290000', '1290000', 'd11f8afa93.jpg', 1, '2023-05-25', 9, 100, '<b>Đặc điểm nổi bật</b>\r\n<br> - Thiết kế đế laptop dọc độc đáo giúp tiết kiệm không gian bàn làm việc. \r\n<br> - Chất liệu nhôm (Aluminum) nguyên khối liền mảnh sang trọng, bền bỉ, tản nhiệt hiệu quả. \r\n<br> - Bên trong khe sườn để Macbook, có đệm bọc cao su chống trầy xước máy.\r\n<br> - Dùng cho mọi dòng Macbook từ 12 – 16 inch và các máy tính xách tay tương thích khác.', 1, 0),
(47, 'Đế Laptop Rain Design RD10037 Nhôm Bạc', '1290000', '1290000', '1e470c5392.jpg', 1, '2023-05-25', 9, 100, '<b>Đặc điểm nổi bật</b>\r\n<br> - Thiết kế bằng hợp kim nhôm (Aluminum) cao cấp nguyên khối chắc chắn, bền bỉ.\r\n<br> - Giá đỡ máy tính xách tay dọc giúp tiết kiệm không gian bàn làm việc\r\n<br> - Tăng luồng không khí xung quanh để giúp máy tản nhiệt tốt hơn.\r\n<br> - Bên trong khe sườn để Macbook có đệm bọc cao su cao cấp bảo vệ thiết bị đặt vào giá đỡ không bị trầy xước.\r\n<br> - Phù hợp với tất cả các Macbook từ 12 – 16 inch và các dòng laptop tương tự khác', 1, 0),
(48, 'Đế Tablet Rain Design RD10055 Nhôm Xám', '1190000', '1190000', 'c53bbd26ae.jpg', 1, '2023-05-25', 9, 100, '<b>Đặc điểm nổi bật</b>\r\n<br> - Vẻ ngoài sang trọng, chân đế lớn đặt vững vàng trên mặt phẳng.\r\n<br> - Điều khiển góc nghiêng 10º - 50º chính xác để có tầm nhìn xem phim phù hợp nhất. \r\n<br> - Bằng nhôm nguyên khối cao cấp bền bỉ, tản nhiệt hiệu quả. \r\n<br> - Sạc pin tiện lợi qua khe cắm sạc. \r\n<br> - Đặt vừa các dòng iPad từ 9.7 - 12.9 inch và nhiều mẫu tablet khác.', 1, 0),
(49, 'Đế Laptop Rain Design RD12031 Nhôm Bạc', '1790000', '1790000', 'c3071307e6.jpg', 1, '2023-05-25', 9, 100, '<b>Đặc điểm nổi bật</b>\r\n<br> - Điều chỉnh độ cao dễ dàng với thanh trượt phía trước và nâng màn hình lên ngang tầm mắt để có tư thế tốt hơn.\r\n<br> - Miếng đệm cao su trên giá đỡ bảo vệ máy tính xách tay và bàn của bạn.\r\n<br> - Thiết kế nghiêng giúp tản nhiệt tốt, tạo khoảng cách phù hợp giữa mắt người dùng và màn hình máy tính.\r\n<br> - Chất liệu hợp kim nhôm (Aluminum) cao cấp nguyên khối, làm mát máy tính giúp tản nhiệt tối ưu nhất.\r\n<br> - Phù hợp với tất cả các Macbook từ 12 inch – 16 inch và hầu hết các máy tính xách tay khác.', 1, 0),
(50, 'Đế Laptop Rain Design RD12031 Nhôm Bạc', '1790000', '1790000', 'c8f009fc40.jpg', 1, '2023-05-26', 9, 100, '<b>Đặc điểm nổi bật:</b>\r\n<br> - Điều chỉnh độ cao dễ dàng với thanh trượt phía trước và nâng màn hình lên ngang tầm mắt để có tư thế tốt hơn.\r\n<br> - Miếng đệm cao su trên giá đỡ bảo vệ máy tính xách tay và bàn của bạn.\r\n<br> - Thiết kế nghiêng giúp tản nhiệt tốt, tạo khoảng cách phù hợp giữa mắt người dùng và màn hình máy tính.\r\n<br> - Chất liệu hợp kim nhôm (Aluminum) cao cấp nguyên khối, làm mát máy tính giúp tản nhiệt tối ưu nhất.\r\n<br> - Phù hợp với tất cả các Macbook từ 12 inch – 16 inch và hầu hết các máy tính xách tay khác.', 1, 0),
(51, 'Đế Laptop Rain Design RD10074 Nhôm Xám', '1690000', '1690000', '8896355bbd.jpg', 1, '2023-05-26', 9, 100, '<b>Đặc điểm nổi bật:</b>\r\n<br> - Thiết kế hiện đại, màu xám trang nhã, tiện sắp đặt.\r\n<br> - Đổi hướng máy tính dễ dàng với chân đế xoay 360 độ.\r\n<br> - Nâng cao thiết bị đến 15 cm kết hợp thiết kế nghiêng giúp làm việc tiện lợi. \r\n<br> - Làm từ nhôm (Aluminum) nguyên khối nhẹ bền, hạn chế ăn mòn. \r\n<br> - Đặt vừa các Macbook cỡ từ 12 - 16 inch và những máy tính xách tay có kích thước phù hợp khác.', 1, 0),
(52, 'Đế Laptop Rain Design RD10073 Nhôm Gold', '1690000', '1690000', '991847a91b.jpg', 1, '2023-05-26', 9, 100, '<b>Đặc điểm nổi bật:</b>\r\n<br> - Thiết kế hiện đại, màu xám trang nhã, tiện sắp đặt.\r\n<br> - Đổi hướng máy tính dễ dàng với chân đế xoay 360 độ.\r\n<br> - Nâng cao thiết bị đến 15 cm kết hợp thiết kế nghiêng giúp làm việc tiện lợi. \r\n<br> - Làm từ nhôm (Aluminum) nguyên khối nhẹ bền, hạn chế ăn mòn. \r\n<br> - Đặt vừa các Macbook cỡ từ 12 - 16 inch và những máy tính xách tay có kích thước phù hợp khác.', 1, 0),
(53, 'Đế Laptop Rain Design RD10036 Nhôm Bạc', '1690000', '1690000', 'fc706e7b5e.jpg', 1, '2023-05-26', 9, 100, '<b>Đặc điểm nổi bật:</b>\r\n<br> - Thiết kế hiện đại, màu xám trang nhã, tiện sắp đặt.\r\n<br> - Đổi hướng máy tính dễ dàng với chân đế xoay 360 độ.\r\n<br> - Nâng cao thiết bị đến 15 cm kết hợp thiết kế nghiêng giúp làm việc tiện lợi. \r\n<br> - Làm từ nhôm (Aluminum) nguyên khối nhẹ bền, hạn chế ăn mòn. \r\n<br> - Đặt vừa các Macbook cỡ từ 12 - 16 inch và những máy tính xách tay có kích thước phù hợp khác.', 1, 0),
(54, 'Đế Laptop Rain Design RD10082 Nhôm Bạc', '1590000', '1590000', 'e9924e14d6.jpg', 1, '2023-05-26', 9, 100, '<b>Đặc điểm nổi bật:</b>\r\n<br> - Độ cao màn hình đến 75 mm, giảm nhiệt máy tối ưu. \r\n<br> - Làm từ nhôm (aluminum) nguyên khối dày chắc, sử dụng bền. \r\n<br> - Thích hợp cho các Macbook, laptop, máy tính bảng dài dưới 10.4 inch.\r\n<br> - Thiết kế hiện đại, thanh mảnh, có thể gập gọn, mang theo đến bất kỳ nơi nào.\r\n<br> - Có túi đựng chuyên dụng, cất giữ giá đỡ đơn giản. ', 1, 0),
(55, 'Đế Laptop Rain Design RD10080 Nhôm Bạc', '750000', '750000', 'c36db8ae2f.jpg', 1, '2023-05-26', 9, 100, '<b>Đặc điểm nổi bật:</b>\r\n<br> - Nâng máy tính xách tay lên 67 mm tạo hiệu quả tản nhiệt tốt hơn.\r\n<br> - Chất liệu nhôm (aluminum) nguyên khối cao cấp có độ bền cao.\r\n<br> - Tương thích với hầu hết laptop, Macbook, tablet dài dưới 10.4 inch.\r\n<br> - Chân đế bọc cao su chống trơn trượt.\r\n<br> - Thiết kế nhẹ và mỏng, chỉ 100 gram, dễ dịch chuyển và sử dụng.', 1, 0),
(56, 'Đế Laptop WIWU S400 Nhôm Bạc', '750000', '675000', 'c8c114dcb1.jpg', 1, '2023-05-26', 9, 100, '<b>Đặc điểm nổi bật:</b>\r\n<br> - Kiểu dáng hiện đại, có thể gập lại, tiện mang theo.\r\n<br> - Trên các bề mặt tiếp xúc có miếng silicon chống trượt tốt.\r\n<br> - Chiều cao điều chỉnh được 6 mức độ cho bạn dùng laptop với tư thế dễ chịu nhất.\r\n<br> - Tản nhiệt tốt, kéo dài độ bền cho laptop/macbook của bạn hiệu quả.', 1, 0),
(57, 'Đế Laptop JCPAL JCP6110 Nhôm Bạc', '780000', '702000', '64759cc0bc.jpg', 1, '2023-05-26', 9, 100, '<b>Đặc điểm nổi bật:</b>\r\n<br> - Thiết kế nhôm nguyên khối màu bạc cao cấp và siêu nhẹ.\r\n<br> - Cho máy luôn thoáng mát, làm tăng tuổi thọ máy.\r\n<br> - Có thể điều chỉnh được nhiều góc độ cho phù hợp với bạn.\r\n<br> - Phù hợp với tất cả dòng laptop/macbook giúp vận hành tối ưu, nhẹ nhàng.', 1, 0),
(58, 'Đế điện thoại xe hơi OSMIA CK-CH4 Xám', '120000', '120000', '6295923885.jpg', 1, '2023-05-26', 9, 100, '<b>Đặc điểm nổi bật:</b>\r\n<br> - Thiết kế hiện đại, dễ dùng, có thể xoay 270 độ.\r\n<br> - Tính năng khóa/mở tự động khi đặt điện thoại lên giá đỡ hoặc nhấc điện thoại ra khỏi.\r\n<br> - Phù hợp cho điện thoại kích thước từ 6.0 inch trở xuống.\r\n<br> - Chân đế hút chân không Silicon có thể hút chắc chắn.', 1, 0),
(59, 'Đế điện thoại OSMIA CK-CH1/CK-CH3', '50000', '50000', '61a3598e8c.jpg', 1, '2023-05-26', 9, 1000, '<b>Đặc điểm nổi bật:</b>\r\n<br> - Thiết kế đẹp mắt, nhỏ gọn.\r\n<br> - Giữ điện thoại chắc chắn.\r\n<br> - Dễ dàng theo dõi thông báo lúc làm việc.', 1, 0),
(60, 'Đế điện thoại xe hơi OSMIA CK-CH10/CK-CH11', '100000', '100000', 'dea9a70312.jpg', 1, '2023-05-26', 9, 200, '<b>Đặc điểm nổi bật:</b>\r\n<br> - Thiết kế độc đáo, có khả năng xoay 360 độ.\r\n<br> - Ba chấu thông minh tự động ôm khít điện thoại.\r\n<br> - Ba chấu được trang bị miếng cao su dày và êm.\r\n<br> - Phần đế thiết kế dạng kẹp chắc chắn.\r\n<br> - Tiện lợi xem thông báo, xem map (bản đồ) khi lái xe.', 1, 0),
(61, 'Đế điện thoại trên xe Cosano PH-Z2', '80000', '80000', '9a382258aa.jpg', 1, '2023-05-26', 9, 100, '<b>Đặc điểm nổi bật:</b>\r\n<br> - Thiết kế đẹp mắt, nhỏ gọn.\r\n<br> - Giữ điện thoại chắc chắn.\r\n<br> - Đế hút chân không giúp bám chặt trên nhiều bề mặt.\r\n<br> - Có thể linh hoạt xoay 360 độ, ngang hoặc dọc.', 1, 0),
(62, 'Đế điện thoại trên xe Cosano PH-Z1', '100000', '100000', '90d6e87d73.jpg', 1, '2023-05-26', 9, 100, '<b>Đặc điểm nổi bật:</b>\r\n<br> - Thiết kế đẹp mắt, nhỏ gọn.\r\n<br> - Giữ điện thoại chắc chắn.\r\n<br> - Đế hút chân không giúp bám chặt trên nhiều bề mặt.\r\n<br> - Có thể linh hoạt xoay 360 độ, ngang hoặc dọc.', 1, 0),
(63, 'Đế điện thoại trên xe máy Esaver JHD-40HD12 Đen', '120000', '120000', '4affeca067.jpg', 1, '2023-05-26', 9, 99, '<b>Đặc điểm nổi bật:</b>\r\n<br> - Thiết kế chắc chắn, an toàn.\r\n<br> - Tiện lời gọi điện, xem bản đồ khi đang di chuyển bằng xe máy.\r\n<br> - Trang bị miếng lót đệm êm chống sock và tăng độ bám dính.\r\n<br> - Có khả năng xoay 360 độ linh hoạt góc nhìn.\r\n<br> - Thiết kế công tắc mở/ khóa giúp cố định điện thoại.\r\n<br> - Dễ dàng điều chỉnh kích thước điện thoại.', 1, 1),
(64, 'Dây đeo điện thoại OSMIA silicon CRS ', '30000', '30000', '362dbff9ea.jpg', 1, '2023-05-26', 10, 500, '<b>Đặc điểm nổi bật:</b>\r\n<br> - Sử dụng chất liệu silicon có độ bền cao.\r\n<br> - Màu sắc nổi bật, trẻ trung.\r\n<br> - Móc vào ốp lưng điện thoại, máy ảnh.', 1, 0),
(65, 'Bộ 2 móc điện thoại OSMIA CK-CRS10 Mèo cá heo xanh', '60000', '50000', '9a5fd3d85e.jpg', 1, '2023-05-26', 10, 500, 'Cập nhật sau', 1, 0),
(66, 'Bộ 2 móc điện thoại OSMIA CK-CRS11 Hươu cánh cụt vàng', '60000', '50000', 'd1d38269e3.jpg', 1, '2023-05-26', 10, 500, 'Cập nhật sau', 1, 0),
(67, 'Bộ 2 móc điện thoại OSMIA CK-CRS34 Xanh hồng', '60000', '50000', '3bf831a11b.jpg', 1, '2023-05-26', 10, 500, 'Cập nhật sau', 1, 0),
(68, 'Bộ 2 móc điện thoại OSMIA CK-CRS43 Mèo sóc nâu', '60000', '50000', '080cd497be.jpg', 1, '2023-05-26', 10, 500, 'Cập nhật sau', 1, 0),
(69, 'Bộ 2 móc điện thoại nhựa dẻo OSMIA CK-CRS3 Nai Mèo Đen', '40000', '40000', 'a161eb2ee2.jpg', 1, '2023-05-26', 10, 100, ' ', 1, 0),
(70, 'Bộ 2 móc điện thoại nhựa dẻo OSMIA CK-CRS2 Gấu Khỉ Đen', '40000', '40000', '75de1eab05.jpg', 1, '2023-05-26', 10, 100, ' ', 1, 0),
(71, 'Bộ 2 móc điện thoại nhựa dẻo OSMIA CK-CRS1 Mèo Hoa Đen', '40000', '40000', '108f690fea.jpg', 1, '2023-05-26', 10, 100, ' ', 1, 0),
(72, 'Đế dán điện thoại OSMIA POP006 Banh Trắng đen', '50000', '40000', 'f1274d5421.jpg', 1, '2023-05-26', 10, 100, ' ', 1, 0),
(73, 'Đế dán điện thoại OSMIA POP005 Hoa Văn Xanh lá', '50000', '40000', '6d96eb1fc2.jpg', 1, '2023-05-26', 10, 100, ' ', 1, 0),
(74, 'Móc dán điện thoại OSMIA RingCK044 Sọc Vàng', '50000', '40000', '2d7959b1e9.jpg', 1, '2023-05-26', 10, 100, ' ', 1, 0),
(75, 'Móc dán điện thoại OSMIA RingCK043 Sao Đen', '50000', '40000', '2d833330e0.jpg', 1, '2023-05-26', 10, 100, ' ', 1, 0),
(76, 'Móc dán điện thoại OSMIA RingCK042 Vân Đen', '50000', '40000', '983c1d57dc.jpg', 1, '2023-05-26', 10, 100, ' ', 1, 0),
(77, 'Móc dán điện thoại OSMIA RingCK041 Vân Hồng', '50000', '40000', '6a08a530f0.jpg', 1, '2023-05-26', 10, 100, ' ', 1, 0),
(78, 'Đế dán điện thoại OSMIA POP004 Hoa văn Đen', '50000', '40000', '2e0530236f.jpg', 1, '2023-05-26', 10, 100, ' ', 1, 0),
(79, 'Đế dán điện thoại OSMIA POP003 Gold', '30000', '25000', '8e0eaa9084.jpg', 1, '2023-05-26', 10, 100, ' ', 1, 0),
(80, 'Móc dán điện thoại OSMIA RingCK039 Cún Trắng', '50000', '40000', 'b4114b0ed4.jpg', 1, '2023-05-26', 10, 100, ' ', 1, 0),
(81, 'Móc dán điện thoại OSMIA RingCK038', '50000', '40000', '712cb77544.jpg', 1, '2023-05-26', 10, 100, ' ', 1, 0),
(82, 'Móc dán điện thoại OSMIA RingCK037 Mèo Trắng', '50000', '50000', '92d84079ca.jpg', 1, '2023-05-26', 10, 100, '  ', 1, 0),
(83, 'Đế dán điện thoại OSMIA POP002 Xanh dương', '30000', '25000', '5f45e630cc.jpg', 1, '2023-05-26', 10, 100, '  ', 1, 0),
(84, 'Đế dán điện thoại OSMIA POP001 Cờ Đỏ', '30000', '25000', '1629ce9d6d.jpg', 1, '2023-05-26', 10, 100, '  ', 1, 0),
(85, 'Móc dán điện thoại OSMIA RingCK036 Viền Hồng', '50000', '40000', '6d27c9733b.jpg', 1, '2023-05-26', 10, 100, '  ', 1, 0),
(86, 'Móc dán điện thoại OSMIA RingCK034 Rose Gold', '50000', '40000', '0d237c24a4.jpg', 1, '2023-05-26', 10, 100, '  ', 1, 0),
(87, 'Móc dán điện thoại OSMIA RingCK035 Xám', '50000', '40000', '1d967b9e80.jpg', 1, '2023-05-26', 10, 100, '  ', 1, 0),
(88, 'Móc treo phích cắm JM HOOKWJM02', '50000', '40000', '8bfbae28f9.jpg', 1, '2023-05-26', 10, 100, '  ', 1, 0),
(89, 'Móc treo phích cắm JM HOOKWJM01', '50000', '40000', 'c4a4c8672e.jpg', 1, '2023-05-26', 10, 100, '  ', 1, 0),
(90, 'Móc treo điện thoại Cosano Hình Búp Bê', '40000', '30000', 'ef86faa854.jpg', 1, '2023-05-26', 10, 99, '  ', 1, 1),
(91, 'Túi chống nước Cosano JMG-C-20 Xanh lá', '100000', '50000', '41e413344e.jpg', 1, '2023-05-26', 11, 100, '  ', 1, 0),
(92, 'Túi chống nước Cosano JMG-C-21 Xanh biển', '100000', '50000', '580188b2fb.jpg', 1, '2023-05-26', 11, 121, ' ', 1, 2),
(93, 'Túi chống nước Cosano 5 inch Vàng Chanh', '100000', '50000', '580aa82f51.jpg', 1, '2023-05-26', 11, 123, '  ', 1, 0),
(94, 'Túi chống nước 5 inch Cosano Hình Chú mèo', '100000', '50000', '405b0a48ed.jpg', 1, '2023-05-26', 11, 123, '  ', 1, 0),
(95, 'Túi chống nước 5 inch Cosano Hình Trái cây Xanh lá', '100000', '50000', '14c00d39c2.jpg', 1, '2023-05-26', 11, 123, '  ', 1, 0),
(96, 'Túi chống nước 5 inch Cosano Hình Khiên Captain Xanh', '100000', '50000', 'fe6020d209.jpg', 1, '2023-05-26', 11, 123, '  ', 1, 0),
(97, 'Túi chống nước 5 inch Cosano Hình Chú thỏ Hồng', '100000', '50000', '309ffc9575.jpg', 1, '2023-05-26', 11, 123, '  ', 1, 0),
(98, 'Túi chống nước 5 inch Cosano Trong suốt', '100000', '50000', 'e7f8e62c73.jpg', 1, '2023-05-26', 11, 122, '  ', 1, 1),
(99, 'Tai nghe Bluetooth AirPods 2 Wireless charge Apple MRXJ2 ', '5590000', '3490000', 'a19b1392ad.jpg', 1, '2023-05-26', 12, 99, '<b>Thông số kỹ thuật:</b> \r\n<br> - Thời gian tai nghe: Dùng 5 giờ - Sạc 2 giờ\r\n<br> - Thời gian hộp sạc: Dùng 24 giờ - Sạc 3 giờ\r\n<br> - Cổng sạc: Lightning, Sạc không dây\r\n<br> - Công nghệ âm thanh: Chip Apple H1\r\n<br> - Tương thích: Android, IOS (iPhone)\r\n<br> - Tiện ích: Có mic thoại\r\n<br> - Hỗ trợ kết nối: Bluetooth 5.0\r\n<br> - Điều khiển bằng: Cảm ứng chạm\r\n<br> - Hãng Apple', 1, 1),
(100, 'Tai nghe Bluetooth AirPods Pro MagSafe Charge Apple MLWK3 Trắng', '6790000', '5190000', '93eda2c3ec.jpg', 1, '2023-05-26', 12, 93, '<b>Thông số kỹ thuật:</b> \r\n<br> - Pin: Dùng 5 giờ - Sạc 2 giờ\r\n<br> - Cổng sạc: Lightning, Sạc không dây, Sạc MagSafe\r\n<br> - Công nghệ âm thanh: Active Noise CancellationAdaptive EQCustom high-excursion Apple driverHigh Dynamic RangeSpatial AudioTransparency Mode\r\n<br> - Tương thích: Android, IOS (iPhone), iPadOS (iPad), MacOS (Macbook, iMac)\r\n<br> - Tiện ích: Chống nước IPX4Chống ồnCó mic thoại\r\n<br> - Hỗ trợ kết nối: Bluetooth 5.0\r\n<br> - Điều khiển bằng: Cảm ứng chạm\r\n<br> - Hãng Apple. ', 1, 5),
(101, 'Tai nghe Bluetooth AirPods 3 Apple MME73 Trắng', '5490000', '4490000', '968abb4093.jpeg', 1, '2023-05-26', 12, 99, '<b>Thông số kỹ thuật:</b> \r\n<br> - Pin: Dùng 6 giờ - Sạc 2 giờ\r\n<br> - Cổng sạc: Lightning, Sạc không dây\r\n<br> - Công nghệ âm thanh: Adaptive EQCustom high-excursion Apple driverHigh Dynamic RangeSpatial Audio\r\n<br> - Tương thích: Android, iOS (iPhone), iPadOS (iPad), MacOS (Macbook, iMac)\r\n<br> - Tiện ích: Chống nước IPX4, Có mic thoại, Sạc không dây\r\n<br> - Hỗ trợ kết nối: Bluetooth 5.0\r\n<br> - Điều khiển bằng: Cảm ứng chạm\r\n<br> - Hãng Apple. Xem thông tin hãng', 1, 1),
(102, 'Tai nghe Bluetooth True Wireless Galaxy Buds Pro Bạc', '4990000', '2490000', '67417a99ec.jpeg', 1, '2023-05-26', 12, 100, '<b>Thông số kỹ thuật:</b> \r\n<br> - Thời gian tai nghe: Dùng 8 giờ - Sạc 3 giờ\r\n<br> - Thời gian hộp sạc: Dùng 20 giờ - Sạc 3 giờ\r\n<br> - Cổng sạc: Sạc không dây, Type-C\r\n<br> - Công nghệ âm thanh: Active Noise Cancellation, Dolby Head Tracking\r\n<br> - Tương thích: Android, IOS (iPhone)Windows\r\n<br> - Ứng dụng kết nối: SmartThings\r\n<br> - Tiện ích: Chống nước IPX7, Chống ồn, Có mic thoại\r\n<br> - Hỗ trợ kết nối: Bluetooth 5.0\r\n<br> - Điều khiển bằng: Cảm ứng chạm\r\n<br> - Hãng Samsung. ', 1, 0),
(103, 'Tai nghe Bluetooth True Wireless JBL T115TWS', '1490000', '990000', '743abf4bd5.jpeg', 1, '2023-05-26', 12, 100, '<b>Thông số kỹ thuật:</b> \r\n<br> - Thời gian tai nghe: Dùng 6 giờ - Sạc 2 giờ\r\n<br> - Thời gian hộp sạc: Dùng 15 giờ - Sạc 2 giờ\r\n<br> - Cổng sạc: Type-C\r\n<br> - Công nghệ âm thanh: JBL Pure Bass\r\n<br> - Tương thích: Android, iOS (iPhone)Windows\r\n<br> - Tiện ích: Có mic thoại, Sạc nhanh, Đệm tai đi kèm\r\n<br> - Hỗ trợ kết nối: Bluetooth 5.0\r\n<br> - Điều khiển bằng: Phím nhấn\r\n<br> - Hãng JBL. Xem thông tin hãng', 1, 0),
(104, 'Tai nghe Bluetooth True Wireless OPPO ENCO Air 2 ETE11', '1590000', '1351000', '340df0b397.jpg', 1, '2023-05-26', 12, 98, '<b>Thông số kỹ thuật:</b> \r\n<br> - Thời gian tai nghe: Dùng 4 giờ - Sạc 1.5 giờ\r\n<br> - Thời gian hộp sạc: Dùng 24 giờ - Sạc 2 giờ\r\n<br> - Cổng sạc: Type-C\r\n<br> - Công nghệ âm thanh: codecAAC, codecSBC\r\n<br> - Tương thích: Android, iOS, WindowsMacOS\r\n<br> - Ứng dụng kết nối: HeyMelody App\r\n<br> - Tiện ích: Chống nước IPX4, Game Mode, Hỗ trợ chụp ảnh, Kết nối 1 chạm Fast Pair, Sử dụng độc lập 1 bên tai nghe\r\n<br> - Hỗ trợ kết nối: Bluetooth 5.2\r\n<br> - Điều khiển bằng: Cảm ứng chạm\r\n<br> - Hãng OPPO. ', 1, 2),
(105, 'Tai nghe Bluetooth True Wireless AVA+ DS200A-WB', '650000', '399000', 'aa38b6596c.png', 1, '2023-05-26', 12, 100, '<b>Thông số kỹ thuật:</b> \r\n<br> - Thời gian tai nghe: Dùng 4 giờ - Sạc 1.5 giờ\r\n<br> - Thời gian hộp sạc: Dùng 12 giờ - Sạc 1.5 giờ\r\n<br> - Cổng sạc: Micro USB\r\n<br> - Tương thích: Android, iOS (iPhone). iPadOS (iPad), MacOS (Macbook, iMac), Windows\r\n<br> - Tiện ích: Có mic thoại\r\n<br> - Hỗ trợ kết nối: Bluetooth 5.0\r\n<br> - Điều khiển bằng: Phím nhấn\r\n<br> - Hãng AVA+. ', 1, 0),
(106, 'Tai nghe Bluetooth True Wireless Sony WF-C500', '2290000', '2080000', 'e6ea3562f1.jpg', 1, '2023-05-26', 12, 100, '<b>Thông số kỹ thuật:</b> \r\n<br> - Thời gian tai nghe: Dùng 10 giờ - Sạc 2.5 giờ\r\n<br> - Thời gian hộp sạc: Dùng 20 giờ - Sạc 3 giờ\r\n<br> - Cổng sạc: Type-C\r\n<br> - Công nghệ âm thanh: 360 Reality AudioDSEE\r\n<br> - Tương thích: Android, iOS, Windows, MacOS (Macbook, iMac)\r\n<br> - Ứng dụng kết nối: Sony Headphones Connect\r\n<br> - Tiện ích: Chống nước IPX4, Có mic thoại, Kết nối 1 chạm Fast Pair, Sử dụng độc lập 1 bên tai nghe\r\n<br> - Hỗ trợ kết nối: Bluetooth 5.0\r\n<br> - Điều khiển bằng: Phím nhấn\r\n<br> - Hãng Sony. ', 1, 0),
(107, 'Tai nghe Bluetooth True Wireless Rezo F15', '800000', '480000', 'b94f08bce8.jpeg', 1, '2023-05-26', 12, 100, '<b>Thông số kỹ thuật:</b> \r\n<br> - Thời gian tai nghe: Dùng 4 giờ - Sạc 1.5 giờ\r\n<br> - Thời gian hộp sạc: Dùng 20 giờ - Sạc 1.5 giờ\r\n<br> - Cổng sạc: Type-C\r\n<br> - Tương thích: Android, iOS, Windows, MacOS (Macbook, iMac)\r\n<br> - Tiện ích: Chống nước IPX5, Có mic thoại, Sử dụng độc lập 1 bên tai nghe\r\n<br> - Hỗ trợ kết nối: Bluetooth 5.0\r\n<br> - Điều khiển bằng: Cảm ứng chạm\r\n<br> - Hãng Rezo. ', 1, 0),
(108, 'Tai nghe Bluetooth True Wireless Hydrus TS12BC', '500000', '220', 'c23a2411eb.jpg', 1, '2023-05-26', 12, 100, '<b>Thông số kỹ thuật:</b> \r\n<br> - Thời gian tai nghe: Dùng 3.5 giờ - Sạc 1 giờ\r\n<br> - Thời gian hộp sạc: Dùng 12 giờ - Sạc 1.5 giờ\r\n<br> - Cổng sạc: Type-C\r\n<br> - Tương thích: Android, iOS (iPhone), MacOS (Macbook, iMac), Windows\r\n<br> - Tiện ích: Đệm tai đi kèm\r\n<br> - Hỗ trợ kết nối: Bluetooth 5.0\r\n<br> - Điều khiển bằng: Phím nhấn\r\n<br> - Hãng Hydrus. ', 1, 0),
(109, 'Loa Bluetooth JBL Charge 5', '3990000', '3990000', '7e65702670.jpg', 1, '2023-05-26', 13, 100, '<b>Thông số kỹ thuật:</b> \r\n<br> - Tổng công suất: 40 W\r\n<br> - Nguồn: Pin\r\n<br> - Thời gian sử dụng: Dùng khoảng 20 tiếngSạc khoảng 4 tiếng\r\n<br> - Kết nối không dây: Bluetooth 5.1\r\n<br> - Kết nối khác: USB\r\n<br> - Tiện ích: Chống nước, chống bụi IP67Kết nối cùng lúc 2 loaSạc được cho thiết bị khác (cổng USB)\r\n<br> - Phím điều khiển: Bật / tắt nguồnBật/tắt bluetoothGhép đôiPhát/dừng chơi nhạcTăng/giảm âm lượng\r\n<br> - Thương hiệu của: Mỹ\r\n<br> - Hãng JBL. Xem thông tin hãng', 1, 0),
(110, 'Loa Bluetooth Sony SRS-XB13', '1290000', '1290000', 'b09130650c.jpg', 1, '2023-05-26', 13, 100, '<b>Thông số kỹ thuật:</b> \r\n<br> - Tổng công suất: 5 W\r\n<br> - Nguồn: Pin\r\n<br> - Thời gian sử dụng: Dùng khoảng 16 tiếngSạc khoảng 4 - 5 tiếng\r\n<br> - Kết nối không dây: Bluetooth 4.2\r\n<br> - Tiện ích: Chống nước, chống bụi IP67Kết nối cùng lúc 2 loa\r\n<br> - Phím điều khiển: Bật/tắt bluetoothNghe/nhận cuộc gọiNút nguồnPhát/dừng chơi nhạcTăng/giảm âm lượng\r\n<br> - Thương hiệu của: Nhật Bản\r\n<br> - Hãng Sony.', 1, 0);

-- --------------------------------------------------------

--
-- Cấu trúc bảng cho bảng `role`
--

CREATE TABLE `role` (
  `id` int(11) NOT NULL,
  `name` varchar(255) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Đang đổ dữ liệu cho bảng `role`
--

INSERT INTO `role` (`id`, `name`) VALUES
(1, 'Admin'),
(2, 'Normal'),
(3, 'Staff');

-- --------------------------------------------------------

--
-- Cấu trúc bảng cho bảng `users`
--

CREATE TABLE `users` (
  `id` int(11) NOT NULL,
  `email` varchar(255) NOT NULL,
  `fullname` varchar(255) NOT NULL,
  `dob` date NOT NULL,
  `password` varchar(255) NOT NULL,
  `role_id` int(11) NOT NULL,
  `status` tinyint(1) NOT NULL,
  `address` varchar(500) NOT NULL,
  `isConfirmed` tinyint(4) NOT NULL DEFAULT 0,
  `captcha` varchar(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Đang đổ dữ liệu cho bảng `users`
--

INSERT INTO `users` (`id`, `email`, `fullname`, `dob`, `password`, `role_id`, `status`, `address`, `isConfirmed`, `captcha`) VALUES
(1, 'admin@gmail.com', 'Admin', '0000-00-00', '0cc175b9c0f1b6a831c399e269772661', 1, 1, '', 1, ''),
(2, 'nguyendung080703@gmail.com', 'Nguyễn Hoàng Dũng', '2003-07-08', '0cc175b9c0f1b6a831c399e269772661', 2, 1, 'Nghệ An', 1, '56666'),
(35, 'nguyendat@gmail.com', 'Nguyễn Thế Đạt', '2003-09-22', '0cc175b9c0f1b6a831c399e269772661', 2, 1, 'Minh Khai, Bắc Từ Liêm, Hà Nội', 1, '87909'),
(42, 'dolam180903@gmail.com', 'Đỗ  Quang Lâm', '2003-09-18', '0cc175b9c0f1b6a831c399e269772661', 3, 1, 'Văn Trì, Bắc Từ Liêm, Hà Nội', 1, '59682');


--
-- Cấu trúc bảng cho bảng `tbl_statistical`
--

CREATE TABLE `statistical` (
  `id` int(11) NOT NULL,
  `order_date` varchar(100) NOT NULL,
  `sales` varchar(200) NOT NULL,
  `profit` varchar(200) NOT NULL,
  `quantity` int(11) NOT NULL,
  `total_order` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Đang đổ dữ liệu cho bảng `statistical`
--

INSERT INTO `statistical` (`id`, `order_date`, `sales`, `profit`, `quantity`, `total_order`) VALUES
(1, '2023-06-08', '16000000', '5600000', 90, 10),
(2, '2023-06-07', '54400000', '7200000', 60, 8),
(3, '2023-06-06', '24000000', '2400000', 45, 7),
(4, '2023-06-05', '36000000', '3040000', 30, 9),
(5, '2023-06-04', '24000000', '1200000', 15, 12),
(6, '2023-06-03', '6400000', '560000', 65, 30),
(7, '2023-06-02', '22400000', '18400000', 32, 20),
(8, '2023-06-01', '20000000', '16000000', 7, 6),
(9, '2023-05-31', '28800000', '22400000', 40, 15),
(10, '2023-05-30', '40000000', '10400000', 89, 19),
(11, '2023-05-29', '16000000', '12000000', 63, 11),
(12, '2023-05-28', '20000000', '12800000', 94, 14),
(13, '2023-05-27', '25600000', '13600000', 16, 10),
(14, '2023-05-26', '26400000', '15200000', 14, 5),
(15, '2023-05-25', '28800000', '14400000', 22, 12),
(16, '2023-05-24', '27200000', '16000000', 33, 20),
(17, '2023-05-23', '20000000', '12800000', 94, 14),
(18, '2023-05-22', '9600000', '5600000', 16, 10),
(19, '2023-05-21', '50400000', '15200000', 14, 5),
(20, '2023-05-20', '52800000', '14400000', 22, 12),
(21, '2023-05-19', '59200000', '16000000', 33, 20),
(22, '2023-05-18', '50400000', '15200000', 14, 5),
(23, '2023-05-17', '52800000', '14400000', 23, 12),
(24, '2023-05-16', '59200000', '16000000', 32, 20),
(25, '2023-05-15', '50400000', '15200000', 14, 5),
(26, '2023-05-14', '52800000', '14400000', 23, 12),
(27, '2023-05-13', '59200000', '16000000', 33, 20),
(28, '2023-05-12', '52800000', '14400000', 23, 12),
(29, '2023-05-11', '59200000', '16000000', 10, 20),
(30, '2023-05-10', '50400000', '15200000', 14, 5),
(31, '2023-05-09', '52800000', '14400000', 23, 12),
(32, '2023-05-08', '59200000', '16000000', 15, 20),
(33, '2023-05-07', '52800000', '14400000', 23, 12),
(34, '2023-05-06', '59200000', '16000000', 30, 22),
(35, '2023-05-05', '52800000', '14400000', 23, 12),
(36, '2023-05-04', '59200000', '16000000', 32, 20),
(37, '2023-05-03', '50400000', '15200000', 14, 5),
(38, '2023-05-02', '52800000', '14400000', 23, 12),
(39, '2023-05-01', '59200000', '16000000', 32, 20),
(40, '2023-04-30', '50400000', '15200000', 14, 5),
(41, '2023-04-29', '52800000', '14400000', 23, 12),
(42, '2023-04-28', '59200000', '16000000', 15, 20),
(43, '2023-04-27', '52800000', '14400000', 23, 12),
(44, '2023-04-26', '59200000', '16000000', 30, 22),
(45, '2023-04-25', '52800000', '14400000', 23, 12),
(46, '2023-04-24', '59200000', '16000000', 32, 20),
(47, '2023-04-23', '50400000', '15200000', 14, 5),
(48, '2023-04-22', '52800000', '14400000', 23, 12),
(49, '2023-04-21', '59200000', '16000000', 32, 20),
(50, '2023-04-20', '50400000', '15200000', 14, 5),
(51, '2023-04-19', '52800000', '14400000', 23, 12),
(52, '2023-04-18', '59200000', '16000000', 15, 20),
(53, '2023-04-17', '52800000', '14400000', 23, 12),
(54, '2023-04-16', '59200000', '16000000', 30, 22),
(55, '2023-04-15', '52800000', '14400000', 23, 12),
(56, '2023-04-14', '59200000', '16000000', 32, 20),
(57, '2023-04-13', '50400000', '15200000', 14, 5),
(58, '2023-04-12', '52800000', '14400000', 23, 12),
(59, '2023-04-11', '59200000', '16000000', 32, 20),
(60, '2023-04-10', '50400000', '15200000', 14, 5),
(61, '2023-04-09', '52800000', '14400000', 23, 12),
(62, '2023-04-08', '59200000', '16000000', 15, 20),
(63, '2023-04-07', '52800000', '14400000', 23, 12),
(64, '2023-04-06', '59200000', '16000000', 30, 22),
(65, '2023-04-05', '52800000', '14400000', 23, 12),
(66, '2023-04-04', '59200000', '16000000', 32, 20),
(67, '2023-04-03', '50400000', '15200000', 14, 5),
(68, '2023-04-02', '52800000', '14400000', 23, 12),
(69, '2023-06-10', '14400000', '5600000', 90, 10),
(70, '2023-06-11', '12000000', '7200000', 60, 8),
(71, '2023-06-12', '16800000', '2400000', 45, 7),
(72, '2023-06-13', '30400000', '3040000', 30, 9),
(73, '2023-06-14', '22800000', '1200000', 15, 12),
(74, '2023-06-15', '5840000', '560000', 65, 30),
(75, '2023-06-16', '400000', '18400000', 32, 20),
(76, '2023-06-17', '4000000', '16000000', 7, 6),
(77, '2023-06-18', '6400000', '22400000', 40, 15),
(78, '2023-06-19', '1200000', '10400000', 89, 19),
(79, '2023-06-20', '4000000', '12000000', 63, 11),
(80, '2023-06-21', '7200000', '12800000', 94, 14),
(81, '2023-06-22', '12000000', '13600000', 16, 10),
(82, '2023-06-23', '11200000', '15200000', 14, 5),
(83, '2023-06-24', '14400000', '14400000', 22, 12);


--
-- Chỉ mục cho các bảng đã đổ
--

--
-- Chỉ mục cho bảng `statistical`
--
ALTER TABLE `statistical`
  ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT cho các bảng đã đổ
--

--
-- AUTO_INCREMENT cho bảng `statistical`
--
ALTER TABLE `statistical`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=70;




--
-- Chỉ mục cho các bảng đã đổ
--

--
-- Chỉ mục cho bảng `cart`
--
ALTER TABLE `cart`
  ADD PRIMARY KEY (`id`),
  ADD KEY `user_id` (`userId`),
  ADD KEY `product_id` (`productId`);

--
-- Chỉ mục cho bảng `categories`
--
ALTER TABLE `categories`
  ADD PRIMARY KEY (`id`);

--
-- Chỉ mục cho bảng `chatbot`
--
ALTER TABLE `chatbot`
  ADD PRIMARY KEY (`id`);

--
-- Chỉ mục cho bảng `orders`
--
ALTER TABLE `orders`
  ADD PRIMARY KEY (`id`),
  ADD KEY `user_id` (`userId`);

--
-- Chỉ mục cho bảng `order_details`
--
ALTER TABLE `order_details`
  ADD PRIMARY KEY (`id`),
  ADD KEY `order_id` (`orderId`),
  ADD KEY `product_id` (`productId`);

--
-- Chỉ mục cho bảng `products`
--
ALTER TABLE `products`
  ADD PRIMARY KEY (`id`),
  ADD KEY `cate_id` (`cateId`);

--
-- Chỉ mục cho bảng `role`
--
ALTER TABLE `role`
  ADD PRIMARY KEY (`id`);

--
-- Chỉ mục cho bảng `users`
--
ALTER TABLE `users`
  ADD PRIMARY KEY (`id`),
  ADD KEY `role_id` (`role_id`);

--
-- AUTO_INCREMENT cho các bảng đã đổ
--

--
-- AUTO_INCREMENT cho bảng `cart`
--
ALTER TABLE `cart`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=123;

--
-- AUTO_INCREMENT cho bảng `categories`
--
ALTER TABLE `categories`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=14;

--
-- AUTO_INCREMENT cho bảng `chatbot`
--
ALTER TABLE `chatbot`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=2;

--
-- AUTO_INCREMENT cho bảng `orders`
--
ALTER TABLE `orders`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=16;

--
-- AUTO_INCREMENT cho bảng `order_details`
--
ALTER TABLE `order_details`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=19;

--
-- AUTO_INCREMENT cho bảng `products`
--
ALTER TABLE `products`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=114;

--
-- AUTO_INCREMENT cho bảng `role`
--
ALTER TABLE `role`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;

--
-- AUTO_INCREMENT cho bảng `users`
--
ALTER TABLE `users`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=44;

--
-- Các ràng buộc cho các bảng đã đổ
--

--
-- Các ràng buộc cho bảng `cart`
--
ALTER TABLE `cart`
  ADD CONSTRAINT `cart_ibfk_1` FOREIGN KEY (`productId`) REFERENCES `products` (`id`),
  ADD CONSTRAINT `cart_ibfk_2` FOREIGN KEY (`userId`) REFERENCES `users` (`id`);

--
-- Các ràng buộc cho bảng `orders`
--
ALTER TABLE `orders`
  ADD CONSTRAINT `orders_ibfk_1` FOREIGN KEY (`userId`) REFERENCES `users` (`id`);

--
-- Các ràng buộc cho bảng `order_details`
--
ALTER TABLE `order_details`
  ADD CONSTRAINT `order_details_ibfk_1` FOREIGN KEY (`productId`) REFERENCES `products` (`id`),
  ADD CONSTRAINT `order_details_ibfk_2` FOREIGN KEY (`orderId`) REFERENCES `orders` (`id`);

--
-- Các ràng buộc cho bảng `products`
--
ALTER TABLE `products`
  ADD CONSTRAINT `products_ibfk_1` FOREIGN KEY (`cateId`) REFERENCES `categories` (`id`);

--
-- Các ràng buộc cho bảng `users`
--
ALTER TABLE `users`
  ADD CONSTRAINT `users_ibfk_1` FOREIGN KEY (`role_id`) REFERENCES `role` (`id`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
