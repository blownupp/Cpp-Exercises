#include <iostream>
#include <vector>

//Count the even numbers only and 
//return the sum of those in the vector
int even_sum(const std::vector<int>& v)
{
	int sum = 0;
	if (!v.empty())
	{
		for (int element : v)
			sum = (element % 2 == 0) ? sum + element : sum;
		return sum;
	}
	else
	{
		return 0;
	}
}

/* Counts the even numbers
 *in a 2D vector of integers
 */
int count_evens(const std::vector<std::vector<int>>& v)
{
	int sum = 0;
	if (!v.empty())
	{

		for (const std::vector<int>& row : v)
		{

			for (int elem : row )
			{
				sum = (elem % 2 == 0) ? sum + elem : sum;
			}

		}

		return sum;

	}
	else
		return 0;
}

/*
 *   Compares two integer vectors to see if they contain exactly
 * the same elements in exactly the same positions. The function
 * returns TRUE if the vectors are equal; otherwise, 
 * it returns FALSE.
 * 
 *   For example, if vector VEC1 contains the elements:
 *			{  3,  5,  2, -1,  2  } ... and vector VEC2
 * contains the elements:
 *			{  3,  5,  2, -1,  2  } ... the call 
 *      equals(vec1, vec2);  --  would evaluate to TRUE. 
 * 
 *   If instead vector VEC2 contains the elements:
 *			{  3,  2,  5, -1,  2  } ... the call
 *		equals(vec1, vec2);  --  would evaluate to FALSE.
 *
 *        DATE: 2017-01-10
 *      AUTHOR: Chris Stromski (blownupp@gmail.com)
 * LAST EDITED: 2017-01-10
 *
 */

bool equals(const std::vector<int>& v1, const std::vector<int>& v2)
{

	// If the size() of v1 != v2, they are not equal
	if (v1.size() != v2.size())
		return false;

	// Loop through v1 and compare the value at the same index in v2
	for (unsigned index = 0; index < v1.size(); index++)
	{
		// If at any point the values don't match, return FALSE
		if (v1[index] != v2[index])
			return false;
	}
	// If FALSE hasn't been returned by the end of the loop, return TRUE
	// because all other options have been exhausted and they must be the same.
	return true;

}

/*
 *     Determines if all the elements in one vector also appear in
 * another. The function returns TRUE if all the elements in the 
 * SECOND vector also appear in the first; otherwise, it returns FALSE.
 * 
 *     For example, if vector VEC1 contains the elements:
 *			{  3,  5,  2, -1,  7,  2  } ... and vector VEC2
 * contains the elements:
 *						{  5,  7,  2  } ... the call
 *		contains(vec1, vec2);  --  would evaluate to TRUE.
 *     If instead vector VEC2 contains the elements:
 *					{  3,  8, -1,  2  } ... the call
 *		contains(vec1, vec2);  --  would evaluate to FALSE,
 * since 8 does not appear in the first vector.
 *
 *     Also if vector VEC2 contains the elements:
 *					{  5,  7,  2,  5  } ... the call
 *		contains(vec1, vec2);  --  would evaluate to FALSE,
 * since 5 appears twice in VEC2 but only once in VEC1, so VEC1 does not
 * contain all the elements that appear in VEC2.
 *
 *		The function does not affect the contents of the vectors.
 *
 *	      DATE: 2017-01-10
 *      AUTHOR: Chris Stromski (blownupp@gmail.com)
 * LAST EDITED: 2017-01-10
 */

