use master
go 
create database TRUONGHOC
go
use TRUONGHOC
go
create table HOCSINH(
	mahs char(5) primary key,
	tenhs nvarchar(30),
	gioitinh bit,
	ngaysinh datetime,
	diachi nvarchar(20),
	diemTB float
)
create table GIAOVIEN(
	magv char(5) not null primary key,
	ten nvarchar(30) not null,
	GT bit,
	Ngaysinh datetime,
	Diachi varchar(20),
	luong money
)
create table LOPHOC(
	malop char(5) not null primary key,
	tenlop nvarchar(30),
	soluong int,
)


insert into HOCSINH
values('256',N'Hoa',0,'12/6/2003',N'Hà Nội',7.5),
	  ('257',N'Nam',1,'12/8/2003',N'Hà Nam',8.5)
select* from HOCSINH

update HOCSINH
set diachi=N'Thái Bình'
where diachi=N'Hà Nội'
	