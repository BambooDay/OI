#include <bits/stdc++.h>
const int N = 2e5+10;
#define int long long
using namespace std;
int n,m;
int h[N],c[N];
int R[N],L[N],head,tail;
 namespace Sub1{
 	void solve(){
		for(int i = 1; i <= n; i++) cin >> h[i];
		for(int j = 1; j <= m; j++) cin >> c[j];
		for(int i = 1;i <= m; i++){
			int now = 0;
	//		if(h[1] > c[i]){
	//			h[1] += c[i];
	//			now = c[i];
	//		} 
			int cnt = 0;
			for(int j = 1; j <= n; j++){
				if(h[j] > c[i]) cnt++;
				if(cnt>1)break;
				if(h[j] >= now){
					int now1 = now;
					now = h[j];
					h[j] += min(h[j] - now1,max(c[i]-now1,0ll));
				}
			}
		}
		for(int i = 1;i <= n; i++) cout << h[i] << '\n';	
	 }
 }
 namespace Sub2{
 	void solve(){
 		for(int i = 1; i <= n; i++) cin >> h[i];
		for(int j = 1; j <= m; j++) cin >> c[j];
		h[0] = 0;
		h[n+1] = N;
		for(int i = 1; i <= n; i++){
			if(h[tail] < h[i]) R[tail] = i,L[i] = tail,tail = i;
		}
		for(int i = 1;i <= m; i++){
			int now = tail;
			while(h[now] > c[i] && now != head) now = L[now];
			if(now == head) h[R[now]] += c[i];
	//		cout << now << " " << head << endl;
			while(now != head){
				h[now] += h[now] - h[L[now]];
				now = L[now];
			}
			now = head;
			while(now != L[tail]){
				if(h[R[now]] <= h[now]) L[R[R[now]]] = now, R[now] = R[R[now]];
				else now = R[now]; 
			}
			if(h[R[now]] <= h[now]) tail = now;
		}
		for(int i = 1;i <= n; i++) cout << h[i] << '\n';
	}
 }
signed main(){
	cin >> n >> m;
	if(n < 2e5 && m < 2e5) Sub1::solve();
	else Sub2::solve();
	return 0;
}
//5 2
//1 2 3 4 5
//5 3
//2 3 4 5 6
//4 4 4 5 6
