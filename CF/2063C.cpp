#include <iostream>
#include <vector>
#include <set>
using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<set<int> > adj(n + 1);
    
    // Read the m edges and build the adjacency list
    for (int i = 0; i < n-1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    
    // Identify potential pivot nodes based on their degree
    for (int i = 1; i <= n; ++i) {
        if (adj[i].size() == 2) {
            set<int> neighbors = adj[i];
            auto it = neighbors.begin();
            int a = *it;
            int b = *(++it);
            
            // Check if removing node 'i' results in an independent set of neighbors
            if (adj[a].size() == 2 && adj[b].size() == 2 && adj[a].count(b) && adj[b].count(a)) {
                cout << 0 << endl;
                return;
            }
        }
    }

    // Count degree frequencies
    vector<int> degree_count(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        degree_count[adj[i].size()]++;
    }

    // The result depends on degrees of nodes in the graph
    for (int i = 1; i <= n; ++i) {
        if (degree_count[i] == 2) {
            cout << i - 1 << endl;
            return;
        }
    }

    cout << n - 2 << endl;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("/Users/Adity/Downloads/CP/input.txt", "r", stdin);
    freopen("/Users/Adity/Downloads/CP/output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
