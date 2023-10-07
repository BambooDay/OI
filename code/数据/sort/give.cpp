#include <bits/stdc++.h>
const long long N = 1e15+10;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;

using namespace std;

int main(){
	srand(time(0));
	freopen("sort.in","w",stdout);
	int n = rand() % 1000005;
	cout << n << endl;
	for(int i = 1; i <= n; i++){
		long long a = rand() % N;
		cout<< a << " ";
	}
	return 0;
}

