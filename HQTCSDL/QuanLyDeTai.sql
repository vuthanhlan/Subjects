use master
create database QuanLyDeTai
go
use QuanLyDeTai
go
create table GiaoVien(
	MaGV varchar(10) not null primary key,
	HoTen nvarchar(20),
	Khoa nvarchar(20)
)
create table DeTai(
	MaDT varchar(10) not null primary key,
	TenDT nvarchar(50),
	SoLuongTV int,
	MaGV varchar(10),
	constraint FK_DT_GV foreign key(MaGV)
		references GiaoVien(MaGV)
)
create table SinhVien(
	MaSV varchar(10) not null primary key,
	HoTen nvarchar(20),
	Lop nvarchar(20),
	MaDT varchar(10),
	Diem float,
	constraint FK_SV_DT foreign key(MaDT)
		references DeTai(MaDT)
)
insert into GiaoVien values('GV1',N'Trần Thị Thanh','CNTT'),
							('GV2',N'Bùi Thanh Tam','KT'),
							('GV3',N'Trần Đức Mạnh','DL')
insert into DeTai values ('DT1',N'Máy Móc', 6, 'GV1'),
							('DT2',N'Kinh doanh', 10, 'GV2'),
							('DT3',N'Hang Núi', 20, 'GV3')
insert into SinhVien values('SV01',N'Khoa','HTTT01','DT1',9.5),
						   ('SV02',N'Hoa','TCNH01','DT2',8.5),
						   ('SV03',N'Mai','DL02','DT3',9.5),
						   ('SV04',N'Thắng','CNTT02','DT1',9),
						   ('SV05',N'Mạnh','Marketing02','DT2',7.5)

select * from GiaoVien
select * from DeTai
select * from SinhVien

--cau2
create proc pr_addNewSV(@msv varchar(10),
						@ten nvarchar(20), 
						@lop nvarchar(20), 
						@mdt varchar(10),
						@diem float)
as
begin
	if(exists(select * from SinhVien where MaSV=@msv))
	print(N'Mã Sinh Viên đã bị trùng')
	else
		if(not exists(select * from DeTai where MaDT=@mdt))
		print(N'Đề tài cần phải có trong bảng DeTai')
		else
			insert into SinhVien values(@msv, @ten, @lop, @mdt, @diem)
end

select * from SinhVien
select * from DeTai
exec pr_addNewSV 'SV06',N'Hồng','DL02','DT3',8

select * from SinhVien
select * from DeTai
exec pr_addNewSV 'SV05',N'Hồng','DL02','DT3',8

select * from SinhVien
select * from DeTai
exec pr_addNewSV 'SV07',N'Hồng','DL02','DT4',8

--cau3
create trigger trg_updatesv
on SinhVien
for update
as
	begin
		declare @mdt varchar(10)
		if(select count(*) from inserted)>1
			begin
				raiserror(N'Không được sửa quá 1 dòng lệnh',16,1)
				rollback transaction
			end
		else
			if update(MaDT)
				select @mdt= MaDT from inserted
				if(not exists(select * from DeTai where MaDT=@mdt))
					begin
						raiserror(N'Mã Đề Tài Không Tồn Tại',16,1)
						rollback transaction
					end
				else
					update DeTai set SoLuongTV=SoLuongTV+1
					where @mdt=MaDT
	end
select * from DeTai
select * from SinhVien
update DeTai set SoLuongTV=SoLuongTV+1 where MaDT='DT2'
