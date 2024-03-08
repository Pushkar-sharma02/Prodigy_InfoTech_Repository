#include <iostream>

double convertCelsiusToFahrenheit(double celsius) {
    return (celsius * 9 / 5) + 32;
}

double convertCelsiusToKelvin(double celsius) {
    return celsius + 273.15;
}

double convertFahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

double convertFahrenheitToKelvin(double fahrenheit) {
    return (fahrenheit + 459.67) * 5 / 9;
}

double convertKelvinToCelsius(double kelvin) {
    return kelvin - 273.15;
}

double convertKelvinToFahrenheit(double kelvin) {
    return (kelvin * 9 / 5) - 459.67;
}

int main() {
    std::cout << "              Welcome to the Temperature Converter!\n";
    std::cout << "This program converts temperatures between Celsius, Fahrenheit, and Kelvin.\n";

    double temperature;
    char originalUnit;

    // Prompt user for input
    std::cout << "\nEnter the temperature value: ";
    std::cin >> temperature;

    std::cout << "Enter the original unit of measurement (C, F, or K): ";
    std::cin >> originalUnit;

    // Convert temperature based on the original unit
    double convertedCelsius, convertedFahrenheit, convertedKelvin;

    switch (originalUnit) {
        case 'C':
        case 'c':
            convertedCelsius = temperature;
            convertedFahrenheit = convertCelsiusToFahrenheit(temperature);
            convertedKelvin = convertCelsiusToKelvin(temperature);
            break;
        case 'F':
        case 'f':
            convertedCelsius = convertFahrenheitToCelsius(temperature);
            convertedFahrenheit = temperature;
            convertedKelvin = convertFahrenheitToKelvin(temperature);
            break;
        case 'K':
        case 'k':
            convertedCelsius = convertKelvinToCelsius(temperature);
            convertedFahrenheit = convertKelvinToFahrenheit(temperature);
            convertedKelvin = temperature;
            break;
        default:
            std::cerr << "Invalid unit of measurement. Please enter C, F, or K." << std::endl;
            return 1;
    }

    // Display the converted values
    std::cout << "\nConverted Temperatures:" << std::endl;
    std::cout << "Celsius: " << convertedCelsius << " C" << std::endl;
    std::cout << "Fahrenheit: " << convertedFahrenheit << " F" << std::endl;
    std::cout << "Kelvin: " << convertedKelvin << " K" << std::endl;

    return 0;
}
