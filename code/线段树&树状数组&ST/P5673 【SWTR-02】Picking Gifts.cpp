#include <bits/stdc++.h>

using namespace std;
const int N = 1e6+10;
const int M = 5e5+10;
struct question{
	int l, r;
	int id;
}que[M];
bool cmp(question a, question b){
	return a.r < b.r;
}
int tree[N];
int n, m, k;
void modify(int x, int y){
	for(int i = x; i <= n; i += (i & -i)){
		tree[i] += y;
	}
}
int query(int x){
	int res = 0;
	for(int i = x; i > 0; i -= (i & -i)){
		res += tree[i];
	}
	return res;
}
int p[N],v[N];
vector<int> pos[N];
//int cnt[N];
int ans[M];
int main(){
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++){
		cin >> p[i];
	}
	for(int i = 1; i <= n; i++){
		cin >> v[i];
		modify(i,v[i]);
//		cout << query(i) << endl;
	}
	for(int i = 1; i <= m; i++){
		cin >> que[i].l >> que[i].r;
		que[i].id = i;
	}
	sort(que+1,que+1+m,cmp);
	int j  = 1;
	for(int i = 1; i <= m; i++){
		int l =que[i].l, r = que[i].r;
		while(j <= r){
//			if(j > r) break;
//			cout << j << " " << r << endl;
			pos[p[j]].push_back(j);
			if(pos[p[j]].size() == k){
				modify(pos[p[j]][0],-v[pos[p[j]][0]]);
//				cout<< v[pos[p[j]][0]] << " ";
				pos[p[j]].erase(pos[p[j]].begin());
////				cout<< pos[p[j]][0] << endl;
//				cout << j << "xx" << endl;
			}
			j++;
		}
//			cout << "xx";
//		cout << query(r) << " " << endl;
		ans[que[i].id] = query(r) - query(l-1);
	}
	for(int i = 1; i <= m; i++){
		printf("%d\n",ans[i]);
//		cout << ans[i] << endl;
	}
	return 0;
}
