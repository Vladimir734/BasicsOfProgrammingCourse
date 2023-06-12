#include <stdio.h>
#include "libs/data_structures/unordered_array_set/unordered_array_set.h"
//#include "libs/data_structures/bitset/bitset.h"
#include <assert.h>
#include <windows.h>
#include "libs/data_structures/vector/vector.h"


//vector

void test_pushBack_emptyVector(){
    vector v = createVector(1);
    //printf ("%d ",isEmpty(&v));
    assert(isEmpty(&v)==true);
    pushBack(&v, 10);
    //printf ("%d ",isEmpty(&v));
    assert(isEmpty(&v)==false);
}
void test_pushBack_fullVector(){
    vector v = createVector(1);
    //printf ("%d ",isFull(&v));
    assert(isFull(&v)==false);
    pushBack(&v, 10);
    //printf ("%d ",isFull(&v));
    assert(isFull(&v)==true);
}
void test_popBack_notEmptyVector() {
    vector v = createVector(1);
    pushBack(&v, 10);
    assert(v.size == 1);
    popBack(&v);
    assert(v.size == 0);
    assert(v.capacity == 1);
}

void test_atVector_notEmptyVector(){
    vector v = createVector(1);
    pushBack(&v, 10);
    pushBack(&v, 100);
    pushBack(&v, 1000);
    assert(*atVector(&v,1)==100);
}
void test_atVector_requestToLastElement(){
    vector v = createVector(1);
    pushBack(&v, 10);
    assert(*atVector(&v,1));
}
void test_back_oneElementInVector(){
    vector v = createVector(2);
    pushBack(&v, 10);
    pushBack(&v, 100);
    //int t=*(back(&v));
    //printf("t %d ", t);
    assert(*(back(&v))==100);
}

void test_front_oneElementInVector(){
    vector v = createVector(2);
    pushBack(&v, 10);
    pushBack(&v, 100);
    //int t=*(front(&v));
    assert(*(front(&v))==10);
}

void test() {
    test_pushBack_emptyVector();
    test_pushBack_fullVector();
    test_popBack_notEmptyVector();
    test_atVector_notEmptyVector();
    test_atVector_requestToLastElement();
    test_back_oneElementInVector();
    test_front_oneElementInVector();

}


int main () {
    SetConsoleOutputCP(CP_UTF8);

    test();

    return 0;
}