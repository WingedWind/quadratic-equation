#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "floats.h"
#include "test.h"
#include "solver.h"
#include "overall.h"

void test(void)
{
    int n_failed_tests_quadratic = test_solve_quadratic();
    if (n_failed_tests_quadratic != 0)
        printf("TESTS FAILED (function solve_quadratic): "
               "number of failed tests: %d\n", n_failed_tests_quadratic);
    else
        printf("TESTS PASSED (function solve_quadratic)\n");

    int n_failed_tests_square_linear = test_solve_linear();
    if (n_failed_tests_square_linear != 0)
        printf("TESTS FAILED (function solve_linear): "
               "number of failed tests: %d\n", n_failed_tests_square_linear);
    else
        printf("TESTS PASSED (function solve_linear)\n");
}

int input(float *a, float *b, float *c)
{
    int numbersEntered = scanf("%f %f %f", a, b, c);
    if (numbersEntered != 3)
    {
        printf("INPUT ERROR: incorrect number of values\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

int print(enum roots_num  n_roots, const float root1, const float root2)
{
    switch (n_roots)
    {
        case NO_ROOTS:
            printf("The quadratic equation has no roots\n");
            break;

        case ONE_ROOT:
            printf("The quadratic equation has one root: %g\n", root1);
            break;

        case TWO_ROOTS:
            printf(
                "The quadratic equation has two roots\n"
                "First: %g\n"
                "Second: %g\n",
                root1, root2
            );
            break;

        case INF_ROOTS:
            printf("The equation has an infinite number of solutions\n");
            break;

        default:
            printf(
                "INTERNAL ERROR: solve_quadratic returned"
                " a unexpected number of roots: %g\n",
                n_roots
            );
            return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
