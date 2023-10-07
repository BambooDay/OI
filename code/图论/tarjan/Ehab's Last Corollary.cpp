#include <bits/stdc++.h>

using namespace std;

const int N = 100010, M = N << 2;
int n, m, K, mx, S, T;
vector<int> e[N];
int dep[N], cnt[N];
bool st[N], col[N];
vector<int> v, res1, res2;


void dfs(int u,int fa){
    v.push_back(u);
    dep[u] = dep[fa]+1;
    for(auto j : e[u]){
        if(j == fa) continue;
        if(!dep[j]) dfs(j,u);
        if(dep[j] < dep[u] - 1){
            int t = dep[u] - dep[j] + 1;
            if(t <= K){
                printf("2\n%d\n", t);
                for(int k = dep[j]-1; k <= dep[u]-1; k++){
					printf("%d ", v[k]);
                }
                exit(0);
            }
            else if(t <= mx){
                mx = t;
                S = u, T = j;
            }
        }
    }
    v.pop_back();
}

void dfs1(int u){
    v.push_back(u);
    dep[u] = v.size();
    if(u == T){
        puts("1");
        for(int k = 0; k < K; k += 2) printf("%d ", v[k]);
        exit(0);
    }
    for(auto j : e[u]){
        if(u == S && j == T) continue;
        if(!dep[j]) dfs1(j);
    }
    v.pop_back();
}

void dfs2(int u){
    st[u] = true;
    if(col[u]) res1.push_back(u);
    else res2.push_back(u);
    for(auto j : e[u]){
        if(!st[j]){
            col[j] = !col[u];
            dfs2(j);
        }
    }
}

int main(){
    scanf("%d%d%d", &n, &m, &K);
    while(m --){
        int a, b;
        scanf("%d%d", &a, &b);
        e[a].push_back(b);
        e[b].push_back(a);
    }
    mx = n;
    dfs(1,0);
    if(S){
        memset(dep, 0,sizeof dep);
        dfs1(S);
    }
    puts("1");
    dfs2(1);
    int t = (K + 1) / 2;
    if(res1.size() >= t){
        for(int i = 0; i < t; i++) printf("%d ", res1[i]);
    }
    else{
        for(int i = 0;i < t; i++) printf("%d ", res2[i]);
    }
    return 0;
}
