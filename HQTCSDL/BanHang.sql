use master
create database BanHang
go
use BanHang
go
create table Khoa(
	MaKhoa varchar(10) not null primary key,
	TenKhoa nvarchar(20),
	DiaDiem nvarchar(30)
)
create table Lop(
	MaLop varchar(10) not null primary key,
	TenLop nvarchar(20),
	SiSo int,
	MaKhoa varchar(10),
	constraint FK_L_K foreign key(MaKhoa)
		references Khoa(MaKhoa)
)
create table SinhVien(
	MaSV varchar(10) not null primary key,
	HoTen nvarchar(20),
	Ngaysinh date,
	GioiTinh nvarchar(10),
	MaLop varchar(10),
	constraint FK_SV_L foreign key(MaLop)
		references Lop(MaLop)
)
insert into Khoa values('K01','CNTT','A1'),
					   ('K02','TCNN','A10'),
					   ('K03','DT','A9')
insert into Lop values('ML01',N'HTTT01',56,'K01'),
						('ML02',N'TCNH02',55,'K02'),
						('ML03',N'DT03',100,'K03')
insert into SinhVien values('SV01',N'Hoàng','2003/01/02',N'Nam','ML01'),
							('SV02',N'Hường','2003/01/02',N'Nữ','ML02'),
							('SV03',N'Hùng','2003/01/02',N'Nam','ML03'),
							('SV04',N'Việt','2003/01/02',N'Nữ','ML01'),
							('SV05',N'Hiền','2003/01/02',N'Nữ','ML02'),
							('SV06',N'Mạnh','2003/01/02',N'Nam','ML03')
select * from Khoa
select * from Lop
select * from SinhVien

--cau2
Alter proc sp_addNewstudent(@msv varchar(10),
					    @ten nvarchar(20), 
						@ns date, 
						@gt nvarchar(10),
						@ml varchar(10),
						@trave int output)
as
	begin
		if(exists (select * from SinhVien where Day(@ns)>day(getdate())))
		begin
			set @trave=1
			print(N'Lỗi')
		end
		else
			begin
			set @trave=0
			insert into SinhVien values(@msv,@ten,@ns,@gt,@ml)
			end
	return @trave
	end

	declare @bien int
	exec sp_addNewstudent 'SV07',N'Mạnh','2003/01/01',N'Nam','ML03',@bien output
	select @bien
	select* from SinhVien

	declare @bien int
	exec sp_addNewstudent 'SV07',N'Mạnh','2003/01/15',N'Nam','ML03',@bien output
	select @bien

--cau3
Alter trigger trg_updateSV
on SinhVien
for update
as
	begin
		declare @ml varchar
		select @ml=Malop from inserted
		declare @ss int
		declare @sssau int
		declare @sstruoc int
		select @sssau= SoSV from (select MaLop, count(*) as 'SoSV'
								from inserted
								group by MaLop) as sumsvt
		select @sstruoc= SoSV from (select MaLop, count(*) as 'SoSV'
								from deleted
								group by MaLop) as sumsvs
		if update(MaSV)
		begin
			raiserror(N'Không cho phép cập nhật cột MaSV',16,1)
			rollback transaction
		end
		if update(MaLop)
		begin
			update Lop
			set SiSo=SiSo-(@sssau-@sstruoc)
			from Lop inner join (select MaLop, count(*) as 'SoSVsau'
								from inserted
								group by MaLop) as SUMSVsau on Lop.MaLop=SUMSVsau.MaLop
					inner join (select MaLop, count(*) as 'Sosvtruoc'
								from deleted
								group by MaLop) as sumsvtruoc on Lop.MaLop=sumsvtruoc.MaLop
			where Lop.MaLop=@ml
		end
	end

update SinhVien set MaLop='ML01' where MaSV='SV01'
update SinhVien set MaLop='ML02' where MaSV='SV03'
select * from Lop
select * from SinhVien
select MaLop, count(*) as 'SoSV'
								from SinhVien
								group by MaLop