use master
create database WEBSITE_TICKET
go
use WEBSITE_TICKET
go
create table tb_Role(
	Role_ID int not null primary key,
	RoleName varchar(20) not null,
	CreateDate datetime,
	CreateBy varchar(20),
	UpdateDate datetime,
	UpdateBy varchar(20),
	Deleted bit
)
create table tb_User(
	User_IDs int not null primary key,
	FullName varchar(50),
	Email varchar(150),
	Role_ID int,
	CreateDate datetime,
	CreateBy varchar(20),
	UpdateDate datetime,
	UpdateBy varchar(20),
	Deleted bit,
	constraint FK_US_RO foreign key(Role_ID)
		references tb_Role(Role_ID)
)
create table tb_Product(
	Product_ID int not null primary key,
	Title varchar(350),
	Price int,
	CreateDate datetime,
	CreateBy varchar(20),
	UpdateDate datetime,
	UpdateBy varchar(20),
	Deleted bit
)
create table tb_Order(
	Order_ID int not null primary key,
	User_IDs int,
	OrderDate datetime,
	TotalMoney int,
	CreateDate datetime,
	CreateBy varchar(20),
	UpdateDate datetime,
	UpdateBy varchar(20),
	Deleted bit,
	constraint FK_O_US foreign key(User_IDs)
		references tb_User(User_IDs)
)
create table tb_OrderDetail(
	OrderDetail_ID int not null primary key,
	Order_ID int,
	Product_ID int,
	price int,
	Num int,
	OrderCode varchar(50),
	statuss int,
	DeliveryTime varchar(50),
	TatolMoney int,
	CreateDate datetime,
	CreateBy varchar(20),
	UpdateDate datetime,
	UpdateBy varchar(20),
	Deleted bit,
	constraint FK_OD_O foreign key(Order_ID)
		references tb_Order(Order_ID),
	constraint FK_OD_P foreign key(Product_ID)
		references tb_Product(Product_ID)
)
create table tb_Feedback(
	Feedback_ID int not null primary key,
	User_IDs int,
	Note varchar(500),
	constraint FK_F_US foreign key(User_IDs)
		references tb_User(User_IDS)
)
