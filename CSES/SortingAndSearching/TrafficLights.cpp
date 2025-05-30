#include <bits/stdc++.h>
using ll = long long;
using namespace std;
void solve(ll X, ll N, ll* P)
{
    set<pair<int, int> > ranges;
    ranges.insert(make_pair(0, X));
    multiset<ll> lengths;
    lengths.insert(X);

    for (int i = 0; i < N; i++) {
        ll pos = P[i];
        auto it = ranges.upper_bound(make_pair(pos, 0));
        it--;
        ll start = it->first, end = it->second;
        ranges.erase(it); lengths.erase(lengths.find(end - start));

        ranges.insert(make_pair(start, pos)); ranges.insert(make_pair(pos, end));
        
        lengths.insert(pos - start); lengths.insert(end - pos);

        cout << *lengths.rbegin() << " ";
    }
}
int main()
{
    ll X, N; cin >> X >> N; 
    ll P[N]; for(int i=0; i<N; i++){ cin >> P[i]; }
    solve(X, N, P); cout << '\n';
    return 0;
}