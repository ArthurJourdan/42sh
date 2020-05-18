##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makes library
##

ECHO    =       /bin/echo -e
DEFAULT =       "\033[00m"
#SHELL  =       "\e[0;0m"

DEFAULT =       "\e[0m"
BOLD	=       "\e[1m"
DIM		=       "\e[2m"
UNDLN	=       "\e[4m"
SHINE   =       "\e[5;37m"
RODE    =       "\e[9;30m"
IDK	=       "\e[5;37m"

BLACK	=       "\e[30m"
RED		=       "\e[31m"
GREEN	=       "\e[32m"
YELLOW	=       "\e[33m"
BLUE	=       "\e[34m"
MAGENTA	=       "\e[35m"
CYAN	=       "\e[36m"
WHITE	=       "\e[37m"

LIGHT_GREY      =       "\e[90m"
LIGHT_RED       =       "\e[91m"
LIGHT_GREEN     =       "\e[92m"
LIGHT_YELLOW    =       "\e[93m"
LIGHT_BLUE      =       "\e[94m"
LIGHT_MAGENTA   =       "\e[95m"
LIGHT_CYAN      =       "\e[96m"

CFLAGS	=   -I ../../include/

SRCDIR	=   src/

CHECK	=   $(SRCDIR)checking/

NUM		=   $(SRCDIR)numbering/

MODIF	=   $(SRCDIR)modifying/

FREE	=	$(SRCDIR)freeing/

SRC     =	$(CHECK)my_strlen.c					\
			$(CHECK)my_int_arr_len.c			\
			\
			$(CHECK)my_strcmp.c					\
			$(CHECK)compare_str.c				\
			\
			$(CHECK)my_str_is_alphanum.c		\
			$(CHECK)my_str_is_nothing.c			\
			$(CHECK)my_str_is_chars.c			\
			\
			$(CHECK)error_msg.c					\
			\
			$(NUM)my_getnbr.c					\
			$(NUM)my_getdigit.c					\
			$(NUM)my_getfloat.c					\
			$(NUM)my_reg_nbr.c					\
			$(NUM)my_str_is_num.c				\
			\
			$(NUM)invert_bool.c					\
			\
			$(MODIF)my_strcat.c					\
			$(MODIF)my_strcat_path.c			\
			$(MODIF)my_arrcat.c					\
			$(MODIF)add_str_to_arr.c			\
			$(MODIF)remove_str_to_arr.c			\
			\
			$(MODIF)my_strcpy.c					\
			$(MODIF)my_strcpy_quotation.c		\
			$(MODIF)my_double_arr_dup.c			\
			\
			$(MODIF)my_word_arr_to_str.c		\
			$(MODIF)my_str_to_word_arr.c		\
			$(MODIF)my_sep_parser.c				\
			\
			$(MODIF)sort_arr_alphabetically.c	\
			$(MODIF)reverse_arr.c				\
			$(MODIF)reverse_str.c				\
			\
			$(MODIF)replace_char_in_str.c	\
			\
			$(MODIF)my_memset.c					\
			\
			$(FREE)free_arr.c					\
			$(FREE)free_to_null.c				\

OBJ     =       $(SRC:.c=.o)

NAME    =       libmy.a

all:		 $(NAME) title

title:
		@$(ECHO) $(BOLD) $(YELLOW) Built $(NAME)$(DEFAULT)

$(NAME):        $(OBJ)
		@ar rc $(NAME) $(OBJ)
		mv $(NAME) ../
clean:
		@rm -f $(OBJ)
		@($(ECHO) $(BOLD) $(GREEN)✓" CLEAN "$(NAME)$(DEFAULT))

fclean:
		@rm -f $(OBJ)
		@rm -f ../$(NAME)
		@($(ECHO) $(BOLD) $(GREEN)✓" FCLEAN "$(NAME)$(DEFAULT))

re:		fclean all

%.o :           %.c
		@gcc $(CFLAGS) -c -o $@ $^ && $(ECHO) -n $(BOLD) $(GREEN)"  [OK] "$(WHITE) || $(ECHO) -n $(BOLD) $(RED)"  [KO] "$(WHITE) && $(ECHO) $(BOLD) $< | rev | cut -d'/' -f 1 | rev
