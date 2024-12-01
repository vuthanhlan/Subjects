use master
go 
create database QLGV
go 
use QLGV
go 
create table KHOA(
	MaKhoa nvarchar(10) primary key,
	TenKhoa nvarchar(20)
)
create table GV(
	MaGV nvarchar(10) not null primary key,
	TenGV nvarchar(20),
	MaKhoa nvarchar(10),
	constraint FK_GV_K foreign key(MaKhoa)
		references KHOA(MaKhoa)
)
create table LHP(
	MaLHP nvarchar(10) primary key,
	MaGV nvarchar(10),
	SS int,
	HinhThucDH nvarchar(10),
	constraint FK_HP_GV foreign key(MaGV)
		references GV(MaGV)
)

insert into KHOA values('K1','CNTT'),
						('K2','tcnh'),
						('K3','dulich')
select * from KHOA
insert into GV values('GV1','Hoa','K1'),
						('GV2','huong','K2'),
						('GV3','Hong','K3'),
						('GV4','thang','K1')
select * from GV

insert into LHP values('LHP1','GV1',55,'Onl'),
						('LHP2','GV2',56,'off'),
						('LHP3','GV3',45,'Onl')
select * from LHP
select TOP 1KHOA.MaKhoa,TenKhoa
from KHOA inner join GV on KHOA.MaKhoa=GV.MaKhoa
group by KHOA.MaKhoa,TenKhoa
order by count(MaGV) DESC

select MaGV,TenGV
from GV inner join KHOA on KHOA.MaKhoa=GV.MaKhoa
where TenKhoa='CNTT' and TenGV like'%%%'
