use master
go
create database QLBanHang
go
use QLBanHang
go
create table HangSX(
	MaHangSX nvarchar(10) not null primary key,
	TenHang nvarchar (20),
	DiaCHi nvarchar(30),
	SoDT nvarchar(20),
	email nvarchar(30)
)
create table SanPham(
	MaSP nchar(10) not null primary key,
	MaHangSX nvarchar(10),
	TenSP nvarchar(20),
	SoLuong int,
	MauSac nvarchar(20),
	GiaBan money,
	DoViTinh nchar(10),
	MoTa nvarchar(max),
	constraint FK_SP_HXS foreign key(MaHangSX)
	  references HangSX(MaHangSX)
)
create table NhanVien(
	MaNV nchar(10) primary key,
	TenNV nvarchar(20),
	GioiTinh nchar(10),
	DiaChi nvarchar(20),
	SoDT nvarchar(20),
	Email nvarchar(30),
	TenPhong nvarchar(30)
)
create table PNhap(
	SoHDN nchar(10) not null primary key,
	NgayN date,
	MaNV nchar(10),
	constraint FK_PN_NV foreign key(MaNV)
		references NhanVien(MaNV)
)
	create table Nhap(
		SoHDN nchar(10),
		MaSP nchar(10),
		SoLuongN int,
		DonGiaN money,
		constraint PK_Nhap primary key(SoHDN,MaSP),
		constraint FK_N_PN foreign key(SoHDN)
			references PNhap(SoHDN),
		constraint FK_N_SP foreign key(MaSP)
			references SanPham(MaSP)
	)
	create table PXuat(
		SoHDX nchar(10) not null primary key,
		NgayX date,
		MaNV nchar(10),
		constraint FK_PX_NV foreign key(MaNV)
			references NhanVien(MaNV)
	)
	create table Xuat(
		SoHDX nchar(10),
		MaSP nchar(10),
		SoLuongX int,
		constraint PK_Xuat primary key(SoHDX,MaSP),
		constraint FK_X_PX foreign key(SoHDX)
			references PXuat(SoHDX),
		constraint FK_X_SP foreign key(MaSP)
			references SanPham(MaSP)
	)
insert into HangSX 
values ('H01',N'Samsung',N'Korean',N'011-08271717',N'ss@gamil.com.kr'),
('H02',N'OPPO',N'China',N'081-08626262',N'oppo@gmail.com'),
('H03',N'Vinfone',N'Việt Nam','084-0982626',N'vf@gmail.com.vn');
select* from HangSX

insert into NhanVien 
values ('NV01',N'Nguyễn Thị Thu',N'Nữ',N'Hà Nội','0982626521','thu@gmail.com',N'Kế Toán'),
('NV02',N'Lê Văn Nam',N'Nam',N'Bắc Ninh','0972525252','nam@gmail.com',N'Vật tư'),
('NV03',N'Trần hòa Bình',N'Nữ',N'Hà Nội','0328388388',N'hb@gmail.com',N'Kế toán');
select * from NhanVien

insert into SanPham 
values ('SP01',N'H02',N'F1 Plus','100',N'Xám','7000000',N'Chiếc',N'Hàng cận cao cấp'),
('SP02',N'H01',N'Galaxy Note11','50',N'Đỏ','19000000',N'Chiếc',N'Hàng cao cấp'),
('SP03',N'H02',N'F3 list','200',N'Nâu','3000000',N'Chiếc',N'Hàng phổ thông'),
('SP04',N'H03',N'Vjoy3','200',N'Xám','1500000',N'Chiếc',N'Hàng phổ thông'),
('SP05',N'H01',N'Galaxy V21','500',N'Nâu','8000000',N'Chiếc',N'Hàng cận cao cấp');
select * from SanPham

insert into PNhap
values('N01','02-05-2019','NV01'),
('N02','04-07-2020','NV02'),
('N03','05-17-2020','NV02'),
('N04','03-22-2020','NV03'),
('N05','07-07-2020 ','NV01');
select * from PNhap

insert into Nhap
values('N01','SP02',10,17000000),
('N02','SP01',30,6000000),
('N03','SP04',20,1200000),
('N04','SP01',10,6200000),
('N05','SP05',20,7000000);
select * from Nhap

insert into PXuat
values('X01','06-14-2020','NV02'),
('X02','03-05-2019','NV03'),
('X03','12-12-2020','NV01'),
('X04','06-02-2020','NV02'),
('X05','05-18-2020','NV01');
select * from PXuat

