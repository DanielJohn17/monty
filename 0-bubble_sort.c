#include "sort.h"

/**
 * bubble_sort - Sorts a given array using the bubble sorting method
 * @array: The array to be sorted
 * @size: Number of elements in @array
*/
void bubble_sort(int *array, size_t size)
{
	size_t i, j, temp;

	if (array == NULL || !size)
		return;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
			}
		}
	}
}
