#include <iostream>

// Inputs an RGB value and returns if the color of that RBG value is red, blue, yellow, or grey in a character
// Parameters: R (The red value of the color) : B (The blue value of the color) : G (The green value of the color)
// Returns: r (Color is red) : b (Color is blue) : y (Color is yellow) : g (Color is grey) : c (Color is clear) :  ? (Color does not match criteria)

char detectColor (int colorDegree, double distance) {
    char color; // Contains the determined color

    int redMin = 340; // Defines the minimum and maximum wheel angle to declare the detected color as red.
    int redMax = 20; 

    int blueMin = 200; // Defines the minimum and maximum wheel angle to declare the detected color as blue.
    int blueMax = 240;

    int yellowMin = 40;  // Defines the minimum and maximum wheel angle to declare the detected color as yellow.
    int yellowMax = 80;

    int minDistance = 1; // Defines the minimum and maximum distance to detect the object.
    int maxDistance = 10;

    int clearMinColor = 280; // Define the minimum and maximum distance to declare the dected color as clear.
    int clearMaxColor = 320;


    // Determines the color based on RGB parameters
    if (colorDegree > redMin - 360 && colorDegree < redMax) { // Red subtracted by 360 to create a negative angle representing the same color so the range works
        color = 'r';
    } else if (colorDegree > blueMin && colorDegree < blueMax) {
        color = 'b';
    } else if (colorDegree > yellowMin && colorDegree < yellowMax) {
        color = 'y';
    } else if (distance > minDistance && distance < maxDistance && colorDegree > clearMinColor && colorDegree < clearMaxColor) {
        color = 'c';
    } else if (distance > minDistance && distance < maxDistance) {
        color = 'g';
    } else {
        color = '?';
    }
    return color;
}

int main() {
    std::cout << detectColor(90, 0);
}