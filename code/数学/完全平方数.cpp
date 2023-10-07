/*
7: 2 3 2*2 5 2*3 7
   2*2*2*2*3*3
9:2 3 2*2 5 2*3 7 2*2*2 3*3
  2^6 * 3^4
*/
#include <bits/stdc++.h>
#define int long long
const int mod = 1e8+7;
const int N = 5e6+10;
using namespace std;
int n;
vector<int> pr;
int pre[N];
void solve(){
	for(int i = 2;i <= n; i++){
		if(!pre[i]){
			pr.push_back(i);
		}
		for(int j : pr){
			if(i*j > n) break;
			pre[i*j] = j;
			if(i % j == 0) break;
		}
	}
	
}
int cnt[N];
int pow(int a,int b) {
     int c = 1;
     while (b) {
     if (b&1) c = (c*a)%mod;
     b >>= 1;
     a = (a*a)%mod;
     }
     return c;
 }
signed main(){
	cin >> n;
	solve();
	for(int i = 2; i <= n; i++){
		int j = i;
		while(pre[j]){
			cnt[pre[j]]++;
			j /= pre[j];
		}
		cnt[j]++;
	}
	int sum = 1;
	for(int i : pr){
		sum = ((long long)pow(i,cnt[i]/2*2) % mod * sum) % mod;
	}
	cout << sum;
	return 0;
}