insert into Xuat
values('X01','SP03',5),
('X02','SP01',3),
('X03','SP02',1),
('X04','SP03',2),
('X05','SP05',1);
select * from Xuat

--a
create view vw_caua
as
select Nhap.SoHDN,SanPham.MaSP, TenSP,SoLuongN,DonGiaN,NgayN,TenNV,Tenphong
from Nhap Inner join SanPham on Nhap.MaSP = SanPham.MaSP
		  Inner join PNhap on Nhap.SoHDN=PNhap.SoHDN
		  Inner join NhanVien on PNhap.MaNV = NhanVien.MaNV
		  Inner join HangSX on SanPham.MaHangSX = HangSX.MaHangSX
where TenHang='Samsung' and Year(NgayN)=2020

--b
create view wv_caub
as
select MaSP,TenSP, SoLuong, MauSac, GiaBan, DoViTinh, MoTa
from SanPham inner join HangSX on SanPham.MaHangSX=HangSX.MaHangSX
where TenHang='Samsung' and GiaBan between 100000 and 500000

--c
create view wv_cauc
as
select sum(SoLuongN*DonGiaN) as'TongN'
from Nhap inner join SanPham on Nhap.MaSP=SanPham.MaSP
		  inner join HangSX on SanPham.MaHangSX=HangSX.MaHangSX
		  inner join PNhap on Nhap.SoHDN=PNhap.SoHDN
where TenHang='Samsung' and Year(NgayN)=2020


--d
create view wv_caud
as
select sum(SoLuongX*GiaBan) as'Tong tien xuat'
from Xuat inner join SanPham on Xuat.MaSP=SanPham.MaSP
		  inner join PXuat on Xuat.SoHDX=PXuat.SoHDX
where NgayX='06/14/2020'

--e
create view wv_caue
as
select Nhap.SoHDN,NgayN
from Nhap inner join PNhap on Nhap.SoHDN=PNhap.SoHDN
where Year(NgayN)=2020 and (SoLuongN*DonGiaN)=(select max(SoLuongN*DonGiaN)
											   from Nhap inner join PNhap on Nhap.SoHDN=PNhap.SoHDN
											   where Year(NgayN)=2020)

--f
create view wn_cauf
as
select HangSX.MaHangSX,TenHang, count(MaSP) as 'SlSanPham'
from HangSX inner join SanPHam on HangSX.MaHangSX=SanPham.MaHangSX
group by HangSX.MaHangSX,TenHang

--g
create view wv_caug
as
select SanPham.MaSP,TenSP, sum(SoLuongN*DonGiaN) as'Tong Tien Nhap'
from SanPham inner join Nhap on SanPham.MaSP=Nhap.MaSP
			 inner join PNhap on Nhap.SoHDN=PNhap.SoHDN
where Year(NgayN)=2020
group by SanPham.MaSP,TenSP

--h
create view wv_cauh
as
select SanPham.MaSP,TenSP,sum(SoLuongX) as'Tong SLX'
from SanPham inner join Xuat on SanPham.MaSP=Xuat.MaSP
			 inner join PXuat on Xuat.SoHDX=PXuat.SoHDX
			 inner join HangSX on SanPham.MaHangSX=HangSX.MaHangSX
where Year(NgayX)=2020 and TenHang='Samsung'
group by SanPham.MaSP,TenSP
having sum(SoLuongX)>10000

--i
create view wv_caui
as
select TenPhong, count(MaNV) as'SoNV'
from NhanVien
where GioiTinh=N'Nam'
group by TenPhong

--j
create view vw_cauj
as
select HangSX.MaHangSX,TenHang, sum(SoLuongN) as'SLX'
from HangSX inner join SanPham on HangSX.MaHangSX=SanPham.MaHangSX
			inner join Nhap on Nhap.MaSp=SanPham.MaSP
			inner join PNhap on Nhap.SoHDN=PNhap.SoHDN
where Year(NgayN)=2018
group by HangSX.MaHangSX,TenHang

--k
create view vw_cauk
as
select NhanVien.MaNV,TenNV, sum(SoLuongX*GiaBan) as'TongTienXuat'
from NhanVien inner join PXuat on NhanVien.MaNV=PXuat.MaNV
			  inner join Xuat on PXuat.SoHDX=Xuat.SoHDX
			  inner join SanPham on Xuat.MaSP=SanPham.MaSP
where Year(NgayX)=2018
group by  NhanVien.MaNV,TenNV