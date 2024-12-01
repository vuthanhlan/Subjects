use master
create database QLNhaHang
go
use QLNhaHang
go
create table Ban(
	MaBan varchar(10) not null primary key,
	ViTri varchar(10),
	SoChoNgoi int
)
create table Mon(
	MaMon varchar(10) not null primary key,
	TenMon nvarchar(20),
	MauSac nvarchar(20),
	SoLuong int,
	GiaBan int,
	MoTa nvarchar(50)
)
create table HoaDon(
	SoHD varchar(10) not null primary key,
	MaBan varchar(10),
	MaMon varchar(10),
	SoLuongDat int,
	NgayDat date
	constraint FK_HD_B foreign key(MaBan)
		references Ban(MaBan),
	constraint FK_HD_M foreign key(MaMon)
		references Mon(MaMon)
)

insert into Ban values('MB01','A1',6),
						('MB02','A2',5),
						('MB03','A3',6)
insert into Mon values('M01',N'Cơm rang dưa bò',N'vàng',5,35000,N'Ngon'),
						('M02',N'Cơm rang thập cẩm',N'vàng',6,30000,N'Ngon'),
						('M03',N'Cơm rang xúc xích',N'vàng',8,25000,N'Ngon')
insert into HoaDon values('HD01','MB01','M01',2,'2023/02/02'),
							('HD02','MB02','M02',2,'2023/02/02'),
							('HD03','MB03','M03',2,'2023/02/03'),
							('HD04','MB01','M02',3,'2023/02/04'),
							('HD05','MB02','M03',2,'2023/02/01')

select * from Ban
select * from Mon
select * from HoaDon

--cau2
create function fn_thongketongtien(@vt varchar(10), @nd int)
returns int
as
 begin
	declare @tong int
		set @tong=(select sum(SoLuongDat*GiaBan)
					from HoaDon inner join Mon on HoaDon.MaMon=Mon.MaMon
								inner join Ban on HoaDon.MaBan=Ban.MaBan
					where ViTri=@vt and day(NgayDat)=@nd)
	return @tong
 end

 select dbo.fn_thongketongtien('A1',01)
 select dbo.fn_thongketongtien('A1',02)

 --cau3
 create proc sp_insertHD(@shd varchar(10),
						@mb varchar(10),
						@mm varchar(10),
						@sld int,
						@nd date,					
						@trave int output)
as
 begin
	if(not exists(select * from Ban where MaBan=@mb))
		set @trave=1
	else
	 begin
		if(not exists(select * from Mon where MaMon=@mm))
			set @trave=2
		else
			set @trave=0
			insert into HoaDon values(@shd,@mb,@mm,@sld,@nd)

	 end
	return @trave
 end

 declare @bien int
 exec sp_insertHD 'HD06','MB02','M03',2,'2023/02/01',@bien output
 select @bien
 select * from HoaDon

 declare @bien int
 exec sp_insertHD 'HD07','MB04','M03',2,'2023/02/01',@bien output
 select @bien

 declare @bien int
 exec sp_insertHD 'HD07','MB03','M04',2,'2023/02/01',@bien output
 select @bien

 --cau4
 create trigger trg_insertHD
 on HoaDon
 for insert
 as
	begin
		declare @sld int,@sl int, @mm varchar(10)
		select @sld =SoLuongDat, @mm=MaMon from inserted
		select @sl=SoLuong from Mon where MaMon=@mm
		if(@sl<@sld)
			begin
				raiserror('Khong du hang',16,1)
				rollback transaction
			end
		else
			update Mon set SoLuong=SoLuong-@sld
			where MaMon=@mm
	end

select * from Mon
select * from HoaDon
insert into HoaDon values('HD07','MB02','M03',2,'2023/02/01')

insert into HoaDon values('HD08','MB02','M01',6,'2023/02/01')
insert into HoaDon values('HD09','MB02','M01',6,'2023/02/01')