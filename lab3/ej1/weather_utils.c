#include "weather_utils.h"

int min_temp_min(WeatherTable a){
	int hist_min_temp = 0;
	int aux_min_read = 0;
	for (unsigned int k_year = 0u; k_year < YEARS; k_year++){

		for (unsigned int k_month = 0u; k_month < MONTHS; k_month++){

			for (unsigned int k_day = 0u; k_day < DAYS; k_day++){
				aux_min_read = a[k_year][k_month][k_day]._min_temp;

				if (aux_min_read < hist_min_temp){
					hist_min_temp = aux_min_read;
				}
			}
		}
	}
	return hist_min_temp;
}

int max_temp_year(WeatherTable a, unsigned int year){
	int max_temp = 0;
	int aux_max_read = 0;
	for (unsigned int k_month = 0u; k_month < MONTHS; k_month++){
		for (unsigned int k_day = 0u; k_day < DAYS; k_day++){
			aux_max_read = a[year][k_month][k_day]._max_temp;
			if (aux_max_read > max_temp){
				max_temp = aux_max_read;
			}
		}
	}
	return max_temp;
}

void max_temp_max(WeatherTable a, int output[YEARS]){
	for (unsigned int year = 0u; year < YEARS; year++){
		output[year] = max_temp_year(a, year);
	}
}

unsigned int rain_month(WeatherTable a, unsigned int year, month_t month){
	unsigned int sum_rain = 0;
	for (unsigned int k_day = 0u; k_day < DAYS; k_day++){
		sum_rain = a[year][month][k_day]._rainfall + sum_rain;
	}
	return sum_rain;
}

month_t max_rain_year(WeatherTable a, unsigned int year){
	month_t max_rain_month = january;
	/* this array contains the sum of rainfall for each month */
	for (unsigned int k_month = 0u; k_month < MONTHS; k_month++){
		if (rain_month(a, year, k_month) > rain_month(a, year, max_rain_month)){
			max_rain_month = k_month;
		}
	}

	return max_rain_month;
}

void max_rainfall_month(WeatherTable a, month_t array_of_months[YEARS]){
	for (unsigned int year = 0u; year < YEARS; year++){
		array_of_months[year] = max_rain_year(a, year);
	}
}

