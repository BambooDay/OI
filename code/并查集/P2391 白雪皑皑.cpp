#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 1e6+10;
const int M = 1e7+10;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;

using namespace std;
int n, m;
int fa[N];
int p, q;
int get(int x){
	return fa[x] == x? x:fa[x] = get(fa[x]);
}
int color[N];
int main(){
//	cin >> n >> m >> p >> q;
	scanf("%d%d%d%d",&n,&m,&p,&q);
	for(int i = 1; i <= n;i++) fa[i] = i;
	for(int i = m;i >= 1; i--){
		int l = (i*p+q)%n+1,r =(i*q+p)%n+1;
		if(l > r) swap(l,r);
//		cout << l << " " << r << endl;
		for(int j = r; j >= l;){
//			cout << j << " ";
			int f = get(j);
			if(f == j){
				color[j] = i;
				fa[j] = get(j-1);
			}
//			cout << fa[j] << ' ';
			j = fa[j];
		} 
//		cout << endl;
	}
	for(int i = 1;i <= n; i++) printf("%d\n",color[i]);//cout << color[i] <<endl;
	return 0;
}
