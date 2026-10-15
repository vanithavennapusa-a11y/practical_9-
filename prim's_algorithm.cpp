
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int n, edges;
    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> edges;

    vector<vector<int>> graph(n, vector<int>(n, 0));

    cout << "Enter edges (source destination weight):\n";

    for (int i = 0; i < edges; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        graph[u][v] = w;
        graph[v][u] = w;
    }

    vector<int> key(n, INT_MAX);
    vector<int> parent(n, -1);
    vector<bool> visited(n, false);

    key[0] = 0;
    int totalWeight = 0;

    cout << "\nMinimum Spanning Tree:\n";

    for (int count = 0; count < n; count++) {
        int u = -1;

        for (int i = 0; i < n; i++) {
            if (!visited[i] &&
                (u == -1 || key[i] < key[u])) {
                u = i;
            }
        }

        if (u == -1 || key[u] == INT_MAX) {
            cout << "Graph is disconnected.\n";
            return 0;
        }

        visited[u] = true;

        if (parent[u] != -1) {
            cout << parent[u] << " - " << u
                 << " : " << key[u] << "\n";

            totalWeight += key[u];
        }

        for (int v = 0; v < n; v++) {
            if (graph[u][v] > 0 &&
                !visited[v] &&
                graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    cout << "Total weight of MST: "
         << totalWeight << "\n";

    return 0;
}
```
