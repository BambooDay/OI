#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n,m;
    cin >> n >> m;
    bitset<305> g[305];
    for(int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        g[u].set(v,1);
    }
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if((g[i]&g[j]) != 0 && (g[i]^g[j]) != 0){
                cout << "No" << endl;
                return;
            }
        }
    }
    cout << "Yes" << endl;
}
int main(){
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}