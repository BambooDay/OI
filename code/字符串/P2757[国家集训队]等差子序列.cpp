#include <bits/stdc++.h>

const int N = 5e5+10;
const int BASE = 13331;
const int mod = 1e9+7;
#define int long long
#define ls(fa) fa << 1
#define rs(fa) fa << 1 | 1
using namespace std;
int T,n;
int base[N];
int hash1[N<<2],hash2[N<<2];
int a[N];
void push_up(int pos,int l, int r){
    int mid = (l+r) >> 1;
    hash1[pos] = (hash1[rs(pos)] + hash1[ls(pos)] * base[r-mid]%mod)%mod;
    hash2[pos] = (hash2[ls(pos)] + hash2[rs(pos)]*base[mid-l+1]%mod)%mod;
}
void modify(int pos, int l, int r, int x){
    if(l == r){
        hash1[pos] = hash2[pos] =1;
        return;
    }
    int mid = (l+r) >>1;
    if(mid >= x){
        modify(ls(pos),l,mid,x);
    }else{
        modify(rs(pos),mid+1,r,x);
    }
    push_up(pos,l,r);
}
int now,res1,res2;
void ask1(int pos, int l, int r, int x, int y){
    if(l >= x && r <= y){
        res1 = (res1+hash1[pos]*base[now]%mod)%mod;
        now += (r-l+1);
        return;
    }
    int mid = (l+r) >> 1;
    if(mid+1 <= y){
        ask1(rs(pos),mid+1,r,x,y);
    }
    if(mid >= x){
        ask1(ls(pos),l,mid,x,y);
    }
}
void ask2(int pos, int l, int r, int x, int y){
    if(l >= x && r <= y){
        res2 = (res2 + hash2[pos]*base[now]%mod)%mod;
        now += (r-l+1);
        return;
    }
    int mid = (l+r) >> 1;
    if(mid >= x){
        ask2(ls(pos),l,mid,x,y);
    }
    if(mid+1 <= y){
        ask2(rs(pos),mid+1,r,x,y);
    }
    
}
signed main(){
    cin >> T;
    base[0] = 1;
    for(int i =1;i <= 5e5; i++){
        base[i] = base[i-1]*BASE%mod;
    }
    while(T--){
        memset(hash1,0,sizeof hash1);
        memset(hash2,0,sizeof hash2);
        cin >> n;
        bool flag = 0;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        for(int i = 1;i <= n; i++){
            modify(1,1,n,a[i]);
            int len = min(a[i],n-a[i]+1);
            res1 = res2 = now = 0;
            ask1(1,1,n,a[i]-len+1,a[i]+len-1);
            now = 0;
            ask2(1,1,n,a[i]-len+1,a[i]+len-1);
            if(res1 != res2){
                flag = 1;
                break;
            }
        }
        if(flag) cout << "Y" << endl;
        else cout << "N" << endl;
    }
    return 0;
}