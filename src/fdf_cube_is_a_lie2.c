#include "fdf.h"

void	main_face_1(t_cube *cb, char cube, t_node **cn, int *fv)
{
	cb->m = fv[1];
	cb->o = fv[3];
	cb->main[0] = cube & 8 ? cn[4] : NULL;
	cb->main[1] = cube & 4 ? cn[5] : NULL;
	cb->main[2] = cube & 64 ? cn[1] : NULL;
	cb->main[3] = cube & 128 ? cn[0] : NULL;
	cb->opp[0] = cube & 1 ? cn[7] : NULL;
	cb->opp[1] = cube & 2 ? cn[6] : NULL;
	cb->opp[2] = cube & 32 ? cn[2] : NULL;
	cb->opp[3] = cube & 16 ? cn[3] : NULL;
	cb->cube = cube;
}

void	main_face_2(t_cube *cb, char cube, t_node **cn, int *fv)
{
	cb->m = fv[2];
	cb->o = fv[0];
	cb->main[0] = cube & 1 ? cn[7] : NULL;
	cb->main[1] = cube & 2 ? cn[6] : NULL;
	cb->main[2] = cube & 4 ? cn[5] : NULL;
	cb->main[3] = cube & 8 ? cn[4] : NULL;
	cb->opp[0] = cube & 16 ? cn[3] : NULL;
	cb->opp[1] = cube & 32 ? cn[2] : NULL;
	cb->opp[2] = cube & 64 ? cn[1] : NULL;
	cb->opp[3] = cube & 128 ? cn[0] : NULL;
	cb->cube = cube;
}

void	main_face_3(t_cube *cb, char cube, t_node **cn, int *fv)
{
	cb->m = fv[3];
	cb->o = fv[1];
	cb->main[0] = cube & 16 ? cn[3] : NULL;
	cb->main[1] = cube & 32 ? cn[2] : NULL;
	cb->main[2] = cube & 2 ? cn[6] : NULL;
	cb->main[3] = cube & 1 ? cn[7] : NULL;
	cb->opp[0] = cube & 128 ? cn[0] : NULL;
	cb->opp[1] = cube & 64 ? cn[1] : NULL;
	cb->opp[2] = cube & 4 ? cn[5] : NULL;
	cb->opp[3] = cube & 8 ? cn[4] : NULL;
	cb->cube = cube;
}

void	main_face_4(t_cube *cb, char cube, t_node **cn, int *fv)
{
	cb->m = fv[4];
	cb->o = fv[5];
	cb->main[0] = cube & 8 ? cn[4] : NULL;
	cb->main[1] = cube & 128 ? cn[0] : NULL;
	cb->main[2] = cube & 16 ? cn[3] : NULL;
	cb->main[3] = cube & 1 ? cn[7] : NULL;
	cb->opp[0] = cube & 4 ? cn[5] : NULL;
	cb->opp[1] = cube & 64 ? cn[1] : NULL;
	cb->opp[2] = cube & 32 ? cn[2] : NULL;
	cb->opp[3] = cube & 2 ? cn[6] : NULL;
	cb->cube = cube;
}

void	main_face_5(t_cube *cb, char cube, t_node **cn, int *fv)
{
	cb->m = fv[5];
	cb->o = fv[4];
	cb->main[0] = cube & 64 ? cn[1] : NULL;
	cb->main[1] = cube & 4 ? cn[5] : NULL;
	cb->main[2] = cube & 2 ? cn[6] : NULL;
	cb->main[3] = cube & 32 ? cn[2] : NULL;
	cb->opp[0] = cube & 128 ? cn[0] : NULL;
	cb->opp[1] = cube & 8 ? cn[4] : NULL;
	cb->opp[2] = cube & 1 ? cn[7] : NULL;
	cb->opp[3] = cube & 16 ? cn[3] : NULL;
	cb->cube = cube;
}
