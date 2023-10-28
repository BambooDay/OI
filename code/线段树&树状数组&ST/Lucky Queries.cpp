#include <bits/stdc++.h>
#define ls(fa) fa << 1
#define rs(fa) fa << 1 | 1
#define mid ((l+r)>> 1)
const int N = 1e6+10;

using namespace std;
int n,m;
char s[N];
struct Node{
	int _4,_7,up,down;
	bool tag;
	Node(){}
	Node(int a,int b, int c, int d, bool e):_4(a),_7(b),up(c),down(d),tag(e){}
}node[N<<2];
void push_up(int pos){
	node[pos]._4 = node[ls(pos)]._4 + node[rs(pos)]._4;
	node[pos]._7 = node[ls(pos)]._7 + node[rs(pos)]._7;
	node[pos].up = max(node[ls(pos)].up + node[rs(pos)]._7, node[ls(pos)]._4 + node[rs(pos)].up);
	node[pos].down = max(node[ls(pos)].down + node[rs(pos)]._4, node[ls(pos)]._7 + node[rs(pos)].down);
}
void upd(int pos){
	swap(node[pos]._4,node[pos]._7);
	swap(node[pos].up,node[pos].down);
	node[pos].tag ^= 1;
}
void push_down(int pos){
	if(node[pos].tag){
		upd(ls(pos));
		upd(rs(pos));
		node[pos].tag ^= 1;
	}
}
void build(int pos, int l, int r){
	if(l == r){
		node[pos] = (s[l] == '4' ? Node(1,0,1,1,false): Node(0,1,1,1,false));
		return;
	}
	build(ls(pos),l,mid);
	build(rs(pos),mid+1,r);
	push_up(pos);
}
void update(int pos, int l, int r, int x, int y){
	if(x <= l && r <= y){
		upd(pos);
		return;
	}
	push_down(pos);
	if(x <= mid){
		update(ls(pos),l,mid,x,y);
	}
	if(mid < y){
		update(rs(pos),mid+1,r,x,y);
	}
	push_up(pos);
}
int main(){
	cin >> n >> m;
	scanf("%s",1+s);
	build(1,1,n);
	for(int i = 1; i <= m; i++){
		char op[10];
		scanf("%s",op);
//		cin >> op;
		if(op[0] == 'c'){
			cout << node[1].up << endl;
		}else{
			int l,r;
			cin >> l >> r;
			update(1,1,n,l,r);
		}
	}
	return 0;
} 
