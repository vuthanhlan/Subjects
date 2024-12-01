----------------BAI1---------------------
use master
go
create database DeptEmp
on primary(
	name='DeptEmp_dat',
	filename='D:\DeptEmp.mdf',
	size=10MB,
	maxsize=50MB,
	filegrowth=10MB
)
log on(
	name='DeptEmp_log',
	filename='D:\DeptEmp.ldf',
	size=1MB,
	maxsize=5MB,
	filegrowth=20%
)
go
use DeptEmp
go
create table Department(	DepartmentNo integer not null primary key,	DepartmentName char(25) not null,	Locations char(25) not null,)create table Employee(	EmpNo integer not null primary key,	Fname varchar(15) not null,	Lname varchar(15) not null,	Job varchar(25) not null,	HireDate Datetime not null,	Salary numeric,	Commision numeric,	DepartmentNo integer,	constraint FK_EL_D foreign key(DepartmentNo)		references Department(DepartmentNo))insert into Departmentvalues(10,'Accounting','Melbourne'),(20,'Research','Adealide'),(30,'Sales','Sydney'),(40,'Operations','Perth');select * from Departmentinsert into Employeevalues(1,'John','Smith','Clerk','17-Dec-1980',800,null,20),(2,'Peter','Allen','Salesman','20-Feb-1981',1600,300,30),(3,'Kate','Ward','Salesman','22-Feb-1981',1250,500,30),(4,'Jack','Jones','Manager','02-Apr-1981',2975,null,20),(5,'Joe','Martin','Salesman','28-Sep-1981 ',2975,1400,30);select * from Employee

--1
select * from Department

--2
select * from Employee

--3
select EmpNo,Fname,Lname
from Employee
where Fname='Kate'


--4
select concat(Fname,Lname) as'Fullname',Salary,(Salary+Salary*0.1) as'10% Salary' from Employee
--5
select Fname,Lname,HireDate
from Employee
where year(HireDate)=1981
order by Lname


--6
select DepartmentNo,avg(Salary) as'TB',max(Salary) as'MAX',min(Salary) as'MIN'
from Employee
group by DepartmentNo

--7
select DepartmentNo,count(*) as'NumberEployee'
from Employee
group by DepartmentNo

--8
select Department.DepartmentNo,DepartmentName,concat(Fname,Lname) as'Fullname',Job,Salary
from Employee inner join Department on Employee.DepartmentNo=Department.DepartmentNo

--9,10
select Department.DepartmentNo,DepartmentName,Locations,count(*) as'NumberEployee'
from Employee inner join Department on Employee.DepartmentNo=Department.DepartmentNo
group by Department.DepartmentNo,DepartmentName,Locations






--------------BAI2-----------------
use master
go
create database MarkManagement
on primary(
	name='MarkManagement_dat',
	filename='D:\MarkManagement.mdf',
	size=10MB,
	maxsize=50MB,
	filegrowth=10MB
)
log on(
	name='MarkManagement_log',
	filename='D:\MarkManagement.ldf',
	size=1MB,
	maxsize=5MB,
	filegrowth=20%
)
go
use MarkManagement
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
	Theory Tinyint,
	Practial Tinyint,
	Date nvarchar(20),
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
('AV0807006','S002',16,30,'6/5/2008'),
('AV0807007','S001',10,25,'6/5/2008'),
('AV0807009','S003',7,13,'6/5/2008'),
('AV0807010 ','S003',9,16,'6/5/2008'),
('AV0807011','S002',8,30,'6/5/2008'),
('AV0807012','S001',7,31,'6/5/2008'),
('AV0807005','S002',12,11,'6/6/2008'),
('AV0807010','S001',7,16,'6/6/2008');
select * from Mark
--1
select * from Students

--2
select StudentID,StudentName,DateofBirth,Email,Phone,class
from Students
where class='AV1'

--3
update Students
set Class='AV2'
where StudentID='AV0807012'
--4
select class,count(*) AS 'NumberStudent'
from Students
group by class

--5
select StudentID,StudentName,DateofBirth,Email,Phone,class
from Students
where class='AV2'
order by StudentName

--6
select Students.StudentID,StudentName,DateofBirth,Email,Phone,class
from Students inner join Mark on Students.StudentID=Mark.StudentID
where Theory<10 and Date='6/5/2008' and SubjectID='S001'

--7
select SubjectID,count(*) as'SoSV'
from Mark
group by SubjectID

--8
select StudentID,StudentName,DateofBirth,Email,Phone,class
from Students
where class='AV1' and DateofBirth>'1/1/1980'

--9
Alter table Students
drop primary key
Delete from Students where StudentID='AV0807011'
--10
select Students.StudentID,StudentName,SubjectName, Theory,Practial,Date
from Mark inner join Students on Students.StudentID=Mark.StudentID
		  inner join subjects on subjects.subjectID=Mark.subjectID
where subjects.subjectID='S001' and Date='6/5/2008'

