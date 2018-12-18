#include <iostream>
#include <cstring>
using namespace std;

int min(int a, int b)
{
    if(a >= b) return b;
    else return a;
}

int main(int argc, char const *argv[])
{
    int n;
    int ls[1000050];
    int dp[100050];
    int a, b;

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &ls[i]);
    }

    memset(dp, 0, n+5);
    dp[0] = ls[0];
    int top = 0;
 
    for(int i = 1; i < n; i++)
    {   
        int left = 0, right = top;
        bool found = false;

        while(left <= right)
        {
            if(ls[i] > dp[(left+right)/2])  left = (left+right)/2+1;
            else if(ls[i] < dp[(left+right)/2])     right = (left+right)/2-1;
            else if(ls[i] == dp[(left+right)/2])    
            {
                found = true;
                break;
            }
        }
        if(found)   continue;
        dp[right+1] = ls[i];

        if(right == top)    top++;
    }
    
    a = top+1;

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &ls[i]);
    }

    memset(dp, 0, n+5);
    dp[0] = ls[0];
    top = 0;
 
    for(int i = 1; i < n; i++)
    {   
        int left = 0, right = top;
        bool found = false;

        while(left <= right)
        {
            if(ls[i] > dp[(left+right)/2])  left = (left+right)/2+1;
            else if(ls[i] < dp[(left+right)/2])     right = (left+right)/2-1;
            else if(ls[i] == dp[(left+right)/2])    
            {
                found = true;
                break;
            }
        }
        if(found)   continue;
        dp[right+1] = ls[i];

        if(right == top)    top++;
    }
    
    b = top+1;

    cout << min(a, b) << endl;

    return 0;
}