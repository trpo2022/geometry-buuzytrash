#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    double x, y, r;
    char *num = malloc(4 * sizeof(char)), *figure = malloc(4 * sizeof(char)),
         *str = malloc(4 * sizeof(char));
    char *cor1 = malloc(4 * sizeof(char)), *cor2 = malloc(4 * sizeof(char)),
         *rad = malloc(4 * sizeof(char));
    int i = 0, nof = 0, e = 0, f = 0;
    char cir[] = {"circle"};

    FILE* file = fopen("output.txt", "r");

    printf("Enter the number of figures:");
    scanf("%d", &nof);

    for (; e < nof; e++) {
        fgets(str, 100, file);
        if (strstr(str, cir) != NULL || strstr(figure, cir) != NULL) {
            if (strcmp(figure, cir) != 0) {
                strcpy(figure, "");
                i = 0;
            }
            while (str[i] != '\0') {
                if (strcmp(figure, cir) == 0)
                    f = i;
                if ((str[i] >= 65 && str[i] <= 90)
                    || (str[i] >= 97 && str[i] <= 122))

                    strncat(figure, &str[i], 1);
                else
                    break;
                i++;
            };

            while (str[i] != ')') {
                if (str[i] == '-')
                    strncat(num, &str[i], 1);
                if ((str[i] >= 48 && str[i] <= 57) || str[i] == '.')
                    strncat(num, &str[i], 1);
                i++;
                if (str[i] == ' ' && str[i - 1] != ',') {
                    strcpy(cor1, num);
                    strcpy(num, "");
                    x = atof(cor1);
                }
                if (str[i] == ',') {
                    strcpy(cor2, num);
                    strcpy(num, "");
                    y = atof(cor2);
                }
                if (str[i] == ')') {
                    strcpy(rad, num);
                    strcpy(num, "");
                    r = atof(rad);
                }
            }
            if (r <= 0)
                printf("Error! Incorrect radius. Please, try again\n");
            else if (strcmp(figure, cir) > 0) {
                printf("Error! Incorrent name of figure. Please try "
                       "again\n");
            } else if (strcmp(figure, cir) < 0) {
                printf("Error! Incorrent name of figure. Please try "
                       "again\n");
                strcpy(figure, "circle");
            } else
                printf("%s(%.3f %.3f, %.3f)\n", figure, x, y, r);
            i = f;
        }
    }
    fclose(file);

    free(str);
    free(num);
    free(cor1);
    free(cor2);
    free(rad);
    free(figure);
}