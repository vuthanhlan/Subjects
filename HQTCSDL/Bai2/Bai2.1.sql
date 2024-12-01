use master
go
create database MarkM
on primary(
	name='MarkM_dat',
	filename='D:\MarkM.mdf',
	size=10MB,
	maxsize=50MB,
	filegrowth=10MB
)
log on(
	name='MarkM_log',
	filename='D:\MarkM.ldf',
	size=1MB,
	maxsize=5MB,
	filegrowth=20%
)
go
use MarkM
go
create table Students(
	StudentID nvarchar(12) not null primary key,
	StudentName nvarchar(25) not null,
	DateofBirth datetime ,
	Email nvarchar(40),
	Phone nvarchar(12),
	Class nvarchar(10)
)
create table subjects(
	SubjectID nvarchar(10) not null primary key,
	subjectName nvarchar(25),
)
create table Mark(
	StudentID nvarchar(12),
	SubjectID nvarchar(10),
	Date Datetime,
	Theory Tinyint,
	Practial nvarchar(20),
	constraint PK_M primary key(StudentID,SubjectID),
	constraint FP_Mk_St foreign key(StudentID)
		references Students(StudentID),
	constraint FP_Mk_Sb foreign key(SubjectID)
		references Subjects(SubjectID)
)
insert into Students
values('AV0807005',N'Mail Trung Hiếu','11/10/1989','trunghieuyahoo.com',0904115116,'AV1'),
('AV0807006 ',N'Nguyễn Quý Hùng','2/12/1988','quyhungyahoo.com',0955667787 ,'AV2'),
('AV0807007 ',N'Đỗ Đắc Huỳnh','2/1/1990','dachuynhyahoo.com',0988574747,'AV2'),
('AV0807009 ',N'An Đăng Khuê ','6/3/1986','dangkhueyahoo.com',0986757463,'AV1'),
('AV0807010',N'Nguyễn T. Tuyết Lan','12/7/1989','tuyetlanyahoo.com',0983310342,'AV2'),
('AV0807011',N' Đinh Phụng Long','2/12/1990','phnglongyahoo.com',null,'AV1'),
('AV0807012',N'Nguyễn Tuấn Nam ','2/3/1990 ','tuannamyahoo.com',null,'AV1');
select * from Students

insert into Subjects
values('S001','SQL'),
('S002','Java Simplefield'),
('S003','Active Server Page');
select * from Subjects

insert into Mark
values('AV0807005','S001',8,25,'6/5/2008'),
('AV0807006','S002',16,30,'6/5/20080'),
('AV0807007','S001',10,25,'6/5/2008'),
('AV0807009','S003',7,13,'6/5/2008'),
('AV0807010 ','S003',9,16,'6/5/2008'),
('AV0807011','S002',8,30,'6/5/2008'),
('AV0807012','S001',7,31,'6/5/2008'),
('AV0807005','S002',12,11,'6/6/2008'),
('AV0807010','S001',7,16,'6/6/2008');
select * from Mark