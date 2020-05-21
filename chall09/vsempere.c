#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>

#define YEAR_UNIT       0
#define DAY_UNIT        1
#define HOUR_UNIT       2
#define MINUTE_UNIT     3
#define SECOND_UNIT     4
#define YEAR_SECONDS    31536000
#define DAY_SECONDS     86400
#define HOUR_SECONDS    3600
#define MINUTE_SECONDS  60
#define MAX_SECONDS     10000000000000000000ul

static void extract_unit(long long *num, int unit_seconds, long *units)
{
    *units = *num / unit_seconds;
    *num = *num - (*units * unit_seconds);
}

static char *build_particle(long seconds, char *unit, char *use_separator,
    int *remaining_particles)
{
    char    *str;

    str = 0;
    if (seconds <= 0 || !(str = malloc(sizeof(char) * 25)))
        return (str);

    if (*use_separator && *remaining_particles > 1)
        sprintf(str, ", %ld %s", seconds, unit);
    else if (*use_separator && *remaining_particles == 1)
        sprintf(str, " and %ld %s", seconds, unit);
    else
        sprintf(str, "%ld %s", seconds, unit);

    *use_separator = 1;
    (*remaining_particles)--;

    return (str);
}

static char *build_human_time(long unit_values[5], int particles)
{
    int     len;
    char    *human_time;
    char    *years;
    char    *days;
    char    *hours;
    char    *minutes;
    char    *seconds;
    char    use_separator;
    
    use_separator = 0;
    years = build_particle(unit_values[YEAR_UNIT],
        unit_values[YEAR_UNIT] > 1 ? "years" : "year", &use_separator, &particles);
    days = build_particle(unit_values[DAY_UNIT],
        unit_values[DAY_UNIT] > 1 ? "days" : "day", &use_separator, &particles);
    hours = build_particle(unit_values[2],
        unit_values[HOUR_UNIT] > 1 ? "hours" : "hour", &use_separator, &particles);
    minutes = build_particle(unit_values[3],
        unit_values[MINUTE_UNIT] > 1 ? "minutes" : "minute", &use_separator, &particles);
    seconds = build_particle(unit_values[4],
        unit_values[SECOND_UNIT] > 1 ? "seconds" : "second", &use_separator, &particles);
    
    len = 0;
    if (years) 
        len += strlen(years);
    if (days)
        len += strlen(days);
    if (hours)
        len += strlen(hours);
    if (minutes)
        len += strlen(minutes);
    if (seconds)
        len += strlen(seconds);
    human_time = calloc(len + 1, sizeof(char));
    if (years) {
        if (human_time) 
            strcat(human_time, years);
        free(years);
    }
    if (days) {
        if (human_time) 
            strcat(human_time, days);
        free(days);
    }
    if (hours) {
        if (human_time) 
            strcat(human_time, hours);
        free(hours);
    }
    if (minutes) {
        if (human_time) 
            strcat(human_time, minutes);
        free(minutes);
    }
    if (seconds) {
        if (human_time) 
            strcat(human_time, seconds);
        free(seconds);
    }
    return (human_time);
}

char    check_input(char *seconds)
{
    int i;

    if (!seconds)
        return (0);
    i = 0;
    while (isspace(seconds[i]))
        i++;
    while (isdigit(seconds[i]))
        i++;
    while (isspace(seconds[i]))
        i++;
    return (i && seconds[i] == '\0' ? 1 : 0);
}

static char *allocate_string(const char *str) {
    char *astr;
    
    astr = calloc(strlen(str) + 1, sizeof(char));
    return (strcat(astr, str));
}

static void extract_values_per_unit(long long num, long human_time[5], int *particles) 
{
    extract_unit(&num, YEAR_SECONDS, &human_time[YEAR_UNIT]);
    extract_unit(&num, DAY_SECONDS, &human_time[DAY_UNIT]);
    extract_unit(&num, HOUR_SECONDS, &human_time[HOUR_UNIT]);
    extract_unit(&num, MINUTE_SECONDS, &human_time[MINUTE_UNIT]);
    human_time[SECOND_UNIT] = num;
    
    (*particles) = 0;
    (*particles) += (human_time[YEAR_UNIT] > 0 ? 1 : 0);
    (*particles) += (human_time[DAY_UNIT] > 0 ? 1 : 0);
    (*particles) += (human_time[HOUR_UNIT] > 0 ? 1 : 0);
    (*particles) += (human_time[MINUTE_UNIT] > 0 ? 1 : 0);
    (*particles) += (human_time[SECOND_UNIT] > 0 ? 1 : 0);
}

char *ft_format_duration(char *seconds)
{
    long        human_time[5];
    long long   num;
    int         particles;

    if (!check_input(seconds) || (num = atoll(seconds)) > MAX_SECONDS || num < 0)
        return (allocate_string("Invalid input."));
    if (num == 0)
        return (allocate_string("now"));
    extract_values_per_unit(num, human_time, &particles);
    return (build_human_time(human_time, particles));
}
