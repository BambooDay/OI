#include <bits/stdc++.h>
const int N = 1e4+10;

using namespace std;
int n, x[N],y[N],w[N];
double ansx, ansy, dis;
double Rand(){
	return (double) rand()/RAND_MAX;
}
double calc(double xx, double yy){//计算当前值的答案 
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
	double t = 200000;//初始温度 
	for(;t > 0.0001; t *= 0.999){
		double nxtx = nowx + t * (Rand() * 2 - 1);
		double nxty = nowy + t * (Rand() * 2 - 1);
		double delta = calc(nxtx, nxty) - calc(nowx, nowy);//新退的值和旧的比较 
		if(exp(-delta / t) > Rand()) nowx = nxtx,nowy = nxty;
	}
	for(int i =1;i <= 100000; i++){//这个根据题目决定，这个是退火之后再爬山（应该 
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
	SA();//可以根据题目不同选择退几次 
	printf("%.3lf %.3lf\n", ansx, ansy); 
	return 0;
}
