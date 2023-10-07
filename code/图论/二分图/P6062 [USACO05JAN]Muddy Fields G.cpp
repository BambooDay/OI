#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define mem(a,b) memset(a,b,sizeof a)
const int N = 2010;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;

using namespace std;

int n,m,r[N][N],c[N][N],rcnt = 1,ccnt = 1;
char mp[60][60];
bool g[1800][1800];
int match[N],v[N];

bool find(int x) { //±ê×¼ÐÙÑÀÀû
	for (int j = 1; j <= ccnt; j++){
		if (!v[j] && g[x][j]) {
			v[j] = true;
			int t = match[j];

			if (!t || find(t)) {
				match[j] = x;
				return true;
			}
		}
	}
	return false;
}
int main(){
//	freopen("P6062_3.in","r",stdin);
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> mp[i][j];
		}
	}
	for(int i = 1; i<= n; i++){
		for(int j =1; j <= m; j++){
			if(mp[i][j] == '*' && mp[i][j-1] == '.') rcnt++;
			if(mp[i][j] == '*') r[i][j] = rcnt;
		}
		rcnt++;
	}
	for(int j = 1; j <= m; j++){
		for(int i = 1; i <= n; i++){
			if(mp[i][j] == '*' && mp[i-1][j] == '.') ccnt++;
			if(mp[i][j] == '*') c[i][j] = ccnt;
		}
		ccnt++;
	}
	for (int i = 1; i <= n; i++){ 
		for (int j = 1; j <= m; j++){ 
			if (mp[i][j] == '*'){ 
//				cout << i << " " << j << " ";
//				cout<<"(" << r[i][j] <<','<< c[i][j] << ") " ;
				g[r[i][j]][c[i][j]] = true;
		    } 
		}
	} 
//	find(26);
	int tot = 0;
	for(int i =1; i <= rcnt; i++){
		memset(v,0,sizeof v);
		if(find(i)) {
			tot++;
		}
	}
	
	cout << tot;	

	return 0;
}
