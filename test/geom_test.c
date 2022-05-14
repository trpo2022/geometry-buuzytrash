#include <ctest.h>
#include <libgeom/geom.h>

CTEST(getfig, test)
{
    char str[] = "circle(1.5 3, 5)", fig[10];
    get_fig(str, fig);

    ASSERT_STR(fig, "circle");
}

CTEST(figcheck, test)
{
    char str[] = "circle(1.5 3, 5)", fig[10];
    get_fig(str, fig);

    fig_check(fig, "circle");
}

CTEST(getnumbers, test_1)
{
    krug circle;
    char str[] = "circle(10 10, 10)";

    int error = 0;
    circle.error = 0;
    float x = 10, y = 10, rad = 10;

    get_numbers(&circle, str);

    ASSERT_DBL_NEAR(circle.p.x, x);
    ASSERT_DBL_NEAR(circle.p.y, y);
    ASSERT_DBL_NEAR(circle.r, rad);
    ASSERT_EQUAL(circle.error, error);
}

CTEST(getnumbers, test_2)
{
    krug circle;
    char str[] = "circle(-4 2, 3.5) af";

    int error = 1;
    circle.error = 0;
    float x = -4, y = 2, rad = 3.5;

    get_numbers(&circle, str);

    ASSERT_DBL_NEAR(circle.p.x, x);
    ASSERT_DBL_NEAR(circle.p.y, y);
    ASSERT_DBL_NEAR(circle.r, rad);
    ASSERT_EQUAL(circle.error, error);
}