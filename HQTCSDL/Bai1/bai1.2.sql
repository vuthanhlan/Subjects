use master
go
create database QLBHang
on primary(
	name='QLBHang_dat',
	filename='D:\QLBHang.mdf',
	size=10MB,
	maxsize=50MB,
	filegrowth=10MB
)
log on(
	name='QLBHang_log',
	filename='D:\QLBHang.ldf',
	size=1MB,
	maxsize=5MB,
	filegrowth=20%
)
go
use QLBHang
go
create table CongTy(
	MaCT nchar(10) not null primary key,
	TenCT nvarchar (20) not null,
	TrangThai nvarchar(50),
	ThanhPho nchar(20)
)
create table SanPham(
	MaSP nchar(10) not null primary key,
	TenSP nvarchar(20) not null,
	MauSac nchar(20) default N'Đỏ',
	Gia money,
	Soluongco int,
	constraint unique_SP unique(TenSP)
)
create table CungUng(
	MaCT nchar(10) not null,
	MaSP nchar(10) not null,
	Soluongban int,
	constraint PK_CU primary key(MaCT,MaSP),
	constraint chk_SL check(Soluongban>0),
	constraint FK_CU_CT foreign key(MaCT)
		references CongTy(MaCT),
	constraint FK_CU_SP foreign key (MaSP)
		references SanPham(MaSP)
)
insert into CongTy
values('CT01','Samsung',N'Hoạt động',N'Korean'),
('CT02','viettle',N'Hoạt động',N'Việt Nam'),
('CT03','LG',N'Hoạt động',N'Korean');
select * from CongTy

insert into SanPham
values('SP01',N'Tivi',N'Đỏ',10000000,5000),
('SP02',N'Tủ Lạnh',N'Đỏ',9000000,4000),
('SP03',N'Điều Hòa',N'Đỏ',15000000,3589);
select * from SanPham

insert into CungUng
values('CT01','SP01',258),
('CT02','SP01',389),
('CT03','SP01',548),
('CT01','SP02',185),
('CT02','SP03',28),
('CT03','SP02',242);
select * from CungUng