//============================================================================
// Name        : Exercises.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
//using namespace std;

/*/ Question 19
int main19 ()
{

    int uIn1, uIn2, uIn3, uIn4, uIn5, uMax, uMin;

    std::cout << "Please enter 5 numbers: ";
    std::cin >> uIn1 >> uIn2 >> uIn3 >> uIn4 >> uIn5;

    uMax = uIn1;
    uMin = uIn1;

    if ( uMax <= uIn2 )
    {
        uMax = uIn2;
    }

        if ( uMin >= uIn2 )
        {
        	uMin = uIn2;
        }

    if ( uMax <= uIn3 )
    {
    	uMax = uIn3;
    }

    	if ( uMin >= uIn3 )
    	{
    		uMin = uIn3;
    	}

    if ( uMax <= uIn4 )
    {
    	uMax = uIn4;
    }

    	if ( uMin >= uIn4 )
    	{
    		uMin = uIn4;
    	}

    if ( uMax <= uIn5 )
    {
    	uMax = uIn5;
    }

    	if ( uMin >= uIn5 )
    	{
    		uMin = uIn5;
    	}




    std::cout << "The highest integer is: "
              << uMax << '\n';
    std::cout << "The lowest integer is: "
    		  << uMin << '\n';

}
*/
int main ()
{

	int uIn1, uIn2, uIn3, uIn4, uIn5;
	bool _dupes = false;

	std::cout << "Please enter 5 numbers: ";
	std::cin >> uIn1 >> uIn2 >> uIn3 >> uIn4 >> uIn5;

	if ( uIn1 == uIn2 || uIn2 == uIn3 || uIn3 == uIn4 || uIn4 == uIn5 )
	{
		_dupes = true;
	}
	else if ( uIn1 == uIn3 || uIn1 == uIn5 || uIn2 == uIn4 )
	{
		_dupes = true;
	}
	else if ( uIn1 == uIn5 || uIn1 == uIn4 || uIn2 == uIn5)
	{
		_dupes = true;
	}
	else if ( uIn3 == uIn5 )
		_dupes = true;

	if ( _dupes )
	{
		std::cout << "DUPLICATES";
	}
	else
	{
		std::cout << "ALL UNIQUE";
	}

}
