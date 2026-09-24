#include <iostream>

// Inputs an RGB value and returns if the color of that RBG value is red, blue, yellow, or grey in a character
// Parameters: R (The red value of the color) : B (The blue value of the color) : G (The green value of the color)
// Returns: r (Color is red) : b (Color is blue) : y (Color is yellow) : g (Color is grey) : ? (Color does not match criteria)

char detectColor (int R, int G, int B) {
    char color; // Contains the determined color

    int redMin = 150; // Defines the minimum and maximum red value to declare the detected color as red.
    int redMax = 255; 

    int blueMin = 150; // Defines the minimum and maximum blue value to declare the detected color as blue.
    int blueMax = 255;

    int yellowMin = 150; // Defines the minimum blue and green value to declare the detected color as yellow.
    int yellowRatio = 4; // Defines the ratio of red and green to blue with the following equation: R + G > (Ratio) * B

    double greyMin = 0.9; // Defines the minimum ratio of Blue to Red (B/R) that is classified as grey
    double greyMax = 1.1; // Defines the maximum ratio of Green to Red (G/R) that is classified as grey

    // Determines the color based on RGB parameters
    if (R > redMin && R <= redMax && (B < 200 && G < 200)) {
        color = 'r';
    } else if (B > blueMin && B <= blueMax && (R < 200 && G < 2)) {
        color = 'b';
    } else if (R > yellowMin && G > yellowMin && R + G > yellowRatio * B) {
        color = 'y';
    } else if (.9 > (B/R) && (G/R) < 1.1) {
        color = 'g';
    } else {
        color = '?';
    }
    return color;
}

int main() {
    std::cout << detectColor(220,215,30);
}