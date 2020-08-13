#include "list.h"


struct arraylist* list_new(const size_t defaultSize){
  struct arraylist* list;
  
  list = calloc(1, sizeof(struct arraylist*));
  list->Array = calloc(defaultSize, sizeof(size_t));
  list->Size = defaultSize;
  list->LastElementIndex = 0;
  
  return list;
}


size_t list_size(struct arraylist* list){
    if(list != NULL){
        return list->LastElementIndex;
    }
    return 0;
}


void list_free(struct arraylist* list){
    free(list);
}

void list_add(struct arraylist* list, size_t const element){
    if(list == NULL) return;
    /*
     * Если лист переполнен необходимо увеличить размер массива, после чего выполнять вставку
     * */
    if((list->LastElementIndex + 1) == list->Size){
        list->Array = realloc(list->Array, (list->Size * CAPACITY_MULTIPLY) * sizeof(size_t));
        list->Size = list->Size * CAPACITY_MULTIPLY;
        list->Array[list->LastElementIndex++] = element;
    }
    else{
        /*
        * Обычная вставка
        * */
        list->Array[list->LastElementIndex++] = element;
    }
}

size_t list_capacity(struct arraylist* list){
    if(list != NULL){
        return list->Size;
    }
    return 0;
}


size_t list_get(struct arraylist* list, size_t index){
    if(index <= list->LastElementIndex){
        return list->Array[index];
    }
    return (size_t)NULL;
}

void list_remove(struct arraylist* list, size_t index){
    if(index < list->LastElementIndex){
        for(int i = index + 1; i < list->LastElementIndex; i++){
            list->Array[i - 1] = list->Array[i];
        }
        list->LastElementIndex--;
    }
}

size_t list_indexof(struct arraylist* list, size_t element){
    for(int i = 0; i < list->LastElementIndex; i++){
        if(list->Array[i] == element){
            return i;
        }
    }
    return (size_t)NULL;
}