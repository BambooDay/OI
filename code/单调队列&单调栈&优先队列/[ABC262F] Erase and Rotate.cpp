#include <bits/stdc++.h>
const int N = 2e5+10;

using namespace std;
int a[N];
int n,k;
vector<int> ans1,ans2;
int q[N],b[N];
int tp,hd;
int main(){
	cin >> n >> k;
	for(int i = 1;i <= n; i++){
		cin >> a[i];
	}	
	for(int i = 1,cnt = 0;i <= n;i++){
		while(tp && a[i] < a[q[tp]] && cnt < k)tp--,cnt++;
		q[++tp] = i;
		if(i == n){
			while(tp && cnt < k) cnt++,tp--;
		}
	}
	for(int i = 1;i <= tp;i++) ans1.push_back(a[q[i]]);
	tp = 0;
	a[n+1] = 1e9;
	int p = n+1;
	for(int i = n;i > n-k;i--){
		if(a[i] < a[p]) p = i;
	}
	for(int i = p;i <= n;i++){
		while(tp && a[i] < a[q[tp]]) tp--;
		q[++tp] = i;
	}
	k -= (n - p + 1);
	for(int i = 1;i < p;i++){
		while(hd && k && a[b[hd]] > a[i]) hd--,k--;
		b[++hd] = i;
	}
	while(k) hd--,k--;
	while(hd && tp && a[q[tp]] > a[b[1]]) tp--;
	for(int i = 1;i <= tp; i++) ans2.push_back(a[q[i]]);
	for(int i = 1;i <= hd; i++) ans2.push_back(a[b[i]]);
	if(ans1 < ans2) for(auto i : ans1)cout << i << " ";
	else for(auto i : ans2) cout << i << " ";
	
	return 0;
}
