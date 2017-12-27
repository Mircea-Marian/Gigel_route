#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <cstring>
#include <climits>
 
using namespace std;
 
typedef struct {
    signed short length;
    unsigned short toNode;
} Edge;
 
int main(){
    unsigned short N, M;
    fstream file ("traseu.in", ios::in);
    file >> N >> M;
 
    vector<Edge> graph[N + 2];
    signed short diff[N];
    memset((void*)diff, 0, N * sizeof(signed short));
 
    Edge newEdge;
    unsigned short x, y, i, capacity[N+2][N+2];
    short cost;
    unsigned int rez = 0;
    while(M--){
        file >> x >> y >> cost;
 
        newEdge.toNode = y;
        capacity[x][y] = USHRT_MAX;
        newEdge.length = cost;
        graph[x].push_back(newEdge);
        diff[x-1]++;
 
        newEdge.toNode = x;
        capacity[y][x] = 0;
        newEdge.length = -cost;
        graph[y].push_back(newEdge);
        diff[y-1]--;
 
        rez += cost;
    }
    file.close();
 
    for(i = 1 ; i <= N ; i++){
        if(diff[i-1] < 0){
            newEdge.toNode = i;
            newEdge.length = 0;
            capacity[0][i] = -diff[i-1];
            graph[0].push_back(newEdge);
        }
        if(diff[i-1] > 0){
            newEdge.toNode = N + 1;
            newEdge.length = 0;
            capacity[i][N+1] = diff[i-1];
            graph[i].push_back(newEdge);
        }
    }
 
    N += 2;
    unsigned int distance[N];
    unsigned char parent[N], nOfE;
    bool visited[N];
    vector <Edge>::iterator itGraph;
    do{
        for(i = 1 ; i < N ; i++){
            distance[i] = UINT_MAX;
            visited[i] = false;
        }
 
        distance[0] = 0;
        parent[0] = 0;
        visited[0] = true;
        queue<unsigned short> queue;
        queue.push(0);
        while(!queue.empty()) {
            x = queue.front();
            queue.pop();
            itGraph = graph[x].begin();
            nOfE = graph[x].size();
            while(nOfE--) {
                if(capacity[x][itGraph->toNode] && distance[itGraph->toNode] > distance[x] + itGraph->length){
                    distance[itGraph->toNode] = distance[x] + itGraph->length;
                    parent[itGraph->toNode] = x;
 
                    if(!visited[itGraph->toNode]){
                        queue.push(itGraph->toNode);
                        visited[itGraph->toNode] = true;
                    }
                }
                itGraph++;
            }
            visited[x] = false;
        }
        if(distance[N-1] < UINT_MAX){
            unsigned short flow = UCHAR_MAX;
            y = N - 1;
            while(y) {
                if(flow > capacity[parent[y]][y])
                    flow = capacity[parent[y]][y];
                y = parent[y];
            }
            y = N - 1;
            while(y) {
                capacity[parent[y]][y] -= flow;
                capacity[y][parent[y]] += flow;
                y = parent[y];
            }
            rez += flow * distance[N-1];
        }
    }while(distance[N-1] < UINT_MAX);
 
    file.open("traseu.out", ios::out);
    file << rez;
    file.close();
 
    return 0;
}
