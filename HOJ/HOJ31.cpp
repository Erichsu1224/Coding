#include <iostream>
#include <vector>
using namespace std;

int max(int a, int b)
{
    if(a >= b) return a;
    else return b;
}

int main(int argc, char const *argv[])
{
    int n, m;
    vector <int> lis1;
    vector <int> lis2;
    lis1.push_back(0);
    lis2.push_back(0);

    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        int hold;

        cin >> hold;

        lis1.push_back(hold);
    }

    for(int i = 0; i < m; i++)
    {
        int hold;
        cin >> hold;

        lis2.push_back(hold);
    }

    int dp[n+1][m+1];

    for(int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }

    for(int i = 0; i <= m; i++)
    {
        dp[0][i] = 0;
    }

    for(int i = 1; i <= n; i++)
    {
        for(int k = 1; k <= m; k++)
        {
            if(lis1[i] == lis2[k])
            {
                dp[i][k] = dp[i-1][k-1] + 1;
            }

            else
            {
                dp[i][k] = max(dp[i][k-1], dp[i-1][k]);
            }
        }
    }

    cout << dp[n][m] << endl;

    return 0;
}