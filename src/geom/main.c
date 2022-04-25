#include <libgeom/geom.h>

int main()
{
    krug circle;
    double s = 0, p = 0;
    char *figure = malloc(4 * sizeof(char)), *str = malloc(4 * sizeof(char));
    char cir[] = {"circle"};
    int nof = 0, e = 1;

    FILE* file = fopen("output.txt", "r");

    printf("Enter the number of figures: ");
    scanf("%d", &nof);

    for (; e <= nof; e++) {
        fgets(str, 100, file);
        get_fig(str, figure);

        if ((fig_check(figure, cir) == 1)) {
            printf("%d) ", e);
            get_numbers(&circle, str);
            if ((circle.r > 0)) {
                p = perimeter(&circle);
                s = area(&circle);
                printf("%s(%.3f %.3f, %.3f)\nPerimeter: %.3f\nArea: %.3f\n",
                       figure,
                       circle.x,
                       circle.y,
                       circle.r,
                       p,
                       s);
            } else {
                printf("ERROR! Incorrect radius. Please, try again\n");
                circle.r = 0;
            }
        } else
            printf("%d) ERROR! Incorrect name of figure\n", e);
        for (int i = 0; i < 6; i++) {
            figure[i] = 0;
        }
    }
    fclose(file);
}