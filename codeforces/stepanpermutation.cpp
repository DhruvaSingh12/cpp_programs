#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, x, y;
        cin>>n>>x>>y;

        vector<int> p(n);
        vector<vector<int>> adj(n);
        for(int i=0; i<n; i++) cin>>p[i];

        for(int i=0; i<n; i++){
            if(i+x<n){
                adj[i].push_back(i+x);
                adj[i+x].push_back(i);
            }
            if(i+y<n){
                adj[i].push_back(i+y);
                adj[i+y].push_back(i);
            }
        }

        vector<int> vec(n, -1);
        int id=0;

        for(int i=0; i<n; i++){
            if(vec[i]!=-1) continue;

            queue<int> q;
            q.push(i);
            vec[i]=id;

            while(!q.empty()){
                int u=q.front();
                q.pop();
                for(int v:adj[u]){
                    if(vec[v]==-1){
                        vec[v]=id;
                        q.push(v);
                    }
                }
            }
            id++;
        }

        bool flag=true;
        for(int i=0; i<n; i++){
            if(vec[i]!=vec[p[i]-1]){
                flag=false;
                break;
            }
        }
        cout<<(flag ? "YES":"NO")<<'\n';
    }
    return 0;
}