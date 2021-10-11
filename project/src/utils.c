#include <stdlib.h>
#include "stdio.h"
#include "utils.h"


const int MAX_TEMP = 70;
const int MIN_TEMP = -60;

const int MAX_FALL = 150;
const int MIN_FALL = 0;

const int MAX_WIND = 80;
const int MIN_WIND = 0;

const char STR1[] = "температуру";
const char STR2[] = "осадки";
const char STR3[] = "скорость ветра";

static int get_rand(const int MIN, const int MAX, size_t i) {
    srand(i * 10 + 20);
    return rand() % (MAX - MIN + 1) + MIN;
}

int input_weather_rand(struct weather *week, int num) {
    if (week == NULL) return -1;
    for (int i = 0; i < num; i++) {
        week[i].temperature = get_rand(MIN_TEMP, MAX_TEMP, i);
        week[i].fallout = get_rand(MIN_FALL, MAX_FALL, i);
        week[i].wind_velocity = get_rand(MIN_WIND, MAX_WIND, i);
    }
    return 1;
}

int input_weather(struct weather *week, int num) {
    if (week == NULL) return -1;
    for (int i = 0; i < num; i++) {
        printf("Введите %s %d дня недели\n", STR1, i + 1);
        if ((scanf("%d", &(week[i].temperature))) != 1) return -1;
        printf("Введите %s %d дня недели\n", STR2, i + 1);
        if ((scanf("%d", &(week[i].fallout))) != 1) return -1;
        printf("Введите %s %d дня недели\n", STR3, i + 1);
        if ((scanf("%d", &(week[i].wind_velocity))) != 1) return -1;
    }
    if (checkout_weather_value(week, num) < 0) return -1;
    return 1;
}

int max_temp(struct weather *week, int num) {
    if (week == NULL) return -1;
    if (checkout_weather_value(week, num) == 0) return -1;
    int max = 0;
    for (int i = 1; i < num; i++) {
        if (week[max].temperature < week[i].temperature) max = i;
    }
    return max;
}

int min_temp(struct weather *week, int num) {
    if (week == NULL) return -1;
    if (checkout_weather_value(week, num) == 0) return -1;
    int min = 0;
    for (int i = 1; i < num; i++) {
        if (week[min].temperature > week[i].temperature) min = i;
    }
    return min;
}

int sum_fall(struct weather *week, int num) {
    if (week == NULL) return -1;
    if (checkout_weather_value(week, num) == 0) return -1;
    int sum = 0;
    for (int i = 0; i < num; i++) sum += week[i].fallout;
    return sum;
}

float mean_temp(struct weather *week, int num) {
    if (week == NULL) return -1;
    if (checkout_weather_value(week, num) == 0) return -1;
    int sum = 0;
    for (int i = 0; i < num; i++) {
        sum += week[i].temperature;
    }
    if (sum == 0) return 0;
    float mean = (float) sum / num;
    return mean;
}

int checkout_weather_ptr(struct weather *week, int num) {
    if (week == NULL)
        return 0;
    return 1;
}

int checkout_weather_value(struct weather *week, int num) {
    for (int i = 0; i < num; i++) {
        if (((week[i].wind_velocity) > MAX_WIND) || ((week[i].wind_velocity) < MIN_WIND) ||
            ((week[i].temperature) > MAX_TEMP) || ((week[i].temperature) < MIN_TEMP) ||
            ((week[i].fallout) > MAX_FALL) || ((week[i].fallout) < MIN_FALL))
            return 0;
    }
    return 1;
}
