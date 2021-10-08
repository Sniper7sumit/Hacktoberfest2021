#include<bits/stdc++.h>
using namespace std;

void BFS(vector<int> adj, int v){
	
	vector<int> bfs;
	vector<int> vis(v+1,0);	
	
	for(int i = 1; i<=v; i++){
		if(!vis[i]){
			queue<int> q;
			q.push(i);
			vis[i] = 1;
			while(!q.empty()){
				int node = q.front();
				q.pop();
				bfs.push_back(node);
				
				for(auto pp : adj[node]){
					if(!vis[pp]){
						q.push(pp);
						vis[pp] = 1;
					}
				}
				
			}
		}
	}
	
	for(int i = 0; i<bfs.size(); i++){
		cout<<bfs[i]<<" ";
	}
	
}

int main(){
	int n,m;
	cin>> n >> m;
	
	vector<int> adj(n+1,0);
	for(int i = 0; i<m; i++){
		int a,b;
		cin>> a >> b;
		
		adj[a].push_back(b);
		adj[b].push_back(a);		
	}
	
	
	BFS(adj,n);
	
	return 0;
}
