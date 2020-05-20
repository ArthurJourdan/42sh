##
## EPITECH PROJECT, 2019
## makefile
## File description:
## lib
##

ECHO    =       /bin/echo -e
DEFAULT =       "\033[00m"

DEFAULT =       "\e[0m"
BOLD    =       "\e[1m"
DIM     =       "\e[2m"
UNDLN   =       "\e[4m"
SHINE   =       "\e[5;37m"
RODE    =       "\e[9;37m"

BLACK   =       "\e[30m"
RED     =       "\e[31m"
GREEN   =       "\e[32m"
YELLOW  =       "\e[33m"
BLUE    =       "\e[34m"
MAGEN   =       "\e[35m"
CYAN    =       "\e[36m"
WHITE   =       "\e[1;37m"


TESTNAME	=	unit_tests

TEST		=   --coverage -lcriterion

INCLUDE		=	-I include

CFLAGS		=	-W -Wall -Wextra $(INCLUDE)

RMFLAGS		=	*.gcda *.gcno src/*.gcda src/*.gcno

LIBDIR		=	./lib/

SRCDIR		=	src/

PARSE	=	$(SRCDIR)parsing_command_line/

BUILTIN	=	$(SRCDIR)built_ins/

GLOB	=	$(SRCDIR)globbing/

ENV		=	$(BUILTIN)env_management/

CD		=	$(BUILTIN)change_directory/

HIST	=	$(BUILTIN)history/

ALIAS	=	$(BUILTIN)aliases/

COMMAND	=	$(SRCDIR)exec_command/

SRC		=	${SRCDIR}main.c						\
			\
			${SRCDIR}minishell_manager.c		\
			\
			$(PARSE)command_read.c				\
			$(PARSE)my_command_parser.c			\
			$(PARSE)fill_cmd_part.c				\
			$(PARSE)parsing_error.c				\
			$(PARSE)parsing_error_management.c	\
			$(PARSE)assign_types.c				\
			\
			$(PARSE)free_all.c					\
			\
			$(ENV)init_env_memory.c				\
			$(ENV)path_to_path_array.c			\
			$(ENV)find_var_in_env.c				\
			$(ENV)disp_env.c					\
			$(ENV)env_management.c				\
			\
			$(BUILTIN)exec_built_ins.c			\
			$(BUILTIN)my_exit.c					\
			\
			$(ALIAS)get_aliases_from_file.c		\
			$(ALIAS)fill_alias_struct.c			\
			\
			$(CD)change_pwd.c					\
			\
			$(HIST)manage_history.c				\
			$(HIST)action_history.c				\
			\
			$(COMMAND)command_exists.c			\
			$(COMMAND)my_exec.c					\
			$(COMMAND)my_pre_exec.c				\
			$(COMMAND)set_pipes.c				\
			$(COMMAND)create_fd_redirect.c	\
			$(COMMAND)set_redirections.c		\
			$(COMMAND)exec_error_msg.c			\
			$(GLOB)check_wildcard.c			\
			$(GLOB)wildcards.c	\
			$(GLOB)my_strcpy1.c	\
			$(GLOB)my_strncpy.c	\
			$(GLOB)my_strdup.c	\
			$(GLOB)my_str_to_word_array.c	\

SRCTESTS	=	${SRCDIR}.c	\

OBJ		=       $(SRC:.c=.o)

NAME		=	42sh

SRC_LIB		=	linked_list	\
				print		\
				my			\
				file		\

LIB_PATHS	=   $(LIBDIR)lib_my				\
				$(LIBDIR)lib_file			\
				$(LIBDIR)lib_linked_list	\
				$(LIBDIR)lib_print			\

LIBRARIES   =	$(SRC_LIB:%=-l%)

LDFLAGS		=	-L./lib $(LIBRARIES)

all:		$(NAME)

lib:
			@$(ECHO)
			@for MAKE_PATH in $(LIB_PATHS) ; do \
				make -C $$MAKE_PATH -s ; \
			done

pre_building:
			@$(ECHO) $(BOLD) $(YELLOW) Built $(CYAN)$(NAME) $(WHITE) "\t$(CFLAGS)" $(DEFAULT)

$(NAME):	lib  $(OBJ) pre_building
			@$(ECHO)
			@gcc -o  $(NAME) $(OBJ) $(LDFLAGS) \
			&& $(ECHO) $(BOLD) $(GREEN)"-> BUILD SUCCESS !"$(DEFAULT) || $(ECHO) $(BOLD) $(RED)"-> BUILD FAILED"$(DEFAULT)

clean:
			@for MAKE_PATH in $(LIB_PATHS) ; do \
				make clean -C $$MAKE_PATH -s ; \
			done
			@rm -f $(OBJ)
			@rm -f $(RMFLAGS)
			@($(ECHO) $(BOLD) $(GREEN)✓" CLEAN "$(NAME)$(DEFAULT))

fclean:
			@for MAKE_PATH in $(LIB_PATHS) ; do \
				make fclean -C $$MAKE_PATH -s ; \
			done
			@rm -f $(OBJ)
			@rm -f $(NAME)
			@rm -f $(RMFLAGS)
			@rm -f $(TESTNAME)
			@($(ECHO) $(BOLD) $(GREEN)✓" FCLEAN "$(NAME)$(DEFAULT))
			@($(ECHO) $(BOLD) $(GREEN)✓" FCLEAN "$(TESTNAME)$(DEFAULT))

re:         fclean all

prev_test:	fclean
prev_test:
			@$(ECHO)
			@for MAKE_PATH in $(LIB_PATHS) ; do \
				make -C $$MAKE_PATH -s ; \
			done
			@$(ECHO)

tests_run:	prev_test $(OBJ)
			@$(ECHO)
			@gcc -o $(TESTNAME) $(SRCTESTS) tests/unit_tests.c $(TEST) $(CFLAGS) $(LDFLAGS) \
			&& $(ECHO) $(BOLD) $(GREEN)"-> BUILD SUCCESS !"$(DEFAULT) \
			|| $(ECHO) $(BOLD) $(RED)"-> BUILD FAILED"$(DEFAULT) \
			@$(ECHO)
			./$(TESTNAME)

debug:		CFLAGS += -g
debug:		re


%.o :		%.c
			@gcc -c -o $@ $^ $(CFLAGS) && \
			$(ECHO) -n $(BOLD) $(GREEN)"  [OK] "$(WHITE) || \
			$(ECHO) -n $(BOLD) $(RED)"  [KO] "$(WHITE) && \
			$(ECHO) $(BOLD) $< | rev | cut -d'/' -f 1 | rev

.PHONY:		all title clean fclean re tests_run debug lib probuilding
