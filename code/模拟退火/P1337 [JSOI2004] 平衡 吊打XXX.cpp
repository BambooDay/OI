#include <bits/stdc++.h>
const int N = 1e4+10;

using namespace std;
int n, x[N],y[N],w[N];
double ansx, ansy, dis;
double Rand(){
	return (double) rand()/RAND_MAX;
}
double calc(double xx, double yy){
	double res = 0;
	for(int i =1;i <= n; i++){
		double dx = x[i] - xx,dy = y[i] - yy;
		res += sqrt(dx*dx + dy*dy)*w[i]; 
	}
	if(res < dis) dis = res, ansx = xx, ansy = yy;
	return res;
}
void SA(){
	
	double nowx = ansx, nowy = ansy;
	double t = 200000;
	for(;t > 0.0001; t *= 0.999){
		double nxtx = nowx + t * (Rand() * 2 - 1);
		double nxty = nowy + t * (Rand() * 2 - 1);
		double delta = calc(nxtx, nxty) - calc(nowx, nowy);
		if(exp(-delta / t) > Rand()) nowx = nxtx,nowy = nxty;
	}
	for(int i =1;i <= 100000; i++){
		double nxtx = ansx + t * (Rand() * 2 - 1);
		double nxty = ansy + t * (Rand() * 2 - 1);
		calc(nxtx, nxty);
	}
}
int main(){
	srand(time(0));
	scanf("%d", &n);
	for(int i =1; i <= n; i++){
		scanf("%d%d%d", &x[i], &y[i], &w[i]);
		ansx += x[i],ansy += y[i]; 
	}
	ansx /= n, ansy /= n, dis = calc(ansx,ansy);
	SA();
	printf("%.3lf %.3lf\n", ansx, ansy); 
	return 0;
}
