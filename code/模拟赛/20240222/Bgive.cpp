#include <bits/stdc++.h>

using namespace std;
int n,m,x,k;

int main(){
	freopen("python.in","w",stdout);
	srand(time(0));
	n = 5,m = 7,x = 2, k = 5;
	cout << n << " " << m << " " << x << " " << k << endl;
	for(int i = 1;i <= n; i++){
		if(rand()&1){
			cout << rand()%10+1 << " ";
		}else{
			cout << -(rand()%10+1) << " ";
		}
	} 	
	cout << endl;
	for(int i = 1;i <= m; i++){
		if(rand()&1){
			cout << rand()%10+1 << " ";
		}else{
			cout << -(rand()%10+1) << " ";
		}
	} 
	return 0;
} 
