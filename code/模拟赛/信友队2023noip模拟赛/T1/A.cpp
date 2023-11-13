#include <bits/stdc++.h>
const int N = 2005;
using namespace std;
int n,m;
int a[N][N];
int b[N][N];
int get(int x, int y, int c, int d){
//	cout << x << " " << y << " " << c << " " << d << " " << (b[c][d] - b[x-1][d] - b[x][y-1]  + b[x-1][y-1]) << endl;
//	cout << b[c][d] << " " <<  b[x-1][d] <<" " << b[x][y-1]  << " "  << b[x-1][y-1] << endl;
	return (b[c][d] - b[x-1][d] - b[c][y-1]  + b[x-1][y-1]);
}
int find(int x, int y){
	int l = 1,r = min(n-x,m-y)+1;
	int ans = 0;
	while(l <= r){
		int mid = (l+r) >>1;
//		cout << mid << " " << get(x,y,x+mid-1,y+mid-1) << endl;
		if(get(x,y,x+mid-1,y+mid-1) == (mid*mid)) ans = mid,l = mid+1;
		else r = mid-1;
	}
	return ans;
}
int getr(int up,int down, int x){
	int l = 1,r = m - x+1;
	int ans = 0;
	while(l <= r){
		int mid = (l+r)>>1;
		if(get(up,x,down,x+mid-1) == 0) ans = mid,l = mid+1;
		else r = mid-1;
	}
	return ans;
}
long long ans = 0 ;
int main(){
	freopen("wu.in","r",stdin);
	freopen("wu.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n; i++){
		for(int j =1 ;j <= m; j++){
			cin >> a[i][j];
//			cout << a[i][j] << " ";
			b[i][j] = b[i-1][j] + b[i][j-1] -  b[i-1][j-1] + a[i][j];
		}
	}
//	cout << 1111<<endl;
//	cout <<get(3,2,4,3) << endl; 
//	cout << find(7,3) << endl;
//	for(int i = 1;i <= n; i++){
//		for(int j = 1; j <= m; j++){
//			cout << b[i][j] << " ";
//		}
//		cout << endl;
//	}
//	return 0;
	for(int i = 1;i <= n; i++){
		for(int j = 1;j <= m; j++){
			if(!a[i][j]) continue;
			int len = find(i,j);
//			cout << i << " " << j << " : " << len << endl;
			if(get(i,j,i+len,j+len) != len*len) continue;
			for(int r = j+len; r <= m; r++){
				if(get(i,j,i+len,r) != len*len) break;
				for(int down = i + len; down <= n; down++){
//					cout << i << " " << j << " " << down << " " << r << " " << get(i,j,down,r) << endl;
					if(get(i,j,down,r) == len*len){
						ans++;
//						cout << i << " " << j << " " << down << " " << r << endl; 
					} 
					else break;
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}
/*
5 5
1 1 0 0 0
1 1 1 0 0
1 1 1 0 0
1 1 1 0 0
0 0 0 0 0
*/
