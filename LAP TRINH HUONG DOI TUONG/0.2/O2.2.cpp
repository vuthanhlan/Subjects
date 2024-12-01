#include<iostream>
#include<stdio.h>
#include<string.h>
#include<iomanip>
using namespace std;
class student;
class school
{
	private:
		char name[20];
		char date[20];
	friend class faculty;
	friend class student;
	friend void sua(student &t);
};
class faculty
{
	private:
		char Name[20];
		char ngay[20];
		school x;
	public:
		void nhap();
		void xuat();
		friend class student;
		friend void sua(student &t);
};
class person
{
	protected:
		char ten[20];
		char birth[20];
		char address[30];
	public:
		void nhap();
		void xuat();
		person();
};
person::person()
{
	strcpy(ten,"");
	strcpy(birth,"");
	strcpy(address,"");
}
class student:public person
{
	private:
		faculty y;
		char classs[20];
		float score;
	public:
		void nhap();
		void xuat();
		student();
		friend void sua(student &t);
};
student::student():person()
{
	strcpy(y.Name,"");
	strcpy(y.ngay,"");
	strcpy(y.x.name,"");
	strcpy(y.x.date,"");
	strcpy(classs,"");
	score=0;
}
void faculty::nhap()
{
	cout<<"name faculty: ";				fflush(stdin);	gets(Name);
	cout<<"date faculty: ";				fflush(stdin);	gets(ngay);
	cout<<"Name school: ";				fflush(stdin);	gets(x.name);
	cout<<"Date school: ";				fflush(stdin);	gets(x.date);
}
void faculty::xuat()
{
	cout<<setw(15)<<Name<<setw(15)<<ngay<<setw(15)<<x.name<<setw(15)<<x.date;
}

void person::nhap()
{
	cout<<"Name person: ";			fflush(stdin); 	gets(ten);
	cout<<"birth: ";				fflush(stdin);	gets(birth);
	cout<<"address: ";				fflush(stdin);	gets(address);
}
void person::xuat()
{
	cout<<setw(15)<<ten<<setw(15)<<birth<<setw(15)<<address;
}
void student::nhap()
{
	person::nhap();
	y.nhap();
	cout<<"class: ";				fflush(stdin);	gets(classs);
	cout<<"score: ";								cin>>score;	
}
void student::xuat()
{
	cout<<setw(15)<<"Name preson"<<setw(15)<<"birth"<<setw(15)<<"address"<<setw(15)<<"Name faculty"<<setw(15)<<"date faculty"<<setw(15)<<"name school"<<setw(15)<<"date school"<<setw(15)<<"class"<<setw(15)<<"score"<<endl;
	person::xuat();
	y.xuat();
	cout<<setw(15)<<classs<<setw(15)<<score<<endl;
}
void sua(student &t)
{
	strcpy(t.y.x.name,"DHCNHN");
}
int main()
{
	student t;
	t.nhap();
	t.xuat();
	sua(t),
	t.xuat();
}



