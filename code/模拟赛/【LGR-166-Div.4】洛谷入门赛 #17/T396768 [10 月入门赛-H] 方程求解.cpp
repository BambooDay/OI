#include<bits/stdc++.h>
#define int long long
const int N = 2e5+10;

using namespace std;
int n,q;
int x[N];
int find(int val){
	int l = 0,r = n;
	int ans = 0;
	while(l <= r){
		int mid = (l+r)>>1;
		if(x[mid] <= val) ans = mid,l = mid+1;
		else r = mid-1;
	} 
	return ans;
}
signed main(){
	cin >> n >> q;
	for(int i =1; i <= n; i++){
		int a,b,c;
		scanf("%lldx%lld=%lld",&a,&b,&c);
		x[i] = (c-b)/a;	
//		cout << x[i] << " ";
	}	
//	cout << endl;
	sort(x+1,x+1+n);
	n = unique(x+1,x+1+n)-x-1;
//	cout << find(3) << endl;
	while(q--){
		int l,r;
		cin >> l >> r;
		cout << find(r) - find(l-1) << endl;
	}
	return 0;
}
