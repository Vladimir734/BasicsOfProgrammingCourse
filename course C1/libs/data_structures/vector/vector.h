#ifndef COURSE_C1_VECTOR_H
#define COURSE_C1_VECTOR_H

# include <stdint.h>
# include <assert.h>
# include <memory.h>
# include <stdio.h>
# include <stdbool.h>
typedef struct vector {
    int *data; // указатель на элементы вектора
    size_t size; // размер вектора
    size_t capacity; // вместимость вектора
} vector;

//возвращает структуру-дескриптор вектор из n значений.
vector createVector(size_t n);

//изменяет количество
//памяти, выделенное под хранение элементов вектора
void reserve(vector *v, size_t newCapacity);

//удаляет элементы из контейнера, но не освобож-
//дает выделенную память.
void clear(vector *v);

//освобождает память, выделенную под
//неиспользуемые элементы.
void shrinkToFit(vector *v);

//освобождает память, выделенную век-
//тору
void deleteVector(vector *v);

//проверки на то, является ли вектор пустым
bool isEmpty(vector *v);

//проверки на то, является ли вектор полным
bool isFull(vector *v);

//возвращает i-ый элемент вектора v.
int getVectorValue(vector *v, size_t i);

//добавляет элемент x в конец вектора
//v. Если вектор заполнен, увеличьте количество выделенной ему памяти в
//2 раза, используя reserve.
void pushBack(vector *v, int x);

//удаляет последний элемент из вектора. Функ-
//ция должна ’выкидывать’ в поток ошибок сообщение, если вектор пуст и
//закончить выполнение с кодом 1.
void popBack(vector *v);

//возвращает указатель на
//index-ый элемент вектора. Если осуществляется попытка получить доступ
//вне пределов используемых элементов вектора, в поток ошибок должна
//выводиться ошибка: "IndexError: a[index] is not exists", где в каче-
//стве index указывается позиция элемента, к которому пытались осуще-
//ствить доступ.
int* atVector(vector *v, size_t index);

//возвращает указатель на последний элемент век-
//тора.
int* back(vector *v);

//возвращает указатель на нулевой элемент век-
//тора.0
int* front(vector *v);

#endif //COURSE_C1_VECTOR_H