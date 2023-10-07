#include <bits/stdc++.h>
#define int long long
const int N = 300;

using namespace std;
int n,m,T,k,c[N];
int id[N][10],tot;

struct Node{
	int t,x,y;
}t[N];
bool cmp(Node a, Node b){
	return a.t < b.t;
}
struct Matrix{
	int s[N][N];
	Matrix(){
		memset(s,0,sizeof(s));
	}
	int *operator [](int i){
		return s[i];
	}
}Q[35];
int A[N];
Matrix operator *(Matrix a, Matrix b){
	Matrix c;
	for(int i = 1; i <= tot; i++){
		for(int k = 1; k <= tot; k++){
			if(a[i][k] < 0) continue;
			for(int j = 1; j <= tot; j++){
				c[i][j] = max(c[i][j], a[i][k] + b[k][j]);
			}
		}
	}
	return c;
} 
void Mul(Matrix Q){
	int B[N];
	for(int i = 1; i <= tot; i++){
		B[i] = -4e18;
	}
	for(int k = 1; k <= tot; k++){
		if(A[k] < 0) continue;
		for(int j = 1; j <= tot; j++){
			B[j] = max(B[j],A[k] + Q[k][j]);
		}
	}
	for(int i =1; i <= tot; i++) A[i] = B[i];
}
signed main(){
	cin >> n;
	tot = n;
	cin >> m >> T >> k;
	for(int i = 1;i <= n; i++) cin >> c[i];
	for(int i = 1; i <= m; i++){
		int u,v,w;
		cin >> u >> v >> w;
		for(int j = 1; j < w; j++){
			if(!id[u][j]) id[u][j] = ++tot;
		}
		for(int j = 1;j < w; j++){
			Q[0][id[u][j-1]][id[u][j]] = 0;
		}
		Q[0][id[u][w-1]][v] = c[v];
	}
	for(int i = 1; i <= k; i++){
		cin >> t[i].t >> t[i].x >> t[i].y;
	}
	sort(t+1,t+1+k,cmp);
	t[0] = {0,0,0};
	t[k+1] = {T,0,0};
	for(int i = 1; i <= 30; i++){
		Q[i] = Q[i-1]*Q[i-1];
	}
	for(int i = 2; i <= tot; i++){
		A[i] = -4e18;
	}
	A[1] = c[1];
	for(int i = 1; i <= k+1; i++){
		int dt = t[i].t - t[i-1].t;
		for(int j = 30; j >= 0; j--){
			if(dt&(1<<j)) Mul(Q[j]);
		}
		A[t[i].x] += t[i].y;
	}
	if(A[1] < 0){
		cout << -1 << endl;
	}else{
		cout << A[1] << endl;
	}
	return 0;
}
