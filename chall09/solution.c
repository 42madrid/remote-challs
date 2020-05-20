#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

#define MAX_SECONDS 10000000000000000000ULL
#define MINUTE 60
#define HOUR (MINUTE * 60)
#define DAY (HOUR * 24)
#define YEAR (DAY * 365)

static void     store(unsigned long long num, size_t *ai, char storage[5][32], const char *str)
{
    if (num > 0) {
        if (num == 1)
            sprintf(storage[*ai], "%llu %s", num, str);
        else
            sprintf(storage[*ai], "%llu %ss", num, str);
        *ai += 1;
    }
}

char            *ft_format_duration_solution(char *seconds) {
    char                *output;
    char                *endptr = NULL;
    unsigned long long  parsed_seconds;
    char                storage[5][32];
    size_t              i = 0;
    size_t              j = 0;

    for (j = 0; j < strlen(seconds); j++)
        if (!(isdigit(seconds[j]))) {
            asprintf(&output, "Invalid input.");
            return (output);
        }
    parsed_seconds = strtoull(seconds, &endptr, 10);
    if ((parsed_seconds == ULLONG_MAX && errno == ERANGE) || parsed_seconds > MAX_SECONDS)
        asprintf(&output, "Invalid input.");
    else if (parsed_seconds == 0) {
        if (errno == EINVAL || errno == ERANGE || endptr == seconds)
            asprintf(&output, "Invalid input.");
        else
            asprintf(&output, "now");
    }
    else {
        store(parsed_seconds / YEAR, &i, storage, "year");
        parsed_seconds %= YEAR;
        store(parsed_seconds / DAY, &i, storage, "day");
        parsed_seconds %= DAY;
        store(parsed_seconds / HOUR, &i, storage, "hour");
        parsed_seconds %= HOUR;
        store(parsed_seconds / MINUTE, &i, storage, "minute");
        parsed_seconds %= MINUTE;
        store(parsed_seconds, &i, storage, "second");
        switch(i) {
            case 1:
                asprintf(&output, "%s", storage[0]);
                break;
            case 2:
                asprintf(&output, "%s and %s", storage[0], storage[1]);
                break;
            case 3:
                asprintf(&output, "%s, %s and %s", storage[0], storage[1], storage[2]);
                break;
            case 4:
                asprintf(&output, "%s, %s, %s and %s", storage[0], storage[1], storage[2], storage[3]);
                break;
            default:
                asprintf(&output, "%s, %s, %s, %s and %s", storage[0], storage[1], storage[2], storage[3], storage[4]);
        }
    }
    return(output);
}
