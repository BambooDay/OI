#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 1e6+10;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;

using namespace std;
map <int,int> m;
int cnt = 0;
int n;

int main(){
	int q;
	scanf("%d%d",&q,&n);
//	cin >> q;
//	cin >> n;
	for(int i = 0; i <= n; i++){
		bool v[10] = {0};
		int t = i;
		bool flag = 1;
		while(t){
			if(v[t%10]){flag = 0;break;}
			v[t% 10] = 1;
			t /= 10;
		}
		if(flag){
			m[i] = cnt++;
		}
	}
	while(q--){
		int x;
		scanf("%d",&x);
//		cin >> x;
		if(m.count(x)) printf("%d\n",m[x]); //cout << m[x] << endl;
		else puts("not exist£¡"); //cout << "not exist£¡" << endl;
	}
	return 0;
}
