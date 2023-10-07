#include <bits/stdc++.h>
const int N = 1e5+10;
#define int long long
using namespace std;
struct Node{
	int val,siz,l,r,key,sum;
}fhq[N];
int cnt,root;
mt19937 rnd(time(0));
int new_node(int val){
	fhq[++cnt].val = val;
	fhq[cnt].sum = val;
	fhq[cnt].siz = 1;
	fhq[cnt].key = rnd();
	fhq[cnt].l = fhq[cnt].r = 0;
	return cnt;
}
void push_up(int pos){
	fhq[pos].siz = fhq[fhq[pos].l].siz + fhq[fhq[pos].r].siz+1;
	fhq[pos].sum = fhq[fhq[pos].l].sum + fhq[fhq[pos].r].sum + fhq[pos].val;
}
void split(int pos, int val, int &x, int &y){
	if(!pos){
		x = y = 0;
		return;
	}
	if(fhq[pos].val <= val){
		x = pos;
		split(fhq[pos].r,val,fhq[pos].r,y);
	}else{
		y = pos;
		split(fhq[pos].l, val, x, fhq[pos].l);
	}
	push_up(pos);
}
int merge(int x, int y){
	if(!x || !y) return x+y;
	if(fhq[x].key > fhq[y].key){
		fhq[x].r = merge(fhq[x].r,y);
		push_up(x);
		return x;
	}else{
		fhq[y].l = merge(x, fhq[y].l);
		push_up(y);
		return y;
	}
}
int get_num(int rank){
	int now = root;
	while(now){
		if(fhq[fhq[now].l].siz+1 == rank) break;
		else if(fhq[fhq[now].l].siz >= rank) now = fhq[now].l;
		else{
			rank -= fhq[fhq[now].l].siz+1;
			now = fhq[now].r;
		}
	}
	return fhq[now].val;
}
void insert(int val){
	int x, y;
	split(root,val,x,y);
	root = merge(merge(x,new_node(val)),y);
}
void del(int val){
	int x,y,z;
	split(root,val,x,z);
	split(x,val-1,x,y);
	y = merge(fhq[y].l,fhq[y].r);
	root = merge(merge(x,y),z);
}
int query(int val){
	int x,y,z;
	split(root,val,x,z);
	split(x,val-1,x,y);
	int siz1 = fhq[x].siz,siz2 = fhq[z].siz;
	int ans1 = fhq[x].sum,ans2 = fhq[z].sum;
	root = merge(x,merge(y,z));
	int l = siz1*val - ans1,r = ans2 - siz2*val;
	return l+r;
}
int n,k,a[N];
int ans = 1e17, ans_mid,ans_l,ans_r;
signed main(){
	cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 0; i < k; i++) insert(a[i]);
	int l = 0,r = k-1;
	for(int i = k,mid; i <= n; i++){
		l++,r++;
		del(a[l-1]);
		insert(a[r]);
		if(k & 1){
			mid = get_num((k>>1)+1);
		}else{
			mid = get_num(k >> 1) + get_num((k>>1)+1);
			mid >>= 1;
		}
		int tmp = query(mid);
		if(tmp < ans){
			ans = tmp,ans_mid = mid,ans_l = l,ans_r = r;
		}
	}
	cout << ans << endl;
	for(int i =1;i < ans_l; i++) cout << a[i] << endl;
	for(int i = ans_l; i <= ans_r; i++) cout << ans_mid << endl;
	for(int i = ans_r + 1; i <= n; i++) cout << a[i] << endl;
	return 0;
}
