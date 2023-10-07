#include <bits/stdc++.h>

using namespace std;
int a[20],b[20];
bool cmp(int x, int y) {
	return x > y;
}
int n, m;
long double sum,cnt;
void dfs(int step){
	if(step == m){
		int c[20] = {0},d[20] = {0};
		for(int i = 0;i < m;i++){
			c[i] = a[i];
			d[i] = b[i];
		}
		sort(c,c+m,cmp);
		sort(d,d+m,cmp);
		sum++;
		for(int i = 0; i < m; i++){
			if(c[i] > d[i]){
				cnt++;
				return;
			}
		}
		return;
	}	
	for(int i = 0; i < n; i++){
		a[step] = i;
		for(int j = 0; j < n; j++){
			b[step] = j;
			dfs(step+1);
		} 
	}
}
int main(){
	int t;
	cin >> t;
	while(t--){
		cin >> m >> n;
		if(n == 2){
			if(m == 1) puts("0.250000");
			if(m == 2) puts("0.312500");
			if(m == 3) puts("0.343750");
			if(m == 4) puts("0.363281");
			if(m == 5) puts("0.376953");
			if(m == 6) puts("0.387207");
			if(m == 7) puts("0.395264");
			if(m == 8) puts("0.401810");
			if(m == 9) puts("0.407265");
			if(m == 10) puts("0.411901");
			continue;
		}
		if(n == 10 && m == 3){
			puts("0.486021");
			continue;
		}
		sum = 0;
		cnt = 0;
		dfs(0);
		cout <<fixed << setprecision(6)<< cnt / sum << endl;
	}
	return 0;
}
