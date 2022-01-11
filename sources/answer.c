/**
 * @file answer.c
 *
 * @brief Template implementation for answers
 *
 * @author Karl Krach
 *
 * @copyright Copyright 2021 Karl Krach
 * @license{This file is licensed under the MIT license.}
 *
 */

#include "library.h"

#define ANSWER_DEFAULT 42

static int answer = ANSWER_DEFAULT;

int clib_get_answer()
{
	return answer;
}

void clib_set_answer(int value)
{
	answer = value;
}
