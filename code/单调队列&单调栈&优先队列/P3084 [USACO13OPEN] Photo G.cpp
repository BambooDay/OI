#include <bits/stdc++.h>
const int N = 2e5+10;

using namespace std;
int n, m;
int minl[N],maxl[N];
int f[N];
deque<int> q;
//int q[N];
//int h,t;
int main(){
	cin >> n >> m;
	for(int i= 1;i <= n+1; i++){
		minl[i] = i;
	}	
	for(int i = 1;i <= m; i++){
		int l,r;
		cin >> l >> r;
		minl[r] = min(minl[r],l);
		maxl[r+1] = max(maxl[r+1],l);
	}

	
	for(int i = 1;i <= n+1; i++){
		maxl[i] = max(maxl[i],maxl[i-1]);
	}
	for(int i = n; i >0; i--){
		minl[i] = min(minl[i],minl[i+1]);
	}

	int j = 1;
	q.push_back(0);
	for(int i = 1;i <= n+1; i++){
		while(j < minl[i]){
			if(f[j] != -1){
				while(!q.empty() && f[q.back()] < f[j]){
					q.pop_back();
				}
				q.push_back(j);
			}
			j++;
		}
		while(!q.empty() && q.front() < maxl[i]) q.pop_front();
		if(!q.empty()) f[i] = f[q.front()] + (i != n+1);
		else f[i] = -1; 
	}

	cout << f[n+1];
	return 0;
}
