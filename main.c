#include <stdio.h>
#include "libs/data_structures/unordered_array_set/unordered_array_set.h"
#include "libs/data_structures/bitset/bitset.h"
#include <assert.h>
#include <windows.h>

void test_unordered_array_set_in1() {
    printf("Test set in1:\n");
    unordered_array_set set1;
    set1 = unordered_array_set_create_from_array((int[]) {1, 2, 5, 7, 8}, 5);
    unordered_array_set_print(set1);
    int value = 2;
    int k = unordered_array_set_in(&set1, value);
    if (k == set1.size)
        printf("Элемента= %d в множестве нет\n", value);
    else
        printf("Элемент= %d в множестве на позиции с индексом %d\n", value, k);
    unordered_array_set_delete ( set1 );
}
void test_unordered_array_set_in2() {
    printf("Test set in2:\n");
    unordered_array_set set1;
    set1 = unordered_array_set_create_from_array((int[]) {2, 3,6,7}, 4);
    unordered_array_set_print(set1);
    int value=7;
    int k=unordered_array_set_in(&set1,value);
    if (k==set1.size)
        printf("Элемента= %d в множестве нет\n",value);
    else
        printf("Элемент= %d в множестве на позиции с индексом %d\n",value,k);
    unordered_array_set_delete ( set1 );
}

void test_unordered_array_set_isSubset1(){
    printf("Test set isSubset1:\n");
    unordered_array_set set1;
    set1 = unordered_array_set_create_from_array((int[]) {1, 2,5,7,8}, 5);
    unordered_array_set_print(set1);
    unordered_array_set set2;
    set2 = unordered_array_set_create_from_array((int[]) {2, 3,}, 2);
    unordered_array_set_print(set2);
    if (unordered_array_set_isSubset(set1,set2))
        printf("Множество 1 является подмножеством множества 2 \n");
    else
        printf("Множество 1 не является подмножеством множества 2 \n");
    unordered_array_set_delete ( set1 );
    unordered_array_set_delete ( set2 );
}
void test_unordered_array_set_isSubset2(){
    printf("Test set isSubset2:\n");
    unordered_array_set set1;
    set1 = unordered_array_set_create_from_array((int[]) {1, 2}, 2);
    unordered_array_set_print(set1);
    unordered_array_set set2;
    set2 = unordered_array_set_create_from_array((int[]) {1, 2,3}, 3);
    unordered_array_set_print(set2);
    if (unordered_array_set_isSubset(set1,set2))
        printf("Множество 1 является подмножеством множества 2 \n");
    else
        printf("Множество 1 не является подмножеством множества 2 \n");
    unordered_array_set_delete ( set1 );
    unordered_array_set_delete ( set2 );
}
void test_unordered_array_set_insert1 () {
    printf("Test set insert1:\n");
    unordered_array_set set1;
    set1 = unordered_array_set_create_from_array((int[]) {1, 2, 5, 7, 8}, 5);
    unordered_array_set_print(set1);
    int value = 9;
    unordered_array_set_insert(&set1, value);
    unordered_array_set_print(set1);
    unordered_array_set expectedSet =
            unordered_array_set_create_from_array((int[]) {1, 2, 5, 7, 8,9}, 6);
    assert ( unordered_array_set_isEqual ( set1 , expectedSet ));
    unordered_array_set_delete ( set1 );
    unordered_array_set_delete ( expectedSet );
}
void test_unordered_array_set_insert2 () {
    printf("Test set insert2:\n");
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {2, 3}, 2);
    unordered_array_set_print(set1);
    int value=5;
    unordered_array_set_insert(&set1,value);
    unordered_array_set_print(set1);
    unordered_array_set expectedSet =
            unordered_array_set_create_from_array((int[]) {2, 3,5}, 3);
    assert ( unordered_array_set_isEqual ( set1 , expectedSet ));
    unordered_array_set_delete ( set1 );
    unordered_array_set_delete ( expectedSet );
}
void test_unordered_array_set_deleteElement1 () {
    printf("Test set deleteElement1:\n");
    unordered_array_set set1;
    set1 = unordered_array_set_create_from_array((int[]) {1, 2, 5, 7, 8}, 5);
    unordered_array_set_print(set1);
    int value = 1;
    unordered_array_set_deleteElement(&set1, value);
    unordered_array_set_print(set1);
    unordered_array_set expectedSet =
            unordered_array_set_create_from_array((int[]) {2, 5, 7, 8}, 4);
    assert (unordered_array_set_isEqual(set1, expectedSet));
    unordered_array_set_delete(set1);
    unordered_array_set_delete ( expectedSet );
}
    void test_unordered_array_set_deleteElement2 (){
        printf("Test set deleteElement2:\n");
    unordered_array_set set1;
    set1 = unordered_array_set_create_from_array((int[]) {2, 3}, 2);
    unordered_array_set_print(set1);
    int value=3;
    unordered_array_set_deleteElement(&set1,value);
    unordered_array_set_print(set1);
    unordered_array_set expectedSet =
            unordered_array_set_create_from_array((int[]) {2}, 1);
    assert ( unordered_array_set_isEqual ( set1 , expectedSet ));
    unordered_array_set_delete ( set1 );
        unordered_array_set_delete ( expectedSet );
}

