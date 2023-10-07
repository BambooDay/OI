#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 2e5+10;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;

using namespace std;
int n;
int tree1[65*N][2], tree2[65*N][2],idx1,idx2,siz1[65*N],siz2[65*N];
void add1(ull x){
	int p = 0;
	for(int i = 63; i >= 0; i--){
		//cout << x << " " << p << " " << ((x>>i) & 1 )<< endl;
		if((x>>i) & 1){
			if(!tree1[p][1]){
				tree1[p][1] = ++idx1;
			}
			p = tree1[p][1];
		}else{
			if(!tree1[p][0]){
				//if(p == 0) cout << 1 << endl;
				tree1[p][0] = ++idx1;
			}
			p = tree1[p][0];
		}
		siz1[p]++;
	}
}
void add2(ull x){
	int p = 0;
	for(int i = 63; i >= 0; i--){
		if((x>>i) & 1){
			if(!tree2[p][1]){
				tree2[p][1] = ++idx2;
			}
			p = tree2[p][1];
		}else{
			if(!tree2[p][0]){
				tree2[p][0] = ++idx2;
			}
			p = tree2[p][0];
		}
		//cout << x << " " << p << endl;
		siz2[p]++;
	}
}
vector<ull> ans;
int dfs(int frist, int second, ull x, int dep){
//	cout << dep << " " << x << " " << frist << " " << second <<  endl;
	int ret = 0;
	if(dep == 64){
		while(siz1[frist] && siz2[second]){
			ans.push_back(x);
			siz1[frist]--,siz2[second]--,ret++;
		}
		return ret;
	}
	if(siz1[tree1[frist][0]] && siz2[tree2[second][0]]){
		ret += dfs(tree1[frist][0],tree2[second][0],x << 1, dep+1);
	}
	if(siz1[tree1[frist][1]] && siz2[tree2[second][1]]){
		ret += dfs(tree1[frist][1],tree2[second][1],x << 1 , dep+1);
	}
	if(siz1[tree1[frist][1]] && siz2[tree2[second][0]]){
		ret += dfs(tree1[frist][1],tree2[second][0],(x << 1)+1 , dep+1);
	}
	if(siz1[tree1[frist][0]] && siz2[tree2[second][1]]){
		ret += dfs(tree1[frist][0],tree2[second][1],(x << 1)+1 , dep+1);
	}
	siz1[frist] -= ret,siz2[second] -= ret;
	return ret;
}
int main(){
	//add1(3);
	//add1(2);
	//cout << tree1[0][0];
	cin >> n;
	for(int i = 1; i <= n; i++){
		ull a;
		cin >> a;
		add1(a);
	}
	for(int i = 1; i <= n; i++){
		ull a;
		cin >> a;
		add2(a);
	}
	dfs(0,0,0,0);
	sort(ans.begin(),ans.end());
	for(ull i : ans){
		cout << i << " ";
	}
	return 0;
}
  
