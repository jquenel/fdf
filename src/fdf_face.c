#include "fdf.h"
#include <stdlib.h>

void			fdf_addface(t_face **face1, t_face *face2)
{
	if (!(*face1))
		*face1 = face2;
	else
	{
		while ((*face1)->next)
			*face1 = (*face1)->next;
		(*face1)->next = face2;
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

	//heckerror
	face = malloc(sizeof(t_face));
	face->a = a;
	face->b = b;
	face->c = c;
	face->edge = NULL;
	fdf_addedge(&(face->edge), fdf_newedge(a, b));
	fdf_addedge(&(face->edge), fdf_newedge(b, c));
	fdf_addedge(&(face->edge), fdf_newedge(c, a));
	fdf_fton(face, a);
	fdf_fton(face, b);
	fdf_fton(face, c);
}