void test_unordered_array_set_union1 () {
    printf("Test Union1:\n");
    unordered_array_set set1;
    set1 = unordered_array_set_create_from_array((int[]) {1, 2,5,7,8}, 5);
    unordered_array_set_print(set1);
    unordered_array_set set2;
    set2 = unordered_array_set_create_from_array((int[]) {2, 3,4}, 3);
    unordered_array_set_print(set2);
    unordered_array_set resSet;
    resSet = unordered_array_set_union(set1, set2);
    unordered_array_set_print(resSet);
    unordered_array_set expectedSet =
            unordered_array_set_create_from_array (( int []) {1, 2,5,7,8,3,4}, 7);
    assert ( unordered_array_set_isEqual ( resSet , expectedSet ));

    unordered_array_set_delete ( set1 );
    unordered_array_set_delete ( set2 );
    unordered_array_set_delete ( resSet );
    unordered_array_set_delete ( expectedSet );
}

void test_unordered_array_set_union2 () {
    printf("Test Union2:\n");
    unordered_array_set set1 =
            unordered_array_set_create_from_array (( int []) {1, 2, 3}, 3);
    unordered_array_set_print(set1);
    unordered_array_set set2 =
            unordered_array_set_create_from_array (( int []) {1, 4}, 2);
    unordered_array_set_print(set2);

    unordered_array_set resSet;
    resSet = unordered_array_set_union (set1 , set2 );
    unordered_array_set_print(resSet);
    unordered_array_set expectedSet =
            unordered_array_set_create_from_array (( int []) {1, 2, 3,4}, 4);
    assert ( unordered_array_set_isEqual ( resSet , expectedSet ));

    unordered_array_set_delete ( set1 );
    unordered_array_set_delete ( set2 );
    unordered_array_set_delete ( resSet );
    unordered_array_set_delete ( expectedSet );
}

void test_unordered_array_set_intersection1 () {
    printf("Test intersection1: \n");
    unordered_array_set set1;
    set1 = unordered_array_set_create_from_array((int[]) {1, 2,5,7,8}, 5);
    unordered_array_set_print(set1);
    unordered_array_set set2;
    set2 = unordered_array_set_create_from_array((int[]) {2, 3,4}, 3);
    unordered_array_set_print(set2);
    unordered_array_set resSet;
    resSet = unordered_array_set_intersection(set1, set2);
    unordered_array_set_print(resSet);
    unordered_array_set expectedSet =
            unordered_array_set_create_from_array (( int []) {2}, 1);
    unordered_array_set_print(expectedSet);
    assert ( unordered_array_set_isEqual ( resSet , expectedSet ));

    unordered_array_set_delete ( set1 );
    unordered_array_set_delete ( set2 );
    unordered_array_set_delete ( resSet );
    unordered_array_set_delete ( expectedSet );
}
void test_unordered_array_set_intersection2 () {
    printf("Test intersection2: \n");
    unordered_array_set set1;
    set1 = unordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);
    unordered_array_set_print(set1);
    unordered_array_set set2;
    set2 = unordered_array_set_create_from_array((int[]) {1, 4}, 2);
    unordered_array_set_print(set2);
    unordered_array_set resSet;
    resSet = unordered_array_set_intersection(set1, set2);
    unordered_array_set_print(resSet);
    unordered_array_set expectedSet =
            unordered_array_set_create_from_array (( int []) {1}, 1);
    unordered_array_set_print(expectedSet);
    assert ( unordered_array_set_isEqual ( resSet , expectedSet ));

    unordered_array_set_delete ( set1 );
    unordered_array_set_delete ( set2 );
    unordered_array_set_delete ( resSet );
    unordered_array_set_delete ( expectedSet );
}

