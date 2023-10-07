#include <algorithm>
#include <bits/stdc++.h>
#include <queue>

using namespace std;
int n, m;
vector<int> e[100005],ne[200005];
stack<int> st;
int belong[100005];
int scc = 0;
int dfn[100005],low[100005],cnt = 0;
int sum[100005];
//vector<vector<int> > ans;
void tarjan(int pos){
    dfn[pos] = low[pos] = ++cnt;
    st.push(pos);
    for(int to : e[pos]){
        if(!dfn[to]){
            tarjan(to);
            low[pos] = min(low[pos],low[to]);
        }else{
            if(!belong[to]){
                low[pos] = min(low[pos],dfn[to]);
            }
        }
    }
    if(low[pos] == dfn[pos]){
        //vector<int> x;
        scc++;
        while(st.top() != pos){
            int t = st.top();
            st.pop();
            belong[t] = scc;
            sum[scc]++;
           // x.push_back(t);
        }
        //x.push_back(pos);
        //ans.push_back(x);
        sum[scc]++;
        belong[pos] = scc;
        st.pop();
    }
}
int dis[200005];
bool in[200005];
// void dij(int st){
//     for(int i = 0;i <= scc*2;i++) dis[i] = -1e9;
//     dis[st] = 0;
//     priority_queue<pair<int,int> > q;
//     q.push(make_pair(dis[st],st));
//     while(!q.empty()){
//         int u = q.top().second;
        
//         q.pop();
//         if(v[u]) continue;
//         cout << u << endl;
//         v[u] = 1;
//         for(int to : ne[u]){
//             if(dis[to] < dis[u]+sum[(to-1+scc)%scc+1]){
//                 dis[to] = dis[u]+sum[(to-1+scc)%scc+1];
//                 q.push(make_pair(dis[to],to));
//             }
//         }
//     }
// }
void spfa(int st){
    queue<int> q;
    for(int i = 0; i <= scc*2; i++) dis[i] = -1e9;
    dis[st] = 0;
    in[st] = 1;
    q.push(st);
    while(!q.empty()){
        int t = q.front();
        q.pop();
        in[t] = 0;
        for(int to : ne[t]){
            if(dis[to] < dis[t] + sum[(to-1+scc)%scc+1]){
                dis[to] = dis[t] + sum[(to-1+scc)%scc+1];
                if(!in[to]){
                    in[to] = 1;
                    q.push(to);
                }
            }
        }
    }
}
int main(){
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
    }
    for(int i = 1; i <= n; i++){
        if(!dfn[i]) tarjan(i);
    }
    // for(auto i : ans){
    //     for(auto j : i){
    //         cout << j << ' ';
    //     }
    //     cout << endl;
    // }
    // tarjan(1);
    //cout << sum[belong[2]] << endl;
    for(int i = 1; i <= n; i++){
        //cout << i << belong[i] << endl;
        for(int to : e[i]){
            if(belong[to] != belong[i]){
                ne[belong[i]].push_back(belong[to]);
                ne[belong[i]+scc].push_back(belong[to]+scc);
                //(x-1+scc)%scc+1
                ne[belong[to]].push_back(belong[i]+scc);
            }
        }
    }
    // for(int i = 1; i <= scc*2; i++){
    //     cout << i << ": ";
    //     for(int j : ne[i]){
    //         cout  << j << " ";
    //     }
    //     cout << endl;
    // }
    spfa(belong[1]);
    cout << max(dis[belong[1]+scc],sum[belong[1]]);
    return 0;
}
/*
7 10 
1 2 
3 1 
2 5 
2 4 
3 7 
3 5 
3 6 
6 5 
7 2
4 7
*/ 