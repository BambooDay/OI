#include <atomic>
#include <bits/stdc++.h>
const int N = 2e6+10;
using namespace std;
int n, m;
vector<int> e[N];
int dfn[N],belong[N],low[N];
stack<int> st;
int cnt,scc;
void tarjan(int pos){
    dfn[pos] = low[pos] = ++cnt;
    st.push(pos);
    for(int to : e[pos]){
        if(!dfn[to]){
            tarjan(to);
            low[pos] = min(low[pos],low[to]);
        }else{
            if(!belong[to]) low[pos] = min(low[pos],dfn[to]);
        }
    }
    if(dfn[pos] == low[pos]){
        scc++;
        while(st.top() != pos){
            int t = st.top();
            belong[t] = scc;
            st.pop();
        }
        belong[pos] = scc;
        st.pop();
    }
}
void solve(){
    memset(dfn,0,sizeof dfn);
    memset(low,0,sizeof low);
    memset(belong,0,sizeof belong);
    for(int i = 0; i <= n*2; i++) e[i].clear();
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        char a,b;
        int x, y;
        cin >> a >> x >> b >> y;
        a = (a == 'h'),b = (b == 'h');
        if(a && !b){
            e[x+n].push_back(y+n);
            e[y].push_back(x);
        }
        if(!a && b){
            e[y+n].push_back(x+n);
            e[x].push_back(y);
        }
        if(a && b){
            e[x+n].push_back(y);
            e[y+n].push_back(x);
        }
        if(!a&&!b){
            e[x].push_back(y+n);
            e[y].push_back(x+n);
        }
    }
    for(int i = 1;i <= n*2; i++){
        if(!dfn[i]) tarjan(i);
    }
    for(int i = 1; i <= n; i++){
        if(belong[i] == belong[i+n]){
            cout << "BAD" << endl;
            return ;
        }
    }
    cout << "GOOD" << endl;
}
int main(){
    int k;
    cin >> k;
    while(k--) solve();
    return 0;
}