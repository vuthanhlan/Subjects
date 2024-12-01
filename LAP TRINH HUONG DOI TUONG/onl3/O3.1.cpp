#include<iostream>
#include<fstream>
#include<stdlib.h>
using namespace std;

class MANG
{
	private:
		float *value;
		int n;
	public:
		friend istream& operator>>(istream& in, MANG &x);
		friend ostream& operator<<(ostream& out, MANG y);
		MANG operator++();
		MANG operator-();
};
istream& operator>>(istream& in, MANG &x)
{
	cout<<"so phan tu cua mang: ";		in>>x.n;
	x.value= new float[x.n];
	for(int i=0; i<x.n; i++){
		cout<<"value["<<i<<"]=";
		in>>x.value[i];
	}
return in;
}
ostream& operator<<(ostream& out, MANG y)
{
	for(int i=0; i<y.n; i++){
		out<<y.value[i]<<" ";
	}
	out<<endl;
return out;
}

MANG MANG::operator++()
{
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n;j++){
			if(value[i]>value[j]){
				float temp=value[i];
				value[i]=value[j];
				value[j]=temp;
			}
			
		}
	}
}
MANG MANG::operator-()
{
		for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n;j++){
			if(value[i]<value[j]){
				float temp=value[i];
				value[i]=value[j];
				value[j]=temp;
			}
			
		}
	}
}
int main()
{
	MANG a;
	ofstream ghi("MANG.txt");
	cin>>a;
	cout<<a;
	++a;
	cout<<"mang tang dan: "<<a;
	ghi<<"Mang tang dan: "<<a;
	-a;
	cout<<"mang giam dan: "<<a;
	ghi<<"Mang giam dan: "<<a;
}

