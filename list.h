#ifndef LIST_H
#define LIST_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>


#define CAPACITY_MULTIPLY 2


/*
 * @param __Array contains array of list elements
 * @param __Size contatins capacity of list
 * @param __LastElementIndex contains last element index + 1
 * 
 **/
struct arraylist{
    size_t* Array;
    size_t Size;
    size_t LastElementIndex;
};

/*
 * Returning new list with defaultSize capacity
 * @param __defaultSize Capacity of new list
 * 
 * */
struct arraylist* list_new(const size_t defaultSize);

/*
 * Free memory used by list
 * @param __list Pointer for the arraylist structure 
 * 
 * */
void list_free(struct arraylist* list);

/*
 * Returning count of list elements
 * @param __list Pointer for the arraylist structure 
 * 
 * */
size_t list_size(struct arraylist* list);


/*
 * Returning list element by his index
 * @param __list Pointer for the arraylist structure 
 * @param __index Index for the element
 * */
size_t list_get(struct arraylist* list, size_t index);

/*
 * Adding element to the list
 * @param __list Pointer for the arraylist structure 
 * @param __element Element that will be added to list
 * 
 * Function multiply capacity each time when count of elements - 1 = current capacity
 * */
void list_add(struct arraylist* list, size_t const element);


/*
 * Removes element form list
 * @param __list Pointer for the arraylist structure 
 * @param __index index of element that need to be removed
 * 
 * Function removes element with given index, after it moves
 * all elements, placed righter than index to left
 * */
void list_remove(struct arraylist* list, size_t index);

/*
 * Returning current list maxium of elements
 * @param __list Pointer for the arraylist structure 
 * 
 * */
size_t list_capacity(struct arraylist* list);

/*
 * Returning element by his index
 * @param __list Pointer for the arraylist structure 
 * @param __element Element which index needed
 * 
 * */
size_t list_indexof(struct arraylist* list, size_t element);

#endif /* LIST_H */