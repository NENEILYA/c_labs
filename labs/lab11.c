
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#define MULT 2

typedef struct Stack_tag {
    char *word;
    struct Stack_t *prev;
} Stack_t;


int is_sep(char ch){
    return ch == ' ' || ch == '\t' || ch == '\n';
}


char *get_word(){
    int buffer = 64;
    char *word;
    if ((word = (char*)malloc(buffer * sizeof(char))) == NULL)
        return NULL;
    char c;
    int i;
    for (i = 0; !is_sep(c = getchar()); i++) {
        if (c == '0')
            return NULL;
        if (isalpha(c)){
            if (i >= buffer - 1) {
                if ((word = (char*)realloc(word, (buffer *= MULT) * sizeof(char))) == NULL)
                    return NULL;
            }
            word[i] = c;
        }else {
            i--;
        }
    }
    word[i] = '\0';
    return word;
}


Stack_t *create_stack(){
    Stack_t *prev = NULL, *new;
    char *word;
    while ((word = get_word()) != NULL){
        if ((new = (Stack_t*)malloc(sizeof(Stack_t))) == NULL)
            return prev;
        new->word = word;
        new->prev = prev;
        prev = new;
    }
    return prev;
}


void print_stack(Stack_t *top){
    while (top != NULL){
        printf("%s, ", top->word);
        top = top->prev;
    }
    printf("(NULL)\n");
}

void free_stack(Stack_t *top)
{Stack_t *change_elem;
    while (top != NULL){
        free(top->word);
        change_elem = top->prev;
        free(top);
        top = change_elem;}}



int main(){
    Stack_t *top;
    if ((top = create_stack()) == NULL)
        return 1;
    print_stack(top);
    free_stack(top);
    return 0;
}
