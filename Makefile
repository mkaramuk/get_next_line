O_FILES = get_next_line.o get_next_line_utils.o main.o
NAME 	= gnl

$(NAME): $(O_FILES)
	@gcc $(O_FILES) -o gnl

.c.o:
	@gcc -c $<

clean:
	rm -f *.o $(NAME)

# Okunacak dosya adını 'make run file=dosyaadi' şeklinde verebilirsiniz.
run: $(NAME)
	./$(NAME) $(file)

.PHONY: run clean