void test_unordered_array_set_difference1 () {
    printf("Test difference1 \n");
    unordered_array_set set1;
    set1 = unordered_array_set_create_from_array((int[]) {1, 2,5,7,8}, 5);
    unordered_array_set_print(set1);
    unordered_array_set set2;
    set2 = unordered_array_set_create_from_array((int[]) {2, 3}, 2);
    unordered_array_set_print(set2);
    unordered_array_set resSet;
    resSet = unordered_array_set_difference(set1, set2);
    unordered_array_set_print(resSet);
    unordered_array_set expectedSet =
            unordered_array_set_create_from_array (( int []) {1, 5, 7,8}, 4);
    assert ( unordered_array_set_isEqual ( resSet , expectedSet ));

    unordered_array_set_delete ( set1 );
    unordered_array_set_delete ( set2 );
    unordered_array_set_delete ( resSet );
    unordered_array_set_delete ( expectedSet );
}

void test_unordered_array_set_difference2 () {
    printf("Test difference2 \n");
    unordered_array_set set1;
    set1 = unordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);
    unordered_array_set_print(set1);
    unordered_array_set set2;
    set2 = unordered_array_set_create_from_array((int[]) {1, 4}, 2);
    unordered_array_set_print(set2);
    unordered_array_set resSet;
    resSet = unordered_array_set_difference(set1, set2);
    unordered_array_set_print(resSet);
    unordered_array_set expectedSet =
            unordered_array_set_create_from_array (( int []) {2, 3}, 2);
    assert ( unordered_array_set_isEqual ( resSet , expectedSet ));

    unordered_array_set_delete ( set1 );
    unordered_array_set_delete ( set2 );
    unordered_array_set_delete ( resSet );
    unordered_array_set_delete ( expectedSet );
}
void test_unordered_array_set_symmetricDifference1 () {
    printf("Test symmetricDifference1 \n");
    unordered_array_set set1;
    set1 = unordered_array_set_create_from_array((int[]) {1, 2,5,7,8}, 5);
    unordered_array_set_print(set1);
    unordered_array_set set2;
    set2 = unordered_array_set_create_from_array((int[]) {2, 3}, 2);
    unordered_array_set_print(set2);
    unordered_array_set resSet;
    resSet = unordered_array_set_symmetricDifference(set1, set2);
    unordered_array_set_print(resSet);
    unordered_array_set expectedSet =
            unordered_array_set_create_from_array (( int []) {1, 5,7,8,3}, 5);
    assert ( unordered_array_set_isEqual ( resSet , expectedSet ));
    unordered_array_set_delete ( set1 );
    unordered_array_set_delete ( set2 );
    unordered_array_set_delete ( resSet );
    unordered_array_set_delete ( expectedSet );
}
void test_unordered_array_set_symmetricDifference2 () {
    printf("Test symmetricDifference2 \n");
    unordered_array_set set1;
    set1 = unordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);
    unordered_array_set_print(set1);
    unordered_array_set set2;
    set2 = unordered_array_set_create_from_array((int[]) {1, 4}, 2);
    unordered_array_set_print(set2);
    unordered_array_set resSet;
    resSet = unordered_array_set_symmetricDifference(set1, set2);
    unordered_array_set_print(resSet);
    unordered_array_set expectedSet =
            unordered_array_set_create_from_array (( int []) {2, 3,4}, 3);
    assert ( unordered_array_set_isEqual ( resSet , expectedSet ));
    unordered_array_set_delete ( set1 );
    unordered_array_set_delete ( set2 );
    unordered_array_set_delete ( resSet );
    unordered_array_set_delete ( expectedSet );
}

