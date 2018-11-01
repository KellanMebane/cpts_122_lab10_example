#include <iostream>

// from https://www.geeksforgeeks.org/merge-sort/

// watch https://www.youtube.com/watch?v=IR7DFDej6l4 
// watch https://youtu.be/JSceec-wEyw 

// look at code below, test it, then try to use the same idea for a generic version
// if we cut the array in half each iteration, what does that do to our BigO complexity?
// what is the BigO for worst case, average case, and best case?
// what if the list is already sorted?
// what if the list is perfectly unsorted?

// YOU MUST CONVERT THIS INTO A FUNCTION TEMPLATE
// ACCEPT A GENERIC ARRAY OR VECTOR
// INDEXES ARE STILL INTEGERS
// YOU DO NOT NEED TO WORRY ABOUT OVERLOADED OPERATORS
// THE CLASSES USED HERE SHOULD HAVE OVERLOADED OPERATORS (=, ==, <, >)

// merge two arrays back into our original array
// only checks the smallest index of each
void merge(int arr[], int left, int middle, int right)
{
	int n1 = middle - left + 1;
	int n2 = right - middle;

	// create two sub arrays based on input indicies
	int left_arr[n1], right_arr[n2];

	// copy into sub arrays
	for (int i = 0; i < n1; i++)
		left_arr[i] = arr[left + i];

	for (int i = 0; i < n2; i++)
		right_arr[i] = arr[middle + 1 + i];

	int i = 0;
	int j = 0;
	int k = left;

	
	// copy the two arrays back into the main array based on value
	// notice how it's <=, this allows the sort to preserve order (and have duplicates)
	// this means merge sort is a STABLE or SAFE sorting algorithm
	while (i < n1 && j < n2)
	{
		if (left_arr[i] <= right_arr[j])
		{
			arr[k] = left_arr[i];
			i++;
		}
		else
		{
			arr[k] = right_arr[j];
			j++;
		}
		k++;
	}

	// if there's anything left over copy it directly (must be sorted at this point)
	// this is because the previous loop can break on either the first array
	// or the second array
	while (i < n1)
	{
		arr[k] = left_arr[i];
		i++;
		k++;
	}
	while (j < n2)
	{
		arr[k] = right_arr[j];
		j++;
		k++;
	}
}

// Recursive
// splits initial array in half every iteration
// stops when arrays are of size 1
// splits into two arrays and merges them
void merge_sort(int arr[], int left, int right)
{
	if (left < right)
	{
		int middle = left + (right - left) / 2;
		merge_sort(arr, left, middle);
		merge_sort(arr, middle + 1, right);
		merge(arr, left, middle, right);
	}
}

int main(void)
{
	int a[10] = {5, 6, 2, 3, 1, 9, 8, 0, 4, 7};

	for (int i = 0; i < 10; i++)
		std::cout << a[i] << " ";
	std::cout << std::endl;

	merge_sort(a, 0, 10 - 1);

	for (int i = 0; i < 10; i++)
		std::cout << a[i] << " ";
	std::cout << std::endl;

	return 0;
}