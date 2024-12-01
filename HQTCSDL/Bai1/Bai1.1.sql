use master
go
create database QLSV
on primary(
	name='QLSV_dat',
	filename='D:\QLSV.mdf',
	size=10MB,
	maxsize=100MB,
	filegrowth=10MB
)
log on(
	name='QLSV_log',
	filename='D:\QLSV.ldf',
	size=1MB,
	maxsize=5MB,
	filegrowth=20%
)
go
use QLSV
go
Create table SV(
	MaSV nchar(20) not null primary key,
	TenSV nvarchar(30) not null,
	Que nvarchar(30)
)
create table MON(
	MaMH nchar(10) not null primary key,
	TenMH nvarchar(20) not null,
	Sotc int default N'3',
	constraint unique_M unique(TenMH)
)
create table KQ(
	MaSV nchar(20) not null,
	MaMH nchar(10) not null,
	Diem float,
	constraint PK_KQ primary key(MaSV, MaMH),
	constraint chk_D check(Diem>=0 and Diem<=10),
	constraint FK_KQ_SV foreign key(MaSV)
		references SV(MaSV),
	constraint FK_KQ_M foreign key(MaMH)
		references MON(MaMH)
)
insert into SV values('SV01',N'Lê Văn A',N'Hà Nội')
insert into SV values('SV02',N'Lê Văn B',N'Hà Nam')
insert into SV values('SV03',N'Lê Văn C',N'Thái Bình')
select * from SV
insert into MON values('MH01',N'Hệ QTCSDL',N'3')
insert into MON values('MH02',N'Lập trình HDT',N'3')
insert into MON values('MH03',N'Nguyên Lý HĐH',N'3')
select * from MON
insert into KQ
values ('SV01','MH01',9),
('SV02','MH01',7),
('SV03','MH01',8),
('SV01','MH02',8),
('SV02','MH02',9),
('SV03','MH02',9),
('SV01','MH03',7),
('SV02','MH03',9),
('SV03','MH03',10)
select * from KQ