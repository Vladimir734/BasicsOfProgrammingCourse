# include <stdio.h>
# include <assert.h>
# include <malloc.h>
# include "vector.h"

vector createVector(size_t n){
    if (n==SIZE_MAX) {
        fprintf(stderr, "bad alloc");
        exit(1);}
    return ( vector ) {
            malloc ( sizeof ( int ) * n ),
            0,
            n
    };
}
void reserve(vector *v, size_t newCapacity){
    if (newCapacity==0){
        v->data=NULL;
        v->capacity=newCapacity;
    }
    if (newCapacity<v->size){
        v->size=newCapacity;
    }
    if (newCapacity==SIZE_MAX) {
        fprintf(stderr, "bad alloc");
        exit(1);}

    if (newCapacity > v-> capacity ) {
        v-> data = ( int *) realloc (v->data , newCapacity);//sizeof ( int ) * v-> size );
        v-> capacity = newCapacity;
    }
}

void clear(vector *v) {
    v->size=0;
}

void shrinkToFit(vector *v){
    v-> data = ( int *) realloc (v->data , sizeof ( int ) * v-> size );
    v-> capacity = v-> size ;
}

void deleteVector(vector *v){
    free(v->data);
}

bool isEmpty(vector *v){
    return v->size==0;
}

bool isFull(vector *v){
    return v->size==v->capacity;
}

void pushBack(vector *v, int x){
    if (v->capacity==0) {
        fprintf(stderr, "vector isEmpty");
        exit(1);}
    if (v->size==v->capacity)
        reserve( v, 2*(v->capacity));
    v->data[v->size]=x;
    v->size++;
}

void popBack(vector *v){
    if (v->size==0){
        fprintf(stderr, "vector isEmpty");
        exit(1);}
    v->size--;
}

int* back(vector *v){

    return v->data+v->size-1;//(int *) v->data[v->size-1];//????
}

int getVectorValue(vector *v, size_t i){
    return v->data[i];
}

int* front(vector *v){
    return v->data;
}

int* atVector(vector *v, size_t index){
    if (index>v->size) {
        fprintf(stderr,"IndexError: a[%d] is not exists",index);
        exit(1);
    }
    return &v->data[index];
}