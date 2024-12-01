#include<iostream>

using namespace std;

class HCN
{
	private:
		float chieudai;
		float chieurong;
	public:
	void nhap();
	void ve();
	float dientich();
	float chuvi(); 
};

void HCN::nhap()
{
	cout<<"Nhap chieu dai HCN: ";              cin>>chieudai;
	cout<<"Nhap chieu rong cua HCN: ";         cin>>chieurong;
}
void HCN::ve()
{
	for(int i=0; i<chieurong; i++){
		for(int j=0; j<chieudai; j++){
			if(i==0 || i==chieurong-1 || j==0 || j==chieudai-1){
				cout<<"* ";
			}else{
				cout<<"  ";
			}
		}
		cout<<"\n";
	}
}
float HCN::dientich()
{
	float S=chieudai*chieurong;
	return S;
}
float HCN::chuvi()
{
	float P=(chieudai+chieurong)*2;
	return P;
}
int main()
{
	HCN hcn1;
	hcn1.nhap();
	hcn1.ve();
	cout<<"\Dien tich HCN= "<<hcn1.dientich()<<endl;
	cout<<"Chu vi HCN= "<<hcn1.chuvi();
	
}



