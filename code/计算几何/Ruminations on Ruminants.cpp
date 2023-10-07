#include <bits/stdc++.h>
const int N = 3e3 + 5;
const double eps = 1e-12;

using namespace std;
struct point {
	double x, y;
	point() {}
	point(double _x, double _y): x(_x), y(_y) {}
};
struct line {
	double a, b, c;
	line() {}
	line(double _a, double _b, double _c): a(_a), b(_b), c(_c) {}
} l[N];
int n;
point h[N];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		double a, b, c;
		cin >> a >> b >> c;
		h[i] = point(-a * c / (a * a + b * b), -b * c / (a * a + b * b));
//		cout << h[i].x << " " << h[i].y << endl;
	}
	long long ans = 0;
	for(int i = 1; i <= n; i++){
		vector<double> k;
		int cnt = 0;
		for(int j = i+1; j <= n; j++){
			double dx = h[i].x - h[j].x,dy = h[i].y - h[j].y;
//			cout << dx << " "<< dy << endl;
			if(fabs(dx) < eps){
				if(fabs(dy) < eps){
					ans += n-i-1-cnt;
					cnt += 1;
				}else{
					k.push_back(1e100);
				}
			}else{
				k.push_back(dy/dx);
			}
		}
//		cout << cnt << endl;
		sort(k.begin(),k.end());
		int pre = 0;
		for(int j = 0; j < k.size(); j++){
			if(j == 0 || fabs(k[j] - k[j-1]) >= eps) pre = j;
//			cout << pre << endl;
			if(j == (int)k.size()-1 || fabs(k[j] - k[j+1]) >= eps){
				int sum = j - pre+1;
//				cout << sum << endl;
				ans += 1ll*sum * (sum-1) / 2;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
