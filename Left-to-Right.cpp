// Assignment 1: left-to-right Algorithm
// Mohammed Hassnain
// CPSC 335
// Mon,Wed 2:30PM-3:45PM


#include <iostream>
#include <iomanip>
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
	int n, m, k, i, z, h, g;
	char *disks;


	cout << endl << "CPSC 335 x Programming Assignment #1" << endl;
	cout << "The alternating disks problem: left-to-right algorithm\n" << endl;
	cout << "Enter an even number of single color disks(light or dark): \n" << endl;

	cin >> n;    // Read the number of disks.

	 //dynamically allocating a char array of size[2*n]

	disks = new char[2 * n];

	// set the initial configuration for the disks to alternate
	for (i = 0; i < n; i++)
	{
		disks[2 * i] = 1; // 1 light color disk
		disks[2 * i + 1] = 0; // 0 dark color disk
	}

	cout << "Initial configuration " << endl;
	print_disks(n, disks);

	// reset the number of moves to 0;
	m = 0;


	char *temp = NULL;
	temp = new char;


	g = n;
	// loop to push dark ones before light ones
	for (k = 0; k < n; k++)
	{

		h = k;
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
		g = g - 1;
	}


	cout << "\n\nAfter moving darker ones to the left\n" << endl;
	print_disks(n, disks);

	// print the total number of moves
	cout << "\n\nNumber of swaps is: " << m << endl;

	// Deallocate the dynamic memory space
	delete[] disks;
	delete temp;

	disks = NULL;
	temp = NULL;
	return 0;
}