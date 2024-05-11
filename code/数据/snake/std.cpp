/*
t <= 1e6
n <= 1000,m <= 1000
*/
#include<bits/stdc++.h>
const int N = 1100;
const int M = 1e6+10;
#define fi first
#define se second
using namespace std;
int n,m;
int mp[N][N];
int dirx[N][N],diry[N][N];
char op[M];
int q,p;
pair<int,int> food[M];
int hx,hy,tx,ty,cntf = 1,dx,dy; 
int main(){
//	freopen("snake10.in","r",stdin);
//	freopen("snake10.out","w",stdout);
	cin >> n >> m >> q >> p;
	for(int i = 1;i <= q; i++){
		int t;
		char x;
		cin >> t >> x;
		op[t] = x;
	}
	for(int i = 1; i <= p; i++) cin >> food[i].fi >> food[i].se;
	cin >> hx >> hy;
//	cout << hx << " " << hy << endl;
	tx = hx;
	ty = hy-1;
	dirx[hx][hy] = 0;
	dirx[tx][ty] = 0;
	diry[hx][hy] = 1;
	diry[tx][ty] = 1;
	dx = 0,dy = 1;
	int t = 0;
	bool flag = 0;
	while(++t){
		if(hx == food[cntf].fi && hy == food[cntf].se) cntf++,flag = 1;
//		cout << cntf ;
//		break;
//		cout << tx << " " << ty << " " << hx << " " << hy  << " " << dx << " " << dy<< endl;
		if(!flag){
			mp[tx][ty] = 0;
			int xx = dirx[tx][ty];
			int yy = diry[tx][ty];
			tx += xx;
			ty += yy;
		}
		if(tx <= 0) tx = n;
		if(tx > n) tx = 1;
		if(ty <= 0) ty = m;
		if(ty > m) ty = 1;
		flag = 0;
		if(op[t] == 'D') dx = 1,dy = 0;
		if(op[t] == 'U') dx = -1,dy = 0;
		if(op[t] == 'R') dx = 0,dy = 1;
		if(op[t] == 'L') dx = 0,dy = -1;
		dirx[hx][hy] = dx;
		diry[hx][hy] = dy;
		hx += dx;
		hy += dy;
		if(hx <= 0) hx = n;
		if(hx > n) hx = 1;
		if(hy <= 0) hy = m;
		if(hy > m) hy = 1;
//		cout << t << ": " << tx << " " << ty << "xxx" << hx << " " << hy << endl; 
		if(mp[hx][hy]) break;
		mp[hx][hy] = 1;
		if(t > 1e6){
			cout << "-1 " << cntf+1 << "\n";
			return 0;
		}
//		 if(t >= 4970)cout << tx << " " << ty << " xxx "<< hx << " " << hy << endl;
//		if(t <= 2500) printf("%d %d\n",hx,hy);
//		 if(t >= 44560 && t <= 44800 && t % 14 == 0) cout << hx << " " << hy << endl;
	}
//	cout << hx << " " << hy << " " << tx << " " << ty << endl;
	cout << t << " " << cntf+1 << "\n";
	return 0;
}
/*
1 3 1 2
3 L
1 1
1 2
1 1
*/
