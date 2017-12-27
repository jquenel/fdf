NAME=		libft.a

S_PATH=		./srcs/

O_PATH=		./obj/

H_PATH=		./includes/

SRCS_LIST=	ft_printf.c\
			pf_parser.c\
			pf_printer.c\
			pf_rainbow.c\
			pf_disco.c\
			pf_init.c\
			pf_converter.c\
			pf_flagger.c\
			pf_convert_int.c\
			pf_convert_plain.c\
			pf_convert_percent.c\
			pf_convert_uint.c\
			pf_convert_oct.c\
			pf_convert_hex.c\
			pf_convert_char.c\
			pf_convert_wchar.c\
			pf_convert_adr.c\
			pf_convert_float.c\
			pf_convert_bin.c\
			pf_get_binary.c\
			pf_modifs01.c\
			pf_modifs02.c\
			pf_modifs03.c\
			\
			ft_putchar.c\
			ft_putstr.c\
			ft_putnbr.c\
			ft_putendl.c\
			ft_putchar_fd.c\
			ft_putstr_fd.c\
		   	ft_putnbr_fd.c\
			ft_putendl_fd.c\
			ft_putbits.c\
			ft_putbits_fd.c\
			\
			ft_strlen.c\
			ft_strdup.c\
			ft_strndup.c\
			ft_strcpy.c\
			ft_strncpy.c\
			ft_strcat.c\
			ft_strncat.c\
			ft_strlcat.c\
			ft_strcmp.c\
			ft_strncmp.c\
			ft_strchr.c\
			ft_strrchr.c\
			ft_strnew.c\
			ft_strstr.c\
			ft_strnstr.c\
			ft_strdel.c\
			ft_tabdel.c\
			ft_strclr.c\
			ft_striter.c\
			ft_striteri.c\
			ft_strmap.c\
			ft_strmapi.c\
			ft_strequ.c\
			ft_strnequ.c\
			ft_strsub.c\
			ft_strjoin.c\
			ft_strmerge.c\
			ft_strtrim.c\
			ft_strsplit.c\
			ft_strcspn.c\
			ft_strpbrk.c\
			\
			ft_intlen.c\
			\
			ft_memset.c\
			ft_bzero.c\
			ft_memcpy.c\
			ft_memccpy.c\
			ft_memmove.c\
			ft_memchr.c\
			ft_memcmp.c\
			ft_memalloc.c\
			ft_memdel.c\
			ft_memjoin.c\
			ft_memrjoin.c\
			\
			ft_stris.c\
			ft_isalpha.c\
			ft_isdigit.c\
			ft_isalnum.c\
			ft_isascii.c\
			ft_isprint.c\
			ft_isspace.c\
			\
			ft_atoi.c\
			ft_atol.c\
			ft_itoa.c\
			ft_itoa_base.c\
			ft_uitoa.c\
			ft_uitoa_base.c\
			\
			ft_tolower.c\
			ft_toupper.c\
			\
			ft_lstnew.c\
			ft_lstdelone.c\
			ft_lstadd.c\
			ft_lstpushback.c\
			ft_lstdel.c\
			ft_lstinsert.c\
			ft_lstiter.c\
			ft_lstlen.c\
			ft_lstmap.c\
			\
			get_next_line.c\
			ft_err.c\

INC_LIST=	ft_printf.h\
			libft.h\

SRCS=		$(SRCS_LIST:%=$(S_PATH)%)

OBJ=		$(SRCS_LIST:%.c=$(O_PATH)%.o)

TMP_OBJ=	$(SRCS_LIST:%.c=%.o)

INC=		$(INC_LIST:%=$(H_PATH)%)

CFLAGS=		-Wextra -Wall -O3

CC=			gcc

all:		$(NAME)

$(NAME):	$(SRCS) $(INC)
			@$(CC) $(CFLAGS) -I$(H_PATH) -c $(SRCS)
			@mkdir $(O_PATH) 2> /dev/null || true
			@mv $(TMP_OBJ) $(O_PATH)
			@ar rc $(NAME) $(OBJ) $(LIBS)
			@echo "Compiled libft.a."

clean:
			rm -Rf $(O_PATH)

fclean:		clean
			rm -f $(NAME)

lclean:		fclean
			$(MAKE) fclean -C libft

lre:			lclean all

re:			fclean all

.PHONY: all clean fclean re lclean re
