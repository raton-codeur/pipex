NAME = pipex
FLAGS = -Wall -Wextra -Werror -I. -Ilibft
LIBFT = libft/libft.a
OBJS = $(addprefix tmp/, $(notdir $(SRCS:.c=.o)))
SRCS = $(addprefix src/, \
	pipex.c \
	get_path.c \
	get_data.c \
	utils.c \
	get_pipe.c \
	run_pipe.c \
)

$(NAME) : $(LIBFT) $(OBJS)
	@ cc $(FLAGS) $^ -Llibft -lft -o $@ && printf "\n$@ created\n"

$(LIBFT) :
	@ make --no-print-directory -C libft

tmp/%.o : src/%.c
	@ mkdir -p tmp
	@ cc $(FLAGS) -c $< -o $@ && printf "\rcompilation for $(NAME) : %d / %d" $$(ls tmp | wc -w) $(words $(SRCS))

all : $(NAME)

clean :
	@ make clean --no-print-directory -C libft
	@ rm -rf tmp && printf "$(NAME) cleaned\n"

fclean : clean
	@ make fclean --no-print-directory -C libft > /dev/null && printf "libft.a deleted\n"
	@ rm -f $(NAME) && printf "$(NAME) deleted\n"

re : fclean all

.PHONY : all clean fclean re bonus