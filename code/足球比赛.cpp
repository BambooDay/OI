#include <bits/stdc++.h>
#define ll long long
//const int N = 1e6+10;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;

using namespace std;
int n, m,N;
bool v[3000];
ll sum = 0;
void f(int dep,int com,int step){
	if(dep == n) return;
	for(int i = step; i <= N; i+=step){
		if((v[i] == 0 && v[i-com] == 1) || (v[i] == 1 && v[i-1] == 0)){
			sum++;
			v[i] = 0;
		}
	}
	f(dep+1,com*2,step*2);
}

int main(){
	scanf("%d %d",&n,&m);
	N = pow(2,n);
	for(int i = 1; i <= m; i++){
		int x;
		scanf("%d",&x);
		v[x] = 1;
	}
	f(0,1,2);
	printf("%lld",sum);
	return 0;
}

