#include <iostream>
#include <string>

using namespace std;

int getIndexFromChar(char c){
	string alphabet="abcdefghijklmnopqrstuvwxyz";
	
	c= tolower(c);
		
	for(int i=0; i<alphabet.length(); i++){
		if(c== alphabet[i]){
			return i;
		}
	}return -1;
}

char getCharFormIndex(int index){
	string alphabet="abcdefghijklmnopqrstuvwxyz";
	if(index >=0 && index <alphabet.length()){
		return alphabet[index];
	}
	else{
		return ' ';
	}
}

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
string maHoa(string banRo, int a, int b){
//	int a=k[0];
//	int b=k[1];
	string mahoa="";
	for(int i=0; i< banRo.length(); i++){
		int x= getIndexFromChar(banRo[i]);
		if(x==-1){
			mahoa+=banRo[i];
			continue;
		}
		int e= (a*x+b) % 26;
		mahoa+=getCharFormIndex(e);		
	}
	return mahoa;
}
int nghichDao(int a){
	if(a==1){
		return a;
	}else{
		int a1=1, a2=0, a3=26;
		int b1=0, b2=1, b3=a;
		while(b3>0){
		
			int Q = a3/b3;
			int R1= a1-Q*b1;
			int R2= a2-Q*b2;
			int R3= a3-Q*b3;
		
			a1 = b1;
			a2 = b2;
			a3 = b3;
		
			b1 = R1;
			b2 = R2; 
			b3 = R3;
		
			if(b3 == 1){
				if(b2 >0) return b2;
				else return 26+b2;
			}
		}	
	}
	
	
}

void giaiMa(string banGiaiMa, int a, int b){
//	int a=k[0];
//	int b=k[1];
	string giaima="";
	int d;
	int c= nghichDao(a);
	for(int i=0; i< banGiaiMa.length(); i++){
		int y = getIndexFromChar(banGiaiMa[i]);
		if(y==-1){
			giaima+=banGiaiMa[i];
			continue;
		}
		if(y-b >=0){
			d = (c*(y-b)) % 26;	
		}else{
			d = (c*(26+(y-b))) % 26;	
		}
		
		giaima+=getCharFormIndex(d);	
			
	}cout<<giaima;
}

int main(){
	int a,b;
	string banRo;
	string mahoa;
	cout<<"Nhap thong diep ma hoa:";
	getline(cin,banRo);
	do{
		cout<<"Nhap a= "; cin>>a;
		
	}while(gcd(a,26)!=1 || a<1 || a>26);
	do{
		cout<<"Nhap b= "; cin>>b;		
	}while( b<1 || b>26);
	
	mahoa=maHoa(banRo,a,b);
	cout<<"Thong diep ma hoa: "<<mahoa<<endl;
	cout<<"Thong diep giai ma: ";
	giaiMa(mahoa,a,b);
	return 0;
}
