#include <bits/stdc++.h>
const int N = 3000;

using namespace std;
int n, m, ap,bp,as,bs,w,ans= 0;
int f[N][N];

int main(){
	cin >> n >> m >> w;
	memset(f,128,sizeof f);
	for(int i = 1;i <= n;i++){
		cin>> ap >> bp >> as >> bs;
		for(int j = 0; j <= as; j++){
			f[i][j] = -1*j*ap; 
		}
		for(int j = 0; j <= m ; j++){
			f[i][j] = max(f[i][j],f[i-1][j]);
		}
		if(i <= w) continue;
		deque<int> q1;
		for(int j= 0; j <= m; j ++){
			while(!q1.empty() && q1.front() < j-as){
				q1.pop_front();
			}
			while(!q1.empty() && f[i-w-1][q1.back()] + q1.back()*ap <= f[i-w-1][j] + j*ap){
				q1.pop_back();
			} 
			q1.push_back(j);
			if(!q1.empty()){
				f[i][j] = max(f[i][j],f[i-w-1][q1.front()] + q1.front()*ap - j*ap);
			}
		}
		deque<int> q2;
        for(int j = m ; j >= 0 ; j--){
            while(!q2.empty() && q2.front() > j + bs){
                q2.pop_front();
            }
            while(!q2.empty() && f[i - w - 1][q2.back()] + q2.back() * bp <= f[i - w - 1][j] + j * bp){
                q2.pop_back() ;
            }
			q2.push_back(j); 
            if(!q2.empty()){
                f[i][j] = max(f[i][j] , f[i - w - 1][q2.front()] + q2.front() * bp - j * bp); 
            }
        }		
	}	
	cout << f[n][0];
	return 0;
}
