#include<bits/stdc++.h>

using namespace std;
int friends[20][5];
int n;
int a[20],pos[20];
int ans;
int calc(){
	int res =0;
	for(int i = 1;i <= n; i++){
		for(int j = 1;j <= 3; j++){
			res += abs(pos[i] - pos[friends[i][j]]);
		} 
	}
	res /= 2;
//	ans = min(ans,res);
	return res;
}
double Rand(){
	return rand()*1.0/RAND_MAX;
} 
void SA(){
	for(double t = 2007; t > 1e-5; t *= 0.999){
	 	int x = rand()%n+1,y = rand()%n+1;
	 	swap(pos[a[x]],pos[a[y]]);
	 	swap(a[x],a[y]);
	 	int res = calc();
	 	swap(pos[a[x]],pos[a[y]]);
	 	swap(a[x],a[y]);
		double delta = res - ans;
		ans = min(ans,res);
		if(exp(-delta/t) > Rand()){
		 	swap(pos[a[x]],pos[a[y]]);
	 		swap(a[x],a[y]);		
		} 	
	}
}
int main(){
	cin >> n;
	for(int i =1;i <= n; i++){
		a[i] = i;
		pos[i] = i;
		for(int j = 1;j <= 3; j++){
			cin >> friends[i][j];
		}
	}	
	ans = calc();
	SA();
	cout << ans <<  endl;
	return 0;
}
