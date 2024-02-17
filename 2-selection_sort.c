#include "sort.h"

/**
 * selection_sort - sorting an array
 *
 * @array: array to be sorted
 * @size: size of arry
 *
 * Description: using selectin sort
 *
 * Return: nothing
 */
void selection_sort(int *array, size_t size)
{
		int t;
		unsigned long int i, j, low_idx;

		for (i = 0; i < size; i++)
		{
			low_idx = i;
			for (j = i + 1 ; j < size ; j++)
				if (array[j] < array[low_idx])
					low_idx = j;
			if (low_idx != i)
			{
				t = array[i];
				array[i] = array[low_idx];
				array[low_idx] = t;
				print_array(array, size);
			}
		}
}
