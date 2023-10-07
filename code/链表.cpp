#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 5e5+10;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;

using namespace std;
int c[N];
int n , m;
void modify(int cur, int k){
	for(int i = cur; i <= N-10; i += (i & -i)){
		c[i] += k;
	}
}
int find(int cur){
	int ans = 0;
	for(int i = cur; i ; i -= (i & -i)){
		ans += c[i];
	}
	return ans;
}
int a[N];
int main(){
	cin >> n >> m;
	for(int i = 1;i <= n; i++){
		cin >> a[i];
		if(a[i] > a[i-1] ){
			modify(a[i-1]+1,1);
			modify(a[i]+1,-1);
		}
	}
//	for(int i = 1;i <= 10; i++){
//		cout << find(i) << endl;
//	} 
	int w = 0;
	while(m--){
		char op;
		cin >> op;
		if(op == 'Q'){
			int x;
			cin >> x;
			w ^= x;
//			cout << w << " ";
			cout << find(w) << endl;
			w = find(w);
		}
		else{
			int k, y;
			cin >>k >> y;
			k ^= w;
			int t = a[k];
			a[k] = w^ y;
			if(t > a[k-1]){
				if(a[k] <= a[k-1]){
					modify(a[k-1]+1,-1);
					modify(t+1,1);
				}else{
					modify(t+1,1);
					modify(a[k]+1,-1);
				}
			}else{
				if(a[k] > a[k-1]){
					modify(a[k-1]+1,1);
					modify(a[k]+1,-1);
				}
			}
			if(t < a[k+1]){
				if(a[k+1] <= a[k]){
					modify(t+1,-1);
					modify(a[k+1]+1,1);
				}else{
					modify(t+1,-1);
					modify(a[k]+1,1);
				}
			}else{
				if(a[k] < a[k+1]){
					modify(a[k]+1,1);
					modify(a[k+1]+1,-1);
				}
			}
			
		}
	}
//	for(int i = 1;i <= 10; i++){
//			cout << find(i) << endl;
//		}
	return 0;
}
