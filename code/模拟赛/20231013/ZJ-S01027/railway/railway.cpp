#include <bits/stdc++.h>
const int N = 3005;

using namespace std;
set<int> e[N];
int n;
struct Node{
	int a[5];
};
bool find(int pos, int dep,Node &ans){
	bool f = 0;
	ans.a[dep] = pos;
	if(dep == 4) return 1;
	if(!e[pos].size()) return 0;
	for(auto to : e[pos]){
		f = 1;
		//cout << pos << " " << to << "xxx" <<endl;
		e[pos].erase(to);
		find(to,dep+1,ans);
		return 1;
	}
	return f;
}
vector<Node> ans;
int main(){
	freopen("railway.in","r",stdin);
	freopen("railway.out","w",stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = i+1; j <= n; j++){
			e[i].insert(j);
		}
	}

	//for(auto i : e[2]){
	//	cout << i << " yyy ";
	//	e[2].erase(i);
	//} 
	//cout << endl;
	for(int i = 1; i <= n; i++){
		while(e[i].size()){
			Node a;
			a.a[0] = a.a[1] = a.a[2] = a.a[3] = a.a[4] = 0;
			find(i,1,a);
			for(int i = 1; i < 4; i++) if(a.a[i+1] == 0) a.a[i+1] = a.a[i];
			ans.push_back(a);
		}
	}
	cout << ans.size() << endl;
	for(auto a : ans){
		printf("%d %d %d %d\n",a.a[1],a.a[2],a.a[3],a.a[4]);
		//cout << a.a[1] << " " << a.a[2] << " " << a.a[3] << " " << a.a[4] << endl;
	}
	return 0;
}