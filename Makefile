NAME=		fdf

##
##		RESSOURCES
##

SRC_PATH=	src

OBJ_PATH=	obj

CPPFLAGS=	-Iinclude

SRC_NAME=	main.c\
			fdf_bresenham.c\
			fdf_bresenham_2.c\
			fdf_buttonpress.c\
			fdf_clean_cloud.c\
			fdf_create_folume.c\
			fdf_cube_is_a_lie.c\
			fdf_cube_is_a_lie2.c\
			fdf_cube_rotate.c\
			fdf_draw1.c\
			fdf_draw2.c\
			fdf_draw_fractol.c\
			fdf_edges.c\
			fdf_facebuilder.c\
			fdf_faces.c\
			fdf_get_cube.c\
			fdf_hlr.c\
			fdf_init.c\
			fdf_init_cam.c\
			fdf_keyevent.c\
			fdf_loadmatrix.c\
			fdf_move_node.c\
			fdf_nodes.c\
			fdf_parser.c\
			fdf_raster.c\
			fdf_rotxyz.c\
			fdf_tlst.c\
			fdf_wf_2_1.c\
			fdf_wf_2_2.c\
			fdf_wf_3_0.c\
			fdf_wf_3_1.c\
			fdf_wf_3_2.c\
			fdf_wf_3_3.c\
			fdf_wf_4_0.c\
			fdf_wf_4_1.c\
			fdf_wf_4_2.c\
			fdf_wf_4_3.c\
			fdf_wf_4_4.c\
			fdf_wut_face.c\
			fdf_zsort.c\

SRC=		$(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ=		$(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

OBJ_NAME=	$(SRC_NAME:.c=.o)

##
##		COMPILER FLAGS
##

CFLAGS=		-Wextra -Wall -O3 #-fsanitize=address

CC=			gcc

##LDFLAGS=	-Llibft -Llibmat -L/usr/local/lib
LDFLAGS=	-Llibft -Llibmat -L/usr/local/lib

##LIBS=		-lft -lmat -lmlx -lX11 -lXext -lm
LIBS=		-lft -lmat -lmlx -framework OpenGL -framework AppKit

LDLIBS=		$(LDFLAGS) $(LIBS)

##
##		Compile using the program's name to recompile that program.
##		Compile with test for special testing purposes.
##

all:			$(NAME)

$(NAME):		$(OBJ)
				@$(MAKE) -C libft
				@$(MAKE) -C libmat
				$(CC) $(CFLAGS) $(CPPFLAGS) $^ -o $@ $(LDLIBS)
				@echo "compiled $@."

$(OBJ_PATH)/%.o:$(SRC_PATH)/%.c
				@mkdir $(OBJ_PATH) 2> /dev/null || true
				$(CC) $(CFLAGS) -o $@ -c $< $(CPPFLAGS)

##
##		Use fclean to clean this program.
##

clean:
				@rm -Rf $(OBJ_PATH)
				@echo "clean"

fclean:			clean
				@rm -f $(NAME)
				@echo "fclean"

lclean:			fclean
				@$(MAKE) fclean -C libft
				@$(MAKE) fclean -C libmat
				@echo "lclean"

re:				fclean all

lre:			lclean re

.PHONY:			all clean fclean re lclean lre clibft
