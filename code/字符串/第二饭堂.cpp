#include <bits/stdc++.h>
#define int unsigned long long
const int N = 5e6+10;
const int BASE = 13331;

using namespace std;
string s;
int ha[N],ah[N],base[N];
int n;
int f[N];
bool is[N];
signed main(){
    cin >> s;
    n = s.size();
    s = " "+ s;
    base[0] = 1;
    for(int i =1;i <= n; i++){
        ha[i] = ha[i-1]*BASE+s[i];
        ah[i] = ah[i-1]*BASE+s[n-i+1];
        base[i] = base[i-1]*BASE;
    }
    // for(int i = 1; i <= n; i++){
    //     cout << ha[i] << ' ';
    // }
    // cout << endl;
    // for(int i = n; i > 0; i--){
    //     cout << ah[i] << " ";
    // }
    // cout << endl;
    for(int i = 2; i <= n; i++){
        int x = ha[i],y = (ah[n] - ah[n-i]*base[i]) ;
        if(x == y){
            is[i] = 1; 
            // cout << i << " ";
        }
    }
    // cout << endl; 
    f[1] = 1;
    int ans = 1;
    for(int i = 2; i <= n; i++){
        if(is[i]){
            f[i] = f[i >> 1]+1;
            ans += f[i];
        }
    }
    cout << ans;
    return 0;
}