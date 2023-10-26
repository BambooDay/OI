#include <iostream>
#include <algorithm>
#define ls(fa) fa << 1
#define rs(fa) fa << 1 | 1
#define int long long
const int N = 2e4+10;
using namespace std;
int n,X[N << 1];
int x1,y1,x2,y2,pre = 0;

struct SL{
	int l,r,h,mark;
	bool operator < (const SL &a) const{
		if(h == a.h) return mark > a.mark;
		return h < a.h;
	}
}line[N];
struct ST{
	int l,r, t, sum, len, c;
	bool lc,rc;
}tree[N<<2];
void build(int pos, int l, int r){
	tree[pos].lc = tree[pos].rc = 0;
	tree[pos].l = l,tree[pos].r = r;
	tree[pos].sum = tree[pos].len = 0;
	tree[pos].c = 0;
	if(l == r){
		return;
	}
	int mid = (l+r) >> 1;
	build(ls(pos),l,mid);
	build(rs(pos),mid+1,r);
}
void push_up(int pos){
	int l = tree[pos].l,r = tree[pos].r;
	if(tree[pos].sum){
		tree[pos].len = X[r+1] - X[l];
		tree[pos].lc = tree[pos].rc = 1;
		tree[pos].c = 1;
	}else{
		tree[pos].len = tree[ls(pos)].len + tree[rs(pos)].len;
		tree[pos].lc = tree[ls(pos)].lc,tree[pos].rc = tree[rs(pos)].rc;
		tree[pos].c = tree[ls(pos)].c + tree[rs(pos)].c;
		if(tree[ls(pos)].rc && tree[rs(pos)].lc) tree[pos].c -= 1;
	}
}
void update(int pos, int x, int y, int c){
	int l = tree[pos].l,r =  tree[pos].r;
	if(X[l] >= y || X[r+1] <= x) return;//µÈÓÚºÅ 
	if(x <= X[l] && X[r+1] <= y){
		tree[pos].sum += c;
		push_up(pos);
		return;
	}
	update(ls(pos),x,y,c);
	update(rs(pos),x,y,c);
	push_up(pos);
}
SL make_line(int l, int r, int h, int mark) {
	SL res;
	res.l = l, res.r = r,
	res.h = h, res.mark = mark;
	return res;
}
signed main(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> x1 >> y1 >> x2 >> y2;
		line[i*2-1] = make_line(x1,x2,y1,1);
		line[i*2] = make_line(x1,x2,y2,-1);
		X[i*2-1] = x1,X[i*2] = x2;
	}
	n <<= 1;
	sort(line+1,line+1+n);
	sort(X+1,X+1+n);
	int tot = unique(X+1,X+1+n)-X-1;
	build(1,1,tot-1);
	int res = 0;
	for(int i = 1;i < n; i++){
		update(1,line[i].l,line[i].r,line[i].mark);
		res += abs(pre -tree[1].len);
		pre = tree[1].len;
		res += 2*tree[1].c*(line[i+1].h - line[i].h);
	}
	res += line[n].r - line[n].l;
	cout << res;
	return 0;
}
