use master
go
create database THUCTAP
on primary(
	name='THUCTAP_dat',
	filename='D:\THUCTAP.mdf',
	size=10MB,
	maxsize=100MB,
	filegrowth=10MB
)
log on(
	name='THUCTAP_log',
	filename='D:\THUCTAP.ldf',
	size=1MB,
	maxsize=5MB,
	filegrowth=20%
)
go
use THUCTAP
go
create table Khoa(
	MaKhoa char(10) not null primary key,
	TenKhoa char(30),
	DienThoai char(10)
)
create table GiangVien(
	MaGV int not null primary key,
	HoTenGV char(30),
	Luong decimal(5,2),
	MaKhoa char(10),
	constraint FK_GV_K foreign key(MaKhoa)
		references Khoa(MaKhoa)
)
create table SinhVien(
	MaSV int not null primary key,
	HoTenSV char(30),
	MaKhoa char(10),
	NamSinh int,
	QueQuan char(30),
	constraint FK_SV_K foreign key(MaKhoa)
		references Khoa(MaKhoa)
)
create table DeTai(
	MaDT char(10) not null primary key,
	tenDT char(30),
	KinhPhi int,
	NoiThucTap char(30)
)
create table HuongDan(
	MaSV int,
	MaDT char(10),
	MaGV int,
	KetQua decimal(5,2),
	constraint PK_HD primary key(MaSV),
	constraint FK_DT_DT foreign key(MaDT)
		references DeTai(MaDT),
	constraint FK_GV_GV foreign key(MaGV)
		references GiangVien(MaGV)
)

----3.1----
--1
select MaGV,HoTenGV,TenKhoa
from GiangVien inner join Khoa on GiangVien.MaKhoa=Khoa.MaKhoa


--2
select MaGV,HoTenGV,TenKhoa
from GiangVien inner join Khoa on GiangVien.MaKhoa=Khoa.MaKhoa
where TenKhoa='DIA LY' and TenKhoa='QLTN'

--3
select TenKhoa,count(*) as 'SoGV'
from GiangVien inner join Khoa on GiangVien.MaKhoa=Khoa.MaKhoa
where TenKhoa='CONG NGHE SINH HOC'
group by TenKhoa

--4
select MaSV,HoTenSV,(2023-NamSinh) as'Tuoi'
from SinhVien inner join Khoa on SinhVien.MaKhoa=Khoa.MaKhoa
where TenKhoa='TOAN'

--5
select TenKhoa, count(*) as'SoGV'
from GiangVien inner join khoa on GiangVien.MaKhoa=Khoa.MaKhoa
where TenKhoa='CONG NGHE SINH HOC'
group by TenKhoa

--6
select MaSV, HotenSV, MaKhoa,NamSinh, QueQuan
from SinhVien
where MaSV not in (select MaSV from HuongDan)


--7
select Khoa.MaKhoa,TenKhoa,count(*) as'SoGV'
from GiangVien inner join Khoa on GiangVien.MaKhoa=Khoa.MaKhoa
group by Khoa.MaKhoa,TenKhoa

--8
select DienThoai
from SinhVien inner join Khoa on SinhVien.MaKhoa=Khoa.MaKhoa
where HoTenSV like 'Le van son'

----3.2-----
--1
select DeTai.MaDT,tenDT
from DeTai inner join HuongDan on DeTai.MaDT=HuongDan.MaDT
		   inner join GiangVien on GiangVien.MaGV=HuongDan.MaGV
where HoTenGV ='Tran son'


--2
select tenDT
from DeTai
where MaDT not in (select MaDT from HuongDan)


--3
select GiangVien.MaGV,HoTenGV,TenKhoa,count(MaSV) as 'SoSV'
from GiangVien inner join HuongDan on GiangVien.MaGV=HuongDan.MaGV
			   inner join Khoa on GiangVien.MaKhoa=Khoa.MaKhoa
group by GiangVien.MaGV,HoTenGV,TenKhoa
having count(MaSV)>3


--4
select top 1MaDT,tenDT
from DeTai
order by KinhPhi DESC

--5
select DeTai.MaDT,tenDT,count(MaSV)as 'SoSV'
from DeTai inner join HuongDan on DeTai.MaDT=HuongDan.MaDT
group by DeTai.MaDT,tenDT
having count(MaSV)>2

--6
select SinhVien.MaSV,HoTenSV,KetQua
from SinhVien inner join HuongDan on SinhVien.MaSv=HuongDan.MaSV
			  inner join Khoa on SinhVien.MaKhoa=Khoa.MaKhoa
			  where TenKhoa='DIALY' and TenKhoa='QLTN'

--7
select TenKhoa,Khoa.MaKhoa,count(*) as 'SoSV'
from Khoa inner join GiangVien on Khoa.MaKhoa=GiangVien.MaKhoa
group by TenKhoa,Khoa.MaKhoa

--8
select SinhVien.MaSV,HoTenSV,MaKhoa,NamSinh,QueQuan
from SinhVien inner join HuongDan on SinhVien.MaSv=HuongDan.MaSV
			  inner join DeTai on DeTai.MaDT=HuongDan.MaDT
where NoiThucTap=QueQuan

--9
select MaSV,HoTenSV,MaKhoa,NamSinh,QueQuan
from SinhVien
where MaSV not in (select MaSV from HuongDan)

--10
select MaSV,HoTenSV,MaKhoa,NamSinh,QueQuan
from SinhVien
where MaSV in (select MaSV 
			   from HuongDan
			   where KetQua=0)