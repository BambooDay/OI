#include <bits/stdc++.h>
#define ll long long
const int N = 236300;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;

using namespace std;

int idx = 0;
struct DLXnode{
	int col,row;
	int right,left,up,down;
}node[N];
int lcnt[N];
int Row[N];
int mp[10][10];
void init(){

	for(int i = 0; i <= 324; i++){
		node[i].left = i-1;
		node[i].right = i+1;
		node[i].up = node[i].down = i;
		lcnt[i] = 0;
	}
	node[0].left =324;
	node[324].right = 0;
	idx = 324;
} 
void add(int i, int j){
	node[++idx].row = i;
	node[idx].col = j;
	node[idx].down = node[j].down;
	node[idx].up = j;
	node[node[idx].down].up = idx;
	node[j].down = idx;
	lcnt[j]++;
	if(!Row[i]){
		Row[i] = idx;
		node[idx].right = idx;
		node[idx].left = idx;
	}else{
		node[idx].right = Row[i];
		node[idx].left = node[Row[i]].left;
		node[Row[i]].left = idx;
		node[node[idx].left].right = idx;
	}
//		cout << 1 << " ";
}
void remove(int c){
	for(int i = node[c].down; i != c; i = node[i].down){
		for(int j = node[i].right;j != i; j = node[j].right){
			node[node[j].down].up = node[j].up;
			node[node[j].up].down = node[j].down;
			lcnt[node[j].col]--;
		}
	}
	node[node[c].left].right=node[c].right;
    node[node[c].right].left=node[c].left;
}
void remuse(int c){
	for(int i = node[c].down; i != c; i = node[i].down){
		for(int j = node[i].right;j != i; j = node[j].right){
			node[node[j].down].up = j;
			node[node[j].up].down = j;
			lcnt[node[j].col]++;
		}
	}
	node[node[c].left].right=c;
    node[node[c].right].left=c;
}
int ans[100];
void print(int n){
	for(int i = 0; i < n; i++){
		cout << ans[i] << endl;
		int k = (ans[i]-1) % 9 + 1;
		int y = ((ans[i] - k)/9) % 9 + 1;
		int x = ((ans[i] - k) / 9 - y) / 9+1;
		mp[x][y] = k;
	}
	for(int i = 1; i <= 9; i++){
		for(int j = 1; j <= 9; j++){
			printf("%d ",mp[i][j]);
		}
		printf("\n");
	}
}
bool dance(int step){
	if(node[0].right == 0){
//	cout << step << endl;
		print(step);
		exit(0);
	}
	int c = node[0].right;
	for(int i = node[0].right; i ; i = node[i].right){
		if(lcnt[i] < lcnt[c]){
			c = i;
		}
	}
	remove(c);
	for(int i = node[c].down; i != c; i = node[i].down){
		ans[step] = node[i].row;
		for(int j = node[i].right; j != i;j = node[j].right){
			remove(node[j].col);
		}
		if(dance(step+1)) return 1;
		for(int j = node[i].right; j != i;j = node[j].right){
			remuse(node[j].col);
		}
	}
	remuse(c);
	return 0;
}
int main(){
	init();
	for(int i = 1; i <= 9; i++){
		for(int j = 1; j <= 9; j++){
			scanf("%d",&mp[i][j]);

				for(int k=1;k<=9;k++){
	                if(mp[i][j]!=k && mp[i][j]) continue;
	                int id=((i-1)*9+(j-1))*9+k;
	                int c1=(i-1)*9+(j-1)+1,c2=81+(i-1)*9+k,c3=81*3+(j-1)*9+k,c4=81*2+(((i-1)/3)*3+((j-1)/3))*9+k;
	                add(id,c1);
	                add(id,c2);
	                add(id,c3);
	                add(id,c4);//连接行列
	            }
		}
	}
	dance(0);
	return 0;
}

