#include<iostream>
#include<stdlib.h>
using namespace std;

template <class T> class MATRAN
{
	private:
		T **p;
		int n,m;
	public:
		void input();
		void output();
		MATRAN<T>& operator++(); // modify return type to return reference
};

template <class T> void MATRAN<T>::input()
{
	cout<<"nhap so dong: ";		cin>>n;
	cout<<"nhap so cot: ";		cin>>m;
	p=new T*[n]; // fix memory allocation
	for(int i = 0; i < n; i ++){
		p[i] = new T[m];
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cout<<"p["<<i<<"]["<<j<<"]= ";
			cin>>p[i][j];
		}
	}
}
template <class T> void MATRAN<T>::output()
{
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cout<<p[i][j]<<" ";
		}
		cout<<endl;
	}
}
template <class T> MATRAN<T>& MATRAN<T>::operator++() // modify function definition
{
	for(int i = 0; i < n; i++){
		for(int j = 0; j < i; j++){
			T tmp = p[i][j];
			p[i][j] = p[j][i];
			p[j][i] = tmp;
		}
	}
	return *this; // return reference to the modified matrix object
}

int main()
{
	MATRAN <double>a;
	MATRAN <long>b;
	a.input();
	b.input();
	cout<<"Ma tran a:\n";
	a.output();
	cout<<"Ma tran b:\n";
	b.output();
	a=++a;
	cout<<"Ma tran chuyen vi cua ma tran a:\n";
	a.output();
	b=++b;
	cout<<"Ma tran chuyen vi cua ma tran b:\n";
	b.output();
}




