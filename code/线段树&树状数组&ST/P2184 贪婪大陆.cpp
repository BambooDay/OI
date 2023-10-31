#include <bits/stdc++.h>
const int N = 1e5+10;
#define ls (pos<<1)
#define rs (pos<<1|1)
#define mid ((l+r)>>1)

using namespace std;
int n,m;
int head[N],tail[N];
void add(int tr[],int x){
	for(int i = x; i <= n; i += (i & -i)) tr[i]++; 
}
int sum(int tr[], int x){
	int res = 0;
	for(int i = x; i; i -= (i&-i)) res += tr[i];
	return res;
} 
int main(){
	cin >> n >> m;
	while(m--){
		int q,l,r;
		cin >> q >> l >> r;
		if(q == 1){
			add(head,l);
			add(tail,r);
		}else{
			cout << sum(head,r) - sum(tail,l-1) << endl;
		}
	}	
	return 0;
}
