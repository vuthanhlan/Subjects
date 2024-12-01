use master 
go
create database XYZ
go
use XYZ
go
create table Hang(
  Mahang nchar(10) not null primary key,
  Tenhang nvarchar(20) not null,
  Soluong int,
  Giaban money
)
create table Hoadon(
  Mahd nchar(10) not null primary key,
  Mahang nchar(10) not null,
  Soluongban int,
  Ngayban date,
  constraint FK_HD_H foreign key(Mahang)
	references Hang(Mahang)
)
insert into Hang values('sp01',N'Kẹo kéo',200,3000)
insert into Hang values('sp02',N'Kẹo mút',100,5000)
insert into Hang values('sp03',N'Kẹo dồi',300,4000)

select * from Hang
select * from Hoadon

create trigger trg_instHoaDon
on HOADON
for insert
as
	begin
		declare @mahang nchar(10)
		set @mahang=(select Mahang from inserted)
		if(not exists(select *from Hang
								where Mahang=@mahang))
			begin
				raiserror(N'Không có mã hàng này',16,1)
				rollback transaction
			end
		else
			begin
				declare @soluong int
				declare @soluongban int
				set @soluong=(select Soluong from Hang
									where Mahang=@mahang)
				set @soluongban=(select soluongban from inserted)
				if(@soluong<@soluongban)
					begin
						raiserror(N'Số Lượng không đủ',16,1)
						rollback transaction
					end
				else
					update Hang set Soluong=Soluong-@soluongban
					where Mahang=@mahang
			end
	end

select * from Hang
select * from Hoadon
insert into Hoadon values(1,'SP01',25,'2/9/1999')

create trigger trg_xoaDonHang
on HoaDon
for delete
as
	begin
		update Hang set Soluong=Soluong+deleted.Soluongban
		from Hang inner join deleted on Hang.Mahang=deleted.Mahang
	end

select * from Hang
select * from Hoadon
delete from Hoadon where Mahd=1


alter trigger trg_capnhatHoaDon
on hoadon
for update
as
	begin
		declare @truoc int
		declare @sau int
		declare @mahang nchar(10)
		set @mahang=(select Mahang from inserted)
		select @truoc=deleted.soluongban from deleted
		select @sau = inserted.soluongban from inserted
		update Hang set Soluong=Soluong-@sau+@truoc
		where Mahang=@mahang
	end

select * from Hang
select * from Hoadon
update Hoadon set soluongban=soluongban-5 where Mahang='sp02'