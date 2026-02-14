#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "c/519.c"

int main(int argc, char const *argv[])
{

    srand(time(NULL));

    int m = 10000, n = 10000;

    Solution* obj = solutionCreate(m, n);
    // int retSize;


    // int* param_1 = solutionFlip(obj, &retSize);
    // printf("%2d %2d \n", param_1[0], param_1[1]);
    // free(param_1);
    
    // param_1 = solutionFlip(obj, &retSize);
    // printf("%2d %2d \n", param_1[0], param_1[1]);
    // free(param_1);
    
    // param_1 = solutionFlip(obj, &retSize);
    // printf("%2d %2d \n", param_1[0], param_1[1]);
    // free(param_1);


    // solutionReset(obj);
    solutionFree(obj);
    return 0;
}
