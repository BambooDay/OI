#include <bits/stdc++.h>
#define int long long
using namespace std;
string s;
int get(int step, int last, int delta,int now){
	if(step == s.size()) return now;
	return get(step+1,last+delta,delta,now*10 + last+delta);
}
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	if(s.size() == 1){
		cout << s;
		return 0;
	}	
	int n = 0;
	for(int i = 0;i < s.size(); i++){
		n = n*10+s[i]-'0';
	}
//	cout << get(1,1,4,1) << endl;
	int a = s[0]-'0';
	for(int i = a; i <= 9; i++){
		for(int j = -9; j <= 9; j++){
			if(i+j*(s.size()-1) > 9 || i+j*(s.size()-1) < 0) continue;
//			cout << i << " " << j << endl;
			int ans = get(1,i,j,i);
			if(ans >= n){
				cout << ans;
				return 0;
			}
		}
	}
	return 0;
}
