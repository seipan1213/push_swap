/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehattor <sehattor@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 01:24:55 by sehattor          #+#    #+#             */
/*   Updated: 2022/06/11 01:24:55 by sehattor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void long_swap(long *la, long *lb)
{
	long tmp;

	tmp = *la;
	*la = *lb;
	*lb = tmp;
}

void quick_sort(long *arr, int left, int right)
{
	int i;
	int j;
	int pivot;

	i = left;
	j = right;
	pivot = left;
	while (1)
	{
		while (arr[i] < arr[pivot])
			i++;
		while (arr[pivot] < arr[j])
			j--;
		if (i >= j)
			break;
		long_swap(&arr[i], &arr[j]);
		i++;
		j--;
	}
	if (left < i - 1)
		quick_sort(arr, left, i - 1);
	if (j + 1 < right)
		quick_sort(arr, j + 1, right);
}