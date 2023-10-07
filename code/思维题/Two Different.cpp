#include <bits/stdc++.h>

using namespace std;
int n;
vector<pair<int,int> > ans;
//int ls[15005];
void solve(int l, int r){
//	cout << l << " " << r << endl;
	if( l == r) return;
	int mid = (l+r) >> 1;
	solve(l,mid);
	solve(mid+1,r);
	for(int i = l; i <= mid; i++){
		ans.push_back(make_pair(i,i-l+1+mid));
	}
}
int lg[15005];
int main(){
	int n;
	cin >> n;
	lg[1] = 1;
	for(int i = 2;i <= n; i++){
		lg[i] = lg[i>>1] << 1;
	}
	solve(1,lg[n]);
	solve(n-lg[n]+1,n);
	cout<< ans.size() << endl;
	for(auto i : ans){
		cout << i.first << " " << i.second << endl;
	}
	return 0;
}
