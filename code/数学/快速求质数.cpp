#include <bits/stdc++.h>
#include <random>
#define int long long
using namespace std;
bool v[2147483848];
vector<long long> pr;
void solve(long long n){
    for(int i = 2; i <= n; i++){
        if(!v[i]){
            pr.push_back(i);
        }
        for(int j :pr){
            if(i*j > n) break;
            v[i*j] = 1;
            if(i % j == 0) break;
        }
    }
}
signed main(){
    solve(2147483248);
    for(int i : pr){
        cout << i << " ";
    }
    return 0;
}