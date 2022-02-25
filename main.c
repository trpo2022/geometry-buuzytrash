#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// struct Point {
//     float x;
//     float y;
// };

// struct Circle {
//     struct Point xy;
//     float rad;
// } typedef Circle;

// struct Triangle {
//     struct Point xy1;
//     struct Point xy2;
//     struct Point xy3;
//     struct Point xy4;
// } typedef Triangle;

// int number(int y)
// {
//     int x = y - 48;
//     return x;
// }

int main()
{
    FILE* file = fopen("output.txt", "r");
    int a = 0, b = 0;
    int i = 0, k = 0, N = 100, number_of_figures;
    char *str = NULL, cir[] = {"circle"}, tri[] = {"triangle"}, numbers[N];

    printf("Enter the number figures : ");
    scanf("%d", &number_of_figures);

    for (i = 0; i < number_of_figures; i++) {
        str = malloc(N * sizeof(char));
        fgets(str, 100, file);
    }
    printf("\n");
    free(str);

    fclose(file);

    return 0;
}