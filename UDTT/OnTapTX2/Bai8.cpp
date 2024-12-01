#include<bits/stdc++.h>
using namespace std;

struct Laptop{
	string hsx;
	string cauhinh;
	int giaban;
};

int find_char(char target, string str){
	for(int i=0; i<str.length(); i++){
		if(str[i] == target) return i;
	}
	return -1;
}

int B_M_H(string con, string cha){
	int dem=0;
	int len_con=con.length();
	int i= len_con-1;
	while(i<cha.length()){
		int x=len_con-1;
		while(cha[i] == con[x] && x>-1){
			i--;
			x--;
		}
		if(x<0){
			dem++;
			i=i+len_con+1;
		}
		else{
			int k=find_char(cha[i], con);
			if(k<0) i=i+len_con;
			else i=i+len_con-k-1;
		}
	}
	return dem;
}

void TT_Z(string con,string cha, int z[]){
	char tmp='$';
	string s=con + tmp + cha;
	int n=s.length();
	int left=0; int right=0;
	z[0]=-1;
	for(int i=1; i<n; i++){
		if(i>right){
			left=right=i;
			while(right<n && s[right-left] == s[right]) right++;
			z[i]=right - left;
			right--;
		}
		else if(z[i-left]<(right-i+1)){
			z[i]=z[i-left];
		}
		else{
			left=i;
			while(right<n && s[right-left] == s[right]) right++;
			z[i]=right - left;
			right--;
		}
	}
}
int KT_Xaucon(string con, string cha, int z[]){
	TT_Z(con,cha,z);
	int dem=0;
	int n=con.length()+ cha.length() +1;
	for(int i=0; i<n; i++){
		if(z[i]== con.length()) dem++;
	}
	if(dem>0) return 1;
	return 0;;
}
int main(){
	int n=6;
	Laptop laptop[n]{
		{"H1","CPU 2.5GHz upto 3.5GHz-RAM 16GB-SSD 1024GB",2000},
		{"H2","CPU 2.5GHz upto 3.5GHz-RAM 16GB-SSD 512GB",2000},
		{"H3","CPU 2.5GHz upto 3.5GHz-RAM 8GB-HDD 2TB",2000},
		{"H4","CPU 3.5GHz upto 3.5GHz-RAM 16GB-SSD 512GB",2000},
		{"H5","CPU 5.5GHz upto 3.5GHz-RAM 8GB-HDD 2TB",2000},
		{"H6","CPU 1.5GHz upto 3.5GHz-RAM 16GB-HDD 1TB",2000}
	};
	int dem=0;
	for(int i=0; i<n; i++){
		if(B_M_H("16GB", laptop[i].cauhinh)>0) dem++;
	}
	cout<<"Co "<<dem<<" laptop co 16GB"<<endl;
	
	cout<<"\nDANH SACH LAPTOP CO O CUNG SSD"<<endl;
	for(int i=0; i<n; i++){
		int z[3+ laptop[i].cauhinh.length() +1];
		if(KT_Xaucon("SSD", laptop[i].cauhinh, z)==1){
			cout<<laptop[i].hsx<<endl;
		}
	}
}


