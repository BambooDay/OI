#include <bits/stdc++.h>

using namespace std;
vector<int> e[2000];
int n, m;
int fa[2000];
int find(int x){
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}

int main(){
	cin >> n >> m;
	int cnt = n;
	for(int i = 1;i <= n; i++) fa[i] = i;
	while(m--){
		char opt;
		int p, q;
		cin >> opt >> p >> q;
		if(opt == 'F'){
			int fq = find(q),fp = find(p);
			if(fq != fp){
				fa[fq] = fp;
				cnt--;
			}
		}else{
			int fp = find(p);
			e[p].push_back(q);
			e[q].push_back(p);
			for(int to = e[q][0];;){
				int fto = find(to);
				if(fto != fp){
					fa[fp] = fto;
					cnt--;
				}
				break;
			}
			int fq = find(q);
			for(int to = e[p][0];;){
				int fto = find(to);
				if(fto != fq){
					fa[fq] = fto;
					cnt--;
				}
				break;
			}			
		}
	}
	cout << cnt;
	return 0;
}
