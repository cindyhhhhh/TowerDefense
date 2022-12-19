#include <stdio.h>
#include<stdlib.h>
#include <algorithm>
#include <stdint.h>
#include <iostream> 
#include <inttypes.h>
#include<string.h>
#include<vector>

using namespace std;

int Towerdistribute(int N, int K, int B, long long A, vector<long long> defense, long long& Max, vector< vector< long long > >&Tower)
{

	int bindex = 0;
	int nbindex = 0;
	long long bindexmax = 0;
	long long nbindexmax = 0;

	/// K = 1時 ///
	for(int i = 0; i < N; i++)
	{
		Tower[0][i] = defense[i];
	}
	for(int i = 0; i < N; i++ )
	{
		if(Tower[0][i] > Max)
		{
			Max = Tower[0][i];
		}
		// printf("%lld\n", Tower[0][i].d);
	}
	if(K == 1)
	{
		return Max;
	}

	/// recursive ///
	for(int i = 1; i < K; i++)
	{
		for(int j = 0; j < N; j++)
		{
			if(i % 2 == 0)///for K = 3,5,7,9...
			{
				if(j == 0)
				{
					Tower[0][j] = defense[0];
					bindex = 0;
					nbindex = 0;
					bindexmax = 0;
					nbindexmax = defense[0];
				}

				else
				{
					///for bonus///
					if(B > 1)
					{
						// if(j - bindex >= B)
						// {
						// 	bindex = j-1;
						// 	bindexmax = Tower[1][j-1] + A*(B-(1)) + defense[j];
						// 	for(int h = 2; h < B && j-h >= 0; h++)
						// 	{
						// 		if((Tower[1][j-h] + A*(B-(h)) + defense[j]) > bindexmax)
						// 		{
						// 			bindexmax = Tower[1][j-h] + A*(B-(h)) + defense[j];
						// 			bindex = j-h;
						// 		}
						// 	}
						// }
						// else
						// {
						if(Tower[1][j-1] + A*(B-(1)) > Tower[1][bindex] + A*(B-(j-bindex)) )
						{
							bindex = j-1;
						}
						// }
						bindexmax = Tower[1][bindex] + A*(B-(j-bindex)) + defense[j];
					}
					

					///for no bonus///

					if(j - B >= 0)
					{
						if (Tower[1][j - B] > Tower[1][nbindex] )
						{
							nbindex = j - B;
						}
					}
					nbindexmax = Tower[1][nbindex] + defense[j];


					///for which to choose///
					Tower[0][j] = max(bindexmax, nbindexmax);
				}
			}
			if(i % 2 == 1)///for K = 3,5,7,9...
			{
				if(j == 0)
				{
					Tower[1][j] = defense[0];
					bindex = 0;
					nbindex = 0;
					bindexmax = 0;
					nbindexmax = defense[0];
				}

				else
				{
					///for bonus///
					if(B > 1)
					{
						// if(j - bindex >= B)
						// {
						// 	bindex = j-1;
						// 	bindexmax = Tower[0][j-1] + A*(B-(1)) + defense[j];
						// 	for(int h = 2; h < B && j-h >= 0; h++)
						// 	{
						// 		if((Tower[0][j-h] + A*(B-(h)) + defense[j]) > bindexmax)
						// 		{
						// 			bindexmax = Tower[0][j-h] + A*(B-(h)) + defense[j];
						// 			bindex = j-h;
						// 		}
						// 	}
						// }
						// else
						// {
						if(Tower[0][j-1] + A*(B-(1)) > Tower[0][bindex] + A*(B-(j-bindex)) )
						{
							bindex = j-1;
						}
						// }
						bindexmax = Tower[0][bindex] + A*(B-(j-bindex)) + defense[j];
					}
					

					///for no bonus///

					if(j - B >= 0)
					{
						if (Tower[0][j - B] > Tower[0][nbindex] )
						{
							nbindex = j - B;
						}
					}
					nbindexmax = Tower[0][nbindex] + defense[j];


					///for which to choose///
					Tower[1][j] = max(bindexmax, nbindexmax);
				}
			}
		}
		if( i % 2 == 1)
		{
			for(int j = 0; j < N; j++ )
			{
				if(Tower[1][j] > Max)
				{
					Max = Tower[1][j];
				}
				// printf("%lld\n", Tower[1][j].d);
			}
		}
		if( i % 2 == 0)
		{
			for(int j = 0; j < N; j++ )
			{
				if(Tower[0][j] > Max)
				{
					Max = Tower[0][j];
				}
				// printf("%lld\n", Tower[0][j].d);
			}
		}
	}
	return Max;

}

int main()
{
	int N;
	int K;
	int B;
	long long A;
	long long Max = 0;
	vector<long long> defense;
	cin >> N;
	cin >> K;
	cin >> A;
	cin >> B;
	vector<vector<long long> > Tower(2, vector<long long>(N));

	long long temp;
	for(int i = 0; i < N; i++)
	{
		cin >> temp;
		defense.push_back(temp);
	}

	long long answer = Towerdistribute(N, K, B, A, defense, Max, Tower);

	printf("%lld\n", answer);

	return 0;
}