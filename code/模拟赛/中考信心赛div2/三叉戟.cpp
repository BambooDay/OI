#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const int N = 1e6+10;
const int M = 1e4+10;
const int INF = 0x3f3f3f3f;
const int mod = 1e9+7;

using namespace std;
int n;
struct Node{
	char fa,l,r,mid;
	bool v;
}node[150]; 
void yxx(int pos){
	cout << char(pos);
	if(node[pos].l != '*' && node[pos].l) yxx(node[pos].l);
	if(node[pos].mid != '*'&& node[pos].mid) yxx(node[pos].mid);
	if(node[pos].r !='*'&& node[pos].r) yxx(node[pos].r);
}
void yqx(int pos){
	if(node[pos].r!='*'&& node[pos].r) yqx(node[pos].r);
	if(node[pos].l!='*'&& node[pos].l) yqx(node[pos].l);
	cout << char(pos);
	if(node[pos].mid!='*'&& node[pos].mid) yqx(node[pos].mid);
}
void dzx(int pos){
	if(node[pos].mid!='*'&& node[pos].mid) dzx(node[pos].mid);
	cout << char(pos);
	if(node[pos].r!='*'&& node[pos].r) dzx(node[pos].r);
	if(node[pos].l!= '*'&& node[pos].l) dzx(node[pos].l);
}
int main(){
	cin >> n;
	char x;
	while(cin >> x){
		node[x].v = 1;
		cin >> node[x].l >> node[x].mid >> node[x].r;
		node[node[x].l].fa = x;
		node[node[x].mid].fa = x;
		node[node[x].r].fa = x;
		node[node[x].l].v = 1;
		node[node[x].mid].v = 1;
		node[node[x].r].v = 1;
	}
	int rt = 0;
	for(int i = int('A'); i <= (int)'Z'; i++){
		if(!node[i].fa && node[i].v) rt = i;
	}
	for(int i = int('a'); i <= (int)'z'; i++){
		if(!node[i].fa&&node[i].v) rt = i;
	}
//	cout << rt;
	yxx(rt);
	cout<<endl;
	dzx(rt);
	cout << endl;
	yqx(rt);
	return 0;
}
