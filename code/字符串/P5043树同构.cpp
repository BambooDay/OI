#include <bits/stdc++.h>
#define int  unsigned long long

using namespace std;
vector<int> e[60];
int n;
int siz[60],cnt[60];
int cent[2];
void gc(int pos, int fa){
    siz[pos] = 1;
    cnt[pos] = 0;
    for(int to : e[pos]){
        if(to == fa) continue;
        gc(to,pos);
        siz[pos] += siz[to];
        cnt[pos] = max(cnt[pos],siz[to]);
    }
    cnt[pos] = max(cnt[pos],n-siz[pos]);
    if(!cent[0]) cent[0] = pos;
    else if(cnt[pos] < cnt[cent[0]]) cent[0] = pos,cent[1] = 0;
    else if(cnt[pos] == cnt[cent[0]]) cent[1] = pos;
}
map<pair<int,int>, int> tree;
int shift(int x){
    x ^= x << 13;
    x ^= x >> 7;
    x ^= x << 17;
    return x;
}
int gh(int pos, int fa){
    int hs = 1;
    for(int to : e[pos]){
        if(to == fa) continue;
        hs += shift(gh(to,pos));
    }
    return hs;
}
void solve(int id){
    cin >> n;
    for(int i = 0; i <= n; i++) {
        e[i].clear();
        siz[i] = 0;
        cnt[i] = 0;
        cent[1] = cent[0]= 0;
    }
    for(int i = 1; i <= n; i++){
        int fa;
        cin >> fa;
        if(fa){
            e[i].push_back(fa);
            e[fa].push_back(i);
        }
    }
    gc(1,0);
    pair<int,int> ha;
    ha.first = gh(cent[0],0);
    if(cent[1]){
        ha.second = gh(cent[1],0);
        if(ha.first > ha.second) swap(ha.first,ha.second);
    }else{
        ha.second = ha.first;
    }
    if(!tree.count(ha)){
        tree[ha] = id;
    }
    cout << tree[ha] << endl;
}
signed main(){
    int m;
    cin >> m;
    for(int i = 1; i <= m; i++){
        solve(i);
    }
    return 0;
}