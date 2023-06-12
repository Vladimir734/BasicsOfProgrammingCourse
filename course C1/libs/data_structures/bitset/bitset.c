
# include <stdio.h>
# include <assert.h>

# include "bitset.h"
//# include <stdint.h>
# include <stdbool.h>

int bitset_checkValue ( bitset *a, unsigned value ) {
   return value >= 0 && value <= a-> maxValue ;
    }

bitset bitset_create ( unsigned setMaxValue ) {
    assert ( setMaxValue < 32) ;
    return ( bitset ) {0, setMaxValue };
     }

bitset bitset_intersection ( bitset set1 , bitset set2 ) {
    //Пересечение множеств реализуется через побитовое И
    //𝐴 ∩ 𝐵 ⇒ A & B

    //  только в случае, если универсумы совпадают
    assert ( set1 . maxValue == set2 . maxValue );
    return ( bitset ){ set1 . values & set2 . values , set1 . maxValue };
    }
bool bitset_isSubset ( bitset subset , bitset set ){
    //Проверка на то, что множество B нестрого включает множество A
    //𝐴 ⊆ 𝐵 ⇒ B & A == A
    assert ( subset . maxValue == set . maxValue );
    return (set.values & subset.values)==subset.values;
    //Проверка на то, что множество B строго включает множество A
    //𝐴 ⊂ 𝐵 ≡ 𝐴 ⊆ 𝐵 и 𝐴 ̸= 𝐵 ⇒ (B & A == A) && (A != B)
}

bitset bitset_difference ( bitset set1 , bitset set2 ){
    //𝐴∖𝐵 ⇒ A & ∼B
    assert ( set1 . maxValue == set2 . maxValue );
    return ( bitset ){ set1.values & ~ set2.values,set1.maxValue };
}

bitset bitset_symmetricDifference ( bitset set1 , bitset set2 ){
    //𝐴 △𝐵 ≡ (𝐴∖𝐵) ∪ (𝐵 ∖𝐴) ⇒ A ˆ B
    assert ( set1 . maxValue == set2 . maxValue );
    return ( bitset ){ set1.values ^ set2.values,set1.maxValue };
}

bitset bitset_complement ( bitset set ){
    //𝑛 - количество неиспользуемых бит в пред-
    //ставлении множества, тогда операция дополнения:
    //𝐴 ⇒ (∼A ≪ n) ≫ n
    int n=0;
    bitset result= bitset_create(set.maxValue);
    for ( int i = 0; i <= set . maxValue ; ++i) {
        if ( !bitset_in (set , i))
            bitset_insert (&result,i);}
    return result;
}
    void bitset_insert ( bitset *set , unsigned int value ) {
    //A | (1 ≪ x)
    //Если комбинировать операцию побитового сдвига влево и побитового ИЛИ, мож-
    //но выставить значение 𝑖-го бита в единицу
    set->values=set->values | (1<< value);
    //set->maxValue++;
}
bool bitset_isEqual ( bitset set1 , bitset set2 ){
    assert ( set1 . maxValue == set2 . maxValue );
    return set1.values==set2.values;
}

bool bitset_in ( bitset set , unsigned int value ){
    //Если комбинировать операцию побитового сдвига вправо и побитового И, можно
    //узнать значение 𝑖-го бита числа 𝑛:
    //𝑏𝑖𝑡 := 𝑛≫𝑖&1
    //printf ("%d ",set.values>>value&1);
    return (set.values>>value&1);
}

void bitset_deleteElement ( bitset *set , unsigned int value ){
    //Если комбинировать операцию побитового сдвига влево, побитового И
    // и побитового НЕ, можно выставить значение 𝑖-го бита в ноль:
    // 𝑛 := 𝑛& ∼ (1≪𝑖)
    set->values= (set->values & ~ (1<<value));
}
bitset bitset_union ( bitset set1 , bitset set2 ){
    //реализуется за счёт применения побитового ИЛИ
    //𝐴 ∪ 𝐵 ⇒ A | B
    assert ( set1 . maxValue == set2 . maxValue );
    return (bitset) {set1.values | set2.values,set1.maxValue};

}

void bitset_print ( bitset set ) {
    printf ("{");
    int isEmpty = 1;
    for ( int i = 0; i <= set . maxValue ; ++i) {
        if ( bitset_in (set , i)) {
            printf ("%d    ", i);
            isEmpty = 0;
            }
        }
    if ( isEmpty )
         printf ("}\n");
    else
    printf ("\b\b}\n");
     }



