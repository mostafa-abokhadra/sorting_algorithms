#include "sort.h"
#include <stdio.h>

void sort_front(listint_t **head __attribute__((unused)), listint_t *to_sort, listint_t *ptr2)
{
		to_sort->prev->next = to_sort->next;
		if (to_sort->next != NULL)
			to_sort->next->prev = to_sort->prev;
		to_sort->next = ptr2;
		ptr2->prev = to_sort;
		to_sort->prev = NULL;
		*(head) = to_sort;
		print_list(*head);
}
void sort_any_where(listint_t *to_sort, listint_t *ptr2)
{
		ptr2->prev->next = to_sort;
		/*ptr2->next = to_sort->next;*/
		if (to_sort->next != NULL)
		to_sort->next->prev = ptr2;
		if (to_sort->next == NULL)
		to_sort->prev->next = NULL;
		to_sort->prev = ptr2->prev;
		to_sort->next = ptr2;
		ptr2->prev = to_sort;
}
void insertion_sort_list(listint_t **list)
{
		listint_t *ptr, *ptr2, *to_sort;
		bool sort_occur = false;

		if (!(*list) || (*list)->next == NULL)
			return;
		ptr = (*list);
		while(ptr->next != NULL)
		{

			if (ptr->next->n >= ptr->n)
			{
			
				ptr = ptr->next;
			}
			else
			{
				ptr2 = to_sort = ptr->next;
				sort_occur = true;
				ptr = ptr->next->next;
				while (ptr2->prev != NULL &&
						ptr2->prev->n > to_sort->n)
				{
					ptr2 = ptr2->prev;
				}
			}
			if (sort_occur)
			{
				if (ptr2->prev == NULL)
				{
					sort_front(list, to_sort, ptr2);
				}
				else
				{
					sort_any_where(to_sort, ptr2);
					print_list(*list);
				}

			}
			if (sort_occur)
			{
				if (ptr != NULL)
				{
					ptr = ptr->prev;
				
				}
				else break;
			}
			sort_occur = false;
		}
}
