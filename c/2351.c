#include <stdio.h>

char repeatedCharacter(char* s) {
    int32_t storage = 0;
    short offset = 0;
    for(size_t i = 0; s[i] != '\0'; i++){
        offset = s[i] - 'a' + 1;
        if(storage & (1 << offset))
            return s[i];
        storage |= (1 << offset);
    }

    return '\n'; // will never be called, just the compiler needs it
}

int main(int argc, char const *argv[])
{
    printf("%c\n", repeatedCharacter("abccbaacz")); // Output: 'c'

    return 0;
}
