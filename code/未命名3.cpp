#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 1e4+10;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;

using namespace std;
int n;
ll sum[2*N];
int c[2*N];
int a[N];
void modify(int pos, int x){
	for(int i = pos; i; i -= (i & -i)){
		c[i] += x; 
	}
}
int query(int pos){
	int sum = 0;
	for(int i = pos; i <= 2*N-20;i += (i & -i)){
		sum += c[i];
	}
	return sum;
}

int main(){
	cin >> n;
//	sum[0] = 1;
	for(int i =1;i <= n; i++){
		cin >> a[i];
//		a[i] += N-10;
		sum [i] = sum[i-1] + a[i];
	}
	for(int i =1;i <= n; i++){
		sum[i+n] = sum[i+n-1] + a[i];
	}
	int ans = 0;
	for(int i = n*2-1; i >= 0; i--){
//		cout << sum[i] <<" "; 
		modify(sum[i]+N,1);
		if(i < n){
			modify(sum[i+n+1]+N,-1);
		}
		if(i < n){
//			cout << query(sum[i]+N) << endl;
			if(query(sum[i]+N) == n) ans++;
		}
	}
	cout << ans;
	return 0;
}
