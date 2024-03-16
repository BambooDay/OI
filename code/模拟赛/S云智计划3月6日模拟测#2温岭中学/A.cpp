#include <bits/stdc++.h>
const int N = 1e5+10;

using namespace std;
int n,q;
int a[N];
pair<int,int> b[N];
int ans[N];
int now = 0; 

int main(){
	freopen("four.in","r",stdin);
	freopen("four.out","w",stdout);
	cin >> n >> q;
	for(int i = 1;i <= n; i++) scanf("%d",&a[i]);
	for(int i = 1;i <= q; i++){
		b[i].second = i;
		scanf("%d",&b[i].first);
		ans[i] = -1;
	} 
	sort(b+1,b+1+q);
	int j = 1;
	for(int i = 1;i <= n; i++){
		while(now >= b[j].first && j <= q){
			ans[b[j].second] = i-1;
			j++;
		}
		now += a[i];
	}
	while(now >= b[j].first && j <= q){
		ans[b[j].second] = n;
		j++;
	}
	for(int i = 1; i <= q; i++) printf("%d\n",ans[i]);
	return 0;
}
