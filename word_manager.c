#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "word_manager.h"
/*init the word manager*/
void init() {
	head = NULL;
}

/*release the manager*/
void finalize() {
	word_item *p;
	word_item *cur;
	cur = head;
	p = head;
	while(cur != NULL) {
		p = p->next;
		free(cur->word);
		free(cur);
		cur = p;
	}
}

/*create a new word_item node*/
static word_item* create_word(char *word) {
	char *tmp;
	word_item *item;
	item = (word_item*)malloc(sizeof(word_item));
	tmp = strdup(word);
	item->word = tmp;
	item->count = 1;
	item->next = NULL;
	return item;
}

//add a new node
void add_word(char *word){
	word_item *p, *pre, *new_item;
	int result;
	p = head;
	pre = NULL;
	while(p != NULL) {
		if((result = strcmp(p->word, word)) != 0) {
			pre = p;
			p = p->next;
		}else {
			break;
		}
	}

	//find the same word counter plus 1
	if(head != NULL && result == 0) {
		p->count++;
	}else {
		if(pre == NULL) {
			//printf("the head is %s", word);
			new_item = create_word(word);
			head = new_item;
		}else {
			new_item = create_word(word);
			new_item->next = p;
			pre->next = new_item;
		}
	}
}

/*write the result log*/
void dump_word(FILE *fp) {
	fprintf(fp, "==================word_count======================\n");
	word_item *p = head;
	while(p != NULL) {
		fprintf(fp, "%s:\t%d\n", p->word, p->count);
		p = p->next;
	}
}




