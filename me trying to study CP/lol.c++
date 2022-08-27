#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, m, a, b, sum;
    a = 0;
    b = 0;
    sum = 0;
    cin >> N >> m;
    int k[m];
    for (int i = 0; i < m; i++)
    {
        cin >> k[i];
    }
    sort(k, k + m);

    for (int j = 0; j < m; j++)
    {
        a = k[j];
        sum += a;
        if (sum < N)
        {
            b += 1;
        }
        else
        {
            b += 0;
        }
    }
    cout << b;
    return 0;
}