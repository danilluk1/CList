#include <stdio.h>
#include "list.h"

void print_list_info(struct arraylist* const list){
    printf("List capacity: %I64d\n", list_capacity(list));
    printf("List last element index: %I64d\n", list_size(list));
}


int main(int argc, char **argv)
{
	printf("Creating list:\n");
    struct arraylist* list = list_new(10);
    
    if(list != NULL){
        printf("Created %I64d-elements list.\n", list_capacity(list));
    }
    else{
        printf("Cannot allocate memory for list.\n");
    }
    
    for(int i = 0; i < 10; i++){
        list_add(list, i);
    }
    
    printf("Resulting list:\n");
    
    for(int i = 0; i < list->LastElementIndex; i++){
        printf("%I64d", list_get(list, i));
    }
    
    printf("\n");
    
    print_list_info(list);
    
    list_add(list, 10);
    
    printf("Resulting list with added 10:\n");
    
    for(int i = 0; i < list->LastElementIndex; i++){
        printf("%I64d", list_get(list, i));
    }
    
    printf("\n");
    
    print_list_info(list);
    
    list_remove(list, 0);
    printf("Resulting list with removed element at 0 index:\n");
    
    for(int i = 0; i < list->LastElementIndex; i++){
        printf("%I64d", list_get(list, i));
    }
    
    printf("\n");

    
    print_list_info(list);
    printf("\n");
    printf("Try get element = 0\n");
    printf("Element index = %I64d\n", list_indexof(list, 10));
    
    list_free(list);
    
	return 0;
}
