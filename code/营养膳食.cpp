#include <bits/stdc++.h>
#define ll long long
const int N = 1e6+10;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;

using namespace std;
struct food{
	int fat,b;
}a[300];
int num[200];
int n, m,k;
ll sum = 0;
bool cmp(food a, food b){
	return a.fat>b.fat;
}
int main(){
	scanf("%d %d %d",&n,&m,&k);
	for(int i = 1; i <= k; i++){
		scanf("%d",&num[i]);
	}
	for(int i = 1; i <= n; i++){
		scanf("%d %d",&a[i].fat,&a[i].b);
	}
	sort(a+1,a+1+n,cmp);
	int i = 1;
	while(m && i <= n){
		if(num[a[i].b]){
			num[a[i].b]--;
			m--;
			sum += a[i].fat;
		}
		i++;
	}
	printf("%lld",sum);
	return 0;
}

