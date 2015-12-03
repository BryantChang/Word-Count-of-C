all:word_count
word_count:main.c word_manager.o get_word.o
	gcc  main.c word_manager.o get_word.o -o $@
word_manager.o:word_manager.c
	gcc -c  word_manager.c -o $@
get_word.o:get_word.c
	gcc -c  get_word.c -o $@
clean:
	rm -rf *.o
	rm -rf word_count