void test_unordered_array_set_complement1 () {
    printf("Test complement1: \n");
    unordered_array_set set1;
    set1 = unordered_array_set_create_from_array((int[]) {1, 2,5,7,8}, 5);
    unordered_array_set_print(set1);
    unordered_array_set universumSet=
    unordered_array_set_create_from_array (( int []) {0, 1, 2,3, 4, 5,6, 7, 8, 9}, 10);
    unordered_array_set resSet;
    resSet = unordered_array_set_complement(set1, universumSet);
    unordered_array_set_print(resSet);
    unordered_array_set expectedSet =
            unordered_array_set_create_from_array (( int []) {0, 3, 4,6,9}, 5);
    assert ( unordered_array_set_isEqual ( resSet , expectedSet ));
    unordered_array_set_delete ( set1 );
    unordered_array_set_delete ( resSet );
    unordered_array_set_delete ( expectedSet );
}
void test_unordered_array_set_complement2 () {
    printf("Test complement2: \n");
    unordered_array_set set1;
    set1 = unordered_array_set_create_from_array((int[]) {2, 3}, 2);
    unordered_array_set_print(set1);
    unordered_array_set universumSet=
            unordered_array_set_create_from_array (( int []) {0, 1, 2,3, 4, 5,6, 7, 8, 9}, 10);

    unordered_array_set resSet;
    resSet = unordered_array_set_complement(set1, universumSet);
    unordered_array_set_print(resSet);
    unordered_array_set expectedSet =
            unordered_array_set_create_from_array (( int []) {0, 1, 4,5,6,7,8,9}, 8);
    assert ( unordered_array_set_isEqual ( resSet , expectedSet ));
    unordered_array_set_delete ( set1 );
    unordered_array_set_delete ( resSet );
    unordered_array_set_delete ( expectedSet );
}
void test_unordered_array_set_in (){
    test_unordered_array_set_in1();
    test_unordered_array_set_in2();
}
void test_unordered_array_set_isSubset (){
    test_unordered_array_set_isSubset1();
    test_unordered_array_set_isSubset2();
}
void test_unordered_array_set_insert (){
    test_unordered_array_set_insert1 ();
    test_unordered_array_set_insert2 ();
}
void test_unordered_array_set_deleteElement (){
    test_unordered_array_set_deleteElement1 ();
    test_unordered_array_set_deleteElement2 ();
}
void test_unordered_array_set_union () {
    test_unordered_array_set_union1 ();
    test_unordered_array_set_union2 ();
}
void test_unordered_array_set_intersection () {
    test_unordered_array_set_intersection1 ();
    test_unordered_array_set_intersection2 ();
}
void test_unordered_array_set_difference () {
    test_unordered_array_set_difference1 ();
    test_unordered_array_set_difference2 ();
}
void test_unordered_array_set_symmetricDifference () {
    test_unordered_array_set_symmetricDifference1 ();
    test_unordered_array_set_symmetricDifference2 ();
}
void test_unordered_array_set_complement () {
    test_unordered_array_set_complement1 ();
    test_unordered_array_set_complement2 ();
}
   void test () {
       test_unordered_array_set_in ();
       test_unordered_array_set_isSubset ();
       test_unordered_array_set_insert ();
       test_unordered_array_set_deleteElement ();
       test_unordered_array_set_union ();
       test_unordered_array_set_intersection ();
       test_unordered_array_set_difference ();
       test_unordered_array_set_symmetricDifference ();
       test_unordered_array_set_complement ();
       }
int main () {
    SetConsoleOutputCP(CP_UTF8);
    test();
    return 0;
    }
