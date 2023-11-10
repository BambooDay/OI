#include <bits/stdc++.h>
const int N = 1e5+10;

using namespace std;
struct ques{
	int op,l,r,x,id;
}q[N];
int n,m,l,r,len;
int a[N],c[N],ans[N],blk[N];
bitset<N+5> now1,now2;
bool cmp(ques x, ques y){
	return blk[x.l] == blk[y.l] ? (blk[x.l]&1 ? x.r<y.r : x.r > y.r) : blk[x.l] < blk[y.l];
}
void add(int x){
	if(c[x]++ == 0){
		now1[x] = 1;
		now2[N-x] = 1;
	}
}
void del(int x){
	if(--c[x] == 0){
		now1[x] = 0;
		now2[N-x] = 0;
	}
}
int main(){
	cin >> n >> m;
	len = sqrt(n);
	for(int i = 1;i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) blk[i] = (i-1)/len+1;
	for(int i = 1;i <= m; i++){
		cin >> q[i].op >> q[i].l >> q[i].r >> q[i].x;
		q[i].id = i;
	}	
	sort(q+1,q+1+m,cmp);
	l = 1,r = 0;
	for(int i =1;i<= m; i++){
		while(q[i].l < l) add(a[--l]);
		while(q[i].l > l) del(a[l++]);
		while(q[i].r < r) del(a[r--]);
		while(q[i].r > r) add(a[++r]);
		if(q[i].op == 1){
			ans[q[i].id] = (now1&(now1<<q[i].x)).any();
		}
		if(q[i].op == 2){
			ans[q[i].id] = (now1&(now2>>(N-q[i].x))).any();
		}
		if(q[i].op == 3){
			for(int j = 1; j*j <= q[i].x; j++){
				if(q[i].x % j == 0){
					if(now1[j]&&now1[q[i].x/j]){
						ans[q[i].id] = 1;
						break;
					}
				}
			}
		}
	}
	for(int i = 1; i <= m; i++){
		ans[i] ? puts("hana"):puts("bi");
	}
	return 0;
}
