# Setting targets
NAME := push_swap
CFLAGS := -Wall -Wextra -Werror

SRC_DIR := ./srcs/
OBJS_DIR := ./objs/
HEADER_DIR := header

# Colors for visual effects
BLACK = \033[0;30m
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
PURPLE = \033[0;35m
CYAN = \033[0;36m
WHITE = \033[0;37m
DEF_COLOR = \033[0;39m
LF = \e[1K\r

#################################################################################
######################## [MANDATORY directory] ##################################
#################################################################################
HEADER_FILES_MANDATORY := $(HEADER_DIR)/push_swap.h

MAIN_DIR := $(SRC_DIR)mandatory/main/
PARSE_DIR := $(SRC_DIR)mandatory/parse/
UTILS_DIR := $(SRC_DIR)mandatory/utils/
GREEDY_DIR := $(SRC_DIR)mandatory/solve/greedy/
SANDGLASS_DIR := $(SRC_DIR)mandatory/solve/sand_glass/
MEMORY_DIR := $(SRC_DIR)mandatory/memory/
OPERATIONS_DIR := $(SRC_DIR)mandatory/operations/

SRCS_MAIN := $(addprefix $(MAIN_DIR), \
              main.c)

SRCS_PARSE := $(addprefix $(PARSE_DIR), \
              deque_initialize.c \
              parse_pt1.c \
              parse_pt2.c \
              parse_pt3.c)

SRCS_UTILS := $(addprefix $(UTILS_DIR), \
              push_swap_split.c \
              deque_utils_pt1.c \
              deque_utils_pt2.c \
              sorting_utils_pt1.c \
              sorting_utils_pt2.c \
              sorting_utils_pt3.c)

SRCS_GREEDY := $(addprefix $(GREEDY_DIR), \
               01_solve.c \
               02_data_dispersion.c \
               03_b_to_a_pt1.c \
               03_b_to_a_pt2.c \
               03_b_to_a_pt3.c \
               03_b_to_a_pt4.c \
               03_b_to_a_pt5.c \
               04_final_sort.c)

SRCS_SANDGLASS := $(addprefix $(SANDGLASS_DIR), \
                   sand_glass_algo_pt1.c \
                   sand_glass_algo_pt2.c \
                   sand_glass_algo_pt3.c)

SRCS_MEMORY := $(addprefix $(MEMORY_DIR), \
                memory_mng_pt1.c \
                memory_mng_pt2.c)

SRCS_OPERATIONS := $(addprefix $(OPERATIONS_DIR), \
                    operations_pt1.c \
                    operations_pt2.c \
                    operations_pt3.c)

SRCS := $(SRCS_MAIN) \
        $(SRCS_PARSE) \
        $(SRCS_UTILS) \
        $(SRCS_GREEDY) \
        $(SRCS_SANDGLASS) \
        $(SRCS_MEMORY) \
        $(SRCS_OPERATIONS)

#################################################################################
#################################################################################
#################################################################################
LIB_DIR := ./srcs/ar/
LIB := $(LIB_DIR)libft.a

OBJS := $(patsubst $(SRC_DIR)%.c, $(OBJS_DIR)%.o, $(SRCS))

# setting for progress bar
TOTAL_FILES := $(words $(SRCS))
CURRENT_FILE := 1

progress_bar = printf "\033[999C\e[?25l$(LF)$(RED)[ ♔ linking... ♔ ]$(DEF_COLOR) $(YELLOW)Progress:$(DEF_COLOR) $(YELLOW) %s [%-49s]$(DEF_COLOR)" "$(CURRENT_FILE)/$(TOTAL_FILES)" "$(shell seq -s '>' $$(echo "$(CURRENT_FILE) / $(TOTAL_FILES) * 50" | bc -l) | sed 's/[0-9]//g')"; \
			   printf "\033[s\n\033[K$(WHITE)   ✔︎ $(CYAN)Compiling... $<$(DEF_COLOR)\033[A";

all: $(OBJS_DIR) $(NAME)

$(NAME): $(OBJS) $(LIB)
	@$(CC) $(CFLAGS) $(OBJS) $(LIB) -o $(NAME)
	@echo "\n"
	@echo "$(GREEN)===============================================$(DEF_COLOR)"
	@echo "$(GREEN)|     🥳  [$(NAME)] compile success. 🥳     |$(DEF_COLOR)"
	@echo "$(GREEN)===============================================$(DEF_COLOR)"

$(OBJS): objs/%.o: srcs/%.c $(HEADER_FILES_MANDATORY)
	@mkdir -p $(@D)
	@$(call progress_bar)
	@$(CC) $(CFLAGS) -I$(HEADER_DIR) -c $< -o $@
	@$(eval CURRENT_FILE := $(shell expr $(CURRENT_FILE) + 1))

$(OBJS_DIR):
	@mkdir $(OBJS_DIR)

# ============================== BONUS PART =================================== #
#################################################################################
########################## [BONUS directory] ####################################
#################################################################################
BONUS_NAME := checker

HEADER_FILES_BONUS := $(HEADER_DIR)/push_swap_bonus.h

BONUS_DIR := $(SRC_DIR)bonus/
BONUS_MAIN := $(SRC_DIR)bonus/main/
BONUS_PARSE := $(SRC_DIR)bonus/parse/
BONUS_MEMORY := $(SRC_DIR)bonus/memory/
BONUS_OPERATIONS := $(SRC_DIR)bonus/operations/
BONUS_UTILS := $(SRC_DIR)bonus/utils/
OBJ_DIR_BONUS := $(OBJS_DIR)bonus/

SRCS_BONUS_MAIN := $(addprefix $(BONUS_MAIN), \
                    main_pt1_bonus.c \
                    main_pt2_bonus.c)

SRCS_BONUS_MEMORY := $(addprefix $(BONUS_MEMORY), \
                    memory_mng_pt1_bonus.c)

SRCS_BONUS_OPERATIONS := $(addprefix $(BONUS_OPERATIONS), \
                            operations_pt1_bonus.c \
                            operations_pt2_bonus.c \
                            operations_pt3_bonus.c)

SRCS_BONUS_PARSE := $(addprefix $(BONUS_PARSE), \
                        deque_initialize_bonus.c \
                        parse_pt1_bonus.c \
                        parse_pt2_bonus.c \
                        parse_pt3_bonus.c)

SRCS_BONUS_UTILS := $(addprefix $(BONUS_UTILS), \
                    deque_utils_pt1_bonus.c \
                    deque_utils_pt2_bonus.c \
                    push_swap_split_bonus.c)

SRCS_BONUS := $(SRCS_BONUS_MAIN) \
              $(SRCS_BONUS_MEMORY) \
              $(SRCS_BONUS_OPERATIONS) \
              $(SRCS_BONUS_PARSE) \
              $(SRCS_BONUS_UTILS)
#################################################################################
#################################################################################
#################################################################################

bonus: $(OBJ_DIR_BONUS) $(BONUS_NAME)
OBJS_BONUS  := $(patsubst $(SRC_DIR)%.c, $(OBJS_DIR)%.o, $(SRCS_BONUS))
    
TOTAL_FILES_BONUS := $(words $(SRCS_BONUS))
CURRENT_FILE_BONUS := 1
progress_bar2 = printf "\033[999C\e[?25l$(LF)$(RED)[ ♔ linking... ♔ ]$(DEF_COLOR) $(YELLOW)Progress:$(DEF_COLOR) $(YELLOW) %s [%-49s]$(DEF_COLOR)" "$(CURRENT_FILE_BONUS)/$(TOTAL_FILES_BONUS)" "$(shell seq -s '>' $$(echo "$(CURRENT_FILE_BONUS) / $(TOTAL_FILES_BONUS) * 50" | bc -l) | sed 's/[0-9]//g')"; \
			   printf "\033[s\n\033[K$(WHITE)   ✔︎ $(CYAN)Compiling... $<$(DEF_COLOR)\033[A";

$(OBJS_BONUS): objs/%.o: srcs/%.c $(HEADER_FILES_BONUS)
	@mkdir -p $(@D)
	@$(call progress_bar2)
	@$(CC) $(CFLAGS) -I$(HEADER_DIR) -c $< -o $@
	@$(eval CURRENT_FILE_BONUS := $(shell expr $(CURRENT_FILE_BONUS) + 1))

$(BONUS_NAME): $(OBJS_BONUS) $(LIB)
	@$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIB) -o $(BONUS_NAME)
	@echo "\n"
	@echo "$(GREEN)===============================================$(DEF_COLOR)"
	@echo "$(GREEN)|  🎉  [$(BONUS_NAME)] compile success.  🎉 |$(DEF_COLOR)"
	@echo "$(GREEN)===============================================$(DEF_COLOR)"

$(OBJ_DIR_BONUS): $(OBJS_DIR)
	@mkdir $(OBJ_DIR_BONUS)

# ============================================================================= #

# libft archive file
$(LIB):
	@sleep 0.5
	@$(MAKE) -C $(LIB_DIR)

clean:
	@$(RM) -r $(OBJS_DIR)
	@$(RM) -r $(OBJ_DIR_BONUS)
	@rm -rf $(LIB_DIR)/objs
	@rm -rf $(LIB)
	@printf "$(LF)🚧 $(Yellow)Cleaning...🚨 $(White) $(OBJ_BO) $(OBJ) \n$(DEF_COLOR)"
	@rm -rf $(OBJ_DIR)
	@printf "$(LF)$(YELLOW)Cleanup complete.$(DEFAULT_COLOR)\n\n"
	@sleep 0.5

fclean: clean
	@printf "$(LF)🚧 $(Red)Cleaning...🚨 $(White)$(NAME)\n"
	@rm -f $(NAME)
	@rm -f $(BONUS_NAME)
	@rm -rf $(LIB_DIR)/objs
	@rm -rf $(LIB)
	@echo "$(RED)Executable removed.$(DEFAULT_COLOR)\n"
	@echo "$(CYAN)Clearing terminal in [3 seconds]...$(DEFAULT_COLOR)"
	@sleep 1
	@clear

re: fclean
	@sleep 0.7
	@clear
	@printf "$(PURPLE) ♻️  REBUILD  ♻️\n\n$(DEF_COLOR)"
	@$(MAKE) all

.PHONY: all clean fclean re bonus
