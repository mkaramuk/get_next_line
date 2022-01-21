O_FILES = get_next_line.o get_next_line_utils.o main.o
NAME 	= gnl

$(NAME): $(O_FILES)
	@gcc $(O_FILES) -o gnl

.c.o:
	@gcc -c $<

tester1: $(O_FILES)
	make -C gnltester2 m

tester2: $(O_FILES)
	make -C gnltester1

clean:
	rm -f *.o $(NAME)

run: $(NAME)
	./$(NAME) $(file)


.PHONY: run tester1 tester2 clean