#include <bits/stdc++.h>
#define int long long
const int N =3e5+10;

using namespace std;
int gx(int a,int b, int x, int y){
	return a*x+b*y;
}
int gy(int a, int b, int x, int y){
	return -b*x+a*y;
}
int x[N],y[N];
int n,m,a,b;
int t;
signed main(){
	freopen("tank.in","r",stdin);
	freopen("tank.out","w",stdout);
	cin >> n >> m >> a >> b;
	for(int i = 1; i <= n; i++){
		int xx,yy;
		cin >> xx >> yy;
		x[i] = gx(a,b,xx,yy);
		y[i] = gy(a,b,xx,yy);
	}
	while(m--){
		int l,r,p,q;
		cin >> l >> r >> p >> q;
		int X = gx(a,b,p,q);
		int Y = gy(a,b,p,q);
		int ans = -1;
		for(int i = l; i <= r; i++){
			ans = max(ans,abs(x[i]-X)+abs(y[i]-Y));
		}
		if(ans == 0){
			cout << "0/1" << endl;
		}else{
			int g = __gcd(ans,a*a+b*b);
			printf("%lld/%lld\n",ans/g,(a*a+b*b)/g);
		}
	}
	return 0;
}