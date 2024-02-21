#include "BallsInBins.h"
#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

BallsInBins::BallsInBins()
{
}

int BallsInBins::ballsInBins()
{
	int solutions[20] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int maxRun2 = 100000;
	double x, y;
	int i;
	int ballsmore[10007];
	unsigned int timeUI;
	timeUI = (unsigned int)(time(NULL));
	srand(timeUI);

	for (int j = 0; j < maxRun2; j++)
	{
		for (i = 0; i < 10007; i++)
		{
			ballsmore[i] = 0;
		}

		for (i = 0; i < 10007; i++)
		{
			ballsmore[rand() % 10007]++;
		}
		int maxi = ballsmore[0];

		for (i = 0; i < 10007; i++)
		{
			if (ballsmore[i] > maxi)
			{
				maxi = ballsmore[i];

			}

		}
		solutions[maxi] = solutions[maxi] + 1;
	}

	for (i = 0; i < 20; i++)
	{

		cout << " Max balls in a bin: " << i << "; " << "Times the solution was hit: " << solutions[i] << endl;
	}
	cout << endl;
	cout << " With 10007 bals & bins: " << endl;
	cout << " Number of times through: " << maxRun2 << endl;
	cout << endl;
	return 0;
}

void BallsInBins::ballsInBinsMore()
{
	int solutions[20] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int maxRun2 = 100000;
	double x, y;
	int i;
	int ballsmore[32768];
	unsigned int timeUI;
	timeUI = (unsigned int)(time(NULL));
	srand(timeUI);
	for (int j = 0; j < maxRun2; j++)
	{
		for (i = 0; i < 10000; i++)
		{
			ballsmore[i] = 0;
		}

		for (i = 0; i < 32768; i++)
		{
			ballsmore[rand() % 32768]++;
		}



		int maxi = ballsmore[0];

		for (i = 0; i < 32768; i++)
		{
			if (ballsmore[i] > maxi)
			{
				maxi = ballsmore[i];

			}

		}
		solutions[maxi] = solutions[maxi] + 1;
	}

	for (i = 0; i < 20; i++)
	{

		cout << " Max balls in a bin: " << i << "; " << "Times the solution was hit: " << solutions[i] << endl;
	}
	cout << endl;
	cout << " With 32768 balls & bins" << endl;
	cout << " Number of times through: " << maxRun2 << endl;

}

void BallsInBins::powerOfTwoChoices()
{
	int solution[20] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int maxRun3 = 100000;
	int y;
	int v;
	int i;
	int balls[10007];
	unsigned int timeUI;
	timeUI = (unsigned int)(time(NULL));
	srand(timeUI);
	for (int j = 0; j < maxRun3; j++)
	{

		for (i = 0; i < 10007; i++)
		{

			balls[i] = 0;
		}

		for (i = 0; i < 10007; i++)
		{

			y = rand() % 10007;
			v = rand() % 10007;
			if (balls[(int)y] > balls[(int)v])
			{
				balls[(int)v]++;
			}
			else if (balls[(int)y] < balls[(int)v])
			{
				balls[(int)y]++;
			}
			else
			{
				balls[(int)y]++;
			}
		}



		int max = balls[0];

		for (i = 0; i < 10007; i++)
		{
			if (balls[i] > max)
			{
				max = balls[i];

			}

		}
		solution[max] = solution[max] + 1;
	}

	for (i = 0; i < 20; i++)
	{

		cout << " Max balls in a bin: " << i << "; " << "Times the solution was hit: " << solution[i] << endl;
	}
	cout << endl;
	cout << " With 10007 balls & bins & 2 choices" << endl;
	cout << " Number of times through: " << maxRun3 << endl;

}

void BallsInBins::powerOfTwoChoicesmore()
{
	int solutions[20] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int maxRun4 = 100000;
	int y;
	int v;
	int i;
	int ballsmore[32768];
	unsigned int timeUI;
	timeUI = (unsigned int)(time(NULL));
	srand(timeUI);
	for (int j = 0; j < maxRun4; j++)
	{
		for (i = 0; i < 32768; i++)
		{
			ballsmore[i] = 0;
		}

		for (i = 0; i < 32768; i++)
		{

			y = rand() % 32768;
			v = rand() % 32768;
			if (ballsmore[(int)y] > ballsmore[(int)v])
			{
				ballsmore[(int)v]++;
			}
			else if (ballsmore[(int)y] < ballsmore[(int)v])
			{
				ballsmore[(int)y]++;
			}
			else
			{
				ballsmore[(int)y]++;
			}
		}



		int maxi = ballsmore[0];

		for (i = 0; i < 32768; i++)
		{
			if (ballsmore[i] > maxi)
			{
				maxi = ballsmore[i];

			}

		}
		solutions[maxi] = solutions[maxi] + 1;
	}

	for (i = 0; i < 20; i++)
	{

		cout << " Max balls in a bin: " << i << "; " << "Times the solution was hit: " << solutions[i] << endl;
	}
	cout << endl;
	cout << " With 32768 balls & bins & 2 choices" << endl;
	cout << " Number of times through: " << maxRun4 << endl;

}


BallsInBins::~BallsInBins()
{
}
