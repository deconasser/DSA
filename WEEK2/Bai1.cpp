#include<bits/stdc++.h>
using namespace std;

#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL)
#define Max (1000000000 + 7)
long long d[1000001];
unsigned long long combination(int n, int k) {
    if (k < 0 || k > n) {
        return 0;
    }

    if (k == 0 || k == n) {
        return 1;
    }

    unsigned long long result = 1;
    if (k > n - k) {
        k = n - k;
    }

    for (int i = 0; i < k; ++i) {
        result *= (n - i);
        result /= (i + 1);
    }

    return result;
}
int main()
{  
	int n; cin >> n;
	int a[n];
	int res = 0;
	for(int i = 0; i < n; i++) cin >> a[i];
	map<int, int> mp;
	for(int i = 0; i < n; i++) {
		mp[a[i]]++;
	}
	for(auto it : mp) {
		res += combination(it.second, 2);
	}
	cout << res;

	return 0;
}