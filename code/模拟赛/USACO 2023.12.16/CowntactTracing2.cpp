#include <bits/stdc++.h>
const int N = 3e5+10;

using namespace std;
string s;
int l[N],tot = 0;
int n;
int ans = 1e9;
bool check(int x){
//	cout << x << " ";
	int len = x*2-1;
	int tmp = 0 ;
	for(int i = 1; i <= tot; i++){
		if((i == 1 && s[1] == '1')|| (i == tot&& s[n] == '1')){
			if(x > l[i]) return 0;
			tmp += l[i]/len + !!(l[i]%len); 
			continue;
		}
		if(len > l[i]) return 0;
		tmp += l[i]/len + !!(l[i]%len); 
	}
	ans = min(ans,tmp);
//	cout << x << endl;
	return 1;
}
int main(){
	cin >> n >> s;
	s = " " + s;
	for(int i = 1;i <= n; i++){
		if(s[i] != s[i-1]&&s[i]=='1') tot++;
		if(s[i] == '1') l[tot]++;
	}	
//	if(tot == 1){
//		if(s[1] != '1' && s[2] != '1'){
//			cout << 1+!(l[1]%2) << endl;
//		}else{
//			cout << 1 << endl;
//		}
//		return 0;
//	}
//if(tot==2&&n != 6) return -1;
	int l = 1,r = n/2+1;
	while(l <= r){
		int mid = (l+r)>>1;
		if(check(mid)) l = mid+1;
		else r = mid-1;
	}
	cout << ans << endl;
	return 0;
}
