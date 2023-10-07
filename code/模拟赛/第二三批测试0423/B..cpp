#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 1e6+10;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;

using namespace std;
string ma,mi;
string s;
int max_len = 0,min_len = INF;
int main(){
	while(cin >> s){
		if(!s.find(',')){
			if(s.size() > max_len){
	//		cout<< s.size() << " " << max_len;
				max_len = s.size();
				ma = s;
			}
			if(s.size() < min_len){
				min_len = s.size();
				mi = s;
			}
		}else{
			int i = 0;
			while(i < s.size()){
				int j = i;
				while(s[j] != ',' && j < s.size()){
					j++;
				}
				if(j-i > max_len){
					max_len = j-i;
					ma = s.substr(i,j-i);
				}
				if(j-i < min_len){
					min_len = j-i;
					mi = s.substr(i,j-i);
				}
				i = j+1;
			}
		}
	}
	cout << ma << endl << mi;
	return 0;
}
