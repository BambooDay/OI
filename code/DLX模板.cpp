#include <bits/stdc++.h>
#define ll long long
#define Pair pair<int,node>
#define Map map<int,int>

const int MAXN = 1e6+10;
const int MAXM = 1e4+10;
const int INF  = 0x3f3f3f;

using namespace std;
int n, m;
struct DLXnode{
	int row,col;
	int right,left,up,down;
}node[6000];
int idx = 0;
int Row[510],ans[510],lcnt[510];
void init(){
	for(int i = 0; i <= m; i++){
		node[i].left = i-1;
		node[i].right = i+1;
		node[i].up = i;
		node[i].down = i;
		lcnt[i] = 0;
	}
	node[0].left = m;
	node[m].right = 0;
	idx = m;
}
void add(int r, int c){
	node[++idx].row = r;
	node[idx].col = c;
	node[idx].down = node[c].down;
	node[idx].up = c;
	node[node[idx].down].up = idx;
	node[c].down = idx;
	if(!Row[r]){
		node[idx].left = idx;
		node[idx].right = idx;
		Row[r]= idx;
	}else{
		node[idx].left = node[Row[r]].left;
		node[idx].right= Row[r];
		node[node[idx].left].right=idx;
        node[node[idx].right].left=idx;
	}
	lcnt[c]++;
}
void remove(int c){
	for(int i=node[c].down;i!=c;i=node[i].down){
        for(int j=node[i].right;j!=i;j=node[j].right){
            node[node[j].down].up=node[j].up;
            node[node[j].up].down=node[j].down;
            lcnt[node[j].col]--;
        }
	}
    node[node[c].left].right=node[c].right;
    node[node[c].right].left=node[c].left;
}
void resume(int c) {
    node[node[c].left].right=c;
    node[node[c].right].left=c;
    for(int i=node[c].down;i!=c;i=node[i].down){
        for(int j=node[i].right;j!=i;j=node[j].right){
            node[node[j].down].up=j;
            node[node[j].up].down=j;
            lcnt[node[j].col]++;
        }
	}
}
bool dance_line(int step){
	if(node[0].right == 0){
		for(int i = 1; i < step; i++){
			cout<< ans[i] << " ";
		}
		return 1;
	}
	int C = node[0].right;
	for(int i = node[0].right; i; i = node[i].right){
		if(lcnt[i] < lcnt[C]){
			C = i;
		}
	}
	remove(C);
	for(int i = node[C].down; i != C; i = node[i].down){
		ans[step] = node[i].row;
		for(int j = node[i].right; j != i;j = node[j].right){
			remove(node[j].col);
		}
		if(dance_line(step+1)) return 1;
		for(int j = node[i].right; j != i;j = node[j].right){
			resume(node[j].col);
		}
	}
	resume(C);
	return 0;
}
int main(){
	cin >> n >> m;
	init();
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			int x;
			cin >> x;
			if(x) add(i,j);
		}
	}
	if(!dance_line(1)){
		printf("No Solution!\n");
	}
	return 0;
}
