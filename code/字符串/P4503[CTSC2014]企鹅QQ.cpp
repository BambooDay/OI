#include <bits/stdc++.h>
#define int unsigned long long
using namespace std;
inline unsigned long long randllu() { return static_cast<unsigned long long> (rand()); }
inline unsigned long long RAND() {
	return randllu() << 48 ^ randllu() << 32 ^ randllu() << 16 ^ randllu();
}
int l, n, m;
int bit[300],ch[300];
vector<int> v[300];
signed main(){
    srand(114514);
    cin >> n >> l >> m;
    for(int i = 0; i < 256; i++){
        bit[i] = RAND();
        ch[i] = RAND();
    }
    for(int i = 1;i <= n; i++){
        string s;
        cin >> s;
        int hs = 0;
        for(int i = 0; i < l; i++) hs ^= bit[i]*ch[s[i]];
        for(int i = 0; i < l; i++) v[i].push_back(hs ^ bit[i]*ch[s[i]]);
    }
    int ans = 0;
    for(int i = 0; i < l; i++){
        sort(v[i].begin(),v[i].end());
        for(auto l = v[i].begin();l != v[i].end();){
            int x = *l;
            int now = 0;
            while(l != v[i].end() && *l == x) l++,ans += now++;
        }
    }
    cout << ans << endl;
    return 0;
}