    #include <bits/stdc++.h>
    using namespace std;

    class DSU {
    public:
        vector<int> parent, rank;
        DSU(int n) {
            parent.resize(n);
            rank.resize(n, 0);
            for (int i = 0; i < n; ++i) parent[i] = i;
        }
        int find(int x) {
            if (parent[x] != x) parent[x] = find(parent[x]);
            return parent[x];
        }
        void unite(int x, int y) {
            int xr = find(x), yr = find(y);
            if (xr == yr) return;
            if (rank[xr] < rank[yr]) parent[xr] = yr;
            else if (rank[xr] > rank[yr]) parent[yr] = xr;
            else {
                parent[yr] = xr;
                rank[xr]++;
            }
        }
    };

    int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);

        int t;
        cin >> t;
        while (t--) {
            int n, m1, m2;
            cin >> n >> m1 >> m2;
            DSU dsuF(n), dsuG(n);
            for (int i = 0; i < m2; ++i) {
                int u, v;
                cin >> u >> v;
                dsuG.unite(u - 1, v - 1);
            }
            vector<pair<int, int> > to_remove;
            for (int i = 0; i < m1; ++i) {
                int u, v;
                cin >> u >> v;
                if (dsuG.find(u - 1) != dsuG.find(v - 1)) {
                    to_remove.emplace_back(u - 1, v - 1);
                } else {
                    dsuF.unite(u - 1, v - 1);
                }
            }
            unordered_map<int, unordered_set<int> > compG;
            for (int i = 0; i < n; ++i) {
                int g_root = dsuG.find(i);
                int f_root = dsuF.find(i);
                compG[g_root].insert(f_root);
            }

            int addOp = 0;
            for (auto& [g_comp, f_comps] : compG) {
                addOp += f_comps.size() - 1;  
            }

            int remOp = to_remove.size();
            cout << addOp + remOp << '\n';
        }

        return 0;
    }
