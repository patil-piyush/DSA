#include<iostream>
#include "queue.h"
using namespace std;


void BFS(int g[][7], int start, int n){
    int i = start;
    int u = 0;
    struct Queue q;
    int visited[7] = {0};

    cout<<i<<" ";
    visited[i] = 1;
    q.enqueue(i);

    while(!q.isEmpty()){
        u = q.dequeue();
        for(int v = 1; v<=n; v++){
            if(visited[v] == 0 && g[u][v] == 1){
                cout<<v<<" ";
                visited[v] = 1;
                q.enqueue(v);
            }
        }
    }
}


void DFS(int g[][7], int start, int n){
    static int visited[7] = {0};
    if(visited[start] == 0){
        cout<<start<<" ";
        visited[start] = 1;
        for(int v=1; v<=n; v++){
            if(visited[v] == 0 && g[start][v] == 1){
                DFS(g,v,n);
            }
        }
    }
}

 int main()
 {
    int G[7][7]={{0,0,0,0,0,0,0},
                 {0,0,1,1,0,0,0},
                 {0,1,0,0,1,0,0},
                 {0,1,0,0,1,0,0},
                 {0,0,1,1,0,1,1},
                 {0,0,0,0,1,0,0},
                 {0,0,0,0,1,0,0}};
    DFS(G,1,7);
    
    return 0;
 }