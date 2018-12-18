//dp
//using binart search to dicrease the complexity
//O(n*n) -> O(nlogn) 

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

//cases1 using standard libriary
/*
int main(int argc, char const *argv[])
{
	int x;
	vector <int> lis;

	cin >> x;

	for(int i = 0; i < x; i++)
	{
		int a;

		cin >> a;

		if(lis.size() == 0 || a > lis.back())
			lis.push_back(a);
		else
			*lower_bound(lis.begin(), lis.end(), a) = a;
	}

	cout << lis.size() << endl;
	return 0;
}
*/

/* using LCS

int max(int a, int b)
{
	if(a >= b) return a;
	else return b;
}

int main(void)
{
	int x;
	vector <int> lis;
	vector <int> lis_s;
	lis.push_back(0);
	lis_s.push_back(0);

	cin >> x;

	for(int i = 0; i < x; i++)
	{
		int hold;
		cin >> hold;

		lis.push_back(hold);
		lis_s.push_back(hold);
	}

	sort(lis_s.begin(), lis_s.end());

	int dp[x+1][x+1];

	for(int i = 0; i <= x; i++)
	{
		dp[i][0] = 0;
		dp[0][i] = 0;
	}

	for(int i = 1; i <= x; i++)
	{
		for(int n = 1; n <= x; n++)
		{
			if(lis[i] == lis_s[n])	dp[i][n] = dp[i-1][n-1] +1;
			else dp[i][n] = max(dp[i][n-1], dp[i-1][n]);
		}
	}

	cout << dp[x][x] << endl;
}

*/

//LIS + binary search
int main(int argc, char const *argv[])
{
    int ls[100050];
    int dp[100050];
    int x;
 
    cin >> x;
 
    for(int i = 0; i < x; i++)
    {
        cin >> ls[i];
    }
 
    memset(dp, 0, x+5);
    dp[0] = ls[0];
    int top = 0;
 
    for(int i = 1; i < x; i++)
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

    //test
    for(int i = 0; i < x; i++)
    {
    	printf("%d ", dp[i]);
    }
    cout << endl;
 
    cout << top+1 << endl;
    return 0;
}

/*
int main(void)
{
	int x;
	int dp[100050];
	int top = 0;

	cin >> x;
	memset(dp, 0, x+2);

	for(int i = 0; i < x; i++)
	{
		int a;
		cin >> a;

		if(i == 0)	
		{
			dp[0] = a;
			continue;
		}


		int left = 0, right = top;
		bool found = false;
		while(left < right)
		{
			if(a > dp[(left+right)/2])	left = (left+right)/2+1;
			else if(a < dp[(left+right)/2])		right = (left+right)/2;
			else if(a == dp[(left+right)/2])	
			{
				found = true;
				break;
			}
		}
		if(found)	continue;
		dp[right+1] = a;

		if(right == top)	top++;
	}

	cout << top+1 << endl;

	return 0;
}
*/
