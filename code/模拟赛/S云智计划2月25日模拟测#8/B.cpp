#include <bits/stdc++.h>
#define int long long
const int N = 1e5+10;

using namespace std;
int n,x,y;
struct Node{
	int tp, num;
}a[N];
bool cmp(Node x, Node y){
	return ((x.tp != y.tp) ? x.tp > y.tp : x.num > y.num);
} 
int ans = 0;
signed main(){
	freopen("genshin.in","r",stdin);
	freopen("genshin.out","w",stdout);
	cin >> n >> x;
	y = n-x;
	for(int i = 1; i <= n; i++){
		cin >> a[i].tp >> a[i].num;
	}	
	sort(a+1,a+1+n,cmp);
	for(int i = 1; i <= n; i++){
		if(a[i].tp && x){
			x--;
			ans += a[i].num*2;
		}else if(!a[i].tp && y){
			y--;
			ans += a[i].num*1.5;
		}else{
			ans += a[i].num;
		}
	}
	cout << ans;
	return 0;
}
