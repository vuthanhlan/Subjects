#include<bits/stdc++.h>
using namespace std;

class MATRIX
{
	private:
		double **a;
		int n,m;
	public:
		friend istream& operator>>(istream &in, MATRIX &x);
		friend ostream& operator<<(ostream &out, MATRIX x);
		MATRIX operator+(MATRIX y);
		MATRIX operator-(MATRIX y);
		MATRIX operator--();
		MATRIX operator++();
};

istream& operator>>(istream &in, MATRIX &x)
{
	cout<<"Nhap so cot: ";				in>>x.n;
	cout<<"Nhap so hang: ";				in>>x.m;
	x.a=new double*[x.n];
	for(int i=0; i<x.n; i++)
	{
		x.a[i]=new double[x.m];
	}
	for(int i=0; i<x.n; i++){
		for(int j=0; j<x.m; j++){
			cout<<"a["<<i<<"]["<<j<<"]= ";
			in>>x.a[i][j];
		}
	}
return in;
}
ostream& operator<<(ostream &out, MATRIX x)
{
	for(int i=0; i<x.n; i++){
		for(int j=0; j<x.m; j++){
			out<<x.a[i][j]<<" ";
		}
		out<<endl;
	}
}
MATRIX MATRIX::operator+(MATRIX y)
{
	MATRIX tg;
	if(n==y.n && m==y.m)
	{
		tg.n=n; tg.m=m;
		tg.a=new double*[n];
		for(int i=0; i<n; i++)
		{
			tg.a[i]=new double[m];
		}
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++)
			{
				tg.a[i][j]=a[i][j]+y.a[i][j];
			}
		}
	}
	else{
		cout<<"hai ma tran khong cung kich thuoc!"<<endl;
		tg.n=tg.m=0;
//		tg.a=NULL;
	}
return tg;
}
MATRIX MATRIX::operator-(MATRIX y)
{
	MATRIX tg;
	if(n==y.n && m==y.m)
	{
		tg.n=n; tg.m=m;
		tg.a=new double*[n];
		for(int i=0; i<n; i++)
		{
			tg.a[i]=new double[m];
		}
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				tg.a[i][j]=a[i][j]-y.a[i][j];
			}
		}
	}
	else{
		cout<<"2 Ma tran khong cung kich thuoc"<<endl;
		tg.n=tg.m=0;
//		tg.a=NULL;
	}
return tg;
}
MATRIX MATRIX::operator--()
{
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			a[i][j]=-a[i][j];
		}
	}
return *this;
}
MATRIX MATRIX::operator++()
{
	for(int i=0; i<n; i++){
		for(int j=0; j<i; j++){
			double tmp=a[i][j];
			a[i][j]=a[j][i];
			a[j][i]=tmp;
		}
	}
return *this;
}
int main()
{
	MATRIX P,Q;
	ofstream ghi("MATRIX.txt");
	cout<<"Nhap ma Tran P\n";			cin>>P;
	cout<<"Nhap ma tran Q\n";			cin>>Q;
	cout<<"Ma tran P\n"<<P;
	ghi<<"Ma tran P\n"<<P;
	cout<<"Ma tran Q\n"<<Q;
	ghi<<"Ma tran Q\n"<<Q;
	cout<<"Tong 2 ma tran la:\n"<<P+Q;
	ghi<<"Tong 2 ma tran la:\n"<<P+Q;
	cout<<"Hieu 2 ma tran la:\n"<<P-Q;
	ghi<<"Hieu 2 ma tran la:\n"<<P-Q;
	cout<<"Doi dau Ma Tran P\n"<<--P;
	cout<<"Doi dau Ma Tran Q\n"<<--Q;
	cout<<"Ma tran chuyen vi cua P la:\n"<<++P;
	cout<<"Ma tran chuyen vi cua Q la:\n"<<++Q;
}



