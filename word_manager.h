#ifndef WORD_MANAGER_H
#define WORD_MANAGER_H
//notify the structure of word_item 
typedef struct word_item {
	char *word;
	int count;
	struct word_item *next;
}word_item;
word_item *head;//the head of link list 
void init(); //init the word manager
void finalize();//release the manager
void create_word_item(char *word);//create a new word_item node
void add_word(char *word);//add a new node
void dump_word(FILE *fp);//write the result log
#endif