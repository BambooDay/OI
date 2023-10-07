#include <bits/stdc++.h>
const int N = 1e5+10;

using namespace std;
int n, m;
struct Node{
	int siz,val,key,l,r;
	bool tag;
}fhq[N];
int cnt;
int root;
mt19937 rnd(time(0));
int new_Node(int val){
	fhq[++cnt].val = val;
	fhq[cnt].siz = 1;
	fhq[cnt].key = rnd();
	return cnt;
}
void push_up(int pos){
	fhq[pos].siz = fhq[fhq[pos].l].siz + fhq[fhq[pos].r].siz + 1;
}
void push_down(int pos){
	if(fhq[pos].tag){
		swap(fhq[pos].l, fhq[pos].r);
		fhq[pos].tag = 0;
		fhq[fhq[pos].l].tag ^= 1;
		fhq[fhq[pos].r].tag ^= 1;
	}
}
void split(int pos, int siz, int &x, int &y){
	if(!pos){
		x = y = 0;
		return;
	}
	push_down(pos);
	if(fhq[fhq[pos].l].siz < siz){
		x = pos;
		split(fhq[pos].r,siz - fhq[fhq[pos].l].siz-1,fhq[pos].r,y);
	}else{
		y = pos;
		split(fhq[pos].l,siz,x,fhq[pos].l);
	}
	push_up(pos);
}
int merge(int x, int y){
	if(!x || !y) return x+y;
	if(fhq[x].key < fhq[y].key){
		push_down(x);
		fhq[x].r = merge(fhq[x].r,y);
		push_up(x);
		return x;
	}else{
		push_down(y);
		fhq[y].l = merge(x,fhq[y].l);
		push_up(y);
		return y;
	}
}
void reverse(int l, int r){
	int x,y,z;
	split(root,l-1,x,y);
	split(y,r-l+1,y,z);
	fhq[y].tag^=1;
	root = merge(merge(x,y),z);
}
void print(int pos){
	if(!pos) return;
	push_down(pos);
	print(fhq[pos].l);
	cout << fhq[pos].val << " ";
	print(fhq[pos].r); 
}
int main(){
	cin >> n >> m;
	for(int i = 1;i <= n; i++){
		root = merge(root,new_Node(i));
	}
	while(m--){
		int l,r;
		cin >> l >> r;
		reverse(l,r);
	}
	print(root);
	return 0;
} 
