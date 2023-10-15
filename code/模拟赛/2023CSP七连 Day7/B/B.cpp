#include <bits/stdc++.h>
const int N = 1e6+10;

using namespace std;
int nn;
int n;
char s[N];
int cnt = 0,ans = 0;
int main(){
	cin >> nn >> (s+1);
	bool f = 1; 
	n = nn;
	while(cnt < nn && f){
//		for(int i = 1; i <= n; i++) cout<<s[i];
//		cout << endl;
		f = 0;
		int l = 1,r = 2;
		while(s[l] == s[r] && r <= n) l++,r++;
		if(r > n) break;
		ans++;
		f = 1;
		while((l-1) && s[l-1] != s[l]) l--;
		while(r+1 <= n && s[r+1] != s[r]) r++;
//		cout << l << " " << r << endl;
		int tmp =r-l+1;
		for(int i = l,j = r+1;j <= n; j++,i++){
//			cout << j << "xx" << s[j] << " "; 
			s[i] = s[j];
		}				
//		cout << endl;
		n -= tmp;
		cnt += tmp;
	}
	cout << ans + nn-cnt << endl;
	return 0;
}
