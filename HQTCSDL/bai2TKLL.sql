use master
go
create database QLBanHang
on primary(
	name='QLBanHang_dat',
	filename='D:\QLBanHang.mdf',
	size=10MB,
	maxsize=50MB,
	filegrowth=10MB
)
log on(
	name='QLBanHang_log',
	filename='D:\QLBanHang.ldf',
	size=1MB,
	maxsize=5Mb,
	filegrowth=20%
)
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

BÀI1

Select Top 10 SanPham.MaSP,TenSP,SoLuongN
From Nhap Inner join SanPham on Nhap.MaSP=SanPham.MaSP
		  Inner join PNhap on Nhap.SoHDN=PNhap.SoHDN
Where Year(NgayN)=2019
Order by SoLuongN DESC


select SanPham.MaSP,TenSP
from SanPham Inner join HangSX on SanPham.MaHangSX=HangSX.MaHangSX
			 Inner join Nhap on SanPham.MaSP=Nhap.MaSP
			 Inner join PNhap on Nhap.SoHDN=PNhap.SoHDN
			 Inner join NhanVien on PNhap.MaNV= NhanVien.MaNV
where TenHang='Samsung' and NhanVien.MaNV='NV01'


select PNhap.SoHDN,SanPham.MaSP,SoLuongN,NgayN
from PNhap inner join Nhap on PNhap.SoHDN=Nhap.SoHDN
		   inner join SanPham on Nhap.MaSP=SanPham.MaSP
		   inner join NhanVien on PNhap.MaNV=NhanVien.MaNV
where SanPham.MaSP='SP02' and NhanVien.MaNV='NV02'


select NhanVien.MaNV,TenNV
from NhanVien inner join PXuat on NhanVien.MaNV=PXuat.MaNV
			  inner join Xuat on PXuat.SoHDX=Xuat.SoHDX
where MaSP='SP02' and NgayX='03-02-2020'


BÀI2

select sum(SoLuongN*DonGiaN) AS N'Tổng nhập'
from Nhap inner join PNhap on Nhap.SoHDN=PNhap.SoHDN
where Month(ngayN)=08 and Year(NgayN)=2018
having sum(SoLuongN*DonGiaN)>100000


Select SanPham.MaSP,TenSP
From SanPham Inner join nhap on SanPham.MaSP = nhap.MaSP
Where SanPham.MaSP Not In (Select MaSP From Xuat)Select SanPham.MaSP,TenSP
From SanPham Inner join Nhap on SanPham.MaSP = Nhap.MaSP
Where SanPham.MaSP In (Select MaSP
						   from Nhap inner join PNhap on Nhap.SoHDN=PNhap.SoHDN
						   where Year(NgayN)=2020)
intersect
Select SanPham.MaSP,TenSP
From SanPham Inner join Xuat on SanPham.MaSP = Xuat.MaSP
Where SanPham.MaSP In (Select MaSP
						   from Xuat inner join PXuat on Xuat.SoHDX=PXuat.SoHDX
						   where Year(NgayX)=2020)


select NhanVien.MaNV,TenNV
from NhanVien inner join PNhap on NhanVien.MaNV=PNhap.MaNV
where NhanVien.MaNV in (select MaNV from PNhap)
intersect
select NhanVien.MaNV,TenNV
from NhanVien inner join PXuat on NhanVien.MaNV=PXuat.MaNV
where NhanVien.MaNV in (select MaNV from PXuat)


select NhanVien.MaNV,TenNV
from NhanVien inner join PNhap on NhanVien.MaNV=PNhap.MaNV
where NhanVien.MaNV not in (select MaNV from PNhap)


----BAI7---

--bai1
--a
create function fn_selectTenHang(@msp nchar(10))
returns nvarchar(20)
as
begin
	declare @tenhang nvarchar(20)
	set @tenhang=(select TenHang from HangSX inner join SanPham on HangSX.MaHangSX=SanPham.MaHangSX
								where MaSP=@msp)
	return @tenhang
end

select dbo.fn_selectTenHang('SP01')

--b
Alter function fn_countSP(@x money, @y money, @z nvarchar(20))
returns int
as
	begin
		declare @count int
		set @count=(select count(*)
						from SanPham inner join HangSX on SanPham.MaHangSX=HangSX.MaHangSX
						where TenHang=@z and GiaBan between @x and @y)
	return @count
	end

select dbo.fn_countSP(3000000,4000000,N'Samsung')

--b
create function fn_selecttongtienN(@x int, @y int)
returns int
as
	begin
		declare @tongtien int
		select @tongtien=sum(SoLuongN*DonGiaN) from Nhap inner join PNhap on Nhap.SoHDN=PNhap.SoHDN
							where Year(NgayN) between @x and @y
	return @tongtien
	end
select dbo.fn_selecttongtienN(2016,2020)
--c
Create function fn_thongkesltd(@x nvarchar(20), @y int)
returns int
as
	begin
		declare @tongn int
		declare @tongx int
		declare @thaydoi int
		select @tongn=sum(SoLuongN) from Nhap inner join SanPham on SanPham.MaSP=Nhap.MaSP
												inner join PNhap on PNhap.SoHDN=Nhap.SoHDN
									where TenSP=@x and year(NgayN)=@y
		select @tongx=sum(SoLuongX) from Xuat inner join SanPham on SanPham.MaSP=Xuat.MaSP
												inner join PXuat on PXuat.SoHDX=Xuat.SoHDX
									where TenSP=@x and year(NgayX)=@y
		set @thaydoi=@tongn-@tongx
	return @thaydoi
	end
select dbo.fn_thongkesltd(N'F1 Plus',2019)

--d
create function fn_selecttongtien(@x int, @y int)
returns int
as
	begin
		declare @tongtien int
		select @tongtien=sum(SoLuongN*DonGiaN) from Nhap inner join PNhap on Nhap.SoHDN=PNhap.SoHDN
							where Day(NgayN) between @x and @y
	return @tongtien
	end
select dbo.fn_selecttongtien(15,20)

--bai2
create function fn_selectDSSP(@x money, @y nvarchar(20))
returns @Bang table( MaSP nchar(10), 
					 MaHangSX nvarchar(10),
					 TenSP nvarchar(10), 
					 SoLuong int, 
					 Mausac nvarchar(20), 
					 GiaBan money, 
					 DoViTinh nchar(10),
					 MoTa nvarchar(max))
as
	begin
		insert into @Bang
		select MaSP,SanPham.MaHangSX, TenSP,SoLuong, MauSac,GiaBan,DoViTinh,MoTa
		from SanPham inner join HangSX on SanPham.MaHangSX=HangSX.MaHangSX
		where GiaBan>=@x and TenHang=@y
	return
	end
select * from fn_selectDSSP(3000000,'OPPO')