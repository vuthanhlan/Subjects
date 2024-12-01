use master
go
create database QLSinhVien
go
use QLSinhVien
go
create table Khoa(
	MaKhoa varchar(10) not null primary key,
	TenKhoa nvarchar(20),
	SoDien varchar(10),
)
create table Lop(
	MaLop varchar(10) not null primary key,
	TenLop nvarchar(10),
	SiSo int,
	MaKhoa varchar(10),
	constraint FK_L_K foreign key(MaKhoa)
		references Khoa(MaKhoa)
)
create table SinhVien(
	MaSV varchar(10) not null primary key,
	HoTen nvarchar(20),
	GioiTinh nvarchar(10),
	NgaySinh date,
	MaLop varchar(10),
	constraint FK_SV_L foreign key(MaLop)
		references Lop(MaLop)
)
insert into Khoa values('K01','CNTT','255668-53'),
						('K02','CK','255668-54'),
						('K03','KT','255668-55')
insert into Lop values('L01','HTTT01',45,'K01'),
					  ('L02','CK01',50,'K02'),
					  ('L03','TCNH01',52,'K02')
insert into SinhVien values('SV01',N'Lê Xuân Dương',N'Nam','2003/06/28','L02'),
						   ('SV02',N'Lê Vũ Thanh Lan',N'Nữ','2003/01/05','L01'),
						   ('SV03',N'Lưu Hải And',N'Nữ','2002/12/13','L03'),
						   ('SV04',N'Vũ Hoàng Nhi',N'Nữ','2003/06/29','L01'),
						   ('SV05',N'Lê Thu Huyền',N'Nữ','2003/06/05','L03')
select * from Khoa
select * from Lop
select * from SinhVien
--cau2
create function fn_danhsach(@tenk nvarchar(20))
returns @bang table(MaLop varchar(10),
					TenLop nvarchar(20),
					SiSo int)
as
begin
	insert into @bang
	select MaLop, TenLop, SiSo
	from Lop inner join Khoa on Lop.MaKhoa=Khoa.MaKhoa
	where TenKhoa=@tenK
	return 
end
select * from Lop
select * from fn_danhsach('CNTT')

--cau3
Alter proc pr_insertSV(@msv varchar(10),
						@tensv nvarchar(10),
						@gt nvarchar(10),
						@ns date,					
						@tenl nvarchar(10))
as
begin
	if(not exists(select * from Lop where TenLop=@tenl))
		print('Khong co Ten Lop '+@tenl+' trong bang Lop')
	else
		begin
			declare @ml varchar(10)
			select @ml=MaLop from Lop where TenLop=@tenl
			insert into SinhVien values(@msv,@tensv,@gt,@ns,@ml)
		end
end
--test
select * from SinhVien
select * from Lop
exec pr_insertSV 'SV06',N'Nguyễn Thành Nam',N'Nam','2003/07/07','CK01'
exec pr_insertSV 'SV07',N'Nguyễn Thành Nam',N'Nam','2003/07/07','CK'

--cau4
create trigger trg_updateSV
on SinhVien
for update
as
	begin
		declare @ss int,@ml varchar(10),@ml1 varchar(10)
		select @ml=MaLop from inserted
		select @ml1=Malop from deleted
		select @ss=SiSo from Lop where MaLop=@ml
		if(@ss>=80)
			begin
				raiserror('Lop da day',16,1)
				rollback transaction
			end
		else
			update Lop set SiSo=SiSo+1
			where MaLop=@ml
			update Lop set SiSo=SiSo-1
			where Malop=@ml1
	end
--test
select * from SinhVien
select * from Lop

update SinhVien set MaLop='L01' where MaSV='SV01'
update SinhVien set MaLop='L02' where MaSV='SV03'
update SinhVien set MaLop='L02' where MaSV='SV02'