#include <bits/stdc++.h>
const int N = 1e5+10;
#define ls(pos) tr[pos].l
#define rs(pos) tr[pos].r
#define mid ((l+r)>>1)
#define len(pos) tr[pos].len
const int up = 1e6;
const int down = 1;
using namespace std;
struct Node{
	int l=0,r=0;
	char ch;
	int len = 0;
}tr[N*40];
int tot = 0;
int rt[N];
void push_up(int pos){
	len(pos) = len(rs(pos)) + len(ls(pos));
}
void modify(int last, int now, int l, int r, int x, char y){
	if(l == r){
		tr[now].len = 1;
		tr[now].ch = y;
		return;
	}
	len(now) = len(last);
	ls(now) = ls(last);
	rs(now) = rs(last);
	if(x <= mid){
		ls(now) = ++tot;
		modify(ls(last),ls(now),l,mid,x,y);
	}else{
		rs(now) = ++tot;
		modify(rs(last),rs(now),mid+1,r,x,y);
	}
	push_up(now);
}
char ask(int pos, int l, int r, int x){
	if(l == r){
		return tr[pos].ch;
	}
	if(x <= mid){
		return ask(ls(pos),l,mid,x);
	}else{
		return ask(rs(pos),mid+1,r,x);
	}
}
int n;

int main(){
	cin >> n;
	int now = 1;
	while(n--){
		char op;
		cin >> op;
		if(op == 'T'){
			rt[now] = ++tot;
			char x;
			cin >> x;
			modify(rt[now-1],rt[now],down,up,tr[rt[now-1]].len+1,x);
			now++;
		}
		if(op == 'U'){
			int x;
			cin >> x;
			rt[now] = rt[now-x-1];
			now++;
		}
		if(op == 'Q'){
			int x;
			cin >> x;
			cout << ask(rt[now-1],down,up,x) << endl;
		}
	}	
	return 0;
} 
