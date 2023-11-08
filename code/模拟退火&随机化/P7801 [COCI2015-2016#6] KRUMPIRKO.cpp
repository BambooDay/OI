#include <bits/stdc++.h>
const int N = 105;

using namespace std;
int n;
int a[N],c[N];
int l;
double RAND(){
	return rand()/RAND_MAX*2-1;
}
double Rand(){
	return rand()/RAND_MAX;
}
double cntx,cnty,sumx,sumy;
double ans;
void SA(){
	for(double t = 2010;t>1e-15;t*=0.999){
		int x = rand()%l+1,y = l+1+rand()%(n-l);
		double ncx=cntx-a[x]+a[y],ncy=cnty-a[y]+a[x];
		double nsx=sumx-c[x]+c[y],nsy=sumy-c[y]+c[x];
		double delta = (nsx/ncx)*(nsy/ncy)-(sumx/cntx)*(sumy/cnty);
		ans = min(ans,(nsx/ncx)*(nsy/ncy));
		if(exp(-delta/t)>Rand()){
			swap(a[x],a[y]);
			swap(c[x],c[y]);
			cntx = ncx,cnty = ncy;
			sumx = nsx,sumy = nsy;
		}
	}
}
int main(){
	srand(time(0));
	cin >> n >> l;
	for(int i =1;i <= n; i++){
		cin >> a[i];
		if(i <= l) cntx += a[i];
		else cnty += a[i];
	}	
	for(int i = 1;i <= n; i++){
		cin >> c[i];
		if(i <= l) sumx += c[i];
		else sumy += c[i]; 
	}
	SA();
	cout << fixed << setprecision(3) << (sumx/cntx)*(sumy/cnty) << endl;
	return 0;
}
