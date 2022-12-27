#include<bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
/*    for (int n = 1; n <= 101; n++) {
    cout << n << " ";*/
    if (n == 1) {
        cout << "5" << endl;
    } else {
        int cnt = 0, add = 1, nd = 0;
        bool now = true;
        while(1) {
            nd++;
            if (cnt + add >= n) 
                break;
            cnt += add;
            if (now) 
                add *= 9;
            now = !now;
        }
        int it = n - cnt;
        // << it << endl;
        //cout << add << endl;
        string s = "";
        for (int i = 0; i < nd / 2; i++) {
            add /= 9;
            int cal = (it / add);
            if (it == 0)
                cal = 9;
            else if (it % add != 0) {
                //cout << "?????" << endl;
                cal++;
            }
            char a = (cal) + '0';
            s += a;
            it = it % add;
        }
        if (nd & 1) 
            s += "5";
        string tmp;
        for (int j = 0; j < nd / 2; j++) {
            int A = s[j] - '0';
            A = 10 - A;
            char fa = A + '0';
            tmp += fa;
        }
        reverse(tmp.begin(), tmp.end());
        s += tmp;
        cout << s << endl;
    }
    //}
    return 0;
}