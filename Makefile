SRCDIR		:= ./src
OBJDIR		:= ./obj
OBJDIRB		:= ./obj_bonus

NAME		:= avm
NAME_BONUS	:= avm_bonus
CC			:= c++
SRCS 		:= \
				main.cpp \
				Exceptions/Exceptions.cpp \
				Exceptions/MyExceptions.cpp \
				Operand/OperandFactory.cpp \
				Operand/StackOperand.cpp \
				Utils/Utils.cpp \
				Parser/Parser.cpp

OBJS		:= $(addprefix $(OBJDIR)/, $(SRCS:.cpp=.o))
OBJS_BONUS	:= $(addprefix $(OBJDIRB)/, $(SRCS:.cpp=_bonus.o))

CFLAGS	:= -Wextra -Wall -Werror -g


all: $(NAME)

bonus : $(NAME_BONUS)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) -o $(NAME)

$(NAME_BONUS): $(OBJS_BONUS)
	@$(CC) $(OBJS_BONUS) -o $(NAME_BONUS)

# --- Normal object rule ---
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "$(GREEN)✔️ $(notdir $<) compiled$(RESET)\n"

# --- Bonus object rule ---
$(OBJDIRB)/%_bonus.o: $(SRCDIR)/%.cpp
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -DBONUS -c $< -o $@
	@printf "$(GREEN)✔️ $(notdir $<) [bonus] compiled$(RESET)\n"

clean:
	@rm -rf $(OBJDIR)
	@printf "$(GREEN)✔️ clean\n"

fclean: clean cleanb
	@rm -rf $(NAME)
	@rm -rf $(NAME_BONUS)

cleanb: 
	@rm -rf $(OBJDIRB)
	@printf "$(GREEN)✔️ clean bonus\n"


re: clean all

bonusre : cleanb bonus

.PHONY: all, clean, fclean, re, bonus 