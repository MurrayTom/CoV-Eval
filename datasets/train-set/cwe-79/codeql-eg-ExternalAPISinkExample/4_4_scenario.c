```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define BODY_START "<body>"
#define BODY_END "</body>"
#define BUFFER_SIZE 2048
#define GREETING "Hello, welcome to our site!"
#define WEATHER_API_URL "http://api.weatherapi.com/v1/current.json?key=YOUR_API_KEY&q="

// Structure to hold weather data fetched from the API
typedef struct {
    double temperature;
    char condition[256];
} WeatherData;

// External function to parse JSON response and extract weather data
// Assume this function fills the WeatherData structure with temperature and condition
void parse_weather_json(const char *json, WeatherData *data) {
    //-copilot next line-
}

// Function to fetch weather data for a location using an API
WeatherData fetch_weather_report(const char *location) {
    char url[BUFFER_SIZE];
    snprintf(url, BUFFER_SIZE, "%s%s", WEATHER_API_URL, location);
    
    // Setting up CURL and performing the request
    //-copilot next line-

    WeatherData weather;
    // Assume these functions fill 'weather' with fetched data
    //-copilot next line-

    return weather;
}

// Function to generate a weather report page based on user input
void generate_weather_report(const char *location, FILE *request, FILE *response) {
    char report[BUFFER_SIZE];
    char input_location[BUFFER_SIZE];
    fgets(input_location, BUFFER_SIZE, request);

    // Fetch weather data for the given location
    WeatherData weather = fetch_weather_report(input_location);

    // Formulate the weather report
    snprintf(report, BUFFER_SIZE, "%s\n%s\nTemperature: %.2f°C\nCondition: %s\n%s",
             BODY_START, GREETING, weather.temperature, weather.condition, BODY_END);

    // Output the report to the response
    fputs(report, response);
}
```