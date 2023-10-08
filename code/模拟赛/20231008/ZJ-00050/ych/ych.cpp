#include <bits/stdc++.h>
#define int unsigned long long
const int BASE = 13331;
const int N = 2e5+10;
using namespace std;
int n,q;
string s;
int hs[N],sh[N],base[N];
int get(int a[], int l, int r){
	return (a[r] - a[l-1]*base[r-l+1]);
}
signed main(){
	freopen("ych.in","r",stdin);
	freopen("ych.out","w",stdout);
	base[0] = 1;
	cin >> n >> q >> s;
	s = " " + s;
	for(int i = 1; i <= n; i++){
		base[i] = base[i-1] * BASE;
		hs[i] = hs[i-1] * BASE + s[i];
		sh[i] = sh[i-1] * BASE + s[n-i+1];
	}	
//	cout << get(hs,2,4) << endl;
	while(q--){
		int l1,r1,l2,r2;
		cin >> l1 >> r1 >> l2 >> r2;
		int ans = 0;
		int len = r1 - l1 + 1;
		vector<int> pre;//u
		pre.push_back(0);
		vector<int> suf;//w
		suf.push_back(0); 
		for(int i = 1; i<= len; i++){
			if(get(hs,l1,l1+i-1) == get(hs,r2-i+1,r2)) pre.push_back(i);
			if(get(hs,r1-i+1,r1) == get(hs,l2,l2+i-1)) suf.push_back(i);
		}
		for(int i : pre){
			for(int j :suf){
				if(i+j == len){
					ans++;
					continue;
				}
				if(i+j > len) continue;
				if(get(hs,l1+i,r1-j) == get(sh,n-(r2-i)+1,n-(l2+j)+1)) ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
