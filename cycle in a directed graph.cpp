#include<bits/stdc++.h> 
using namespace std;
bool isCyclicUtil(int v,vector<bool>visited, vector<bool> &recStack,list<int>adj[]) 
{ 
    int next;
    list<int>::iterator i;
	if(visited[v] == false) 
	{  
		visited[v] = true; 
		recStack[v] = true; 
     
		for(i = adj[v].begin(); i!=adj[v].end(); ++i) 
		{ 
		    next=*i;
			if ( visited[next]==false && isCyclicUtil(next, visited, recStack,adj)==true ) 
				return true; 
			else if (recStack[next]==true) 
				return true; 
		} 

	} 
	recStack[v] = false; 
	return false; 
} 
bool isCyclic(list<int>adj[],int v,int e) 
{  
    vector<bool>visited(v+1);
    vector<bool>recStack(v+1);
	for(int i = 0; i < v; i++) 
	{ 
		visited[i] = false; 
		recStack[i] = false; 
	} 
	for(int i = 0; i < v; i++) 
		if (isCyclicUtil(i, visited, recStack,adj)==true) 
			return true; 

	return false; 
} 

int main() 
{ 
    int v,e,i,x,y;
    bool ans;
    cin>>v>>e;
   list<int>adj[v];
   for(i=0;i<e;i++)
   {
       cin>>x>>y;
       adj[x].push_back(y);
   }
   ans=isCyclic(adj,v,e);
	if(ans==true) 
		cout << "Graph contains cycle"; 
	else
		cout << "Graph doesn't contain cycle"; 
	return 0; 
} 