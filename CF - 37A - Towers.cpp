#include<bits/stdc++.h>
using namespace std;
#define AMAX (int)1e3 + 5

int main()
{
	int N, Tower[AMAX], height = 1, count = 1, h = 1;
	cin >> N;
	for(int i = 0 ; i < N; ++i)
	{
		cin >> Tower[i];
	}
	sort(Tower, Tower + N);
	
	for(int i = 1; i < N; ++i)
	{
		if(Tower[i] == Tower[i - 1])
		{
			h++;
			if(h > height)
			{
				height = h;
			}
		}
		else
		{
			h = 1;
			count++;
		}
	}
	cout << height << " " << count << endl;
  return 0;
}
