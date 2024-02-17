#include "sort.h"

/**
 * bubble_sort - sorting an array
 *
 * @array: array to be sorted
 * @size: array size
 *
 * Return: nothing
 */

void bubble_sort(int *array, size_t size)
{
		size_t i;
		int t, flag = 1;

		if (!array)
			return;
		while (flag)
		{
			flag = 0;
			for (i = 0; i < size; i++)
			{
				if (array[i] > array[i + 1] &&
						i != size - 1)
				{
					t = array[i];
					array[i] = array[i + 1];
					array[i + 1] = t;
					flag = 1;
					print_array(array, size);
				}
			}
		}
}
