/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsantana <lsantana@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 02:00:59 by lsantana          #+#    #+#             */
/*   Updated: 2022/10/24 22:30:17 by lsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "stdio.h"
#include "stdlib.h"

void free_nodes(t_node *no)
{
	t_node *aux;

	aux = no;
	while(aux)
	{
		aux = no->next;
		free(no);
		no = aux;
	}
	no = NULL;
}

void    print_stacks(t_node *a, t_node *b)
{
    int    lst_size_a = 0;
    int lst_size_b = 0;
    int max;
    t_node    *aux_a;
    t_node    *aux_b;

    aux_a = a;
    aux_b = b;
    while (aux_a)
    {
        lst_size_a++;
        aux_a = aux_a->next;
    }
    while (aux_b)
    {
        lst_size_b++;
        aux_b = aux_b->next;
    }
    max = lst_size_a > lst_size_b ? lst_size_a : lst_size_b;
    while (max)
    {
        if (a && max <= lst_size_a)
		{
            printf("\t%3d\t", a->value);
			a = a->next;
		}
        else
            printf("\t \t");
        if (b && max <= lst_size_b)
		{
            printf("\t%3d\n", b->value);
			b = b->next;
		}
        else
            printf("\n");
		max--;
    }
	printf("\t___\t\t___\n");
    printf("\t A\t\t B\n");
}

int main(int argc, char **argv)
{
	t_node *no1;
	t_node *no2;

	no1 = 0;
	no2 = 0;
	check_errors(argc, argv, &no1);
	choose_sort(&no1, &no2, argc - 1);
	print_stacks(no1, no2);
	free_nodes(no1);
	free_nodes(no2);
	return (0);
}