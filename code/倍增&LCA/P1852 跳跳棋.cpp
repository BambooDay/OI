#include <bits/stdc++.h>
const int INF = 0x3f3f3f3f;

using namespace std;
struct Node{
	int x,y,z;
};
void init(Node &a){
	cin >> a.x >> a.y >> a.z;
	if(a.x > a.y) swap(a.x,a.y);
	if(a.x > a.z) swap(a.x,a.z);
	if(a.y > a.z) swap(a.y,a.z);
}
Node a,b,ra,rb;
bool check(Node u, Node v){
 	return u.x == v.x && u.y == v.y && u.z == v.z;
}
int step,k;
Node gt(Node t, int s){
	for(step = 0;s;step += k){
		int d1 = t.y - t.x,d2 = t.z - t.y;
		if(d1 == d2) return t;
		if(d1 < d2){
			k = min((d2-1)/d1,s);
			t.x += k*d1, t.y += k*d1;
			s -= k;
		}else{
			k = min((d1-1) / d2 ,s);
			t.z -= k*d2,t.y -= k*d2;
			s -= k;
			
		}
	}
	return t;
}
signed main(){
	init(a),init(b);
	ra = gt(a,INF);
	int step1 = step;
	rb = gt(b,INF);
//	cout << 111;
	int step2 = step;
	if(!check(ra,rb)){
		puts("NO");
		return 0;
	}
	if(step1 < step2){
		swap(a,b);
		swap(step1,step2);
	}
	a = gt(a,step1-step2);
	int l = 0,r = step2;
	while(l < r){
		int mid = (l+r) >> 1;
		if(check(gt(a,mid),gt(b,mid))) r = mid;
		else l = mid+1;
	}
	cout << "YES" << endl << (l<<1)+step1-step2;

	return 0;
} 
