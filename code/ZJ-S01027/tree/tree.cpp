#include <bits/stdc++.h>
const int N = 1e5+10;
//#define ull unsigned long long
//#define int __int128 
using namespace std;
long long n;
long long A[N],B[N], C[N];
vector<int> e[N],E[N];
int h[N],node[N],ne[N],idx = 0;
void add(int u, int v){
	node[++idx] = v;
	ne[idx] = h[u];
	h[u] = idx;
}
int deg[N];
long long t[N];
long long get(__int128 a, __int128 b, __int128 c, __int128 x){
	__int128 l = 1, r = x;
	long long ans = 0;
	while(l <= r){
		__int128 mid = (l+r) >> 1;
		__int128 sum = b*mid + c*(x*mid - (mid-1)*mid / 2);
		if(sum >= a){
			ans = mid;
			r = mid-1;
		}else{
			l = mid+1;
		}
	}
	return ans;
}
bool cmp(long long x, long long y){
	 return x > y;
}
bool check(__int128 x){
	int d[N];
	for(int i = 1;i <= n; i++) d[i] = deg[i];
	map<int,vector<int> > m; 
	for(int i = 1;i <= n; i++){
		__int128 b = B[i],c = C[i],a = A[i];
		if(b+x*c >= 1){
			/*int aa = a;
			aa -= b*x;
			if(aa <= 0){t[i] = get(a,b,c,x); continue;}
			unsigned long long yy = ull*x*x - x*ull*(x*ull-1ull)/2ull;
			if(c < floor(a/yy)) return i;
			else t[i] = get(a,b,c,x);*/
			if(b*x+ c*(x*x - x*(x-1)/2) < a) {
				//cout << b*x+ c*(x*x - x*(x-1)/2) << endl;
				return 0;
			}
			t[i] = get(a,b,c,x);
		}else{
			if(b - c < 1){
				if(a > x) return 0;
				t[i] = a;
			}else{
				long long tmp = ceil(x*1.0+1.0 - (2.0-b*1.0)/(c*1.0))-1;
				if(tmp >= a){
					t[i] = a;
				}else{
					__int128 xx = x - tmp;
					a -= tmp;
					if(b*xx+ c*(xx*xx - xx*(xx-1)/2) < a) return 0;
					t[i] = tmp + get(a-tmp,b,c,xx);
				}
			}
		}
		t[i] = x - t[i]+1;
		m[t[i]].push_back(i);
		d[i]++;
		//cout << t[i] << endl;
	}
	//cout << endl;
	//cout << 111 << endl;
	sort(t+1,t+1+n);
	int tot = unique(t+1,t+1+n) - t - 1;
	int cnt = n;
	queue<int> q;
	bool f = 1;
	//for(int i = 1;i <= n; i++){
	//	if(!d[i]) q.push(i);
	//}
	//cout << (long long)x << endl;
	//cout << t[tot] << endl;
	for(long long i = t[tot]; i && cnt;){
		f = 1;
		//cout << (long long)tot << endl;
		//cout << (long long)i << " : ";
		if(m.count(i)){
			for(int to : m[i]){
				d[to]--;
				
				if(!d[to]){
					//cout << (long long) to << endl;
					q.push(to);
				} 
			}
		}
		if(!q.empty()){
			int u = q.front();
			//cout << (long long)i << " : " << (long long)u << endl;
			cnt--;
			q.pop();
			for(int i = h[u];i;i = ne[i]){
				int to =node[i];
				d[to]--;
				
				if(!d[to]){
					q.push(to);//cout << (long long) to << endl;
				} 
			}
		}
		if(!q.empty()) f = 0;
		while(t[tot] >= i && tot) tot--;
		if(f && tot) i = t[tot];
		else{
			i--; 
		} 
	}
	return !cnt;
}

void dfs(int pos, int fa){
	//e[pos].push_back(fa);
	deg[fa]++;
	for(int to : E[pos]){
		if(to == fa) continue;
		//e[to].push_back(pos);
		add(to,pos);
		dfs(to,pos);
	}
}
signed main(){
//	freopen("tree.in","r",stdin);
//	freopen("tree.out","w",stdout);

	scanf("%lld",&n);
	//cout << n << endl;
	for(int i = 1;i <= n; i++){
		long long aa,bb,cc;
		scanf("%lld%lld%lld",&aa,&bb,&cc);
		A[i] = aa,B[i] = bb, C[i] = cc;
	}
	for(int i = 1;i < n; i++){
		long long u,v;
		scanf("%lld%lld",&u,&v);
		E[u].push_back(v);
		E[v].push_back(u);
	}
//	dfs(1,0);

	//long long id = check(33577724);
	//cout << id << endl;
	//cout << id << " " << A[id] << " " << B[id] << " " << C[id] << endl;
	//return 0;

	long long ans = 0;
	int l = 1, r = 1e9;
	while(l <= r){
		int mid = (l+r) >> 1;
		if(check(mid)) r = mid-1,ans = mid;
		else l = mid+1;
	}
	printf("%lld",ans);
	//cout << ans << endl;
	return 0;
}
