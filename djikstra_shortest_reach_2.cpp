#include<bits/stdc++.h>

using namespace std;
#define pb push_back
#define mp make_pair
#define fi first
#define se second 
#define ll long long int
#define inf 100007

typedef pair<int,int> pii;
typedef vector<pii> vii;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int t;
    cin>>t;
    while(t--){
        int n,m,x,y,r,i,j,a,b,c,d;
        cin>>n>>m;
        vii v[n+5];
        for(i=0;i<m;i++){
            cin>>x>>y>>r;
            (v[x]).pb(mp(y,r));
            (v[y]).pb(mp(x,r));
        }
        int src;
        cin>>src;
        
        int dist[n+5];
        for(i=1;i<=n;i++)dist[i]=inf;
        
        dist[src] = 0;
        
        set<pii>s;
        s.insert(mp(0,src));
        
        pii temp;
        
        while(!s.empty()){
            temp = *(s.begin());
            s.erase(s.begin());
            a = temp.fi; b = temp.se;
            for(i=0;i<v[b].size();i++){
                c = (v[b][i]).fi; d = (v[b][i]).se;
                
                if(dist[c] > dist[b] + d){
                    
                    if(dist[c] != inf)s.erase(s.find(mp(dist[c],c)));
                    
                    dist[c] = dist[b]+d;
                    s.insert(mp(dist[c],c));
                    
                }
                
            }
        }
        
        for(i=1;i<=n;i++){
            if(i != src){
                if(dist[i] != inf)cout<<dist[i]<<" ";
                else
                    cout<<"-1 ";
            }
        }
      cout<<endl;  
    }
    
    return 0;
}
