#include<stdio.h>
#include<limits.h>
#include<stdbool.h>

#define V 6

void printSolution(int value[], int parent[]){
    printf("Vertex \t\t Distance From Source\n");
    int i;
    for(i=0;i<V;i++){
        printf("%d \t\t %d\n",i,value[i]);
    }
    printf("\n\n");
    for(i=1;i<V;i++){
        printf("%d -> %d \t",parent[i],i);
    }
}

int selectMinVertex(bool processed[], int value[]){
    int i, vertex;
    int min = INT_MAX;
    
    for(i=0;i<V;i++){
        if(processed[i]==false && value[i]<min){
            min = value[i];
            vertex=i;
        }
    }
    return vertex;
}

void dijkstra(int graph[V][V], int src){
    bool processed[V];
    int value[V];
    int parent[V];
    int i;
    for(i=0;i<V;i++){
        processed[i]=false; //processed =>> {f,f,f,f,f,f}
        value[i]=INT_MAX; //value => {inf,inf,inf,inf,inf,inf}
    }
    value[src]=0; //value => {0,inf,inf,inf,inf,inf}
    parent[src]=-1;//parent => {-1,-1,-1,-1,-1,-1}
    
    for(i=0;i<V-1;i++){
        int j;
        int U=selectMinVertex(processed,value); //selectMinVertex(processed,value)
        processed[U]=true;
        
        for(j=0;j<V;j++){
            if(graph[U][j]!=0 && processed[j]==false && value[U]!=INT_MAX && value[U] + graph[U][j]<value[j] ){
                value[j]=value[U]+graph[U][j];
                parent[j]=U;
            }
        }
    }
    printSolution(value,parent);
}

void main(){
    int graph[V][V] = { {0, 1, 4, 0, 0, 0},
						{1, 0, 4, 2, 7, 0},
						{4, 4, 0, 3, 5, 0},
						{0, 2, 3, 0, 4, 6},
						{0, 7, 5, 4, 0, 7},
						{0, 0, 0, 6, 7, 0} };
    dijkstra(graph,0);
}
