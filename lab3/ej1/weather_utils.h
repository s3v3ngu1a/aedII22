/*
 @file weather_utils.h
 @brief Defines utilities for a given set of weather data
*/

#ifndef _WEATHER_UTILS_H
#define _WEATHER_UTILS_H

#include "array_helpers.h"

/* @brief gives the historical minimum temperature according
 * the input array */
/* the historic minimum beetween 1980 and 2016 was -15°C */
int min_temp_min(WeatherTable a);

/* @brief gives the maximum temperature for
 * a given range of years */
/* i.e: output[0] = 445 ---> The maximum temperature for 1980 was 44.5°C */
void max_temp_max(WeatherTable a, int output[YEARS]);

/* @brief gives the month with the maximum rainfall register for
 * a given range of years */
/* i.e: array_of_months[0] = January ---> The month with the maximum rainfall register for 1980 was January */
void max_rainfall_month(WeatherTable a, month_t array_of_months[YEARS]);

#endif
