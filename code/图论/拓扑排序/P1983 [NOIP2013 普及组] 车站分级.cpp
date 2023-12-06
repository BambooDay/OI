#include<iostream>
#include<cstdio>
#include<cstring>
#define N 1005
using namespace std;
int n,m,ans,st[N],s,g[N][N],de[N],tt[N],top;
bool vis[N];	
int main() {
	cin >> n >> m;
	for(int i = 1; i <= m; i++) {
		bool is[N] = {0};
		cin >> s;
		for(int j = 1; j <= s; j++){
			cin >> st[j]; is[st[j]] = 1;
		}
		for(int j = st[1]; j <= st[s]; j++){
			if(!is[j]){
				for(int k = 1; k <= s; k++){
					if(!g[j][st[k]]) g[j][st[k]] = 1,de[st[k]]++;
				}
			}		
		}
	}
	top = 0;
	for(int i = 1; i <= n; i++)
		if(!de[i] && !vis[i]) {
			tt[++top] = i,vis[i] = 1;
		}
	for(int i = 1; i <= top; i++){ 
		for(int j = 1; j <= n; j++){
			if(g[tt[i]][j]) g[tt[i]][j] = 0,de[j]--;
		}
	} 
	while(top){
		top = 0;
		for(int i = 1; i <= n; i++)
			if(!de[i] && !vis[i]) {
				tt[++top] = i,vis[i] = 1;
			}
		for(int i = 1; i <= top; i++){ 
			for(int j = 1; j <= n; j++){
				if(g[tt[i]][j]) g[tt[i]][j] = 0,de[j]--;
			}
		} 
		ans++;
	}

	cout << ans << endl;
	return 0;
}

