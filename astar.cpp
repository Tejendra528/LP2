#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

#define ROW 5
#define COL 5

struct Node {
    int x, y;
    int g, h;
    Node* parent;

    Node(int x, int y, int g, int h, Node* p = nullptr) :
        x(x), y(y), g(g), h(h), parent(p) {}

    int f() const { return g + h; }
};

struct Compare {
    bool operator()(const Node* a, const Node* b) {
        return a->f() > b->f();
    }
};

bool isValid(int x, int y, vector<vector<int>>& grid) {
    return x >= 0 && x < ROW && y >= 0 && y < COL && grid[x][y] == 0;
}

int heuristic(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);  // Manhattan distance
}

void printPath(Node* node) {
    if (!node) return;
    printPath(node->parent);
    cout << "(" << node->x << "," << node->y << ") ";
}

void aStarSearch(vector<vector<int>>& grid, pair<int, int> start, pair<int, int> goal) {
    priority_queue<Node*, vector<Node*>, Compare> open;
    vector<vector<bool>> visited(ROW, vector<bool>(COL, false));

    Node* startNode = new Node(start.first, start.second, 0, heuristic(start.first, start.second, goal.first, goal.second));
    open.push(startNode);

    int dx[] = { -1, 1, 0, 0 };
    int dy[] = { 0, 0, -1, 1 };

    while (!open.empty()) {
        Node* current = open.top(); open.pop();

        if (visited[current->x][current->y])
            continue;

        visited[current->x][current->y] = true;

        if (current->x == goal.first && current->y == goal.second) {
            cout << "Path found: ";
            printPath(current);
            cout << "\nTotal cost: " << current->f() << endl;
            return;
        }

        for (int i = 0; i < 4; i++) {
            int nx = current->x + dx[i], ny = current->y + dy[i];
            if (isValid(nx, ny, grid) && !visited[nx][ny]) {
                int gNew = current->g + 1;
                int hNew = heuristic(nx, ny, goal.first, goal.second);
                open.push(new Node(nx, ny, gNew, hNew, current));
            }
        }
    }

    cout << "No path found.\n";
}

int main() {
    vector<vector<int>> grid = {
        { 0, 1, 0, 0, 0 },
        { 0, 1, 0, 1, 0 },
        { 0, 0, 0, 1, 0 },
        { 0, 1, 0, 0, 0 },
        { 0, 0, 0, 1, 0 }
    };

    pair<int, int> start = { 0, 0 };
    pair<int, int> goal = { 4, 4 };

    aStarSearch(grid, start, goal);
    return 0;
}
