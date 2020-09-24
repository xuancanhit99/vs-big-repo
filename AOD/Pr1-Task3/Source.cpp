#include <iostream>
#include <fstream>
#define BITSPERWORD 32
#define SHIFT 5
#define MASK 0x1F 
#define N 100
int a[1 + N / BITSPERWORD];


void setBit(int i) { a[i >> SHIFT] |= (1 << (i & MASK)); }
void clearBit(int i) { a[i >> SHIFT] &= ~(1 << (i & MASK)); }
int  testBit(int i) { return  a[i >> SHIFT] & (1 << (i & MASK)); }

int main(void)
{
    FILE* f = fopen("integers.txt", "r");
    int i;
    for (i = 0; i < N; i++)
        clearBit(i);

    printf("--input--\n");
    while (fscanf(f, "%d", &i;) != EOF) {
        printf("%d%s", i, ",");
        setBit(i);
    }

    printf("\n--output\n");
    for (i = 0; i < N; i++)
        if (!testBit(i))
            printf("%d%s", i, ",");

    return 0;
}