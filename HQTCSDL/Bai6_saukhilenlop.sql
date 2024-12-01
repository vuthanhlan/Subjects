use master
go
create database QLKHO
go
use QLKHO
go
create table Ton(
	MaVT varchar(10) not null primary key,
	TenVT nvarchar(20),
	soluongVT int
)
create table Nhap(
	SoHDN varchar(10) not null primary key,
	MaVT varchar(10) not null,
	soluongN int,
	DonGiaN money,
	NgayN datetime,
	constraint FK_N_T foreign key(MaVT)
		references Ton(MaVT)
)
create table Xuat(
	SoHDX varchar(10) not null primary key,
	MaVT varchar(10),
	soluongX int,
	DonGiaX money,
	NgayX datetime,
	constraint FK_X_T foreign key(MaVT)
		references Ton(MaVT)
)
insert into Ton values('VT1', N'Ban',50),
						('VT2', N'Ghe',60),
						('VT3', N'Bang',20),
						('VT4', N'Phan',15),
						('VT5', N'Thuoc',30)
insert into Nhap values('PN1','VT1',60,70000,19/02/1999),
						('PN2','VT2',70,80000,19/03/1999),
						('PN3','VT3',30,60000,20/02/1999)
insert into Xuat values('PX1','VT1',10,80000,18/05/1999),
						('PX2','VT2',10,70000,19/03/1999)
select * from Ton
select * from Nhap
select * from Xuat

delete from Ton
WHERE MaVT IN ( SELECT MaVT
				FROM Xuat
				WHERE DonGiaX < (SELECT DonGiaN
								 FROM Nhap
								 WHERE Nhap.MaVT = Xuat.MaVT
								)
				)

select top 1 TenVT
from Ton
order by soluongVT ASC

select Ton.MaVT,TenVT,SoLuongVT 
from Ton inner join Xuat on Ton.MaVT=Xuat.MaVT
group by Ton.MaVT,TenVT,SoLuongVT 
having sum(soluongX)>100

create view vw_cau4
as
	select month(NgayX) as 'Thang', year(NgayX)as 'Nam', sum(soluongX)as'Tongsl'
	from Xuat
	GROUP BY YEAR(NgayX), MONTH(NgayX)

select * from vw_cau4

create view wv_cau5
as
	select Ton.MaVT,TenVT,soluongN,soluongX,DonGiaN, DonGiaX,NgayN,NgayX
	from Ton inner join Nhap on Ton.MaVT=Nhap.MaVT
			inner join Xuat on Ton.MaVT=Xuat.MaVT

select * from wv_cau5

create view vw_cau6
as
	select Ton.MaVT, TenVT,(soluongN-soluongX+soluongVT) as 'SLCONLAI'
	from Ton inner join Nhap on Ton.MaVT=Nhap.MaVT
			inner join Xuat on Ton.MaVT=Xuat.MaVT
select * from vw_cau6