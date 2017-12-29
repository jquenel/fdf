NAME=		fdf

##
##		RESSOURCES
##

SRC_PATH=	src

OBJ_PATH=	obj

CPPFLAGS=	-Iinclude

SRC_NAME=	main.c\
			fdf_init.c\
			fdf_parser.c\
			fdf_loadmatrix.c\
			fdf_zsort.c\
			fdf_nodes.c\
			fdf_faces.c\
			fdf_facebuilder.c\
			fdf_edges.c\
			fdf_draw1.c\
			fdf_draw2.c\
			fdf_keyevent.c\
			fdf_tlst.c\
			fdf_bresenham.c\
			fdf_bresenham_2.c\


SRC=		$(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ=		$(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

OBJ_NAME=	$(SRC_NAME:.c=.o)

##
##		COMPILER FLAGS
##

CFLAGS=		-Wextra -Wall -O3

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
