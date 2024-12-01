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
	}
	return -1;
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

string maHoa(string banRo, int k){
	string kq="";
	for(int i=0; i< banRo.length(); i++){
		int x= getIndexFromChar(banRo[i]);
		if(x==-1){
			kq+=banRo[i];
			continue;
		}
		int e= (x+k) % 26;
		kq+=getCharFormIndex(e);		
	}
	return kq;
}

void giaiMa(string banMaHoa, int k){
	int d;
	string giaiMa="";
	for(int i=0; i< banMaHoa.length(); i++){
		int y= getIndexFromChar(banMaHoa[i]);
		if(y==-1){
			giaiMa+=banMaHoa[i];
			continue;
		}
		if(y-k >0){
			d= (y-k) % 26;
		}
		else{
			d= (26+(y-k)) %26;
		}
		
		giaiMa+=getCharFormIndex(d);		
	}
	cout<<giaiMa;
}
main(){
	 
	int k;
	string banRo;
	string kq;
	cout<<"Nhap thong diep ma hoa:";
	getline(cin,banRo);
	
	do{
		cout<<"Nhap k ( so tu 1-25 ): ";
		cin>>k;
	}while(k<1 || k>25);
	
	kq=maHoa(banRo,k);
	cout<<"Ban ma hoa: "<<kq<<endl;
	cout<<"Ban giai ma: ";
	giaiMa(kq,k);
	return 0;
}
