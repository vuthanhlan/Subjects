use master
create database QLBH
go
use QLBH
go
create table SP(
	MaSP varchar(10) not null primary key,
	TenSP nvarchar(20),
	SoLuong int,
	DonGia money,
	MauSac nvarchar(20),
	DonViTinh nvarchar(10)
)
create table NHAP(
	SoHDN varchar(10) ,
	MaSP varchar(10),
	NgayN date,
	SoLuongN int,
	DonGiaN money,
	constraint PK_N primary key(SoHDN, MaSP),
	constraint FK_N_SP foreign key(MaSP)
		references SP(MaSP)
)
create table XUAT(
	SoHDX varchar(10) not null,
	MaSP varchar(10),
	NgayX date,
	SoLuongX int,
	constraint PK_X primary key(SoHDX, MaSP),
	constraint FK_X_SP foreign key(MaSP)
		references SP(MaSP)
)

insert into SP values('SP01',N'Bút',100,50000,N'Đỏ',N'Chiếc'),
					 ('SP02',N'Vở',150,30000,N'Xanh',N'Quyển'),
					 ('SP03',N'Ghế',50,60000,N'Vàng',N'Cái'),
					 ('SP04',N'Bàn',100,50000,N'Hồng',N'Cái'),
					 ('SP05',N'Bảng',50,70000,N'Đen',N'cái')
insert into Nhap values('N01','SP01','2020/08/08',150,40000),
						('N02','SP02','2020/09/09',200,20000),
						('N03','SP03','2020/07/07',100,50000)
insert into Xuat values('X01','SP01','2020/08/09',50),
						('X02','SP02','2020/10/09',50),
						('X03','SP03','2020/08/08',50)
select * from SP
select * from NHAP
select * from XUAT

--cau2
create proc pr_insertXuat(@shdx varchar(10),
						  @msp varchar(10),
						  @nx date,
						  @slx int)
as
 begin
	if(not exists(select * from SP where MaSP=@msp))
		print('Khong co MaSP '+@msp+' trong bang SanPham')
	else
			insert into Xuat values(@shdx,@msp,@nx,@slx)
 end

 exec pr_insertXuat'X04','SP03','2020/08/08',50
 select * from Xuat

 exec pr_insertXuat'X04','SP06','2020/08/08',50

 --cau3
create trigger trg_insertXuat
on Xuat
for insert
as
begin
			declare @slx int
			declare @sl int
			declare @msp varchar(10)
			select @slx=SoLuongX,@msp=MaSP from inserted
			select @sl=SoLuong from SP where MaSP=@msp
	if(not exists(select * from SP where MaSP=@msp))
		begin
			raiserror('Khong co MaSP nay trong bang SP',16,1)
			rollback transaction
		end
	else
		begin
			if(@slx>@sl)
				begin
					raiserror('Khong du so luong',16,1)
					rollback transaction
				end
			else
				update SP set SoLuong=SoLuong-@slx
				where MaSP=@msp
		end
end

select * from SP
select * from XUAT
insert into XUAT values('X05','SP04','2020/08/08',20)

insert into XUAT values('X05','SP06','2020/08/08',20)
insert into XUAT values('X06','SP04','2020/08/08',100)

