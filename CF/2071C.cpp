#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Start Link
// https://t.me/coderhelpp

int num1;
vector<int> elements;
vector<ll> xorOc;
vector<int> xorPrefix;
vector<ll> cumulativeXor;
ll totalSum;
int xorT;

struct DataNode {
    ll value;
    int parity;
};

unordered_map<ll, DataNode> funcCache;
unordered_map<ll, int> xorCache;

struct Interval {
    ll left, right;
    bool operator==(const Interval &o) const { return left == o.left && right == o.right; }
};
struct IntervalHash {
    size_t operator()(const Interval &k) const {
        auto hash1 = hash<ll>()(k.left), hash2 = hash<ll>()(k.right);
        return hash1 ^ (hash2 + 0x9e3779b97f4a7c15LL + (hash1 << 6) + (hash1 >> 2));
    }
};
unordered_map<Interval, ll, IntervalHash> sumCache;

int baseVal;

int computeXor(ll index) {
    if (index <= num1)
        return xorPrefix[index];
    if (xorCache.count(index))
        return xorCache[index];
    int result = (index & 1LL) ? baseVal : (baseVal ^ computeXor(index / 2));
    xorCache[index] = result;
    return result;
}

ll computeSum(ll left, ll right) {
    if (left > right)
        return 0;
    if (right <= num1)
        return cumulativeXor[right] - cumulativeXor[left - 1];
    if (left <= num1)
        return (cumulativeXor[num1] - cumulativeXor[left - 1]) + computeSum(num1 + 1, right);
    

    Interval key{left, right};
    if (sumCache.count(key))
        return sumCache[key];
    
    ll total = right - left + 1;
    ll evenCount = right / 2 - (left - 1) / 2;
    ll oddCount = total - evenCount;
    ll result = oddCount * baseVal;
    
    ll newLeft = (left % 2 == 0 ? left / 2 : (left + 1) / 2);
    ll newRight = right / 2;
    result += (baseVal == 0 ? computeSum(newLeft, newRight) : evenCount - computeSum(newLeft, newRight));

    sumCache[key] = result;
    return result;
}

DataNode calculateFunction(ll index) {
    if (index <= num1)
        return {xorOc[index], xorPrefix[index]};
    if (funcCache.count(index))
        return funcCache[index];
    
    ll maxVal = index / 2;
    ll pivot = (num1 + 1) / 2;
    ll temp1 = 0;
    if ((num1 + 1) & 1)
        temp1 = computeXor(pivot);
    
    ll lowerBound = ((num1 + 1) & 1 ? pivot + 1 : pivot);
    ll upperBound = (index & 1LL ? maxVal : maxVal - 1);
    ll middleSum = (lowerBound <= upperBound ? 2 * computeSum(lowerBound, upperBound) : 0);
    
    int temp2 = (index & 1LL ? 0 : computeXor(maxVal));
    ll totalResult = totalSum + temp1 + middleSum + temp2;
    int parity = (index & 1LL ? baseVal : (baseVal ^ computeXor(index / 2)));

    funcCache[index] = {totalResult, parity};
    return {totalResult, parity};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int testCases;
    cin >> testCases;
    while (testCases--) {
        cin >> num1;
        ll leftRange, rightRange;
        cin >> leftRange >> rightRange;

        elements.resize(num1 + 1);
        xorOc.assign(num1 + 1, 0);
        xorPrefix.assign(num1 + 1, 0);
        cumulativeXor.assign(num1 + 1, 0);

        for (int i = 1; i <= num1; i++)
            cin >> elements[i];

        xorOc[0] = 0;
        xorPrefix[0] = 0;
        cumulativeXor[0] = 0;

        for (int i = 1; i <= num1; i++) {
            xorOc[i] = xorOc[i - 1] + elements[i];
            xorPrefix[i] = xorPrefix[i - 1] ^ elements[i];
            cumulativeXor[i] = cumulativeXor[i - 1] + xorPrefix[i];
        }

        totalSum = xorOc[num1];
        xorT = xorPrefix[num1];

        funcCache.clear();
        xorCache.clear();
        sumCache.clear();
        baseVal = ((num1 + 1) & 1 ? xorT ^ computeXor((num1 + 1) / 2) : xorT);

        DataNode resultRight = calculateFunction(rightRange), resultLeft = calculateFunction(leftRange - 1);
        cout << resultRight.value - resultLeft.value << "\n";
    }
}