#include "fdf.h"
#include <stdlib.h>

void			fdf_addface(t_face **face1, t_face *face2)
{
	t_face		*tmp;

	if (!(*face1))
		*face1 = face2;
	else
	{
		tmp = *face1;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = face2;
		face2->prev = tmp;
	}
}

void			fdf_fton(t_face *f, t_node *n)
{
	int		i;

	i = 0;
	while ((n->face)[i])
		i++;
	(n->face)[i] = f;
}

t_face			*fdf_newface(t_node *a, t_node *b, t_node *c)
{
	t_face		*face;

	ft_err(!(face = malloc(sizeof(t_face))), ERR_M, 0);
	face->a = a;
	face->b = b;
	face->c = c;
	face->edge = NULL;
	face->next = NULL;
	face->prev = NULL;
	fdf_addedge(&(face->edge), fdf_newedge(a, b));
	fdf_addedge(&(face->edge), fdf_newedge(b, c));
	fdf_addedge(&(face->edge), fdf_newedge(c, a));
	fdf_fton(face, a);
	fdf_fton(face, b);
	fdf_fton(face, c);
	return (face);
}
