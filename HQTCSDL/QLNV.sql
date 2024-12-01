use master
create database QLNV
go
use QLNV
go
create table ChucVu(
	MaCV varchar(10) primary key,
	TenCV nvarchar(20)
)
create table NhanVien(
	MaNV varchar(10) primary key,
	MaCV varchar(10),
	TenNV nvarchar(20),
	Ngaysinh date,
	LuongCB  float,
	NgayCong int,
	PhuCap float,
	constraint FK_NV_CV foreign key(MaCV)
		references ChucVu(MaCV)
)
insert into ChucVu values('BV',N'Bảo Vệ'),
						 ('GD',N'Giám Đốc'),
						 ('HC',N'Hành Chính'),
						 ('KT',N'Kế Toán'),
						 ('TQ',N'Thủ Quỹ'),
						 ('VS',N'Vệ Sinh')
insert into NhanVien values('NV01','GD',N'Nguyễn Văn An','1977/12/12',700000,25,500000),
							('NV02','BV',N'Vùi Văn Tí','1978/10/10',400000,24,100000),
							('NV03','KT',N'Trần Thanh Nhật','1977/9/9',600000,26,400000),
							('NV04','VS',N'Nguyễn Thị Út','1980/10/10',300000,26,300000),
							('NV05','HC',N'Lê Thị Hà','1979/10/10',500000,27,200000)
select * from ChucVu
select * from NhanVien

--8.1
--1
create proc pr_addNV(@mnv varchar(10),
					 @mcv varchar(10),
					 @ten nvarchar(20),
					 @ns date,
					 @lcb float,
					 @nc int,
					 @pc float)
as
	Begin
		if(exists(select* from ChucVu where MaCV=@mcv))
			insert into NhanVien values(@mnv,@mcv,@ten,@ns,@lcb,@nc,@pc)
		else
			print('Ma Chuc vu '+@mcv+' Chua co trong bang Chuc Vu')
	end
select * from ChucVu
select * from NhanVien
exec pr_addNV 'NV06','HC',N'Lê Thị Hà','1979/10/10',500000,27,200000

exec pr_addNV 'NV07','CK',N'Lê Thị Hà','1979/10/10',500000,27,200000

--2
create proc pr_updateNV(@mnv varchar(10),
					 @mcv varchar(10),
					 @ten nvarchar(20),
					 @ns date,
					 @lcb float,
					 @nc int,
					 @pc float)
as
 begin
	if(not exists(select * from ChucVu where MaCV=@mcv))
		print('Chuc Vu '+@mcv+' chua co trong bang chuc vu')
	else
		update NhanVien set MaCV=@mcv, TenNV=@ten,Ngaysinh=@ns,LuongCB=@lcb,NgayCong=@nc,PhuCap=@pc
		where MaCV=@mcv
 end

 select * from NhanVien
 exec pr_updateNV 'NV05','HC',N'Mai Thanh Hồng','1979/10/10',500000,27,200000

exec pr_updateNV 'NV05','CK',N'Mai Thanh Hồng','1979/10/10',500000,27,200000	

--8.2
--1
create proc ps_insertNV(@mnv varchar(10),
						@mcv varchar(10),
						@tennv nvarchar(20),
						@ns date,
						@lcb float,
						@nc int,
						@pc float,
						@trave int output)
as
 begin
	if(not exists(select * from Chucvu where MaCV=@mcv))
		set @trave=0
	else
	 begin
		set @trave=1
		insert into NhanVien values(@mnv,@mcv,@tennv,@ns,@lcb,@nc,@pc)
	 end
	return @trave
 end

 select * from NhanVien
 select * from ChucVu
 declare @bien int
 exec ps_insertNV 'NV07','GD',N'Trần Thị Thơm','1978/02/03',500000, 28,4000000,@bien output
 select @bien

 declare @bien int
 exec ps_insertNV 'NV08','TK',N'Trần Thị Thơm','1978/02/03',500000, 28,4000000,@bien output
 select @bien

 --3
 create proc ps_updateNV(@mnv varchar(10),
						 @ns date,
						 @trave int output)
as
 begin
	if(not exists(select * from NhanVien where MaNV=@mnv))
		set @trave=0
	else
	 begin
		set @trave=1
		update NhanVien set Ngaysinh=@ns
		where MaNV=@mnv
	 end
 end

 select * from NhanVien
 declare @bien int
 exec ps_updateNV 'NV01','1978/05/05',@bien output
 select @bien

 select * from NhanVien
 declare @bien int
 exec ps_updateNV 'NV09','1978/05/05',@bien output
 select @bien