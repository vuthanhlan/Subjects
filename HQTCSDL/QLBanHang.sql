use master
go
create database QLBanHang
go
use QLBanHang
go
create table HangSX(
	MaHangSX varchar(10) not null primary key,
	TenHang nvarchar (20),
	DiaCHi nvarchar(30),
	SoDT nvarchar(20),
	email nvarchar(30)
)
create table SanPham(
	MaSP varchar(10) not null primary key,
	MaHangSX varchar(10),
	TenSP nvarchar(20),
	SoLuong int,
	MauSac nvarchar(20),
	GiaBan money,
	DonViTinh nvarchar(10),
	MoTa nvarchar(max),
	constraint FK_SP_HXS foreign key(MaHangSX)
	  references HangSX(MaHangSX)
)
create table NhanVien(
	MaNV varchar(10) primary key,
	TenNV nvarchar(20),
	GioiTinh nchar(10),
	DiaChi nvarchar(20),
	SoDT nvarchar(20),
	Email nvarchar(30),
	TenPhong nvarchar(30)
)
create table PNhap(
	SoHDN varchar(10) not null primary key,
	NgayN date,
	MaNV varchar(10),
	constraint FK_PN_NV foreign key(MaNV)
		references NhanVien(MaNV)
)
	create table Nhap(
		SoHDN varchar(10),
		MaSP varchar(10),
		SoLuongN int,
		DonGiaN money,
		constraint PK_Nhap primary key(SoHDN,MaSP),
		constraint FK_N_PN foreign key(SoHDN)
			references PNhap(SoHDN),
		constraint FK_N_SP foreign key(MaSP)
			references SanPham(MaSP)
	)
	create table PXuat(
		SoHDX varchar(10) not null primary key,
		NgayX date,
		MaNV varchar(10),
		constraint FK_PX_NV foreign key(MaNV)
			references NhanVien(MaNV)
	)
	create table Xuat(
		SoHDX varchar(10),
		MaSP varchar(10),
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
values ('SP01','H02',N'F1 Plus','100',N'Xám','7000000',N'Chiếc',N'Hàng cận cao cấp'),
('SP02','H01',N'Galaxy Note11','50',N'Đỏ','19000000',N'Chiếc',N'Hàng cao cấp'),
('SP03','H02',N'F3 list','200',N'Nâu','3000000',N'Chiếc',N'Hàng phổ thông'),
('SP04','H03',N'Vjoy3','200',N'Xám','1500000',N'Chiếc',N'Hàng phổ thông'),
('SP05','H01',N'Galaxy V21','500',N'Nâu','8000000',N'Chiếc',N'Hàng cận cao cấp');
select * from SanPham

insert into PNhap
values('N01','02-05-2019','NV01'),
('N02','04-07-2020','NV02'),
('N03','05-17-2020','NV02'),
('N04','03-22-2020','NV03'),
('N05','07-07-2020 ','NV01');
select * from PNhap

insert into Nhap values('N01','SP01',100,50000),
					   ('N02','SP02',50,40000),
					   ('N03','SP03',100,30000)
select * from Nhap
insert into PXuat
values('X01','06-14-2020','NV02'),
('X02','03-05-2019','NV03'),
('X03','12-12-2020','NV01'),
('X04','06-02-2020','NV02'),
('X05','05-18-2020','NV01');
insert into PXuat values('X06','06-18-2020','NV02')
select * from PXuat

insert into Xuat
values('X01','SP03',5),
('X02','SP01',3),
('X03','SP02',1),
('X04','SP03',2)
select * from Xuat

--bai1
--a
create function fn_selectds(@x int, @y int)
returns int
as
 begin
	declare @sum int
	select @sum=sum(SoLuongN*DonGiaN) from Nhap inner join PNhap
						on Nhap.SoHDN=PNhap.SoHDN
					where Year(NgayN) between @x and @y
	return @sum
 end
 --goiham
 select dbo.fn_selectds('2018','2019')

 --b
 create function fn_thongkeSLNV(@tenp nvarchar(20))
 returns int
 as
  begin
	declare @count int
	set @count=(select count(*)
	from NhanVien
	where TenPhong=@tenp)
  return @count
  end
  select dbo.fn_thongkeSLNV(N'Kế Toán')

 --c
 create function fn_ThongKeSLX(@x nvarchar(20), @y int)
 returns int
 as
  begin
	declare @count int
	set @count=(select count(*)
				from SanPham inner join Xuat on SanPham.MaSP=Xuat.MaSP
							inner join PXuat on Xuat.SoHDX=PXuat.SoHDX
				where TenSP=@x and day(NgayX)=@y)
  return @count
  end

  select dbo.fn_ThongKeSLX(N'Galaxy Note11',12)
--d
  create function fn_SDT(@x varchar(10))
  returns nvarchar(20)
  as
   begin
   declare @sdt nvarchar(20)
   set @sdt=(select SoDT
			 from NhanVien inner join PXuat on NhanVien.MaNV=PXuat.MaNV
			 where SoHDX=@x)
   return @sdt
   end

   select dbo.fn_SDT('X01')

--e
Create Function fn_ThongKeNhapXuat(@TenSP nvarchar(20),@nam int)
Returns int
As
Begin
 Declare @tongnhap int
 Declare @tongxuat int
 Declare @thaydoi int
 Select @tongnhap = Sum(SoLuongN) From Nhap
					Inner join SanPham on Nhap.MaSP = SanPham.MaSP
					Inner join PNhap on PNhap.SoHDN=Nhap.SoHDN
					Where TenSP = @TenSP And Year(NgayN)=@nam
 Select @tongxuat = Sum(SoLuongX) From Xuat
					Inner join SanPham on Xuat.MaSP = SanPham.MaSP
					Inner join PXuat on PXuat.SoHDX=Xuat.SoHDX
				Where TenSP = @TenSP And Year(NgayX)=@nam
 Set @thaydoi = @tongnhap - @tongxuat
 Return @thaydoi
End
Select dbo.fn_ThongKeNhapXuat(N'F3 list',2020)

--f
create function fn_

--bai2
--a
create function fn_ThongkeSP(@tensp nvarchar(20))
returns @bang table(MaSP varchar(10),
					MaHangSX varchar(10),
					TenSP varchar(20),
					SoLuong int,
					MauSac nvarchar(20),
					GiaBan money,
					DonViTinh nvarchar(10),
					MoTa nvarchar(max))
as
 begin
	insert into @bang
	select MaSP, MaHangSX, TenSP, SoLuong, MauSac, GiaBan, DonViTinh, MoTa
	from SanPham
	where TenSP=@tensp
 return
 end

 select * from fn_ThongkeSP(N'Galaxy Note11')

 --b
 create function fn_DSSP(@x int, @y int)
 returns @bang table(MaSP nvarchar(10),
						TenSP nvarchar(20),
						TenHang nvarchar(20),
						NgayN date,
						SoLuongN int,
						DonGiaN money)
as
 begin
	insert into @bang
	select SanPham.MaSP, TenSP, TenHang, NgayN, SoLuongN, DonGiaN
	from SanPham inner join HangSX on HangSX.MaHangSX=SanPham.MaHangSX
				inner join Nhap on SanPham.MaSP=Nhap.MaSP
				inner join PNhap on Nhap.SoHDN=PNhap.SoHDN
	where Day(NgayN) between @x and @y
 return
 end

select * from fn_DSSP(10,20)	

--c
alter function fn_thongKeDSSP(@tenh nvarchar(20), @flag int)
returns @bang table(MaSP varchar(10),
					MaHangSX varchar(10),
					TenSP nvarchar(20),
					SoLuong int,
					MauSac nvarchar(20),
					GiaBan money,
					DonViTinh nvarchar(10),
					MoTa nvarchar(max))
as
 begin
	if(@flag=0)
		insert into @bang
		select MaSP, HangSX.MaHangSX, TenSP, SoLuong, MauSac, GiaBan, DonViTinh, MoTa
		from SanPham inner join HangSX on SanPham.MaHangSX=HangSX.MaHangSX
		where SoLuong=0 and TenHang=@tenh
	else
		insert into @bang
		select MaSP, HangSX.MaHangSX, TenSP, SoLuong, MauSac, GiaBan, DonViTinh, MoTa
		from SanPham inner join HangSX on SanPham.MaHangSX=HangSX.MaHangSX
		where SoLuong>0 and TenHang=@tenh
 return
 end
	
	select * from fn_thongKeDSSP('Samsung',0)
	select * from fn_thongKeDSSP('Samsung',1)

--d
create function fn_DSNV(@tenp nvarchar(20))
returns @bang table(MaNV varchar(10),
					TenNV nvarchar(20),
					GioiTinh nchar(10),
					DiaChi nvarchar(20),
					SoDT nvarchar(20),
					Email nvarchar(30),
					TenPhong nvarchar(30))
as
begin
	insert into @bang
	select MaNV, TenNV, GioiTinh, DiaChi,SoDT,Email,TenPhong
	from NhanVien
	where TenPhong=@tenp
return
end

select * from fn_DSNV(N'Kế Toán')