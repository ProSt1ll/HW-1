#ifndef PROJECT_INCLUDE_UTILS_H_
#define PROJECT_INCLUDE_UTILS_H_


#if defined(__cplusplus)
extern "C" {
#endif


#define NED 3
struct weather {
    int temperature;
    int fallout;
    int wind_velocity;
};

int input_weather_rand(struct weather *week, int num);

int input_weather(struct weather *week, int num);

int min_temp(struct weather *week, int num);

int max_temp(struct weather *week, int num);

int sum_fall(struct weather *week, int num);

float mean_temp(struct weather *week, int num);

int checkout_weather_ptr(struct weather *week, int num);

int checkout_weather_value(struct weather *week, int num);

#if defined(__cplusplus)
};
#endif
#endif      // PROJECT_INCLUDE_UTILS_H_
