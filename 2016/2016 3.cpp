#include<bits/stdc++.h>
using namespace std;

#define int long long

int l;
int p, q;

vector<bool> sOErastothenes() {
    vector<bool> prime(l + 1, true);
    prime[0] = false; prime[1] = false;
    for (int i = 0; i < prime.size(); i++) {
        if (prime[i]) {
            //cout << i << '\n';
            int it = i + i;
            while (it < prime.size()) {
                prime[it] = false;
                it += i;
            }
        }
    } 
    return prime;
}

int bfs(vector<bool> &prime) {
    deque<pair<int, int>> que;
    map<int, bool> used;
    que.push_back({p, 1});
    while(!que.empty()) {
        auto p = que.front();
        que.pop_front();
        //cout << p.first << '\n';
        if (used[p.first])
            continue;
        used[p.first] = true;
        if (p.first == q)
            return p.second;
        for (int i = 0; (1 << i) <= l; i++) {
            int power2 = (1 << i);
            if (p.first + power2 <= l && prime[p.first + power2]) {
                que.push_back({p.first + power2, p.second + 1});
            }
            if (p.first - power2 >= 2 && prime[p.first - power2]) {
                que.push_back({p.first - power2, p.second + 1});
            }
        }
    }
}

int32_t main() {
    cin >> l;
    cin >> p; cin >> q;
    vector<bool> prime = sOErastothenes();
    cout << bfs(prime) << '\n';
	return 0;
}
