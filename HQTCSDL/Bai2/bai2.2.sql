use master
go
create database DeptEmps
on primary(
	name='DeptEmps_dat',
	filename='D:\DeptEmps.mdf',
	size=10MB,
	maxsize=50MB,
	filegrowth=10MB
)
log on(
	name='DeptEmps_log',
	filename='D:\DeptEmps.ldf',
	size=1MB,
	maxsize=5MB,
	filegrowth=20%
)
go
use DeptEmps
go
create table Department(	DepartmentNo integer not null primary key,	DepartmentName char(25) not null,	Locations char(25) not null,)create table Employee(	EmpNo integer not null primary key,	Fname varchar(15) not null,	Lname varchar(15) not null,	Job varchar(25) not null,	HireDate Datetime not null,	Salary numeric,	Commision numeric,	DepartmentNo integer,	constraint FK_EL_D foreign key(DepartmentNo)		references Department(DepartmentNo))insert into Departmentvalues(10,'Accounting','Melbourne'),(20,'Research','Adealide'),(30,'Sales','Sydney'),(40,'Operations','Perth');select * from Departmentinsert into Employeevalues(1,'John','Smith','Clerk','17-Dec-1980',800,null,20),(2,'Peter','Allen','Salesman','20-Feb-1981',1600,300,30),(3,'Kate','Ward','Salesman','22-Feb-1981',1250,500,30),(4,'Jack','Jones','Manager','02-Apr-1981',2975,null,20),(5,'Joe','Martin','Salesman','28-Sep-1981 ',2975,1400,30);select * from Employee