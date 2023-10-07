#include<bits/stdc++.h>

#define fi first
#define se second
#define endl '\n'
#define pb push_back
#define mp make_pair
#define i64 long long
#define PII pair<int,int>
#define PIL pair<int,i64>
#define PLL pair<i64,i64>

using namespace std;

int n,m;

struct DancingLinks{

    static const int MAXN=5e2+5,MAXP=1e4+5;

    struct node{
        int left,right,up,down;
        int row,col;
    };

    int tot=0,colSize;
    node DLX[MAXP];
    int head[MAXN],colCnt[MAXN],ans[MAXN];

    void init(int _colSize){
    	
    	colSize=_colSize;

        for(int i=0;i<=colSize;i++){
            DLX[i].left=i-1;
            DLX[i].right=i+1;

            DLX[i].up=i;
            DLX[i].down=i;

            DLX[i].row=0;
            DLX[i].col=i;
            
            colCnt[i]=0;
        }

        memset(head,0,sizeof(head));

        DLX[0].left=colSize;
        DLX[colSize].right=0;
        tot=colSize;
    }

    void addNode(int r,int c){
        DLX[++tot].row=r; 
        DLX[tot].col=c;

        DLX[tot].up=DLX[c].up; 
        DLX[tot].down=c;

        DLX[DLX[tot].up].down=tot;
        DLX[c].up=tot;

        if(head[r]==0){
            DLX[tot].left=tot;
            DLX[tot].right=tot;

            head[r]=tot;
        }
        else{
            DLX[tot].left=DLX[head[r]].left;
            DLX[tot].right=head[r];

            DLX[DLX[tot].left].right=tot;
            DLX[DLX[tot].right].left=tot;
        }

        colCnt[c]++;
    }

    void remove(int c){
        for(int i=DLX[c].down;i!=c;i=DLX[i].down)
            for(int j=DLX[i].right;j!=i;j=DLX[j].right){
                DLX[DLX[j].down].up=DLX[j].up;
                DLX[DLX[j].up].down=DLX[j].down;

                colCnt[DLX[j].col]--;
            }

        DLX[DLX[c].left].right=DLX[c].right;
        DLX[DLX[c].right].left=DLX[c].left;
    }

    void resume(int c){
        DLX[DLX[c].left].right=c;
        DLX[DLX[c].right].left=c;

        for(int i=DLX[c].up;i!=c;i=DLX[i].up)
            for(int j=DLX[i].left;j!=i;j=DLX[j].left){
                DLX[DLX[j].down].up=j;
                DLX[DLX[j].up].down=j;

                colCnt[DLX[j].col]++;
            }
    }

    bool dance(int dep){
        if(DLX[0].right==0){
            return true;
        }
        int c=DLX[0].right;
        for(int i=DLX[0].right;i!=0;i=DLX[i].right)
            if(colCnt[i]<colCnt[c])
                c=i;

        remove(c);

        for(int i=DLX[c].down;i!=c;i=DLX[i].down){
            ans[dep]=DLX[i].row;
            for(int j=DLX[i].right;j!=i;j=DLX[j].right) remove(DLX[j].col);
            
            if(dance(dep+1)) return true;

            for(int j=DLX[i].left;j!=i;j=DLX[j].left) resume(DLX[j].col);
        }

        resume(c);
        
        return false;
    }
};

int main(){
	freopen("AK019.in","r",stdin);
	freopen("AK019.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
	while(cin >> n){
		
    DancingLinks DL;
    DL.init(26);

    for(int i=1;i<=n;i++) {
    	int m;
    	cin >> m;
    	string s;
    	cin >> s;
    	for(int j = 1; j <= (int)s.length(); j++) {
    		// cout << i << " " << s[j - 1] - 'a' + 1 << "\n";
    		DL.addNode(i, s[j - 1] - 'a' + 1);
    	}
    }

    if(!DL.dance(1)) cout<<"NO"<<endl;
    else cout << "YES" << endl;
	}
    //cin>>n;


    return 0;
}
