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
create table Department(