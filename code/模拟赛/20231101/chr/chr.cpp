#include <bits/stdc++.h>
const int N = 5e5+10;

using namespace std;
int n;
int a[N];

bool check(int x){
	deque<int> lma,lmi,rma,rmi,mma,mmi;
	for(int i = 2; i <= n; i++){
		while(!rmi.empty() && a[rmi.back()] >= a[i]) rmi.pop_back();
		rmi.push_back(i);
		while(!rma.empty() && a[rma.back()] <= a[i]) rma.pop_back();
		rma.push_back(i);
	}
	int l = 1,r = 1;
	mma.push_back(1);
	mmi.push_back(1);
	while(r <= n){
		if(mmi.empty() || mma.empty()){
			cout << 1111 << endl;
			return 0;
		}
		int inmi = a[mmi.front()] ,inma = a[mma.front()];
		int outmi = 1e9+1,outma = 0;
		if(!lmi.empty()) outmi = min(outmi,a[lmi.front()]);
		if(!lma.empty()) outma = max(outma,a[lma.front()]);
		if(!rmi.empty()) outmi = min(outmi,a[rmi.front()]);
		if(!rma.empty()) outma = max(outma,a[rma.front()]);
		if(outmi == 1e9+1 && outma == 0){
			if(inma-inmi <= x) return 1;
			l++;
			if(mmi.front() < l) mmi.pop_front();
			if(mma.front() < l) mma.pop_front();
			while(!lmi.empty() && a[lmi.back()] >= a[l-1]) lmi.pop_back();
			lmi.push_back(l-1);
			while(!lma.empty() && a[lma.back()] <= a[l-1]) lma.pop_back();
			lma.push_back(l-1);
			if(r < l){
				r++;
				while(!mmi.empty() && a[mmi.back()] >= a[r]) mmi.pop_back();
				mmi.push_back(r);
				while(!mma.empty() && a[mma.back()] <= a[r]) rma.pop_back();
				mma.push_back(r);
				while(!rmi.empty() && rmi.front() <= r) rmi.pop_front();
				while(!rma.empty() && rma.front() <= r) rma.pop_front();
			}
			continue;
		}
		if(inma - inmi > x){
			l++;
			if(mmi.front() < l) mmi.pop_front();
			if(mma.front() < l) mma.pop_front();
			while(!lmi.empty() && a[lmi.back()] >= a[l-1]) lmi.pop_back();
			lmi.push_back(l-1);
			while(!lma.empty() && a[lma.back()] <= a[l-1]) lma.pop_back();
			lma.push_back(l-1);
			if(r < l){
				r++;
				while(!mmi.empty() && a[mmi.back()] >= a[r]) mmi.pop_back();
				mmi.push_back(r);
				while(!mma.empty() && a[mma.back()] <= a[r]) rma.pop_back();
				mma.push_back(r);
				while(!rmi.empty() && rmi.front() <= r) rmi.pop_front();
				while(!rma.empty() && rma.front() <= r) rma.pop_front();
			}		
		}else if(outma - outmi > x){
		//cout << inmi << " " << inma << " " << outmi << " " << outma << endl;
			r++;
			while(!mmi.empty() && a[mmi.back()] >= a[r]) mmi.pop_back();
			mmi.push_back(r);
			while(!mma.empty() && a[mma.back()] <= a[r]) mma.pop_back();
			mma.push_back(r);
			while(!rmi.empty() && rmi.front() <= r) rmi.pop_front();
			while(!rma.empty() && rma.front() <= r) rma.pop_front();		
		}else{
			if(max(0,outma-inmi-x)+inma-outmi <= x) return 1;
			l++;
			if(mmi.front() < l) mmi.pop_front();
			if(mma.front() < l) mma.pop_front();
			while(!lmi.empty() && a[lmi.back()] >= a[l-1]) lmi.pop_back();
			lmi.push_back(l-1);
			while(!lma.empty() && a[lma.back()] <= a[l-1]) lma.pop_back();
			lma.push_back(l-1);
			if(r < l){
				r++;
				while(!mmi.empty() && a[mmi.back()] >= a[r]) mmi.pop_back();
				mmi.push_back(r);
				while(!mma.empty() && a[mma.back()] <= a[r]) rma.pop_back();
				mma.push_back(r);
				while(!rmi.empty() && rmi.front() <= r) rmi.pop_front();
				while(!rma.empty() && rma.front() <= r) rma.pop_front();
			}			
		}
	}
	return 0;
}
void solve(){
	cin >> n;
	int ma=0,mi = n+1;
	a[0] = 0,a[n+1] = 1e9+1;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		if(a[i] >= a[ma]) ma = i;
		if(a[i] <= a[mi]) mi = i;
	}
	//check(1);
	//return;
	int l = 0,r = a[ma] - a[mi]-1;
	int ans = a[ma]-a[mi];
	while(l <= r){
		int mid = (l+r) >> 1;
		if(check(mid)){
			ans = mid;
			r = mid-1;
		}else{
			l = mid+1;
		}
	}
	cout << ans << endl;
}
int main(){
	freopen("chr.in","r",stdin);
	freopen("chr.out","w",stdout);
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}