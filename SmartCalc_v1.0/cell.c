#include "header.h"

// Создаёт первый элемент списка
struct cell *create_cell(data cell_data) {
  struct cell *new_cell = malloc(sizeof(struct cell));
  new_cell->cell_data = cell_data;
  new_cell->next = NULL;
  return new_cell;
}

// Создаёт новый элемент списка
struct cell *append_cell(data cell_data, struct cell *next) {
  struct cell *new_cell;
  if(next==NULL){
    new_cell=create_cell(cell_data);
  }else{
  new_cell = malloc(sizeof(struct cell));
  new_cell->cell_data = cell_data;
  new_cell->next = next;
  }

  return new_cell;
}


void reverse(struct cell **head) {
  // Если список пустой, ничего не делаем
  if (*head == NULL) {
    return;
  }

  // Создаём указатель на последний элемент списка
  struct cell *current = *head;
  struct cell *previous = NULL;

  // Переходим по списку, меняя указатели на соседние элементы
  while (current != NULL) {
    struct cell *next = current->next;
    current->next = previous;
    previous = current;
    current = next;
  }

  // Обновляем указатель на голову списка
  *head = previous;
}

data pop(struct cell *stack) {
  data value;
  value.cell_type[0]='\0';
  value.priority=-1;
  value.value=0;
  // // Если стек пустой, ничего не делаем
  // if (stack->next == NULL) {
  //   return nul;
  // }
  if(stack){
  value = stack->cell_data;
  struct cell *sub_sell=stack->next;
  free(stack);

  stack=sub_sell;
  }


  return value;
}