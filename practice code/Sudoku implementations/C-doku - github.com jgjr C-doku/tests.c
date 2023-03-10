#include <stdarg.h>
#include <string.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include "helpers.h"
#include "sudoku.h"

/* Test helpers */

void test_random_in_range() {
    int random = random_in_range(20);
    assert_in_range(random, 0, 20);
}

void test_group_has_duplicates() {
    Group group1 = { .values = {1, 2, 3, 4, 5, 6, 7, 8, 9}, .count = 9 };
    assert_false(group_has_duplicates(group1));
    Group group2 = { .values = {1, 2, 3, 4, 5, 5, 7, 8, 9}, .count = 9 };
    assert_true(group_has_duplicates(group2));
}

/* Test sudoku */

int blank_grid[81] = {0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0};

int complete_valid_grid[81] = {1, 2, 3, 4, 5, 6, 7, 8, 9,
    4, 5, 6, 7, 8, 9, 1, 2, 3,
    7, 8, 9, 1, 2, 3, 4, 5, 6,
    2, 1, 4, 3, 6, 5, 8, 9, 7,
    3, 6, 5, 8, 9, 7, 2, 1, 4,
    8, 9, 7, 2, 1, 4, 3, 6, 5,
    5, 3, 1, 6, 4, 2, 9, 7, 8,
    6, 4, 2, 9, 7, 8, 5, 3, 1,
    9, 7, 8, 5, 3, 1, 6, 4, 2};

int incomplete_valid_grid[81] = {0, 2, 3, 4, 5, 6, 7, 8, 9,
    4, 5, 6, 7, 8, 9, 1, 2, 3,
    7, 8, 9, 1, 2, 3, 4, 5, 6,
    2, 1, 4, 3, 6, 5, 8, 9, 7,
    3, 6, 5, 8, 9, 7, 2, 1, 4,
    8, 9, 7, 2, 1, 4, 3, 6, 5,
    5, 3, 1, 6, 4, 2, 9, 7, 8,
    6, 4, 2, 9, 7, 8, 5, 3, 1,
    9, 7, 8, 5, 3, 1, 6, 4, 0};

int single_solution_game[81] = {7, 0, 1, 0, 5, 0, 0, 4, 0,
    0, 2, 5, 3, 0, 0, 8, 0, 1,
    0, 0, 4, 6, 0, 9, 0, 7, 5,
    0, 7, 3, 9, 8, 0, 5, 1, 0,
    0, 0, 2, 0, 0, 0, 4, 0, 0,
    0, 0, 0, 0, 0, 1, 6, 3, 7,
    8, 4, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 2, 0, 0, 1, 6, 0,
    2, 0, 6, 0, 0, 3, 0, 0, 8};

int multiple_solution_game[81] = {0, 0, 0, 0, 5, 0, 0, 4, 0,
    0, 2, 5, 3, 0, 0, 8, 0, 1,
    0, 0, 4, 6, 0, 9, 0, 7, 5,
    0, 7, 3, 9, 8, 0, 5, 1, 0,
    0, 0, 2, 0, 0, 0, 4, 0, 0,
    0, 0, 0, 0, 0, 1, 6, 3, 7,
    8, 4, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 2, 0, 0, 1, 6, 0,
    2, 0, 6, 0, 0, 3, 0, 0, 8};

int bad_rows_grid[81] = {0, 0, 1, 1, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0};

int bad_cols_grid[81] = {0, 0, 1, 0, 0, 0, 0, 0, 0,
    0, 0, 1, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0};

int bad_boxes_grid[81] = {1, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 1, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0};

void test_new_blank_grid() {
    Grid* grid = new_blank_grid();
    assert_int_equal(grid->values[0], 0);
    assert_int_equal(grid->values[80], 0);
    assert_int_equal(grid->blanks[0], 0);
    assert_int_equal(grid->blanks[80], 80);
    assert_int_equal(grid->blank_count, 81);
}

void test_check_rows() {
    Grid grid;
    memcpy(grid.values, bad_rows_grid, sizeof(bad_rows_grid));
    assert_false(check_rows(&grid));
    Grid grid2;
    memcpy(grid2.values, complete_valid_grid, sizeof(complete_valid_grid));
    assert_true(check_rows(&grid2));
}

void test_check_cols() {
    Grid grid;
    memcpy(grid.values, bad_cols_grid, sizeof(bad_rows_grid));
    assert_false(check_cols(&grid));
    Grid grid2;
    memcpy(grid2.values, complete_valid_grid, sizeof(complete_valid_grid));
    assert_true(check_cols(&grid2));
}

void test_check_boxes() {
    Grid grid;
    memcpy(grid.values, bad_boxes_grid, sizeof(bad_boxes_grid));
    assert_false(check_boxes(&grid));
    Grid grid2;
    memcpy(grid2.values, complete_valid_grid, sizeof(complete_valid_grid));
    assert_true(check_boxes(&grid2));
}

