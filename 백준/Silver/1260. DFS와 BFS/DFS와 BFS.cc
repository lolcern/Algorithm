#include<stdio.h>

int N, graph[1001][1001] = {0, }, visit[1001] = {0, }, queue[1001];

void dfs(int V) {
    visit[V] = 1;
    printf("%d ", V);
    for(int i=1; i<=N; i++) if(graph[V][i] && !visit[i]) dfs(i);
}

void bfs(int V) {
    int front = 0, rear = 1, pop;
    visit[V] = 1;
    printf("%d ", V);
    queue[0] = V;
    while(front < rear) {
        pop = queue[front++];
        for(int i=1; i<=N; i++)
            if(graph[pop][i] && !visit[i]) {
                visit[i] = 1;
                printf("%d ", i);
                queue[rear++] = i;
            }
    }
}

int main() {
    int M, V, x, y;
    scanf("%d %d %d", &N, &M, &V);
    for(int i=0; i<M; i++) {
        scanf("%d %d", &x, &y);
        graph[x][y] = 1;
        graph[y][x] = 1;
    }
    visit[V] = 1;
    dfs(V);
    for(int i=1; i<=N; i++) visit[i] = 0;
    visit[V] = 1;
    printf("\n");
    bfs(V);
}