##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makes linked list library
##

ECHO    =       /bin/echo -e
DEFAULT =       "\033[00m"
#SHELL  =       "\e[0;0m"

DEFAULT =       "\e[0m"
BOLD	=       "\e[1m"
DIM	=       "\e[2m"
UNDLN	=       "\e[4m"
SHINE   =       "\e[5;37m"
RODE    =       "\e[9;30m"
IDK   =       "\e[5;37m"

BLACK	=       "\e[30m"
RED	=       "\e[31m"
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

CFLAGS	+=	-I../../include

SRCDIR	=	src/

BINDIR	=	../

SRC     =	$(SRCDIR)actions_on_list.c			\
			$(SRCDIR)add_substract_elem_list.c	\
			$(SRCDIR)display_list.c				\
			$(SRCDIR)init_linked_list.c

OBJ     =       $(SRC:.c=.o)

NAME    =       liblinked_list.a

all:		$(NAME) title

title:
			@$(ECHO) $(BOLD) $(YELLOW) Built $(NAME)$(DEFAULT)

$(NAME):    $(OBJ)
			@ar rc $(NAME) $(OBJ)
			mv $(NAME) $(BINDIR)

clean:
			@rm -f $(OBJ)
			@($(ECHO) $(BOLD) $(GREEN)✓" CLEAN "$(NAME)$(DEFAULT))

fclean:
			@rm -f $(OBJ)
			@rm -f $(BINDIR)$(NAME)
			@($(ECHO) $(BOLD) $(GREEN)✓" FCLEAN "$(NAME)$(DEFAULT))

re:			fclean all

debug:		CFLAGS += -g
debug:		re

%.o :           %.c
		@gcc -c -o $@ $^ $(CFLAGS) && $(ECHO) -n $(BOLD) $(GREEN)"  [OK] "$(WHITE) || $(ECHO) -n $(BOLD) $(RED)"  [KO] "$(WHITE) && $(ECHO) $(BOLD) $< | rev | cut -d'/' -f 1 | rev
