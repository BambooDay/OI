#include <bits/stdc++.h>
const int N = 1e3+10;
const int M = 5e5+10;
#define int long long
using namespace std;
int n,m;
int a[N];
bool ans[M];
struct Node{
	int k,x,id;
}q[M];
bool cmp(Node x, Node y){
	return x.x < y.x;
}
signed main(){
	freopen("double.in","r",stdin);
	freopen("double.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= m; i++){
	 	cin >> q[i].k >> q[i].x;
	 	q[i].id = i;
	}
	sort(q+1,q+1+m,cmp);
	#define X q[j].x
	#define K q[j].k
	#define ID q[j].id
	for(int i = 1,j = 1;i < n&&j <= m;j++){
		while(a[i+1] < X) i++;
		if(a[i+1] == X|| a[i] == X){
			ans[q[j].id] = 1;
			continue;
		}
		int l = a[i],r = a[i+1];
		while(K){
			int mid = (l+r)/2;
			if(mid == X){
				ans[ID] = 1;
				break;
			}
			if(mid < X) l = mid;
			else r = mid;
			K--;
		}
	}
	for(int i =1;i <= m; i++){
		if(ans[i]) puts("Yes");
		else puts("No");
	}
	return 0;
}
