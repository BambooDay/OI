#include <bits/stdc++.h>
const int N = 1e6+10;
using namespace std;
int n,m;
struct treap {
	int val,key,siz,l,r,ma = -1e9,mi = 1e9;
} fhq[N];
int cnt,root;

int new_treap(int val) {
	fhq[++cnt].val = val;
	fhq[cnt].mi = val;
	fhq[cnt].ma = val;
	fhq[cnt].siz = 1;
	fhq[cnt].key = rand();
	return cnt;
}
void push_up(int pos) {
	fhq[pos].siz = fhq[fhq[pos].l].siz + fhq[fhq[pos].r].siz + 1;
	fhq[pos].ma = max(fhq[pos].val,max(fhq[fhq[pos].l].ma,fhq[fhq[pos].r].ma));
	fhq[pos].mi = min(fhq[pos].val,min(fhq[fhq[pos].l].mi,fhq[fhq[pos].r].mi));
}

void split(int pos, int siz , int &x, int &y) {
	if(!pos) {
		x = y = 0;
		return;
	}
	if(fhq[fhq[pos].l].siz < siz) {
		x = pos;
		split(fhq[pos].r,siz - fhq[fhq[pos].l].siz-1,fhq[pos].r,y);
	} else {
		y = pos;
		split(fhq[pos].l,siz,x,fhq[pos].l);
	}
	push_up(pos);
}
int merge(int x, int y) {
	if(!x || !y) return x+y;
	if(fhq[x].key < fhq[y].key) {
		fhq[x].r = merge(fhq[x].r,y);
		push_up(x);
		return x;
	} else {
		fhq[y].l = merge(x,fhq[y].l);
		push_up(y);
		return y;
	}
}
void del(int val){
	int x,y,z;
	split(root,val-1,x,y);
	split(y,1,y,z);
	root = merge(x,z);
}
void ask(int l, int r){
	int x,y,z;
	split(root,r,x,z);
	split(x,l-1,x,y);
	cout << fhq[y].mi << " " << fhq[y].ma << endl;
	root = merge(merge(x,y),z);
}
int main() {
	srand(time(0));
	
	cin >> n>> m;
	for(int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		root = merge(root,new_treap(x));
	}
	while(m--) {
		int op;
		cin >> op;
		if(op == 1){
			int k;
			cin >> k;
			del(k);
		}else{
			int x,y;
			cin >> x >> y;
			ask(x,y);
		}		
	}
	return 0;
}
