#include <stdio.h>
#include <stdlib.h>

#include "c/419.c"

int main(int argc, char const *argv[])
{
    printf("%d\n", countBattleships(
        (char *[]){
            "X..X",
             "...X", 
             "...X"}, 
            3, (int[]){4, 4, 4})); // Output: 2
    return 0;
}
