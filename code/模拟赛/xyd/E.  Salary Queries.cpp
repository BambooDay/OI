#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 5e6+10;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;

using namespace std;
int tree[N];
void modify(int x, int y){
	for(int i = x; i <=N-10; i += (i & -i)){
		tree[i] += y;
	}
}
int query(int x){
	int ans = 0;
	for(int i = x; i > 0; i -= (i & -i)){
		ans += tree[i]; 
	}
	return ans;
}
int n, q;
ll p[N];
struct Q{
	char op;
	ll x, y;
}ques[N];
ll a[N],cnt = 0;
map<ll,int> m;
int main(){
	scanf("%d%d",&n,&q);
	for(int i = 1; i <= n; i++){
		scanf("%lld",&p[i]);
		a[++cnt] = p[i];
	}
	for(int i = 1; i <= q; i++){
		cin >> ques[i].op >> ques[i].x >> ques[i].y;
		a[++cnt] = ques[i].x;
		a[++cnt] = ques[i].y; 
	}
	sort(a+1,a+1+cnt);
	cnt = unique(a+1,a+cnt+1) - a-1;
	for(int i =1 ;i <= cnt; i++){
		m[a[i]] = i;
	}
	for(int i = 1; i <= n; i++){
		p[i] = m[p[i]];
		modify(p[i],1);
	}	
	for(int i = 1;i <= q; i++){
		char op = ques[i].op;
		if( op == '!'){
			int k = ques[i].x, x = m[ques[i].y];
			modify(p[k],-1);
			modify(x,1);
			p[k] = x;
		}else{
			int a = m[ques[i].x], b = m[ques[i].y];
			printf("%d ",query(b) - query(a-1));
		}
	}
	return 0;
}
