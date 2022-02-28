
NAME		=	philo

INCLUDE_DIR		=	.

CC			=	clang

CFLAGS		=	-Werror -Wall -Wextra -g -I $(INCLUDE_DIR) -pthread -fsanitize=address -fsanitize=leak#-fsanitize=thread#-fsanitize=address -fsanitize=leak

SRCS		=	check_validity_and_init_ptr_and_philosophers.c \
				death.c \
				update_free_memory.c \
				error.c \
				fork_ressources.c \
				only_one_philo.c \
				utils.c \
				timer.c \
				start_routine.c \
				main.c \
				struct_protect_1_data_race.c \
				struct_protect_2_data_race.c \
				ft_printf.c \
				struct_t_utils_1_data_race_get_var.c \
				struct_t_utils_1_data_race_set_var.c \
				struct_t_philo_1_data_race_get_var.c \
				struct_t_philo_1_data_race_set_var.c \
				struct_t_utils_2_data_race_get_var.c \
				struct_t_utils_2_data_race_set_var.c \
				
OBJS		=	$(SRCS:.c=.o)

all			:	$(NAME)

$(NAME)		:	$(OBJS) $(INCLUDE_DIR)
				$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean		:
				rm -rf $(OBJS)

fclean		:	clean
				rm -rf $(NAME)

re			:	fclean all
