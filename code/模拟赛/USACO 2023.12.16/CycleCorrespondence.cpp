#include <bits/stdc++.h>
const int N = 5e5+10;

using namespace std;
int a[N<<1],b[N<<1];
int n,k;
bitset<N> A,B,C;
map<int,int> pa,pb,ap;
int ans = 0;
bool vis[N];
int main(){
	cin >> n >> k;
	for(int i = 1;i <= k; i++){
		cin >> a[i];
		A[a[i]] = 1;
		pa[a[i]] = i;
		a[i+k] = a[i];
		ap[a[i]] = k-i+1;
	}	
	for(int i = 1; i <= k; i++){
		cin >> b[i];
		B[b[i]] = 1;
		pb[b[i]] = i;
		b[i+k] = b[i];
	}
	C = A&B;
	vector<int > v;
	for(int now = C._Find_first();now != C.size(); now = C._Find_next(now)){
		v.push_back(now);
//		int tmp = 0;
//		for(int i = pa[now],j = pb[now],cnt = 1; cnt <= k; cnt++,i++,j++){
//			if(a[i] == b[j]){
//				tmp++;
//			} 
//		}
////		cout << now << " " << tmp << endl;;
//		ans = max(ans,tmp);
//		tmp = 0;
//		for(int i = pa[now]+k,j = pb[now],cnt = 1; cnt <= k; cnt++,i--,j++){
//			if(a[i] == b[j]) tmp++;
//		}
//		ans = max(ans,tmp);
	}
//	if(n > 5000){
//		cout << n - k*2 + C.count() << endl;
//		return 0;
//	}
	for(int now : v){
		if(vis[now]) continue;
		int anow = ap[now],bnow = pb[now];
		int tmp = 1;
		vis[now] = 1;
		for(int i : v){
			if(i == now) continue;
			int x = ap[i],y = pb[i];
			if(x < anow) x += k;
			if(y < bnow) y += k;
			x -= anow,y -= bnow;
			if(x == y){
				tmp++;
				vis[i] = 1;
			}
		}
		ans = max(ans,tmp);
		if(ans >= v.size()/2+v.size()%2)break;
	}
	memset(vis,0,sizeof vis);
	for(int now : v){
		if(ans > v.size()/2+v.size()%2)break;
		if(vis[now]) continue;
		int anow = pa[now],bnow = pb[now];
		int tmp = 1;
		vis[now] = 1;
		for(int i : v){
			if(i == now) continue;
			int x = pa[i],y = pb[i];
			if(x < anow) x += k;
			if(y < bnow) y += k;
			x -= anow,y -= bnow;
			if(x == y){
				tmp++;
				vis[i] = 1;
			}
		}
		ans = max(ans,tmp);
	}	
//	cout << ans << endl;
	cout << ans + n - k*2 + C.count();
	return 0;
}
