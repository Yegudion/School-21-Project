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
  // Если стек пустой, ничего не делаем
  if (stack->next == NULL) {
    return;
  }

  // Сохраняем значение верхнего элемента
  data value = stack->next->cell_data;

  // Удаляем верхний элемент
  free(stack->next);
  stack->next = stack->next->next;

  // Возвращаем значение верхнего элемента
  return value;
}