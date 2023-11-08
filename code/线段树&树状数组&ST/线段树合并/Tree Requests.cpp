#include<bits/stdc++.h>
const int N = 5e5+10;
#define ls(f) tr[f].l
#define rs(f) tr[f].r
#define val(f) tr[f].val
#define mid ((l+r)>>1)
//#define int long long
using namespace std;
char bg;
int n,m;
vector<int> e[N];
vector<pair<int,int> > ques[N];
//int headl[N], nel[N<<1], tol[N<<1], weight[N<<1],to;
//inline void addQ(int x, int y){
//	++to;
//	tol[to]=y;
//	nel[to]=headl[x];
//	headl[x]=to;
//	weight[to]=to;
//	return ;
//}//¼ÓÑ¯ÎÊ¡£
struct Node{
	int l = 0,r = 0;
	int val = 0;
}tr[N*20];
//int lc[N*20], rc[N*20], tree[N*20];
int tot;
char ch[N];
bool ans[N];
void build(int &root, int l, int r, int x, int y){
	root = ++tot;
	if(l == r){
		val(root) =(1<<y);
//		cout << y << endl; 
//		cout<< val(root) << endl;
		return;
	}	
	if(x <= mid) build(ls(root),l,mid,x,y);
	else build(rs(root),mid+1,r,x,y);
	val(root) = val(ls(root)) ^ val(rs(root));
//	cout << val(root) <<endl;
//	cout << ls(root) << " " << rs(root) << endl;
}
int merge(int x, int y, int l, int r){
	if(!x || !y) return x+y;
	if(l == r){
		val(x) ^= val(y);
		return x;
	}
	ls(x) = merge(ls(x),ls(y),l,mid);
	rs(x) = merge(rs(x),rs(y),mid+1,r);
	val(x) = val(ls(x)) ^ val(rs(x));
	return x; 
}
int ask(int pos, int l, int r, int x){
	if(l == r) return val(pos);
	if(x <= mid) return ask(ls(pos),l,mid,x);
	else return ask(rs(pos),mid+1,r,x);
}
int dep[N],rt[N];
void dfs(int x, int fa){
	dep[x] =  dep[fa]+1;
//	cout << x << " ";
	build(rt[x],1,n,dep[x],ch[x-1]-'a'+1);
//	cout << val(rt[x]) << endl;
//	cout << rt[x] << endl;
	for(int to : e[x]){
		if(to == fa) continue;
		dfs(to,x);
		rt[x] = merge(rt[x],rt[to],1,n);
	}
	for(auto i : ques[x]){
		int cnt = 0,tmp = ask(rt[x],1,n,i.first);
//		cout << tmp << endl;
		while(tmp){
			if(tmp&1) cnt++;
			tmp >>= 1;
		}
		if(cnt > 1) ans[i.second] = 0; 
		else ans[i.second] = 1;
	}
//	for(int i=headl[x];i;i=nel[i]){
//		int cnt=0;
//		int tmp=ask(rt[x],1,n,tol[i]);
////		cout << ans[weight[i]] << endl;
//		while(tmp){
//			if(tmp&1) cnt++;
//			tmp>>=1;
//		}
//		ans[weight[i]]=(cnt <= 1);
//	}
}
char ed;
signed main(){
//	cout << (&bg - &ed) / 1048576.0 << "\n"; 
//	cin >> n >> m;
	scanf("%d%d",&n,&m);
	for(int i = 2;i <= n; i++){
		int fa;
//		cin >> fa;
		scanf("%d",&fa);
		e[fa].push_back(i);
	}
//	scanf("%s",(ch+1));
	scanf("%s",ch);
	for(int i = 1;i <= m; i++){
		int a,b;
//		cin >> a >> b;
		scanf("%d%d",&a,&b);
		ques[a].push_back({b,i}); 
//		addQ(a,b);
	}
	dfs(1,0);
	for(int i =1;i <= m; i++) if(!ans[i]) puts("No");else puts("Yes");
	return 0;
}
