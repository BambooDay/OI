#include <bits/stdc++.h>
const int N = 1e5+10;

using namespace std;
struct Node{
	int siz,val,key,l,r;
}fhq[N<<1];
int cnt,root;
mt19937 rnd(time(0));

int new_node(int val){
	fhq[++cnt].val = val;
	fhq[cnt].siz = 1;
	fhq[cnt].key = rnd();
	return cnt;
}
void push_up(int pos){
	fhq[pos].siz = fhq[fhq[pos].l].siz + fhq[fhq[pos].r].siz+1;
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
void get_rank(int val){
	int x,y;
	split(root,val-1,x,y);
	cout << fhq[x].siz+1 << endl;
	root = merge(x,y);
}
void get_num(int rank){
	int now = root;
	while(now){
		if(fhq[fhq[now].l].siz+1 == rank) break;
		else if(fhq[fhq[now].l].siz >= rank) now = fhq[now].l;
		else{
			rank -= fhq[fhq[now].l].siz+1;
			now = fhq[now].r;
		}
	}
	cout << fhq[now].val << endl;
}
void pre(int val){
	int x,y;
	split(root,val-1,x,y);
	int now = x;
	while(fhq[now].r) now = fhq[now].r;
	cout << fhq[now].val << endl;
	root = merge(x,y);
}
void nxt(int val){
	int x,y;
	split(root,val,x,y);
	int now = y;
	while(fhq[now].l){
		now = fhq[now].l;
	}
	cout << fhq[now].val << endl;
	root = merge(x,y);
}
int n;

int main(){
	cin >> n;
	while(n--){
		int op,x;
		cin >> op >> x;
		if(op == 1){
			insert(x);
		}
		if(op == 2){
			del(x);
		}
		if(op == 3){
			get_rank(x);
		}
		if(op == 4){
			get_num(x);
		}
		if(op == 5){
			pre(x);
		}
		if(op == 6){
			nxt(x);
		}
	}	
	return 0;
}
