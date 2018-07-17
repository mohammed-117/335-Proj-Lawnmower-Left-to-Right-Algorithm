// Assignment 1: Lawnmower Algorithm
// Mohammed Hassnain
// CPSC 335
// Mon,Wed 2:30PM-3:45PM

#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <cstdlib>


using namespace std;

void print_disks(int n, char *disks)
{
	for (int i = 0; i < (2 * n); i++)
	{
		if (disks[i] == 0)
			cout << "D" << " ";
		else
			cout << "L" << " ";
	}


}

int main()
{
	int n, m, k, i, h, z, a, b, c, g, w;
	char *disks;
	char *temp = NULL;
	temp = new char;


	cout << endl << "CPSC 335 x Programming Assignment#1" << endl;
	cout << "The alternating disks problem: lawnmower algorithm\n" << endl;
	cout << "Enter the number of single color disks (light or dark): \n\n" << endl;

	// read the number of disks
	cin >> n;

	// allocate space for the disks
	disks = new char[2 * n];

	// set the initial configurations for the disks to alternate
	for (i = 0; i < n; i++)
	{
		disks[2 * i] = 1;   // light color
		disks[2 * i + 1] = 0;  // dark color
	}

	//print the initial configuration of the list of disks
	cout << "Initial configuration" << endl;

	print_disks(n, disks);

	// reset the number of moves to 0
	m = 0;

	b = n;
	g = n;
	w = n - 1;

	// loop to push the light one before dark ones
	for (k = 0; k < (n / 2); k++)
	{

		h = k + k;
		b = b - 2;
		c = b;
		// develop one for loop for going left to right
		for (z = 0; z<g; z++)
		{
			if (disks[z + h] > disks[z + h + 1])
			{
				*temp = disks[z + h];
				disks[z + h] = disks[z + h + 1];
				disks[z + h + 1] = *temp;
				m++;
				if (h < (n - 1))
				{
					h++;
				}
			}
		}

		g = g - 2;


		// develop one for loop for going right to left
		for (a = w; a > 0; a--)
		{

			if (disks[a + b + 1] < disks[a + b])
			{

				*temp = disks[a + b + 1];
				disks[a + b + 1] = disks[a + b];
				disks[a + b] = *temp;
				m++;
				if (b > 0)
				{
					b--;
				}
			}
		}


		w = w - 2;
		b = c + 2;

	}

	cout << "\n\nAfter moving darker ones to the left: \n" << endl;
	print_disks(n, disks);

	// print the total number of moves
	cout << "\n\nNumber of swaps is " << m << endl;

	// Deallocate the dynamic memory space
	delete[] disks;
	delete temp;

	disks = NULL;
	temp = NULL;

	return 0;
}
