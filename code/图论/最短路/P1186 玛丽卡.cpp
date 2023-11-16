#include<bits/stdc++.h>

const int N=1e3+3;
#define ls(fa) fa<<1
#define rs(fa) fa<<1|1
using namespace std;


int node[N<<2];
void build(int pos,int l,int r){
    node[pos] = 1e9; 
	if(l == r) return; 
	int mid = (l+r)>>1;
    build(ls(pos),l,mid);
	build(rs(pos),mid+1,r);
}
void update(int pos,int l,int r,int x,int y,int w){
    if(x<=l&&r<=y){
    	node[pos] = min(node[pos],w);
	}else{
        int mid = (l+r)>>1;
        if(x <= mid) update(ls(pos),l,mid,x,y,w);
        if(y > mid) update(rs(pos),mid+1,r,x,y,w);
    }
}
int query(int pos,int l,int r,int p){
    if(l == r) return node[pos]; 
	int mid = (l+r)>>1;
    if(p <= mid) return min(node[pos],query(ls(pos),l,mid,p));
    else return min(node[pos],query(rs(pos),mid+1,r,p));
}

int n,m,o,ans; 
bool U[N][N];
int A[N],B[N],W[N][N]; bool V[N];
int P[N],Q[N],I[N];
void dij(int s,int t,int D[],int E[]){
    for(int i = 1;i<= n; i++){
    	D[i] = 1e9;
		V[i] = 0; 
	}
	D[s]=0; 
	for(int i = 1;i <= n; i++){
        int f = 0;
        for(int j = 1;j <= n; j++){
		 	if((!f || D[j] < D[f]) && !V[j]) f=j;
		}
		V[f] = 1;
        for(int j = 1;j <= n;j++){
        	if(!V[j ]&& D[f]+W[f][j] < D[j]){
				D[j] = D[f]+W[f][j];
				E[j]=f;
			}
		} 
    }
    if(!o){
        for(int p = t; p ;p = E[p]) I[p] =--o;
		o = -o+1;
        for(int p = t,q = t; p; q = p,p = E[p]){
			I[p] += o;U[p][q] = 1;
		}
    }
    for(int i = 1;i <= n; i++){
    	if(I[i]) E[i]=i;
	}
}
int get(int x,int *F){
	return x == F[x] ? x: F[x] = get(F[x],F);
}

int main(){
    cin >> n >> m;
    for(int i = 1;i <= n; i++){
		for(int j = 1;j <= n; j++){
			W[i][j] = 1e9;
		}
	}
    for(int i =1;i <= m; i++){
        int u,v,w;
        cin >> u >> v >> w;
        if(w < W[u][v]) W[u][v] = W[v][u] = w;
    }
    dij(1,n,A,P);
	dij(n,1,B,Q);
	build(1,1,o);
    for(int i = 1; i <= n; i++){
    	for(int j = 1; j <= n; j++){
			if(!U[i][j] && !U[j][i]){
	            int w = A[i]+W[i][j]+B[j],s = I[get(i,P)],t = I[get(j,Q)];
	            if(s<t) update(1,1,o,s,t-1,w);
	        }
		}
	} 
    for(int i = 1 ;i <= o-2; i++){
    	ans = max(ans,query(1,1,o,i));
	} 
   	cout << ans << endl;
	return 0;
}

