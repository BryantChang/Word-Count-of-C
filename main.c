#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "word_manager.h"
#include "get_word.h"
#define BUF_SIZE 1024

void usage() {
	printf("usage : ./word_count <the input file> <the output file>\n");
}

int main(int argc, char **argv) {
	if(argc < 3) {
		usage();
		return -1;
	}else {
		char file_input[BUF_SIZE],file_output[BUF_SIZE],buf[BUF_SIZE];
    	int word_len;
    	FILE *fp_in,*fp_out;
    	strcpy(file_input, argv[1]);
    	strcpy(file_output, argv[2]);
        printf("opening the input file....\n");
    	if((fp_in=fopen(file_input,"r"))==NULL) {
            printf("open input file error!\n");
            exit(1);
        }
        fp_out=fopen(file_output,"w");
        printf("init the word list....\n");
        init();
        printf("analyzing the word....\n");
        while(word_len = get_word(buf, BUF_SIZE, fp_in) != EOF) {
        	if(word_len != 0) {
        		add_word(buf);
        	}
        }
        printf("writting the result log....\n");
        dump_word(fp_out);
        printf("closing the file...\n");
        fclose(fp_in);
        fclose(fp_out);
        printf("finalizing the word list...\n");
        finalize();
        printf("all done\n");
	}
}