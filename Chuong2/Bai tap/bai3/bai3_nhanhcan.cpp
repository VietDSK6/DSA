#include <bits/stdc++.h>
using namespace std;

struct Item {
    long long weight;
    long long value;
    int id;
};

int n;
long long b;
vector<Item> items;
vector<int> x, bestX;
long long bestValue = 0;

bool cmp(Item u, Item v) {
    return (double)u.value / u.weight > (double)v.value / v.weight;
}

double upperBound(int i, long long currentWeight, long long currentValue) {
    if (currentWeight > b) return 0;

    double bound = currentValue;
    long long remain = b - currentWeight;

    for (int j = i; j < n; j++) {
        if (items[j].weight <= remain) {
            remain -= items[j].weight;
            bound += items[j].value;
        } else {
            bound += (double)items[j].value / items[j].weight * remain;
            break;
        }
    }

    return bound;
}

void Try(int i, long long currentWeight, long long currentValue) {
    if (i == n) {
        if (currentValue > bestValue) {
            bestValue = currentValue;
            bestX = x;
        }
        return;
    }

    if (upperBound(i, currentWeight, currentValue) <= bestValue) {
        return;
    }

    int originalId = items[i].id;

    // Chọn vật i
    if (currentWeight + items[i].weight <= b) {
        x[originalId] = 1;
        Try(i + 1,
            currentWeight + items[i].weight,
            currentValue + items[i].value);
        x[originalId] = 0;
    }

    // Không chọn vật i
    Try(i + 1, currentWeight, currentValue);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> b;

    items.resize(n);
    x.assign(n, 0);
    bestX.assign(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> items[i].weight >> items[i].value;
        items[i].id = i;
    }

    sort(items.begin(), items.end(), cmp);

    Try(0, 0, 0);

    cout << bestValue << '\n';

    for (int v : bestX) {
        cout << v << ' ';
    }

    return 0;
}