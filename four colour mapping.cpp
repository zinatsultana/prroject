
/**
 * Problem No: 01
 * Name: Four colors Theorem
 */

#include <bits/stdc++.h>
#define SIZE 1001

using namespace std;

int vertex, edge;
vector<int> nodes[SIZE];
int colors[SIZE];

bool BFS(int s) {
    queue<int> color;
    color.push(s);
    colors[s] = 1;

    while(!color.empty()) {
        int actual = color.front();
        color.pop();

        for(int i = 0; i < nodes[actual].size(); i++) {
            int v = nodes[actual][i];

            if(colors[v] == -1) {
                colors[v] = 1 - colors[actual];
                color.push(v);
            }

            if(colors[actual] == colors[v]) {
                return false;
            }
        }
    }

    return true;
}

int main()
{
    int u, v;

    while(scanf("%d", &vertex) && vertex) {
        scanf("%d", &edge);

        for(int i = 0; i < edge; i++) {
            scanf("%d%d", &u, &v);
            nodes[u].push_back(v);
            nodes[v].push_back(u);
        }

        memset(colors, -1, sizeof(colors));

        if(BFS(0)) {
            printf("BICOLORSABLE.\n");
        } else {
            printf("NOT BICOLORSABLE.\n");
        }

        for(int i = 0; i < vertex; i++) {
            nodes[i].clear();
        }
    }

    return 0;
}
