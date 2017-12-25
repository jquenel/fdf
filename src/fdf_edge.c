#include "fdf.h"
#include <stdlib.h>

t_edge			*fdf_newedge(t_node *n1, t_node *n2)
{
	t_edge		*edge;

	//checkerror
	edge = malloc(sizeof(t_edge));
	edge->n1 = n1;
	edge->n2 = n2;
	edge->next = NULL;
	return (edge);
}

void			fdf_addedge(t_edge **edge1, t_edge *edge2)
{
	t_edge	*tmp;

	if (!(*edge1))
		*edge1 = edge2;
	else
	{
		tmp = *edge1;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = edge2;
	}
}
