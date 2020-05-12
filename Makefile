##
## EPITECH PROJECT, 2019
## string library
## File description:
## Build th string library
##

override CFLAGS		+=	-W -Wall -Wextra
override CPPFLAGS	+=	-I./include
override LDFLAGS	+=

CC					=	gcc
LD					=	$(CC)

DIR					=	./src/
SRC					=	editor/add/array/advanced_type.c			\
						editor/add/array/basic_type.c				\
						editor/add/array.c							\
						editor/add/object/advanced_type.c			\
						editor/add/object/basic_type.c				\
						editor/add/object.c							\
						editor/append/array/advanced_type.c			\
						editor/append/array/basic_type.c			\
						editor/append/object/advanced_type.c		\
						editor/append/object/basic_type.c			\
						editor/compare/advanced_type.c				\
						editor/compare/basic_type.c					\
						editor/create/array.c						\
						editor/create/object.c						\
						editor/destroy/array.c						\
						editor/destroy/object.c						\
						editor/destroy/union.c						\
						editor/key.c								\
						editor/set/index/array/advanced_type.c		\
						editor/set/index/array/basic_type.c			\
						editor/set/key/object/advanced_type.c		\
						editor/set/key/object/basic_type.c			\
						editor/unset/index.c						\
						editor/unset/key.c							\
						editor/unset/value/array/advanced_type.c	\
						editor/unset/value/array/basic_type.c		\
						editor/unset/value/array.c					\
						error.c										\
						escape_character.c							\
						generator/array.c							\
						generator/object.c							\
						generator/setup_teardown.c					\
						generator/write/basic_type.c				\
						generator/write/indent.c					\
						generator/write/token.c						\
						generator/write/union.c						\
						generator/write.c							\
						generator_array.c							\
						generator_object.c							\
						getters/index/array/advanced_type.c			\
						getters/index/array/basic_type.c			\
						getters/index/array.c						\
						getters/index/object/advanced_type.c		\
						getters/index/object/basic_type.c			\
						getters/index/object.c						\
						getters/key/object/array.c					\
						getters/key/object/bool.c					\
						getters/key/object/nb.c						\
						getters/key/object/null.c					\
						getters/key/object/object.c					\
						getters/key/object/str.c					\
						getters/key/object.c						\
						getters/type.c								\
						getters/value/array/advanced_type.c			\
						getters/value/array/basic_type.c			\
						getters/value/array.c						\
						parser/array_advanced_type.c				\
						parser/array.c								\
						parser/key.c								\
						parser/object_advanced_type.c				\
						parser/object.c								\
						parser/setup.c								\
						parser/strtok.c								\
						parser/teardown.c							\
						parser/token/file.c							\
						parser/token/flag/array/bracket.c			\
						parser/token/flag/array/other.c				\
						parser/token/flag/array.c					\
						parser/token/flag/object/bracket.c			\
						parser/token/flag/object/other.c			\
						parser/token/flag/object.c					\
						parser/token/flag.c							\
						parser/token/str.c							\
						parser/token.c								\
						parser/type.c								\
						parser/value/array/basic_type.c				\
						parser/value/object/basic_type.c			\
						parser/value/str.c							\
						parser_fd.c									\
						parser_filepath.c							\
						parser_str.c								\
						token.c
						
OBJ_SRC				=	$(addprefix $(DIR), $(SRC:.c=.o))

BINARY				=	libjson.a

DIR_TEST			=	./tests/
SRC_TEST			=	editor/append.c						\
						editor/compare.c					\
						editor/set/index/array.c			\
						editor/set/key/object.c				\
						editor/unset/index.c				\
						editor/unset/value/array.c			\
						editor/unset/object.c				\
						get_file_content.c					\
						getters/index/array.c				\
						getters/index/object.c				\
						getters/key/object.c				\
						getters/value/array.c				\
						parser/json_array_fd.c				\
						parser/json_array_filepath.c		\
						parser/json_array_str.c				\
						parser/json_obj_fd.c				\
						parser/json_obj_filepath.c			\
						parser/json_obj_str.c				\
						parser/strtok.c						\
						parser/token/flag/array.c			\
						parser/token/flag/object.c

OBJ_TEST			=	$(addprefix $(DIR_TEST), $(SRC_TEST:.c=.o))

BINARY_TEST			=	unit_tests

DIR_GCOVR			=	gcovr
DIR_TEST_OUTPUT		=	tests/output

$(BINARY):	$(OBJ_SRC)
	@ar rc $@ $^

$(BINARY_TEST):	LDFLAGS	+=	-lcriterion --coverage
$(BINARY_TEST):	CFLAGS	+=	--coverage -I ./tests/include
$(BINARY_TEST):	$(OBJ_SRC) $(OBJ_TEST)
	@mkdir -p $(DIR_TEST_OUTPUT) $(DIR_TEST_OUTPUT)/obj $(DIR_TEST_OUTPUT)/array
	$(LD) -o $@ $^ $(LDFLAGS)

all: $(BINARY)

debug: CFLAGS += -ggdb3
debug: LDFLAGS += -ggdb3
debug: $(OBJ_SRC)
	$(LD) -o debug $^ main.c -I./include $(LDFLAGS) -ggdb3

clean:
	@echo -e "\e[31;1mRemoving $(BINARY) temporary files\e[0m"
	@rm -f $(OBJ_SRC) $(OBJ_SRC:.o=.gcno) $(OBJ_SRC:.o=.gcda)
	@rm -f $(OBJ_TEST) $(OBJ_TEST:.o=.gcno) $(OBJ_TEST:.o=.gcda)

fclean: clean
	@echo -e "\e[31;1mRemoving $(BINARY) temporary files\e[0m"
	@rm -f $(BINARY)
	@rm -f $(BINARY_TEST)
	@rm -rf $(DIR_GCOVR) $(DIR_TEST_OUTPUT)

tests_run: $(BINARY_TEST)
	@echo -e "\e[34;1m\nUNIT TEST\n\e[0m"
	@./$(BINARY_TEST)

gcovr: $(BINARY_TEST)
	@./$(BINARY_TEST)
	@mkdir -p $(DIR_GCOVR); cd $(DIR_GCOVR); gcovr -r ../ --exclude "../tests/" --exclude "../$(DIR_GCOVR)/" --html --html-details --html-title $(BINARY) -o $(BINARY).html

re: fclean all

.PHONY: all clean fclean re gcovr
