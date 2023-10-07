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
int main(){
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int x,a,y,b;
        cin >> x >> a >> y >> b;
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
            cout << "IMPOSSIBLE";
            return 0;
        }
    }
    cout << "POSSIBLE" << endl;
    for(int i = 1;i <= n; i++){
        cout << (belong[i] < belong[i+n]) << ' ';
    }
    return 0;
}