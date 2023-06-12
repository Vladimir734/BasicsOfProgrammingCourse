
# include <stdio.h>
# include <assert.h>
# include <malloc.h>
# include "unordered_array_set.h"

unordered_array_set unordered_array_set_create ( size_t capacity ) {
    return ( unordered_array_set ) {
            malloc ( sizeof ( int ) * capacity ),
            0,
            capacity
            };
    }

static void unordered_array_set_shrinkToFit ( unordered_array_set *a) {
    if (a-> size != a-> capacity ) {
        a-> data = ( int *) realloc (a->data , sizeof ( int ) * a-> size );
        a-> capacity = a-> size ;
    }
}

unordered_array_set unordered_array_set_create_from_array ( const int *a,size_t size_arr) {
    unordered_array_set set = unordered_array_set_create ( size_arr );
    for ( size_t i = 0; i < size_arr ; i ++)
        unordered_array_set_insert (& set , a[i]);

    return set ;
    }

int unordered_array_set_in(unordered_array_set *set, int value) {
    return linearSearch_((const int *) set->data, set->size , value );
}

int compare_ints(const void* a, const void* b) {
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;
    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}

bool unordered_array_set_isEqual ( unordered_array_set set1 ,
                                  unordered_array_set set2) {
    if ( set1.size != set2.size )
        return 0;
    qsort ( set1 .data , set1 .size , sizeof ( int ), compare_ints );
    qsort ( set2 .data , set2 .size , sizeof ( int ), compare_ints );
    return memcmp ( set1 .data , set2 .data , sizeof ( int )* set1 . size ) == 0;
    }

void unordered_array_set_isAbleAppend ( unordered_array_set * set ) {
    assert (set -> size < set -> capacity );
    }

void unordered_array_set_insert ( unordered_array_set *set , int value ) {
    if ( unordered_array_set_in (set , value ) == set->size ) {
        //unordered_array_set_isAbleAppend ( set );
        append_ ( set->data, &set ->size , value );
        }
    }

 void unordered_array_set_deleteElement ( unordered_array_set *set , int
value ) {
    int k=unordered_array_set_in (set , value );
    if (k!=set->size)
        deleteByPosSaveOrder_(set->data,&set->size,k);
}

unordered_array_set unordered_array_set_union (unordered_array_set set1,unordered_array_set set2){
    int k=set1.capacity+set2.capacity;
    unordered_array_set result;
    result=unordered_array_set_create ( k );

    for ( int i = 0; i < set1.size ; i++) {
        int value = set1.data[i];
        append_ ( result.data, &result.size , value );
    }

    for ( int i = 0; i < set2.size ; i++) {
        int value = set2.data[i];
        unordered_array_set_insert(&result, value);
    }
     unordered_array_set_shrinkToFit (& result );
    return result;
}

unordered_array_set unordered_array_set_intersection ( unordered_array_set set1 , unordered_array_set set2) {
    int k = set1.capacity;
    unordered_array_set result = unordered_array_set_create(k);
    for (int i=0;i<set1.size;i++) {

        int value = set1.data[i];
        int k1 = linearSearch_(set2.data, set2.size, value);
        if (k1 != set2.size) {
            //unordered_array_set_isAbleAppend(&result);--?????
            append_(result.data, &result.size, value);
        }
    }
    unordered_array_set_shrinkToFit (& result );
    return result;
}

unordered_array_set unordered_array_set_difference (
 unordered_array_set set1 , unordered_array_set set2 ) {
    int k = set1.capacity;
    unordered_array_set result = unordered_array_set_create(k);
    for (int i = 0; i < set1.size; i++) {
        int value = set1.data[i];
        int k1 = linearSearch_(set2.data, set2.size, value);
        if (k1 == set2.size) {
            //unordered_array_set_isAbleAppend(&result);--?????
            append_(result.data, &result.size, value);
        }
    }
    unordered_array_set_shrinkToFit(&result);

    return result;
}

unordered_array_set unordered_array_set_symmetricDifference (
unordered_array_set set1 , unordered_array_set set2){
    unordered_array_set temp1= unordered_array_set_create(set1.size);
    temp1=unordered_array_set_difference(set1,set2);
    unordered_array_set temp2= unordered_array_set_create(set1.size);
    temp2=unordered_array_set_difference(set2,set1);
    unordered_array_set result=unordered_array_set_union(temp1,temp2);
    unordered_array_set_delete ( temp1 );
    unordered_array_set_delete ( temp2 );
    unordered_array_set_shrinkToFit(&result);

    return result;
}
bool unordered_array_set_isSubset(unordered_array_set subset ,
                                  unordered_array_set set)
{
int k = 0;
for (int i = 0; i < subset.size; i++) {

int value = subset.data[i];
int k1 = linearSearch_(set.data, set.size, value);
if (k1 != set.size) {
k += 1;
}
}
if (k==subset.size)
    return true;
else
    return false;
}

unordered_array_set unordered_array_set_complement (
        unordered_array_set set , unordered_array_set universumSet) {
    unordered_array_set result = unordered_array_set_create(universumSet.size);
    if (unordered_array_set_isSubset(set,universumSet) != 0) {
        result=unordered_array_set_difference(universumSet, set);
    }
    unordered_array_set_shrinkToFit(&result);
    return result;
    }
void unordered_array_set_print ( unordered_array_set set ){
    printf("Элементы множества: ");
    outputArray_ (set.data, set.size);
}

void unordered_array_set_delete ( unordered_array_set set  ){
    free(set.data);
}