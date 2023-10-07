#include <bits/stdc++.h>
#define ll long long
const int N = 5e5+10;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;

using namespace std;
ll t, n;
struct L{
	int left;
	int c;
};
map<int,vector<L> > node;
ll dp[N];
int main(){
	scanf("%lld %lld",&n,&t);
	while(n--){
		int m;
		scanf("%d",&m);
		//cin >> m;
		while(m--){
			int r;
			L l;
			scanf("%d %d %d",&l.left , &r ,&l.c);
		
			node[r].push_back(l);
		}
	}
	for(int i = 1;i <= t; i++){
		dp[i] = dp[i-1];
		if(!node.count(i)) continue;
		for(auto j : node[i]){
			//cout << j << endl;
			dp[i] = max(dp[i],dp[j.left]+j.c);
		}
	}
	printf("%lld",dp[t]);
	//cout << dp[t];
	return 0;
}

