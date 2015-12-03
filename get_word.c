#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*get a word from file*/
int get_word(char *buf, int buf_size, FILE *fp) {
	int ch;
	int len = 0;
	while((ch = getc(fp)) != EOF) {
		if(isalnum(ch)){
			buf[len] = ch;
			len++;
			if(len >= buf_size) {
				len = 0;
				break;
			}
		}else {
			if(len == 0) {
				continue;
			}else {
				buf[len] = '\0';
				break;
			}
		}
	}
	if(ch == EOF) {
		return EOF;
	}else {
		return len;
	}
}