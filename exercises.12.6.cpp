/*
 *     Fundamentals of C++ Programming
 *				12.6 Exercises
 *	
 *			  Date: 01-12-2017
 *		    Author: Chris Stromski 
 *			(cstromski@gmail.com)
 */

#include <iostream>
#include <vector>
#include <ctime>

#define SIZE 10

void print(const std::vector<int>& v)
{
	if (v.size() != 0)
	{
		int end = v.size();
		std::cout << '{';
		for (int i = 0; i < end; i++)
			std::cout << v[i] << ',';
		std::cout << '}' << '\n';
	}
}

/* Question 1
 *
 *   Complete the following function that reorders the contents of a vector 
 * so they are reversed from their original order. For example, a vector 
 * containing the elements 2, 6, 2, 5, 0, 1, 2, 3 would be transformed into 
 * 3, 2, 1, 0, 5, 2, 6, 2. Note that your function must physically rearrange 
 * the elements within the vector, not just print the elements in reverse order. 
 *
 *
void reverse(std::vector<int>& v)
{
	int end = v.size() - 1;

	// Nothing to do...
	if (v.empty())
		return;

	// Start at the beginning, cycle through loop and swap
	// each progressive index with element at (end - i)
	for (unsigned i = 0; i < (v.size() / 2); i++)
	{
		std::swap(v[i], v[end - i]);
	}

}*/

/* Question 2:
 *
 *		 Complete the following function that reorders the 
 * contents of a vector so that all the even numbers appear 
 * before any odd number. The even values are sorted in ascending 
 * order with respect to themselves, and the odd numbers that 
 * follow are also sorted in ascending order with respect to 
 * themselves. For example, a vector containing the elements 
 * 2, 1, 10, 4, 3, 6, 7, 9, 8, 5 would be transformed into 
 * 2, 4, 6, 8, 10, 1, 3, 5, 7, 9 Note that your function must 
 * physically rearrange the elements within the vector, not just 
 * print the elements in reverse order. 
 *
 */

void special_sort(std::vector<int>& v)
{
	int end = v.size(), small_even = 0, large_odd = 0, largest_even = 0, odd_start = 0;

	// Nothing to do...
	if (v.empty())
		return;

	// Start at beginning. If v[i] is even remember it.
	// If the next digit is even and is smaller swap them,
	// otherwise keep going.
	for (int i = 0; i < end; i++)
	{
		// Do the even numbers...
		small_even = i;
		for (int j = i + 1; j < end; j++)
		{
			if (v[j] % 2 == 0 && v[j] <= v[small_even])
				small_even = j;
		}
		if (i != small_even)
			std::swap(v[i], v[small_even]);
	}
	for (int i = 0; i < end; i++)
	{
		if (v[i] % 2 == 0 && v[i] > largest_even)
		{
			largest_even = v[i];
			odd_start = i;
		}
	}

	// Do the odds once evens are sorted
	for (int i = odd_start; i < end; i++)
	{
		large_odd = i;
		for (int j = i + 1; j < end; j++)
		{
			if (v[j] < v[large_odd])
				large_odd = j;
		}
		if (i != large_odd)
			std::swap(v[i], v[large_odd]);
	}
}

/*
 * Question 3
 *
 *  Shift every element in vector forward one place;
 * last element becomes the first, and everything else
 * shifts up one indicie.
 */
/*
void rotate(std::vector<int>& v)
{
	// .push_back() last element to give us some space
	// to work
	v.push_back(0);			// This expands vector by +1 with an empty spot to move everything else up forward with,
							// then all we do is move everything up 1 and std::swap(0, v.size() -1) followed by v.pop_back();
	int end = v.size();
	// Loop from end to front, swap every element on the way
	for (int i = end - 1; i > 0; i--)
		std::swap(v[i], v[i - 1]);
	std::swap(v[0], v[v.size() - 1]);
	v.pop_back();
}*/

/*
 *		Question 4
 * 
 * Function determines if number of even and odd values in
 * a vector is the same. Function would return true if:
 * v1{5, 1, 0, 2} and false if: v1{5, 1, 0, 2, 11} (too many odds).
 * Returns true if vector is empty, since an empty vector has the
 * same number of odds and evens.
 */
/*
bool balanced(const std::vector<int>& v)
{
	int end = v.size(), odds = 0, evens = 0;

	if (v.empty())
		return true;

	for (int i = 0; i < end; i++)
	{
		if (v[i] == 0 || v[i] % 2 == 0)
			evens++;
		else
			odds++;
	}
	if (odds == evens)
		return true;
	else
		return false;
}*/

/*
 *		Question 5
 *
 *  Function returns true if vector contains duplicate
 * entries; returns false if all elements are unique. An
 * empty vector has no duplicates.
 */
/*
bool has_duplicates(const std::vector<int>& v)
{
	int end = v.size(), matches = 0;

	if (v.empty())
		return false;

	for (int i = 0; i < end; i++)
	{
		for (int n = 0; n < end; n++)
			matches = (v[i] == v[n]) ? matches + 1 : matches;
	}
	if (matches > static_cast<int>(v.size()))
		return true;
	else
		return false;
}
*/
int main()
{
	std::cout << 1 / 0;
	srand(clock());
	int i;
	while (std::cin >> i)
	{
		//bool truth;
		std::vector<int> vec(SIZE);
		for (int i = 0; i < SIZE; i++)
			vec[i] = rand() % SIZE;
		
		print(vec);
		special_sort(vec);
		print(vec);
		/*
		if (truth)
		{
			print(vec);
			std::cout << "\nThere are duplicates!";
		}
		else
			std::cout << "\nThere aren't :(";   */
	}
}