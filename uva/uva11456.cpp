//LIS
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define maxn 2100

int ls[maxn];
int dp[maxn];

int main(void)
{
	int cases;

	cin >> cases;

	while(cases--)
	{
		int n;

		cin >> n;

		for(int i = 0; i < n; i++)
		{
			scanf("%d", &ls[i]);
		}
	 
	    memset(dp, 0, n);
	    dp[0] = ls[0];
	    int top = 0;
	 
	    for(int i = 1; i < n; i++)
	    {   
	        int left = 0, right = top;
			bool found = false;

			while(left <= right)
			{
				if(ls[i] > dp[(left+right)/2])	left = (left+right)/2+1;
				else if(ls[i] < dp[(left+right)/2])		right = (left+right)/2-1;
				else if(ls[i] == dp[(left+right)/2])	
				{
					found = true;
					break;
				}
			}
			if(found)	continue;
			dp[right+1] = ls[i];

			if(right == top)	top++;
	    }

	    cout << top+1 << endl;
	}
}