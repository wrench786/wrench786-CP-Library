#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define nn "\n"

const int N = 1e3+7;

char g[N][N];
int dx[]={+1,-1,+0,+0};
int dy[]={+0,+0,+1,-1};
int villain[N][N];
int hero[N][N];

int n,m;

bool check(int nxt_x, int nxt_y){
    if(nxt_x>=0 && nxt_x<n && nxt_y>=0 && nxt_y<m) return true;
    return false;
}

void solve(){
    cin>>n>>m;

    int x1,y1,x2,y2;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            villain[i][j]=0;
            hero[i][j]=0;
            cin>>g[i][j];

            if(g[i][j]=='H'){
                x1 = i;
                y1 = j;
            }
            if(g[i][j]=='V'){
                x2 = i;
                y2 = j;
            }
        }
    }
    
    int h=1,v=1;

    villain[x2][y2]=0;
    queue<pair<int,int>>q;
    q.push({x2,y2});
    while(!q.empty()){
        auto p = q.front();
        q.pop();

        int x = p.first;
        int y = p.second;

        for(int i=0;i<4;i++){
            int nxt_x = x + dx[i];
            int nxt_y = y + dy[i];

            if( check(nxt_x,nxt_y) && g[nxt_x][nxt_y]=='.'){
                v++;
                g[nxt_x][nxt_y] = 'c';
                villain[nxt_x][nxt_y] = villain[x][y]+1;
                q.push({nxt_x,nxt_y});
            }
        }
    }

    hero[x1][y1]=0;
    // queue<pair<int,int>>q;
    // q.clear();
    q.push({x1,y1});
    while(!q.empty()){
        auto p = q.front();
        q.pop();

        int x = p.first;
        int y = p.second;

        for(int i=0;i<4;i++){
            int nxt_x = x + dx[i];
            int nxt_y = y + dy[i];

            if( check(nxt_x,nxt_y)){
                if(g[nxt_x][nxt_y]=='.'){
                    g[nxt_x][nxt_y] = '#';
                    h++;
                    hero[nxt_x][nxt_y] = hero[x][y]+1;
                    q.push({nxt_x,nxt_y});
                }
                else if(g[nxt_x][nxt_y]=='c' && villain[nxt_x][nxt_y]>(hero[x][y]+1)*2){
                    g[nxt_x][nxt_y] = '#';
                    h++;
                    v--;
                    hero[nxt_x][nxt_y] = hero[x][y]+1;
                    q.push({nxt_x,nxt_y});
                }
            }
        }
    }
    cout<<v<<" "<<h<<nn;

}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // freopen("reduce.in", "r", stdin);
    // freopen("reduce.out", "w", stdout);
    int tc=1;
    //cin>>tc;
    
    //int cases=0;
    while(tc--){
        //cout<<"Case "<<++cases<<": ";
        solve();
    }
    return 0;
}