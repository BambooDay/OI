#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
string s;
int sum;
map<int,int> m;
signed main(){
	cin >> n >> s;
	s = " " + s;
	int res = 0;
	for(int i = 1;i <= n; i++){
		if(s[i] == 'J'){
			sum++;
		}	
		if(s[i] == 'O') sum += 114513;
		if(s[i] == 'I') sum -= 114514;
		if(sum == 0) res = max(res,i);
		else if(m.count(sum)) res = max(res,i-m[sum]);
		else m[sum] = i;	
	}
	cout << res << endl;
	return 0;
}
