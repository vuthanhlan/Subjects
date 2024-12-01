use master

create database QLBH
go
use QLBH
go
create table MATHANG(
	mahang nvarchar(10) not null primary key,
	tenhang nvarchar(20),
	soluong int
)

create table NHATKYBANHANG(
	stt int not null primary key,
	ngay date,
	nguoimua nvarchar(20),
	mahang nvarchar(10),
	soluong int,
	giaban money,
	constraint FK_NK_MH foreign key(mahang)
		references MATHANG(mahang)
	)

insert into MATHANG values('1',N'Kẹo',100),
							('2',N'Bánh',200),
							('3',N'Thuốc',100)
insert into NHATKYBANHANG values('1','09/02/1999',N'ab','2',230,50000)

select * from MATHANG
select * from NHATKYBANHANG

--a
create trigger trg_nhatkybanhang
on NHATKYBANHANG
for insert
as
	update MATHANG
	set MATHANG.soluong=MATHANG.soluong-inserted.soluong
	from MATHANG inner join inserted on MATHANG.mahang=inserted.mahang

select * from MATHANG
select * from NHATKYBANHANG
insert into NHATKYBANHANG values(2,'02/09/1999',N'Mai','1',50,60000)
select * from MATHANG
select * from NHATKYBANHANG

--b
create trigger trg_nkbh_updatesluong
on NHATKYBANHANG
for update
as
	begin
		declare @truoc int
		declare @sau int
		select @truoc=soluong from deleted
		select @sau=soluong from inserted
		if(@sau<> @truoc)
			begin
				update MATHANG
				set MATHANG.soluong=MATHANG.soluong-@sau+@truoc
				from MATHANG inner join deleted on MATHANG.mahang=deleted.mahang
							inner join inserted on MATHANG.mahang=inserted.mahang
			end
	end

select * from mathang
select * from nhatkybanhang
update NHATKYBANHANG set soluong=soluong+20 where stt=1
select * from mathang
select * from nhatkybanhang

--c

create trigger trg_nhatkybanhang_insert
on NHATKYBANHANG
for insert
as
begin
	declare @slco int
	declare @slban int
	declare @mahang nvarchar(10)
	select @mahang=mahang from inserted
	select @slco=soluong from MATHANG where mahang=@mahang
	select @slban=soluong from inserted
	if(@slco<@slban)
		begin
			raiserror(N'KHÔNG ĐỦ HÀNG GIAM SO LUONG XUONG',16,1)
			rollback transaction
		end
	else
		update MATHANG set soluong=soluong-@slban where mahang=@mahang
end

select * from mathang
select * from nhatkybanhang
insert into NHATKYBANHANG values(4,'05/09/1999',N'Hùng','3',50,70000)
select * from mathang
select * from nhatkybanhang

create trigger trg_updatenhatkybanhang
on nhatkybanhang
for update
as
 begin
	declare @mahang nvarchar(5)
	declare @truoc int
	declare @sau int

	if(select COUNT(*) from inserted)>1
		begin
			raiserror('Khong duoc sua qua 1 dong lenh',16,1)
			rollback transaction
			return
		end
	else
		if UPDATE(soluong)
			begin
				select @truoc=soluong from deleted
				select @sau=soluong from inserted
				select @mahang=mahang from inserted
				update mathang set soluong=soluong-(@sau-@truoc) where mahang=@mahang
		end
 end

 update NHATKYBANHANG set soluong=20 where mahang='2'
 select * from MATHANG
 select * from NHATKYBANHANG

 --e
 create trigger trg_nhatkybanhang_delete
 on nhatkybanhang
 for delete
 as
	begin
		declare @mahang nvarchar(10)
		declare @slban int
		if(select count(*) from deleted)>1
			begin
				raiserror(N'Khong xoa duoc',16,1)
				rollback transaction
			end
		else
			begin
				select @mahang=mahang from deleted
				select @slban = soluong from deleted
				update MATHANG set soluong=soluong+@slban
				where mahang=@mahang
			end
	end

delete from NHATKYBANHANG where mahang='3'
 select * from MATHANG
 select * from NHATKYBANHANG