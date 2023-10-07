#include <bits/stdc++.h>
#define int long long
using namespace std;
int ax,ay,bx,by,ans,n,x[70],y[70],xs,ys,t;
int dist(int x1,int y1,int x2, int y2){
	return abs(x1-x2)+abs(y1-y2);
}

signed main(){
	cin >> x[0] >> y[0] >> ax >> ay >> bx >> by >> xs >> ys >> t;
	while(++n){
		x[n] = ax*x[n-1] + bx,y[n] = ay*y[n-1]+by;
		if(x[n] > xs && y[n] > ys && dist(xs,ys,x[n],y[n]) > t) break;
	}
	int ans = 0;
	for(int i = 0; i <= n; i++){
		int res = 0,tt = t;
		if(dist(xs,ys,x[i],y[i]) <= tt) tt -= dist(xs,ys,x[i],y[i]),res++;
		else {
			ans = max(ans,res);
			continue;
		}
		for(int j = i; j; j--){
			if(dist(x[j],y[j],x[j-1],y[j-1]) <= tt) tt -= dist(x[j],y[j],x[j-1],y[j-1]),res++;
			else break;
		}	
		for(int j = 1;j <= n; j++){
			if(dist(x[j],y[j],x[j-1],y[j-1]) <= tt) tt -= dist(x[j],y[j],x[j-1],y[j-1]),res+=(j>i);
			else break;
		}
		ans = max(ans,res);
	}
	cout << ans << endl;
	return 0;
}
