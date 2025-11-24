#include <iostream>
#include <vector>
#include <queue>
#include <limits>

constexpr int kInfinite = std::numeric_limits<int>::max() / 2;

// Dijkstra from node 'source', returns dist array
std::vector<int> dijkstra(
    int n,
    std::vector<std::vector<std::pair<int, int>>> const& adj,
    int source
) {
    std::vector<int> distances(n + 1, kInfinite);
    distances[source] = 0;

    std::priority_queue<
        std::pair<int /*distance*/,int /*node*/>,
        std::vector<std::pair<int /*distance*/,int /*node*/>>,
        std::greater<>
    > pq;

    pq.push({ 0, source });

    while (!pq.empty()) {
        auto current = pq.top();
        pq.pop();

        if (current.first > distances[current.second]) {
            continue;
        }

        for (auto [ v, w ] : adj[current.second]) {
            if (distances[v] > distances[current.second] + w) {
                distances[v] = distances[current.second] + w;
                pq.push({ distances[v], v });
            }
        }
    }

    return distances;
}

int main() {
    // Example graph (1-based):
    // 1 -> 2 (1), 1 -> 3 (4), 2 -> 3 (2), 3 -> 4 (1)
    int n = 4;
    std::vector<std::vector<std::pair<int, int>>> adj(n + 1);
    adj[1].push_back({ 2, 1 });
    adj[1].push_back({ 3, 4 });
    adj[2].push_back({ 3, 2 });
    adj[3].push_back({ 4, 1 });

    int source = 1;
    auto distances = dijkstra(n, adj, source);
    std::cout << "Dijkstra from 1:\n";
    for (int i = 1; i <= n; ++i) {
        std::cout << "distances[1->" << i << "] = " << distances[i] << "\n";
    }
    // Expected output:
    // distances[1 -> 1] = 0
    // distances[1 -> 2] = 1
    // distances[1 -> 3] = 3 (1 -> 2 -> 3)
    // distances[1 -> 4] = 4 (1 -> 2 -> 3 -> 4)
}
