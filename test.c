#include <stdio.h>
#include <assert.h>

#include "bound.h"
#include "clamp.h"

int main(void) {
    // Test Macros

    assert(5 == clamp_upper(5, 5));
    assert(4 == clamp_upper(5, 4));
    assert(4 == clamp_upper(10, 4));
    assert(-1 == clamp_upper(-1, 4));

    assert(5 == clamp_lower(5, 5));
    assert(5 == clamp_lower(5, 2));
    assert(9 == clamp_lower(9, 2));
    assert(2 == clamp_lower(-1, 2));

    assert(5 == clamp_range(5, 0, 5));
    assert(4 == clamp_range(5, 0, 4));
    assert(4 == clamp_range(10, 0, 4));
    assert(0 == clamp_range(-1, 0, 4));

    assert(!is_below_bound(5, 5));
    assert(!is_below_bound(5, 4));
    assert(!is_below_bound(10, 4));
    assert(is_below_bound(-1, 4));

    assert(!is_above_bound(5, 5));
    assert(is_above_bound(5, 2));
    assert(is_above_bound(9, 2));
    assert(!is_above_bound(-1, 2));

    assert(is_within_bound(5, 0, 5));
    assert(!is_within_bound(5, 0, 4));
    assert(!is_within_bound(10, 0, 4));
    assert(!is_within_bound(-1, 0, 4));

    // Generate Report Card
    printf("# ---- REPORT ----");
    const int min = -2;
    const int max = 2;

    printf("# Bounded/Clamped Value Macros Outputs");
    printf("\n");
    printf("* min = %d\n", min);
    printf("* max = %d\n", max);

    printf("\n");
    printf("## Clamped Value Macros Outputs\n");
    printf("| i | clamp_upper | clamp_lower | clamp_range |\n");
    printf("|:---:|:---:|:---:|:---:|\n");
    for (int i = -5; i <= 5; i++) 
    {
        printf("| %2d | %2d | %2d | %2d |\n", i, clamp_upper(i, max), clamp_lower(i, min), clamp_range(i, min, max));
    }

    printf("\n");
    printf("## Bounded Value Macros Outputs\n");
    printf("| i | is_below_bound | is_above_bound | is_within_bound | is_out_of_bound |\n");
    printf("|:---:|:---:|:---:|:---:|:---:|\n");
    for (int i = -5; i <= 5; i++) 
    {
        printf("| %2d | %s | %s | %s | %s |\n", i, is_below_bound(i, min) ? "**true**":"false", is_above_bound(i, max) ? "**true**":"false", is_within_bound(i, min, max) ? "**true**":"false", is_out_of_bound(i, min, max) ? "**true**":"false");
    }

    return 0;
}