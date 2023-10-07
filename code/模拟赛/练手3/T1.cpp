#include <bits/stdc++.h>
const int N = 1e6+10;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;

using namespace std;
int n;
string m;
int a[1005];
bool is_moslems(int x[],int size){
	for(int i = 1; i <= size/2;i++){
		if(x[i-1] != x[size-i]){
			return 0;
		}
	}
	return 1;
}
void f(int size,int x[],int step){
	if(step > 30){
		cout << "Impossible" << endl;
		return;
	}
	int cnt[1005]={0};
	for(int i = 0; i < size;i++){
		cnt[i] = x[i]+x[size-i-1];
	}
	int op = 0;
	for(int i = 0; i <= size;i++){
		cnt[i] += op;
		op = cnt[i] / n;
		cnt[i] %= n;
	}
	int num;
	if(cnt[size]) num = size+1;
	else num = size;
	
	if(is_moslems(cnt,num)){
		cout << step << endl;
		return;
	}
	f(num,cnt,step+1);
}
int main(){
	freopen("moslems.in","r",stdin);
	freopen("moslems.out","w",stdout);
	cin >> n >> m;
	for(int i = 0; i < m.size();i++){
		if('0' <= m[m.size()-i-1] && m[m.size()-i-1] <= '9'){
			a[i] = m[m.size()-i-1]-'0';
		}else{
			a[i] = m[m.size()-i-1]-'A';
		}
		
	}
	f(m.size(),a,1);
	return 0;
}

