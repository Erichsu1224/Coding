//HOJ41
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int main(void)
{
	int mana, n;
	vector<int> lis_ex;
	vector<int> lis_ma;

	cin >> mana >> n;

	for(int i = 0; i < n; i++)
	{
		cin >> lis_ex[i] >> lis_ma[i];
	}

	sort(lis_ex.begin(), lis_ex.end());
	
	return 0;
}