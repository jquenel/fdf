NAME=		libmat.a

S_PATH=		./src/

O_PATH=		./obj/

H_PATH=		./include/

SRC_LIST=	ft_v3d_add.c\
			ft_v3d_sub.c\
			ft_v3d_scale.c\
			ft_v3d_new.c\
			ft_mx4_new.c\
			ft_v3d_mag.c\
			ft_v3d_dir.c\
			ft_v3d_dot.c\
			ft_v3d_normalize.c\
			ft_v3d_copy.c\
			ft_v3d_x_v3d.c\
			ft_v3d_x_mx4.c\
			ft_mx4_x_mx4.c\
			ft_mx4_rot.c\
			ft_mx4_transl.c\
			ft_mx4_change.c\

INC_LIST=	libmat.h\

SRC=		$(SRC_LIST:%=$(S_PATH)%)

OBJ=		$(SRC_LIST:%.c=$(O_PATH)%.o)

TMP_OBJ=	$(SRC_LIST:%.c=%.o)

INC=		$(INC_LIST:%=$(H_PATH)%)

CFLAGS=		-Wextra -Wall -O3

CC=			gcc

all:		$(NAME)

$(NAME):	$(SRC) $(INC)
			@$(CC) $(CFLAGS) -I$(H_PATH) -c $(SRC)
			@mkdir $(O_PATH) 2> /dev/null || true
			@mv $(TMP_OBJ) $(O_PATH)
			@ar rc $(NAME) $(OBJ) $(LIBS)
			@echo "Compiled libmat.a."

clean:
			rm -Rf $(O_PATH)

fclean:		clean
			rm -f $(NAME)

lclean:		fclean
			$(MAKE) fclean -C libft

lre:			lclean all

re:			fclean all

.PHONY: all clean fclean re lclean re
