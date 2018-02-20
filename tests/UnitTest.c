/*
** EPITECH PROJECT, 2017
** PSU_my_sokoban_2017
** File description:
** UnitTest_malloc.c
*/

#include <criterion/criterion.h>
#include "my.h"

Test(map_size, nbr_len)
{
	char *file = "2\n..\n..";

	cr_assert_eq(nbr_len(file), 1);
	file = "10\n";
	cr_assert_eq(nbr_len(file), 2);
	file = "";
	cr_assert_eq(nbr_len(file), 0);
}

Test(map_size, map_size)
{
	int i = 0;
	int j = 0;

	char *file = load_file_in_mem("tests/map_test/map_test_10_10");
	map_size(&j, &i, file);
	cr_assert_eq(i, 10);
	cr_assert_eq(j, 10);
	file = load_file_in_mem("tests/map_test/map_test_100_10");
	map_size(&j, &i, file);
	cr_assert_eq(i, 10);
	cr_assert_eq(j, 100);
	file = load_file_in_mem("tests/map_test/map_test_10_100");
	map_size(&j, &i, file);
	cr_assert_eq(i, 100);
	cr_assert_eq(j, 10);
}

Test(map_int, map_to_int)
{
	char *file = load_file_in_mem("tests/map_test/map_test_3_3");
	int i = 0;
	int j = 0;
	int **map;

	map_size(&j, &i, file);
	map = load_map_to_int("tests/map_test/map_test_3_3",
	i, j, nbr_len(file));
	cr_assert_eq(map[0][0], 0);
	cr_assert_eq(map[0][1], 0);
	cr_assert_eq(map[0][2], 1);
	cr_assert_eq(map[1][0], 1);
	cr_assert_eq(map[1][1], 2);
	cr_assert_eq(map[1][2], 2);
	cr_assert_eq(map[2][0], 1);
	cr_assert_eq(map[2][1], 2);
	cr_assert_eq(map[2][2], 2);
}

Test(bsq, bsq_finder)
{
	char *file = load_file_in_mem("tests/map_test/map_test_3_3");
	int i = 0;
	int j = 0;
	int **map;

	map_size(&j, &i, file);
	map = load_map_to_int("tests/map_test/map_test_3_3",
	i, j, nbr_len(file));
	map = bsq_finder(map, file);
	cr_assert_eq(map[0][0], 0);
	cr_assert_eq(map[0][1], 0);
	cr_assert_eq(map[0][2], 1);
	cr_assert_eq(map[1][0], 1);
	cr_assert_eq(map[1][1], 1);
	cr_assert_eq(map[1][2], 1);
	cr_assert_eq(map[2][0], 1);
	cr_assert_eq(map[2][1], 2);
	cr_assert_eq(map[2][2], 2);
}
