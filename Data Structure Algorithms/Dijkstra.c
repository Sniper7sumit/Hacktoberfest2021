#include<stdio.h>
#include<limits.h>
#define v 8

struct dijkstra
{
    int dist;
    int p;
    int visited;
}graph[v];

void initialize(int s){
    for(int i=0;i<v;i++)
    {
        graph[i].dist=INT_MAX;
        graph[i].p=-1;
        graph[i].visited=0;
    }
    graph[s].dist=0;
}

int findMin(){
    int min=INT_MAX;
    int k=-1;
    for(int i=0;i<v;i++)
    {
        if(graph[i].visited==0)
        {
            if(min>graph[i].dist)
            {
                min=graph[i].dist;
                k=i;
            }
        }
    }
    return k;
}

void findPath(int s,int d){
    if(graph[d].p==s)
    {
        printf("%d->%d->",s,d);
        return;
    }
    else
    {
        findPath(s,graph[d].p);
        printf("%d->",d);
    }
}

void relax(int x,int y,int w){
    if(graph[y].dist > (graph[x].dist+w))
    {
        graph[y].dist = graph[x].dist+w;
        graph[y].p=x;
    }
}

void dijkstraFun(int G[v][v],int source){
    initialize(source);
    for(int i=0;i<v;i++)
    {
        int k=findMin();
        for(int j=0;j<v;j++)
        {
            if(G[k][j]!=0)
            {
                relax(k,j,G[k][j]);
            }
        }
        graph[k].visited=1;
    }
}

int main(){
    int G[v][v]={{0,0,4,0,0,7,0,0},
                 {0,0,0,0,9,0,0,3},
                 {4,0,0,3,0,2,9,0},
                 {0,0,3,0,3,0,7,0},
                 {0,9,0,3,0,0,2,7},
                 {7,0,2,0,0,0,8,0},
                 {0,0,9,7,2,8,0,3},
                 {0,3,0,0,7,0,3,0}};
    dijkstraFun(G,0);
    printf("\nThe updated weights for each node are :");
    printf("\nNode\tdist\tparent\tvisited");
    for(int i=0;i<v;i++)
    {
        printf("\n%d-> \t%d \t%d \t%d",i,graph[i].dist,graph[i].p,graph[i].visited);
    }
    printf("\n");
    findPath(0,1);
    return 0;
}
