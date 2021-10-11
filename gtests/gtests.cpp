#include <gtest/gtest.h>
#include "utils.h"

TEST(input_structure, input_structure) {
    struct weather *week = (struct weather *) malloc(sizeof(struct weather));
    EXPECT_FALSE(week == nullptr);
    free(week);
    week = NULL;
    EXPECT_EQ(input_weather(week, 1), -1);
}

TEST(max_temp, max_temp1) {
    struct weather *week = (struct weather *) malloc(4 * sizeof(struct weather));
    input_weather_rand(week, 4);
    week[0].temperature = 0;
    week[1].temperature = 30;
    week[2].temperature = 50;
    week[3].temperature = -44;
    int expected = 2;
    EXPECT_EQ(max_temp(week, 4), expected);
    free(week);
}

TEST(max_temp, max_temp2) {
    struct weather *week = (struct weather *) malloc(4 * sizeof(struct weather));
    input_weather_rand(week, 4);
    week[0].temperature = 0;
    week[1].temperature = 30;
    week[2].temperature = 5000;
    week[3].temperature = -44;
    int expected = -1;
    EXPECT_EQ(max_temp(week, 4), expected);
    free(week);
}

TEST(min_temp, min_temp1) {
    struct weather *week = (struct weather *) malloc(4 * sizeof(struct weather));
    input_weather_rand(week, 4);
    week[0].temperature = 0;
    week[1].temperature = 30;
    week[2].temperature = 50;
    week[3].temperature = -20;
    int expected = 3;
    EXPECT_EQ(min_temp(week, 4), expected);
    free(week);
}

TEST(min_temp, min_temp2) {
    struct weather *week = (struct weather *) malloc(4 * sizeof(struct weather));
    input_weather_rand(week, 4);
    week[0].temperature = 0;
    week[1].temperature = 30;
    week[2].temperature = 50;
    week[3].temperature = -200;
    int expected = -1;
    EXPECT_EQ(min_temp(week, 4), expected);
    free(week);
}

TEST(summ_fall, summ_fall) {
    struct weather *week = (struct weather *) malloc(4 * sizeof(struct weather));
    input_weather_rand(week, 4);
    week[0].fallout = 0;
    week[1].fallout = 30;
    week[2].fallout = 50;
    week[3].fallout = -200;
    int expected = -1;
    EXPECT_EQ(sum_fall(week, 4), expected);
    free(week);
}

TEST(summ_fall, summ_fall2) {
    struct weather *week = (struct weather *) malloc(4 * sizeof(struct weather));
    input_weather_rand(week, 4);
    week[0].fallout = 0;
    week[1].fallout = 30;
    week[2].fallout = 50;
    week[3].fallout = 100;
    int expected = 180;
    EXPECT_EQ(sum_fall(week, 4), expected);
    free(week);
}

TEST(mean_temp, mean_temp) {
    struct weather *week = (struct weather *) malloc(4 * sizeof(struct weather));
    input_weather_rand(week, 4);
    week[0].temperature = 0;
    week[1].temperature = 30;
    week[2].temperature = 50;
    week[3].temperature = -20;
    int expected = 60 / 4;
    EXPECT_FLOAT_EQ(mean_temp(week, 4), expected);
    free(week);
}

TEST(checkout_weather_value, checkout_weather_value) {
    struct weather *week = (struct weather *) malloc(4 * sizeof(struct weather));
    input_weather_rand(week, 4);
    EXPECT_TRUE(checkout_weather_value(week, 4));
    free(week);
}

TEST(checkout_weather_ptr, checkout_weather_ptr) {
    struct weather *week = (struct weather *) malloc(4 * sizeof(struct weather));
    input_weather_rand(week, 4);
    EXPECT_TRUE(checkout_weather_ptr(week, 4));
    free(week);
}

TEST(checkout_weather_ptr, checkout_weather_ptr2) {
    struct weather *week = 0;
    EXPECT_FALSE(checkout_weather_ptr(week, 4));
    free(week);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}