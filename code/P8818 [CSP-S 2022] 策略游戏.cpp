#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5+10;
const int INF = 0x3fffffffffffffff;
int A[N],B[N];
int n, m;
int maza[N][30],miza[N][30],mafa[N][30],mifa[N][30];
int mab[N][30],mib[N][30];
int q;
int lg[N];
inline bool gmx(int &a, int b) {
    return b > a ? a = b, true : false;
}
signed main(){
//	cout << LONG_LONG_MAX << " " << LONG_LONG_MIN;
	cin >> n >> m;
	cin >> q;
	
    for (int i = 2; i <= max(n, m); ++i){
        lg[i] = lg[i >> 1] + 1;	
	}
    
	for(int i =1 ; i <= n; i++){
        int x ;
        cin >> x;
        maza[i][0] = mifa[i][0] = x;
        mafa[i][0] = (x < 0 ? x : -INF);
        miza[i][0] = (x >= 0 ? x : INF);
//		cout << miza[i][0] << endl;
//		mafa[i][0] = (mafa[i][0] < 0 ? mafa[i][0] : -INF); 
//		miza[i][0] = (miza[i][0] >= 0 ? miza[i][0] : INF); 
	}
	for(int i = 1; i <= m; i++){
		cin >> mab[i][0];
		mib[i][0] = mab[i][0];
	}
	
	for(int t = 1; t <=lg[n]; t++){
		for(int i = 1; i + (1 << t)-1 <= n; i++){
		
			int mid = i+(1 << (t-1));
			maza[i][t] = max(maza[i][t-1],maza[mid][t-1]);
			mafa[i][t] = max(mafa[i][t-1],mafa[mid][t-1]);
			mifa[i][t] = min(mifa[i][t-1],mifa[mid][t-1]);
			miza[i][t] = min(miza[i][t-1],miza[mid][t-1]);
		}
	}		
	
	for(int t = 1; t <=lg[m]; t++){
		for(int i = 1;  i + (1 << t) - 1<= m; i++){
			int mid = i+(1 << (t-1));
			mab[i][t] = max(mab[i][t-1],mab[mid][t-1]);
			mib[i][t] = min(mib[i][t-1],mib[mid][t-1]);
		}
	}
	while(q--){
		int la,ra,lb,rb;
		cin >> la >> ra >> lb >> rb;
        int sa = lg[ra - la + 1], sb = lg[rb - lb + 1];
        int pa = ra - (1 << sa) + 1, pb = rb - (1 << sb) + 1;
        
        int amax = max(maza[la][sa], maza[pa][sa]);
        int amin = min(mifa[la][sa], mifa[pa][sa]);
        int afmx = max(mafa[la][sa], mafa[pa][sa]);
        int azmn = min(miza[la][sa], miza[pa][sa]);
        int bmax = max(mab[lb][sb], mab[pb][sb]);
        int bmin = min(mib[lb][sb], mib[pb][sb]);

        int ans = -INF;

        gmx(ans, amax * (amax >= 0 ? bmin : bmax));
        gmx(ans, amin * (amin >= 0 ? bmin : bmax));
        if (afmx != -INF)
            gmx(ans, afmx * (afmx >= 0 ? bmin : bmax));
        if (azmn != INF)
            gmx(ans, azmn * (azmn >= 0 ? bmin : bmax));
        printf("%lld\n", ans);
	}
	return 0;
}
