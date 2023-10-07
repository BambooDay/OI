#include <bits/stdc++.h>
using namespace std;
const int MAXN=305;
const int MAXM=1000005; 
struct edge{
	int u,v,w;
}G[MAXM];
int fa[MAXN];
int get(int x){
	return fa[x]==x ? x : fa[x] = get(fa[x]);
}
bool cmp(edge x,edge y){
	return x.w<y.w;
}
int kruskal(int n,int m){
    int sum=0;
    sort(G+1,G+1+m,cmp);
    for(int i=1;i<=m;i++){
        int fu=get(G[i].u);
        int fv=get(G[i].v);
        if(fu!=fv){
            fa[fv]=fu;
            sum+=G[i].w;
        }
    }
    return sum;
}
int main(){ 
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) fa[i]=i;
	int m=0;
	for(int i=1;i<=n;i++){
        int a;
		scanf("%d",&a);
		m++;
		G[m].u=0;
		G[m].v=i;
		G[m].w=a;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
            int a;
			scanf("%d",&a);
			m++;
			G[m].u=i;
			G[m].v=j;
			G[m].w=a;
		}
	}
	printf("%d",kruskal(n,m));
    return 0;
} 

