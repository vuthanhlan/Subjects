use master
create database QuanLyKhoa
go
use QuanLyKhoa
go
create table Khoa(
	MaKhoa varchar(10) primary key,
	TenKhoa nvarchar(20),
	DienThoai varchar(20)
)
create table Lop(
	MaLop varchar(10) primary key,
	TenLop nvarchar(20),
	Khoa varchar(10),
	Hedt nvarchar(20),
	NamNH int,
	MaKhoa varchar(10),
	constraint FK_L_K foreign key(MaKhoa)
		references Khoa(MaKhoa)
)
insert into Khoa values('S001','CNTT','0289-522'),
					   ('S002','KT','0287-522'),
					   ('S003','CK','0279-522')
insert into Lop values('L01','HTTT01','K16','DH',2021,'S001'),
					   ('L02','TCNN02','K17','DH',2022,'S002'),
					   ('L03','CK03','K16','DH',2023,'S003')

--cau1.1
Alter proc pr_insertKhoa(@mk varchar(10),
						  @ten nvarchar(20),
						  @dt varchar(20))
as
	begin
		if(exists(select*from Khoa where TenKhoa=@ten))
			print(N'ten khoa '+@ten+' da ton tai')
		else
			insert into Khoa values(@mk,@ten,@dt)
	end

select*from Khoa
exec pr_insertKhoa 'S004','DT','2589-521'

select*from Khoa
exec pr_insertKhoa 'S005','CNTT','2589-521'

--cau2.1
create proc pr_insertLop(@ml varchar(10),
						@ten nvarchar(20),
						@khoa varchar(10),
						@hdt nvarchar(20),
						@namnh int,
						@mk varchar(10))
as
	begin
		if(exists(select* from Lop where TenLop=@ten))
			print(N'Tên lớp '+@ten+N' đã tồn tại')
		else
			if(not exists(select* from Khoa where MaKhoa=@mk))
				print(N'Mã Khoa '+@mk+N' chưa có trong bảng Khoa')
			else
				insert into Lop values(@ml,@ten,@khoa,@hdt,@namnh,@mk)
	end

select * from Khoa
select * from Lop
exec pr_insertLop 'L04','HTTT02','K16','DH','2020','S001'

exec pr_insertLop 'L05','HTTT01','K16','DH','2020','S001'
exec pr_insertLop 'L05','HTTT04','K16','DH','2020','S005'


--cau1.2
create proc pr_addKhoa(@mk varchar(10),
						@ten nvarchar(20),
						@dt varchar(20),
						@trave int output)
as
	begin
		if(exists(select * from Khoa where TenKhoa=@ten))
			set @trave=0
		else
			insert into Khoa values(@mk,@ten,@dt)
		return @trave
	end

	declare @bien int
	exec pr_addKhoa 'S005','DL','25565-565',@bien output
	select @bien
	select * from Khoa

	declare @bien int
	exec pr_addKhoa 'S006','CNTT','25565-565',@bien output
	select @bien

--cau2.2
create proc sp_addLop(@ml varchar(10),
					  @ten nvarchar(20),
					  @khoa varchar(10),
					  @hdt nvarchar(20),
					  @namnh int,
					  @mk varchar(10),
					  @trave int output)
as
	begin
		if(exists(select* from Lop where TenLop=@ten))
			set @trave=0
		else
			if(not exists(select * from Khoa where MaKhoa=@mk))
				set @trave=1
			else
				begin
					set @trave=2
					insert into Lop values(@ml,@ten,@khoa,@hdt,@namnh,@mk)
				end
			return @trave
	end

	declare @bien int
	exec sp_addLop 'L06','CNTT01','K16','DH',2023,'S003',@bien output
	select @bien
	select * from Khoa
	select * from Lop

	declare @bien int
	exec sp_addLop 'L07','HTTT01','K16','DH',2023,'S003',@bien output
	select @bien

	declare @bien int
	exec sp_addLop 'L08','CNTT03','K16','DH',2023,'S006',@bien output
	select @bien
	select * from Khoa
	select * from Lop


