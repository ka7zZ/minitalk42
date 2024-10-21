#include <stdio.h>
#include <unistd.h>

int main() {
    char c = 'a';
    unsigned char bit = c;
    unsigned char ch;
    int i = 8;

    while (i--)
    {
        ch = (bit >> i & 1) + '0';
        write(1, &ch, 1);
    }
    
}

// 128 64 32 16 8 4 2 1
// 0   1   1  0 0 0 0 1