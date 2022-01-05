
#include "library.h"

#define ANSWER_DEFAULT 42

static int answer = ANSWER_DEFAULT;

int get_answer()
{
	return answer;
}

void set_answer(int value)
{
	answer = value;
}
