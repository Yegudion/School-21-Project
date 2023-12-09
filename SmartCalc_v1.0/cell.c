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
  struct cell *new_cell = malloc(sizeof(struct cell));
  new_cell->cell_data = cell_data;
  new_cell->next = next;
  return new_cell;
}