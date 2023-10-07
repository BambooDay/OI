#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 1e6+10;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;

using namespace std;
int n;
int a[1005];
void print(int siz){
	printf("%d=%d",n,a[1]);
	for(int i = 2;i < siz; i++){
		printf("+%d",a[i]);
	}
	puts("");
}
void dfs(int x, int fa,int step){
	if(x == 0){
		print(step);
		return;
	}
	for(int i = fa; i <= x && i != n; i++){
		a[step] = i;
		dfs(x-i,i,step+1);
	}
}
int main(){
	scanf("%d",&n);
	dfs(n,1,1);
	return 0;
}