void test_is_grid_valid() {
    Grid grid;
    memcpy(grid.values, bad_boxes_grid, sizeof(bad_boxes_grid));
    assert_false(is_grid_valid(&grid));
    Grid grid2;
    memcpy(grid2.values, complete_valid_grid, sizeof(complete_valid_grid));
    assert_true(is_grid_valid(&grid2));
}

void test_is_grid_complete() {
    Grid grid;
    memcpy(grid.values, incomplete_valid_grid, sizeof(bad_boxes_grid));
    assert_false(is_grid_complete(&grid));
    Grid grid2;
    memcpy(grid2.values, complete_valid_grid, sizeof(complete_valid_grid));
    assert_true(is_grid_complete(&grid2));
}

void test_find_random_valid_entry() {
    Grid grid;
    memcpy(grid.values, incomplete_valid_grid, sizeof(incomplete_valid_grid));
    int val = find_random_valid_entry(&grid, 80);
    assert_int_equal(val, 2);
}

void test_find_incremented_valid_entry() {
    Grid grid;
    memcpy(grid.values, complete_valid_grid, sizeof(complete_valid_grid));
    int val = find_incremented_valid_entry(&grid, 80, 2);
    assert_int_equal(val, 0);
    Grid grid2;
    memcpy(grid2.values, blank_grid, sizeof(blank_grid));
    int val2 = find_incremented_valid_entry(&grid2, 0, 0);
    assert_int_equal(val2, 1);
}

void test_new_complete_grid() {
    Grid* grid = new_blank_grid();
    new_complete_grid(grid);
    assert_true(is_grid_valid(grid));
    assert_true(is_grid_complete(grid));
    int total = 0;
    for (int grid_i = 0; grid_i < 81; grid_i++) {
        total += grid->values[grid_i];
    }
    assert_int_equal(total, 405);
}

void test_new_game() {
    Grid* grid = new_blank_grid();
    new_game(grid, 35);
    set_blanks(grid);
    assert_true(is_grid_valid(grid));
    assert_int_equal(grid->blank_count, 46);
}

void test_solve_game() {
    Grid* grid = new_blank_grid();
    memcpy(grid->values, incomplete_valid_grid, sizeof(incomplete_valid_grid));
    solve_game(grid);
    assert_int_equal(grid->values[0], 1);
    assert_int_equal(grid->values[80], 2);
}

void test_find_solution() {
    Grid* grid = new_blank_grid();
    memcpy(grid->values, incomplete_valid_grid, sizeof(incomplete_valid_grid));
    set_blanks(grid);
    find_solution(grid, 0);
    assert_int_equal(grid->values[0], 1);
    assert_int_equal(grid->values[80], 2);
    Grid grid2;
    memcpy(grid2.values, bad_boxes_grid, sizeof(bad_boxes_grid));
    set_blanks(&grid2);
    assert_false(find_solution(&grid2, 0));
}

void test_set_blanks() {
    Grid* grid = new_blank_grid();
    memcpy(grid->values, incomplete_valid_grid, sizeof(incomplete_valid_grid));
    set_blanks(grid);
    assert_int_equal(grid->blank_count, 2);
    assert_int_equal(grid->blanks[0], 0);
    assert_int_equal(grid->blanks[1], 80);
}

void test_single_solution() {
    Grid* grid = new_blank_grid();
    memcpy(grid->values, single_solution_game, sizeof(single_solution_game));
    assert_true(single_solution(*grid));
    Grid* grid2 = new_blank_grid();
    memcpy(grid2->values, multiple_solution_game, sizeof(multiple_solution_game));
    assert_false(single_solution(*grid2));
}

void test_get_grid_value() {
    Position pos = { .x = 2, .y = 3 };
    Grid* grid = new_blank_grid();
    memcpy(grid->values, complete_valid_grid, sizeof(complete_valid_grid));
    assert_int_equal(get_grid_value(grid, &pos), 4);
}

void test_position_on_grid() {
    Position pos = { .x = 2, .y = 3 };
    assert_int_equal(position_on_grid(&pos), 29);
}

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_random_in_range),
        cmocka_unit_test(test_group_has_duplicates),
        cmocka_unit_test(test_new_blank_grid),
        cmocka_unit_test(test_check_rows),
        cmocka_unit_test(test_check_cols),
        cmocka_unit_test(test_check_boxes),
        cmocka_unit_test(test_is_grid_valid),
        cmocka_unit_test(test_is_grid_complete),
        cmocka_unit_test(test_find_random_valid_entry),
        cmocka_unit_test(test_find_incremented_valid_entry),
        cmocka_unit_test(test_new_complete_grid),
        cmocka_unit_test(test_new_game),
        cmocka_unit_test(test_solve_game),
        cmocka_unit_test(test_find_solution),
        cmocka_unit_test(test_set_blanks),
        cmocka_unit_test(test_single_solution),
        cmocka_unit_test(test_get_grid_value),
        cmocka_unit_test(test_position_on_grid),
    };
    return cmocka_run_group_tests(tests, NULL, NULL);
}
