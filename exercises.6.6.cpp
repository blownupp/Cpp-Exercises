/*
 * 6.6.exercises.cpp
 *
 *  Created on: Jan 7, 2017
 *      Author: blown
 */

#include <iostream>
#include <cmath>
//using namespace std;


/*/ Question 20
int main20 ( )
{

	const int MAX_INPUT = 20;
	double sum, uInput, uAverage,
		   uMinSoFar = 0, uMaxSoFar = 0;

	std::cout << "Please enter 20 decimal values (like 2.45 for example): ";

	int count = 0;

	while ( count < MAX_INPUT )
	{
		std::cin >> uInput;
		sum += uInput;

		if ( uMaxSoFar < uInput )
			uMaxSoFar = uInput;

		if ( uMinSoFar > uInput )
			uMinSoFar = uInput;

		count++;
	}
	uAverage = sum / MAX_INPUT;

	std::cout << "Total sum = " << sum << '\n'
			  << "Total average = " << uAverage << '\n'
			  << "Lowest number = " << uMinSoFar << '\n'
			  << "Largest number = " << uMaxSoFar << '\n';


}
*/

#include <iostream>

/*/ Question 21
int main21 ( )
{
	double sum, uInput, uAverage,
		   uMinSoFar = 0, uMaxSoFar = 0;

	std::cout << "Enter any number of decimal integers, a negative value\n"
			  << "will stop the input and compute the totals: ";

	int count = 0;
	bool stopCounting = false;

	while ( !stopCounting )
	{
		std::cin >> uInput;

		if (uInput < 0)
			stopCounting = true;
		else
		{
			sum += uInput;

			if ( uMaxSoFar < uInput )
				uMaxSoFar = uInput;

			if ( uMinSoFar > uInput )
				uMinSoFar = uInput;

			count++;
		}
	}
	uAverage = sum / count;

	std::cout << "Entered numbers: " << count << '\n'
			  << "Total sum = " << sum << '\n'
			  << "Total average = " << uAverage << '\n'
			  << "Lowest number = " << uMinSoFar << '\n'
			  << "Largest number = " << uMaxSoFar << '\n';
}
*/

/* Question 22
int main22()
{
	//Height of tree/rows going up/rows going down
	int uHeight, uRow = 0, dRow;

	// Padding for tree
	char s = '*', n = '\n';

	std::cout << "Please enter a size for the tree: ";
	std::cin >> uHeight;
// Rows building up < Max height twice (minus one, since it's less than)
	while ( uRow < uHeight * 2 )
	{
		int count = 0;
		// If we haven't reached the top of the tree...
		if ( uHeight - uRow >= 0 )
		{//Keep building it up!
			while (count < uRow)
			{
				std::cout << s;
				count++;
			}
			dRow = uRow;
		}
		else
		{//Otherwise, start going DOWN
			count = 0;
			while ( count < dRow - 1 )
			{
				std::cout << s;
				count++;
			}
			dRow--;
		}

		std::cout << n;
		uRow++;
	}

}
*/

/* Question 23 - Reverse 22 ~_~
int main()
{
	//Height of tree/rows going up/rows going down
	int uHeight, uRow = 0, dRow;

	// Padding for tree
	char s = '*', n = '\n', _ = ' ';

	std::cout << "Please enter a size for the tree: ";
	std::cin >> uHeight;
// Rows building up < Max height twice (minus one, since it's less than)
	while ( uRow < uHeight * 2 )
	{
		int count = 0;
		// If we haven't reached the top of the tree...
		if ( uHeight - uRow >= 0 )
		{//Keep building it up!
			while (count < uHeight - uRow)
			{
				std::cout << _;
				count++;
			}

			count = 0;
			while (count < uRow)
			{
				std::cout << s;
				count++;
			}
			dRow = uRow;
		}
		else
		{//Otherwise, start going DOWN
			count = 0;

			while (count <= uHeight - dRow)
			{
				std::cout << _;
				count++;
			}

			count = 0;
			while ( count < dRow - 1 )
			{
				std::cout << s;
				count++;
			}
			dRow--;
		}

		std::cout << n;
		uRow++;
	}

}
*/
int main()
{
	// a^2 + b^2 = c^2
	float a, b, c;

	std::cout << "Please enter side 1 and side 2: ";
	std::cin >> a >> b;

	// a2 + b2 = sqrt(c)
	c = pow(a,2) + pow(b,2);
	c = sqrt(c);

	std::cout << "The length of the hypotenuse is: "
			  << c;

}
