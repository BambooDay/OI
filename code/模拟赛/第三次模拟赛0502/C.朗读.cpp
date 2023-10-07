#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 1e6+10;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;

using namespace std;
void read_int(string Z){
	string yi = Z.substr(Z.size()-12,4),wan = Z.substr(Z.size()-8,4),dan = Z.substr(Z.size()-4);
//	cout << yi << " " << wan << " " << dan << endl;
	bool flag = 1,ff = 0;//前面是否已经读过0
	//yi
	bool f = 0; 
	for(int i = 0; i < 4; i++){
		if(yi[i] != '0'){
			f = 1;
			break;
		}
	} 
	if(f){
		ff = 1;
		for(int i = 0; i < 4; i++){
			if(yi[i] == '0'){
				if(!flag){
					flag = 1;
					bool f1 = 0;
					for(int j = i+1; j < 4; j++){
						if(yi[j] != '0'){
//							cout << 1 << "mm";
							f1 = 1;break;
						}
					}
					if(f1) cout << '0';
					else{
//						cout << i << "mm";
						cout << "Y";
						flag = 0;
//						for(int j = 0; j < 4; j++){
//							if(wan[j] != '0' || dan[j] != '0'){	cout << '0';break;}
//						}
						break;
					}
				}
			}else{
				flag = 0;cout << yi[i];
				if(i == 0) cout << 'Q';
				if(i == 1) cout << 'B';
				if(i == 2) cout << 'S';
				if(i == 3) cout << 'Y';
			}
		}
	}
//	/*
	//wan
	f = 0; 
	for(int i = 0; i < 4; i++){
		if(wan[i] != '0'){
			f = 1;
			break;
		}
	} 	
	if(f){
		ff = 1;
		for(int i = 0; i < 4; i++){
			if(wan[i] == '0'){
				if(!flag){
					flag = 1;
					bool f1 = 0;
					for(int j = i+1; j < 4; j++){
						if(wan[j] != '0'){
							f1 = 1;break;
						}
					}
					if(f1) cout << '0';
					else{
						cout << "W";
//						for(int j = 0; j < 4; j++){
//							if(dan[j] != '0') {cout << '0';break;}
//						}
						flag = 0;
						break;
					}
				}
			}else{
				flag = 0;cout << wan[i];
				if(i == 0) cout << 'Q';
				if(i == 1) cout << 'B';
				if(i == 2) cout << 'S';
				if(i == 3) cout << 'W';
			}
		}
	}
	//dan
	f = 0; 
	for(int i = 0; i < 4; i++){
		if(dan[i] != '0'){
			f = 1;
			break;
		}
	} 	
	if(f){
		ff = 1;
		for(int i = 0; i < 4; i++){
			if(dan[i] == '0'){
				if(!flag){
					flag = 1;
					bool f1 = 0;
					for(int j = i+1; j < 4; j++){
						if(dan[j] != '0'){
							f1 = 1;break;
						}
					}
					if(f1) cout << '0';
//					cout << '0';
				}
			}else{
				flag = 0;cout << dan[i];
				if(i == 0) cout << 'Q';
				if(i == 1) cout << 'B';
				if(i == 2) cout << 'S';
			}
		}
	}
	if(!ff) cout << '0';//*/
}
void read_double(string R){
	ll len = R.size()-1;
	while(R[len] == '0'&& len >= 0) len--;
	if(len < 0) return;
	cout << 'D';
	cout << R.substr(0,len+1);
}

void read(string s){
	string Z,R;	
	int i = 0,cnt = 0;
	while(s[i] == '+' || s[i] == '-'){
		if(s[i] =='-') cnt++;
		s[i] = '0';
		i++;
	}
	if(cnt % 2){
		cout << 'F';
	}
	s = "000000000000"+s;
	if(s.find('.') == string::npos) s = s+".0";
	else s = s+"0";
	R = s.substr(s.find('.')+1);
	Z = s.substr(0,s.size()-R.size()-1);
	read_int(Z);
	read_double(R);
}
string s;
int main(){
	cin >> s;
//	if(s[0] == '-'){
//		cout << 'F';
//		s[0] = '0';
//	}	
	if(s.find('/') == string::npos){
		read(s);
	}else{
		string fm = s.substr(s.find('/')+1);
		string fz = s.substr(0,s.size()-fm.size()-1);
		int i = 0,cnt = 0;
		while(fm[i] == '+' || fm[i] == '-'){
			if(fm[i] =='-') cnt++;
			fm[i] = '0';
			i++;
		}
		i = 0;
		while(fz[i] == '+' || fz[i] == '-'){
			if(fz[i] =='-') cnt++;
			fz[i] = '0';
			i++;
		}
		bool f = 0;
		for(int i = 0; i < fz.size(); i++){
			if(fz[i] != '0' && fz[i] != '.'){
				f = 1;
				break;
			}
		}
		if(!f){
			cout << '0';
			return 0;
		}
		if(cnt % 2){
			cout << 'F';
		}
		if(fm.find('.') == string::npos){
			fm = fm+'.';
		}
		f = 0;
		for(int i = 0; i < fm.size(); i++){
			if(fm[i] != '0' && fm[i] != '.' && fm[i+1] != '.') {f = 1;break;}
			if(fm[i] != '1' && fm[i] !=  '.' && fm[i+1] == '.') {f = 1;break;}
		}
		if(f){
			read(fm);
			cout << "fz";
		}
		read(fz);
		
	} 
	return 0;
}
