#include <bits/stdc++.h>
#define int long long
const int N = 3e5+10;

using namespace std;
int n,m;
int tr[N];
void add(int x) {
	for(int i = x; i <= n; i += (i&-i)){
		tr[i]++;
	}
}
int Query(int x) {
	int sum = 0;
	for(int i = x;i; i-= (i&-i)){
		sum += tr[i];
	}
	return sum;
}
struct Num {
	int num;
	int pos;
} a[N];
bool cmp(Num a1,Num a2) {
	return a1.num < a2.num;
}

pair<int,int> pr[N<<1];
int tot = 0;
void add_pair(Num a1,Num a2) {
	int l = min(a1.pos,a2.pos) , r = max(a1.pos,a2.pos);
	pr[++tot].first = l;
	pr[tot].second = r;
}
bool cmpPair(pair<int,int> a1,pair<int,int> a2) {
	if(a1.second != a2.second)	return a1.second < a2.second;
	else return a1.first < a2.first;
}
struct Questions {
	int l,r,pos;
} question[N];
bool cmpQestions(Questions a1,Questions a2) {
	if(a1.r != a2.r)	return a1.r < a2.r;
	else return a1.l < a2.l;
}
signed main() {
	cin >> n >> m;
	if(n == 1) {
		puts("0");
		return 0;
	}
	for(int i = 1 ; i <= n ; i++) {
		cin >> a[i].num;
		a[i].pos = i;
	}
	sort(a+1,a+1+n,cmp);
	add_pair(a[1],a[2]);	
	add_pair(a[n],a[n-1]);	
	for(int i = 2; i < n ;i++) {
		int ldif = a[i].num-a[i-1].num , rdif = a[i+1].num-a[i].num;
		if(ldif < rdif) add_pair(a[i],a[i-1]);	
		else if(ldif == rdif)	add_pair(a[i],a[i-1]),add_pair(a[i],a[i+1]);
		else add_pair(a[i],a[i+1]);	
	}
	sort(pr+1,pr+1+tot,cmpPair);
	for(int i = 1; i <= m;i++) {
		cin >> question[i].l >> question[i].r;
		question[i].pos = i;
	}
	sort(question+1 , question+1+m , cmpQestions);
	int ans = 0;	
	for(int i = 1,j = 1 ; i <= m ; i++) {
		while(pr[j].second <= question[i].r && j <= tot) {
			add(pr[j].first);	
			j++;
		}
		ans += 1ll * question[i].pos * (j - 1- Query(question[i].l-1) );
	}
	cout << ans;
	return 0;
}

