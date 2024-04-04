#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

pair<int, int> BFS(vector<vector<int>>& graf, int start, int mdepth) {
    queue<pair<int, int>> q;
    int iterator = 0;
    int depth;
    int max_depth;

    q.push({start, 0});

    vector<bool> visited(graf.size(), false);
    visited[start] = true;

    while (!q.empty()) {
        pair<int, int> current = q.front();

        int currentCastle = current.first;
        depth = current.second;

        q.pop();

        for (int neighbors : graf[currentCastle]) {
            if (!visited[neighbors]) {
                visited[neighbors] = true;
                q.push({neighbors, depth + 1});
            }
        }

        if (depth <= mdepth) {
            iterator++;
        }

        if (depth > mdepth) {
            depth = max_depth;
        }
    }

    return make_pair(depth, iterator - 1);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, m, s, d;
    cin >> n >> m >> s >> d;

    vector<vector<int>> graf(n);

    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        graf[x].push_back(y);
        graf[y].push_back(x);
    }

    pair<int, int> result = BFS(graf, s, floor(d / 2.0));

    cout << result.first << " " << result.second;

    return 0;
}