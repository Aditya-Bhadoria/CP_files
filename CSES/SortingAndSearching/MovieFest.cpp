#include <bits/stdc++.h>
using namespace std;
int solve(vector<pair<int, int>>& movies, int N) {
    sort(movies.begin(), movies.end(), [](const pair<int, int>& p1, const pair<int, int>& p2) {
        return p1.second < p2.second; 
    });
    int timeElapsed = 0, ans = 0;
    for (int i = 0; i < N; i++) {
        if (movies[i].first >= timeElapsed) {
            ans++;
            timeElapsed = movies[i].second; 
        }
    }
    return ans;
}

int main() {
    int n; cin >> n;
    vector<pair<int, int>> movies;
    for(int i=0; i<n; i++){
        int a, b; cin >> a >> b;
        movies.push_back(make_pair(a,b));
    }
    cout << solve(movies, n) << endl;

    return 0;
}