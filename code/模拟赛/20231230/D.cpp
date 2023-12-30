#include <bits/stdc++.h>
#define int long long
const int N = 2e5+10;

using namespace std;
int n,L,s;
int X[N];
int ans = 0;
struct sol{
	int num;//结尾向左跳的个数
	bitset<N> pos;
//	vector<int> node;//向左跳的点(靠右那个
	int sum;//最终多出来的花费 
}ma;
void print(int &x){
	int st = x;
	int ed = st;
	while(ma.pos[ed]) ed++;
	ed--;
	for(int i = ed; i >= st; i--) printf("%lld ",i);// cout << i << " ";
//	cout << st-1 << " ";
	printf("%lld ",st-1);
	x = ed;
}
bitset<N> _0;
priority_queue<pair<int,int>,vector<pair<int,int> > ,greater<pair<int,int> > > q;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
//	cin >> n >> L >> s;
	scanf("%lld%lld%lld",&n,&L,&s);
	for(int i = 1; i <= n; i++) scanf("%lld",&X[i]);//cin >> X[i];
	if((s != 1 && L == 0) || (s != n && n-L-1 == 0)){
		puts("-1");
		return 0;
	}
	ans = X[n] - X[1];	
	if(L < s){
//		for(int i = 2; i < L; i++) ans += X[i] - X[i-1];
		ans += X[s] - X[1];
//		cout << ans << endl;
		printf("%lld\n",ans);
		for(int i = L; i >= 1; i--) printf("%lld ",i);// cout << i << " "; 
		for(int i = L+1; i <= n; i++) if(i != s) printf("%lld ",i);//cout << i << " ";
		return 0;
	}
	for(int i = s; i >= 2; i--) ans += X[i] - X[i-1];
	for(int i = n; i >= s+2; i--) q.push({(X[i]-X[i-1])*2,i});
	ma.sum = 1e18;
	for(int i = 0; i <= L-(s-1); i++){
		sol now;
		now.num = i;
		now.sum = X[n]-X[n-i];
		int j = L-(s-1)-i;
		vector<pair<int,int> > v;
		while(j){
			pair<int,int> t = q.top();
			q.pop();
			if(t.second >= n-i) continue;
			v.push_back(t);
			now.sum += t.first;
			now.pos[t.second] = 1;
			j--;
		}
		for(auto t : v) q.push(t);
		if(now.sum < ma.sum){
			ma.sum = now.sum;
			ma.num = now.num;
			ma.pos = (ma.pos&_0);
			ma.pos = (ma.pos|now.pos);
		}
	}
//	cout << ans + ma.sum << endl; 
	printf("%lld\n",ans + ma.sum);
	for(int i = s-1; i >= 1; i--)printf("%lld ",i);// cout << i << " ";
	for(int i = s+1; i < n-ma.num; i++){
		if(ma.pos[i]){
			print(i); 
		}else if(!ma.pos[i+1])printf("%lld ",i);//cout << i << " ";
	}
	for(int i = n; i >= n-ma.num; i--)printf("%lld ",i);// cout << i << " ";
	return 0;
}
