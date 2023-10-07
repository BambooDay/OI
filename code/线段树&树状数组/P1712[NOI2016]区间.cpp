#include <bits/stdc++.h>
#define ls(fa) fa<<1
#define rs(fa) fa << 1 | 1
const int N = 5e5+10;
using namespace std;
struct node{
    int l, r, v;
}a[N];
struct Node{
    int v,id;
    bool flag;
}c[N<<1];
int n, m, cnt, tot;
bool cmp(node x, node y){
    return x.v == y.v ? x.l < y.l : x.v < y.v;
}
bool Cmp(Node x, Node y){
    return x.v < y.v;
}
int v[N<<4],lz[N<<4];
void push_down(int pos){
    if(lz[pos]){
        lz[ls(pos)] += lz[pos];
        lz[rs(pos)] += lz[pos];
        v[ls(pos)] += lz[pos];
        v[rs(pos)] += lz[pos];
        lz[pos] = 0;
    }
}
void up_date(int pos, int l, int r, int x, int y, int z){
    if(l >= x && r <= y){
        v[pos] += z;
        lz[pos] += z;
        push_down(pos);
        return;
    }
    int mid = (l+r) >> 1;
    push_down(pos);
    if(x <= mid){
        up_date(ls(pos),l,mid,x,y,z);
    }
    if(y > mid){
        up_date(rs(pos),mid+1,r,x,y,z);
    }
    v[pos] = max(v[ls(pos)],v[rs(pos)]);
}
int last = 1 ,ans = 1e9;
int main(){
    cin >> n >> m;
    for(int i = 1;i <= n; i++){
        cin >> a[i].l >> a[i].r;
        a[i].v = a[i].r - a[i].l;
    }
    sort(a+1,a+1+n,cmp);
    for(int i = 1; i <= n; i++){
        c[++cnt] = (Node){a[i].l,i,0};
        c[++cnt] = (Node){a[i].r,i,1};
    }
    sort(c+1,c+1+cnt,Cmp);
    c[0].v = -1;
    for(int i = 1; i <= cnt; i++){
        if(c[i].v != c[i-1].v) tot++;
        c[i].flag ? a[c[i].id].r = tot:a[c[i].id].l = tot;
    }
    for(int i = 1;i <= n; i++){
        up_date(1,1,tot,a[i].l, a[i].r,1);
        while(v[1] >= m){
            up_date(1,1,tot,a[last].l,a[last].r,-1);
            ans = min(ans,a[i].v - a[last].v),last++;
        }
    }
    if(ans == 1e9) cout << -1;
    else cout << ans;
    return 0;
}