bool contains(const std::vector<int>& v1, const std::vector<int>& v2)
{
	// Since we are checking that the elements of v2 are held by
	// v1, we should make sure we know how many of what is in v2

	//std::vector<int> v2Holder = v2;
	//std::vector<bool> v2Dupes(1, 0), v1Dupes(1, 0);
	int v2dupeNum = 0, v1dupeNum = 0, v2trueCnt = 0, v1trueCnt = 0;

	for (unsigned outer = 0; outer < v2.size(); outer++)
	{
		for (unsigned inner = 0; inner < v2.size(); inner++)
			if (v2[inner] == v2[outer])
				v2trueCnt++;
	}

	for (unsigned outer = 0; outer < v1.size(); outer++)
	{
		for (unsigned inner = 0; inner < v1.size(); inner++)
			if (v1[inner] == v1[outer])
				v1trueCnt++;
	}

	v1dupeNum = v1trueCnt % v1.size();
	v2dupeNum = v2trueCnt % v2.size();

	if (v1dupeNum < v2dupeNum)
		return false;

	// If there are no dupes, this is easy.
	if ( v2dupeNum == 0 )
	{
		v2trueCnt = 0;
		// If it's true that there are 0 duplicates...
		for (unsigned outer = 0; outer < v1.size(); outer++)
		{
			// For each element in v1...
			for (unsigned inner = 0; inner < v2.size(); inner++)
			{
				//... and each one in v2
				if (v2[inner] == v1[outer])
					v2trueCnt++;
			}
		}
		// If trueCnt == v2.size(), we can safely say all of
		// v2's elements are within v1
		if (v2trueCnt == v2.size())
			return true;
		else
			return false;
	}
	else
	{   /* If we're here, that means there were duplicates
		 * in the step before, so we can do this.
		 */
		v1trueCnt = 0;
		for (unsigned outer = 0; outer < v1.size(); outer++)
		{
			// For each element in v1...
			for (unsigned inner = 0; inner < v2.size(); inner++)
			{
				//... and each one in v2
				if (v2[inner] == v1[outer])
					v1trueCnt++;
			}
		}
		/*
		 * After looping through both vectors, we should have:
		 * v2.size() trues + v2dupeNum * 2 and if we don't,
		 * then the elements of v2 are not contained within v1
		 */
		float v2DupeIndex;
		v2DupeIndex = ((v2dupeNum / static_cast<float>(v2.size())) * v2dupeNum + static_cast<float>(v2.size())) + (v2dupeNum + static_cast<float>(v2.size()));
		//std::cout << v2DupeIndex << '\n';
		if (v1trueCnt - v2DupeIndex <= 1 || v2DupeIndex - v1trueCnt <= 1)
			return true;
		else
			return false;

	}
}

int main()
{
	std::vector<int> vec1{ 1, 2, 3, 4, 4, 4, 4, 5, 6, 7, 8, 2 }, vec2{ 4, 4, 4, 4, 2, 1, 3 };
	bool result = contains(vec1, vec2);
	if (result)
		std::cout << "true\n";
	else
		std::cout << "false\n";
}

/*
int main()
{
	std::vector<int> vec1, vec2;
	int input, result;
	while (true)
	{
		std::cout << "\nFill first vector: ";
		do
		{
			static int count = 1;
			std::cin >> input;
			vec1.push_back(input);
			count++;
			std::cout << "\nNumber " << count << ':';
		} while (input != 113);
		std::cout << "\nFill second vector: ";
		do
		{
			static int count = 1;
			std::cin >> input;
			vec2.push_back(input);
			count++;
			std::cout << "\nNumber " << count << ':';
		} while (input != 113);
		result = contains(vec1, vec2);
		if (result == 1)
			std::cout << "\nvec1 contains the elements of vec2";
		else
			std::cout << "\nvec1 does not contain vec2";
		vec1.clear();
		vec2.clear();
	}
}*/
/*
void twoD_print(const int *v, int r, int c)
{
	int *arr = (int *)v, rows, col;

	for ( rows = 0; rows < r; rows++)
	{
		for ( col = 0; col < c; col++)
			std::cout << arr[rows * r + c] << ' ';
		std::cout << '\n';
	}
}

int main()
{
	
	int list[][3] = { { 1, 2, 3}, {1, 2, 3} };
	int arr[] = { 10, 20, 30 };
	int *p = arr;
	//int **a = list[0];
	twoD_print(&list, 2, 3);
} */