#include <bits/stdc++.h>
const int N = 1e4+10;

using namespace std;
int a[N];
int n;
string name;
int main(){
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	string s;
	cin >> n >> s;
	for(int i = 0; i < s.size(); i++){
		if(s[i] >= 'a' && s[i] <= 'z') name = name + s[i];
		else break;
	}	
	for(int i = name.size(); i < s.size()-3; i++){
		a[1] = a[1]*10+s[i]-'0';
	} 
	for(int i = 2; i <= n; i++){
		cin >> s;
		for(int j = name.size(); j < s.size()-3; j++){
			a[i] = a[i]*10+s[j]-'0';
		}		
	}
	sort(a+1,a+1+n);
	for(int i = 1; i <= n; i++){
		cout << name << a[i] << ".in\n";
	}
	return 0;
}
