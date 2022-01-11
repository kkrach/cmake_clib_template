/**
 * @file main.c
 *
 * @brief Example application for C Library Template
 *
 * @author Karl Krach
 *
 * @copyright Copyright 2021 Karl Krach
 * @license{This file is licensed under the MIT license.}
 *
 */

#include <errno.h>
#include <inttypes.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <library.h>

#define UNUSED(X) (void)(X)
#define END_OF_OPTIONS      "--"
#define DEFAULT_ITERATIONS  3

static void print_usage(FILE *stream, const char *program_name)
{
	fprintf(stream, "Usage: %s [-i iterations] [-f] ARG1 [ARG2]\n", program_name);
	fprintf(stream, "\n");
	fprintf(stream, "  -i iterations  sets the number of iterations (default: %i)", DEFAULT_ITERATIONS);
	fprintf(stream, "  -d, --debug    enables additional outputs\n");
	fprintf(stream, "  -q, --quiet    suppresses all output\n");
	fprintf(stream, "  -v, --version  prints the program version\n");
	fprintf(stream, "  -h, --help     prints this help\n");
	fprintf(stream, "  --             terminates the option parsing, e.g. for negative ARG1\n");
	fprintf(stream, "\n");
	fprintf(stream, "  ARG1           big numeric argument\n");
	fprintf(stream, "  ARG2           optional textual argument\n");
	fprintf(stream, "\n");
}

__attribute__((noreturn)) static void print_usage_and_exit(const char *program_name)
{
	fprintf(stderr, "\n");
	print_usage(stderr, program_name);
	exit(EXIT_FAILURE);  // NOLINT
}

static void print_version()
{
	clib_print_version();
}

static void ensure_further_argument(const char *program_name, int argi, int argc, char *argv[])
{
	if (argi == argc)
	{
		fprintf(stderr, "Error: Parameter %s needs argument!\n", argv[argi]);
		print_usage_and_exit(program_name);
	}
}

static int parse_parameter_iterations(const char *program_name, int argi, int argc, char *argv[])
{
	ensure_further_argument(program_name, argi, argc, argv);
	argi++;
	char *endptr = NULL;
	intmax_t arg = strtoimax(argv[argi], &endptr, 0);  // accepts decimal as well as hex input
	if (*endptr != '\0')
	{
		fprintf(stderr, "Error: Parameter iterations '%s' cannot be parsed completely!\n", argv[argi]);
		print_usage_and_exit(program_name);
	}
	else if ((arg == INTMAX_MAX && errno == ERANGE) || arg > INT_MAX)
	{
		fprintf(stderr, "Error: Parameter iterations '%s' is too large!\n", argv[argi]);
		print_usage_and_exit(program_name);
	}
	else if ((arg == INTMAX_MIN && errno == ERANGE) || arg < 0)
	{
		fprintf(stderr, "Error: Parameter iterations '%s' is too small!\n", argv[argi]);
		print_usage_and_exit(program_name);
	}
	return (int)arg;
}

static int parse_argument_arg1(const char *program_name, int argi, int argc, char *argv[])
{
	if (argi == argc)
	{
		fprintf(stderr, "Error: Missing mandatory argument 'ARG1'!\n");
		print_usage_and_exit(program_name);
	}

	char *endptr = NULL;
	intmax_t arg = strtoimax(argv[argi], &endptr, 0);  // accepts decimal as well as hex input
	if (*endptr != '\0')
	{
		fprintf(stderr, "Error: Argument ARG1 '%s' cannot be parsed completely!\n", argv[argi]);
		print_usage_and_exit(program_name);
	}
	else if (arg == INTMAX_MAX && errno == ERANGE)
	{
		fprintf(stderr, "Error: Argument ARG1 '%s' is too large!\n", argv[argi]);
		print_usage_and_exit(program_name);
	}
	else if (arg == INTMAX_MIN && errno == ERANGE)
	{
		fprintf(stderr, "Error: Argument ARG1 '%s' is too small!\n", argv[argi]);
		print_usage_and_exit(program_name);
	}
	return (int)arg;
}
static const char* parse_argument_arg2(const char *program_name, int argi, int argc, char *argv[])
{
	UNUSED(program_name);

	if (argi == argc)
	{
		// no error - second argument is optional
		return "n/a";
	}

	return argv[argi];
}

int main (int argc, char *argv[])
{
	const char *program_name = argv[0];
	int argi = 1;
	int iterations = DEFAULT_ITERATIONS;
	int debug = 0;
	uint64_t arg1 = 0;
	const char *arg2 = "n/a";

	for (; argi < argc; argi++)
	{
		if (strcmp(argv[argi], "-h") == 0 || strcmp(argv[argi], "--help") == 0)
		{
			print_usage(stdout, program_name);
			exit(EXIT_SUCCESS);  // NOLINT
		}
		else if (strcmp(argv[argi], "-i") == 0 || strcmp(argv[argi], "--iterations") == 0)
		{
			iterations = parse_parameter_iterations(program_name, argi, argc, argv);
			argi += 2;
		}
		else if (strcmp(argv[argi], "-d") == 0 || strcmp(argv[argi], "--debug") == 0)
		{
			debug = 1;
		}
		else if (strcmp(argv[argi], "-q") == 0 || strcmp(argv[argi], "--quiet") == 0)
		{
			close(STDIN_FILENO);
			close(STDOUT_FILENO);
			close(STDERR_FILENO);
		}
		else if (strcmp(argv[argi], "-v") == 0 || strcmp(argv[argi], "--version") == 0)
		{
			print_version();
			exit(EXIT_SUCCESS);  // NOLINT
		}
		//
		// from https://pubs.opengroup.org/onlinepubs/9699919799/basedefs/V1_chap12.html#tag_12_02
		//
		//   The first -- argument that is not an option-argument should be accepted
		//   as a delimiter indicating the end of options. Any following arguments
		//   should be treated as operands, even if they begin with the '-' character.
		//
		else if (strcmp(argv[argi], END_OF_OPTIONS) == 0)
		{
			argi++;
			break;
		}
		else if (argv[argi][0] == '-')
		{
			printf("Error: Unknown parameter '%s'!\n", argv[argi]);
			print_usage_and_exit(program_name);
		}
		else // not an option
		{
			break;
		}
	}

	arg1 = parse_argument_arg1(program_name, argi, argc, argv);
	argi++;
	arg2 = parse_argument_arg2(program_name, argi, argc, argv);
	argi++;

	printf("Running %d iterations with %" PRIu64 " and %s and %s mode\n", iterations, arg1, arg2, debug ? "debug" : "regular");

	printf("The answer is %d\n", clib_get_answer());

	clib_print_version();

	return EXIT_SUCCESS;
}
