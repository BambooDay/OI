#include <bits/stdc++.h>
const int N = 505;

using namespace std;
int r,c,a,b,mp[N][N],s[N][N],ans;
bool check(int x){
	int now = 0,num = 0;
	for(int i = 1; i <= r; i++){
		int dis = 0,sum = 0;
		for(int j = 1; j <= c; j++){
			if(dis + s[i][j] - s[i][j-1] - s[now][j] + s[now][j-1] < x){
				dis += s[i][j] - s[i][j-1] - s[now][j] + s[now][j-1];
			}else{
				sum++;
				dis = 0;
			}
		}
		if(sum >= b){
			now = i,num++;
		}
	}
	if(num < a) return 0;
	return 1;
}

int main(){
	cin >> r >> c >> a >> b;
	for(int i = 1;i <= r; i++){
		for(int j = 1; j <= c; j++){
			cin >> mp[i][j];
		}
	}	
	for(int i = 1; i <= r; i++){
		for(int j = 1; j <= c; j++){
			s[i][j] = s[i-1][j] + s[i][j-1] + mp[i][j] - s[i-1][j-1];
		}
	}
	int L = 0,R = s[r][c];
	while(L <= R){
		int mid = (L+R)>>1;
		if(check(mid)) L = mid+1,ans = mid;
		else R = mid-1;
	}
	cout << ans;
	return 0;
}
