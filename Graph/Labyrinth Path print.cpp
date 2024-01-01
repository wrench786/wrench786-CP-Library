#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
#define nn "\n"
 
const int N = 1e3+7;
string g[N];
bool vis[N][N];
char path[N][N];
int dx[]={+1,-1,+0,+0};
int dy[]={+0,+0,+1,-1};
int n,m;
 
void solve(){
    cin>>n>>m;
 
    for(int i=0;i<n;i++){
        cin>>g[i];
    }
    int sx,sy, ex,ey;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            path[i][j]='.';
            if(g[i][j]=='A'){
                sx = i;
                sy = j;
            }
            if(g[i][j]=='B'){
                ex = i;
                ey = j;
            }
        }
    }
 
    map<pair<int,int>,int>d;
    queue<pair<int,int>>q;
    q.push({sx,sy});
 
    while(!q.empty()){
        pair<int,int>u = q.front();
        q.pop();
 
        int i = u.first;
        int j = u.second;
 
        for(int d=0;d<4;d++){
            int x = i+dx[d];
            int y = j+dy[d];
            if(x>=0 && y>=0 && x<n && y<m && !vis[x][y] && (g[x][y]!='#')){
                if(i<x) path[x][y] = 'D'; 
                if(i>x) path[x][y] = 'U'; 
                if(j<y) path[x][y] = 'R'; 
                if(j>y) path[x][y] = 'L';
                vis[x][y] = 1;
                q.push({x,y});
            }
        }
    }
 
    if(!vis[ex][ey]) cout<<"NO"<<nn;
    else{
        cout<<"YES"<<nn;
        vector<char>ans;
 
        int x = ex;
        int y = ey;
 
        while(1){
            if(x==sx && y==sy) break;
            char yo = path[x][y];
            ans.push_back(yo);
 
            if(yo=='D') x--;
            if(yo=='U') x++;
            if(yo=='L') y++;
            if(yo=='R') y--;
        }
        reverse(ans.begin(),ans.end());
        cout<<(int)ans.size()<<nn;
        for(auto x:ans){
            cout<<x;
        }
        cout<<nn;
    }
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