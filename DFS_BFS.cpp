#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void DFS(int node, vector<int> adj[], vector<bool> &visited) {
    visited[node] = true;
    cout << node << " ";
    for (int next : adj[node]) {
        if (!visited[next])
            DFS(next, adj, visited);
    }
}

void BFS(int start, vector<int> adj[], int n) {
    vector<bool> visited(n, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int next : adj[node]) {
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }
}

int main() {
    int n = 4;
    vector<int> adj[n];
    adj[0] = {1, 2};
    adj[1] = {0, 3};
    adj[2] = {0};
    adj[3] = {1};

    vector<bool> visited(n, false);
    cout << "DFS starting from node 0:\n";
    DFS(0, adj, visited);


    cout << "BFS starting from node 0:\n";
    BFS(0, adj, n);
    return 0;
}