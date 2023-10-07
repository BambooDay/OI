#include <bits/stdc++.h>
const int N = 1e6+10;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;

using namespace std;
int n;
struct Node{
	int x,y;
}node[105];
bool cmp(Node a,Node b){
	if(a.x != b.x) return a.x < b.x;
	return a.y < b.y;
}

int main(){
	freopen("maxbot.in","r",stdin);
	freopen("maxbot.out","w",stdout);
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> node[i].x >> node[i].y;
	}
	sort(node,node+n,cmp);
	bool f = 1;
	
	for(int i = 0; i< n; i++){
		if(node[i].x != node[i+1].x){
			if(f){
				printf("(%d,%d)",node[i].x,node[i].y);
				f = 0;
			}else{
				printf(",(%d,%d)",node[i].x,node[i].y);
			}
		} 
	}
	return 0;
}

