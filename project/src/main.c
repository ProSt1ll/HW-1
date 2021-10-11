#include <stdlib.h>
#include "stdio.h"
#include "utils.h"

int main() {
    // struct weather week[NED];
    struct weather *week = (struct weather *) malloc(NED * sizeof(struct weather));
    input_weather(week, NED);
    if (checkout_weather_ptr(week, NED) && checkout_weather_value(week, NED)) {
        printf("Минимальное значение температуры - %d \n", week[min_temp(week, NED)].temperature);
        printf("Максимальное значение температуры - %d \n", week[max_temp(week, NED)].temperature);
        printf("Среднее значение температуры - %3.2f \n", mean_temp(week, NED));
        printf("Суммарное количество оссадков - %d \n", sum_fall(week, NED));
    } else {
        printf("Введены некорректные данные \n");
    }
    free(week);
}
