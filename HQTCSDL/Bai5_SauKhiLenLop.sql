-------BÀI 1-------
use master
go 
create database QLKHO
go
use QLKHO
go
create table TON(
	MaVT varchar(10) primary key,
	TenVT nvarchar(20),
	SLT int
)
create table Nhap(
	SoHDN varchar(10),
	MaVT varchar(10),
	SLN int,
	DonGiaN money,
	NgayN nvarchar(20),
	constraint FK_N_T foreign key(MaVT)
		references TON(MaVT)
)
create table Xuat(
	SoHDX varchar(10),
	MaVT varchar(10),
	SLX int,
	DonGiaX money,
	NgayX nvarchar(20),
	constraint FK_X_T foreign key(MaVT)
		references TON(MaVT)
)

--b
insert into Nhap
values('HD1','VT1',2,20000,'12/2/2007'),
	  ('HD2','VT2',5,35000,'13/5/2007'),
	  ('HD3','VT3',4,15000,'16/3/2007')
select * from Nhap

insert into Xuat
values('HDX1','VT1',1,25000,'12/3/2007'),
	 ('HDX2','VT2',3,40000,'15/6/2007')
select * from Xuat

--c
insert into TON
values('VT1',N'Quần đùi',1),
	  ('VT2',N'Áo Sơ Mi',2),
	  ('VT3',N'Áo Phông',3),
	  ('VT4',N'Áo Balo',2),
	  ('VT5',N'Quần jean',4)
select * from TON

--d
delete from Nhap


