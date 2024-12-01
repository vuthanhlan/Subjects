#include<bits/stdc++.h>
using namespace std;

class SCHOOL
{
	private:
		char name[20];
		char date[10];
};
class FACULTY
{
	private:
		char name[20];
		char date[10];
		SCHOOL x;
	public:
		void nhap();
		void xuat();
};
class PERSON
{
	protected:
		char name[20];
		char birth[10];
		char address[30];
	public:
		void nhap();
		void xuat();
		PERSON();
};

class STUDENT
{
	private:
		FACULTY y;
		char clas[10];
		int score;
	public:
		void nhap()
}



