#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-5;
int n;
double k,t = 0,now;

int main(){
	cin >> k >> n >> now;
	for(int i = 2; i <= n; i++){
		double pos;
		cin >> pos;
		if(now+k<pos-t){
			double x = pos;
			pos = pos-t;
			t += (pos-now-k)/2.0;
			now = x-t;
		}else{
			now = min(now+k,pos+t);
		}
	}	
	cout << fixed << setprecision(4) << t+eps << endl;
	return 0;
}
