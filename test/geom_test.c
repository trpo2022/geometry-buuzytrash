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
