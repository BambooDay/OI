#include <bits/stdc++.h>
const int N = 3e5+5;

using namespace std;
int a[N],b[N],bi[N],ans_vis[N],sm[N],vis[N],t_b,t_s;
int n;
int book[N];
long long ans;
void init(){
	for(int i = 2; i < n; i++){
		if(a[i] > a[i+1] && a[i] > a[i-1]){
			bi[++t_b] = i;
			vis[i] = 2;
		}
		if(a[i] < a[i+1] && a[i] < a[i-1]){
			sm[++t_s] = i;
			vis[i] = -2;
		}
	}
	if(a[1] > a[2]) bi[++t_b] = 1,vis[1] = 1;
	if(a[1] < a[2]) sm[++t_s] = 1,vis[1] = -1;
	if(a[n] < a[n-1]) sm[++t_s] = n, vis[n] = -1;
	if(a[n] > a[n-1]) bi[++t_b] = n, vis[n] = 1;
} 
int main(){
	cin >> n;
	for(int i = 1; i <= n;i++){
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++){
		cin >> b[i];
	}
	init();
	sort(b+1,b+1+n);
	int l = 1,r = n;
	for(int i = 1;i <= t_b; i++){
		ans_vis[bi[i]] = b[r--];
		ans += vis[bi[i]] * ans_vis[bi[i]];
		book[bi[i]] = 1;
	}
	for(int i = 1; i <= t_s; i++){
		ans_vis[sm[i]] = b[l++];
		ans += vis[sm[i]] * ans_vis[sm[i]];
		book[sm[i]] = 2;
	}
	cout << ans << endl;
	int now = 0;
	for(int i = 1;i <= n; i++){
		if(ans_vis[i]){
			now = book[i];
			cout << ans_vis[i] << " ";
		}else if(now == 2){
			cout << b[l++] << " ";
		}else if(now == 1){
			cout << b[r--] << " ";
		}
	}
	return 0;
}
