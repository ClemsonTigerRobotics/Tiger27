#include <iostream>
#include <tuple>

using namespace std;

const double PI = 2 * acos(0.0);

/*
    travel() is a function that describes the straightline path that a robot should make to reach the target position in the shortest distance possible.

    Input:
    startPos = <x, y, angle>
        Starting position of the robot.
    endPos = <x, y, angle>
        Desired ending position of the robot.

    Output:
    No return output.
    Cout with written instructions. Will be changed to actual movements at a later date.

*/
void travel(tuple<double, double, double> startPos, tuple<double, double, double> endPos) {
    //Define local variables
    double xi = get<0>(startPos);
    double yi = get<1>(startPos);
    double thetai = get<2>(startPos);
    double xf = get<0>(endPos);
    double yf = get<1>(endPos);
    double thetaf = get<2>(endPos);

    //Find the turning angle to line up with the end goal
    double travelAngle = tan((yf-yi) / (xf-xi)); //Standard tan(rise / run) to find the angle 
    double firstTurn = travelAngle - thetai; //Difference between robot angle and desired angle to find how far to turn
    
    //These two while loops find the shortest turning path. If we want to turn 3pi/2 radians, it would be faster to go -pi/2 radians instead.
    while(firstTurn > PI) {
        firstTurn -= 2*PI;
    }
    while(firstTurn < -PI) {
        firstTurn += 2*PI;
    }
    cout << "First, turn " << firstTurn << " radians.\n";


    //Find the travel distance to reach the end goal
    double travelDistance = sqrt(pow(xf-xi,2) + pow(yf-yi,2)); //Pythagorean's theorem to find travel length
    cout << "Travel forward " << travelDistance << " units.\n"; //Units will likely be determined based on the odometer we use


    //Find the turning angle to reach the desired end robot state. Position should already match the end goal.
    double secondTurn = thetaf - (thetai + firstTurn);
    //Repeat the same while loops.
    while(secondTurn > PI) {
        secondTurn -= 2*PI;
    }
    while(secondTurn < -PI) {
        secondTurn += 2*PI;
    }
    cout << "Finally, turn " << secondTurn << " radians.\n";
    cout << "Robot has completed travel.\n";
}

int main() {
    //robotPosition holds <x, y, angle in radians>
    tuple<double, double, double> robotPosition(0,0,0); //Set arbitrary robot position for storage. Can be used in conjunction with sensors at a later date.
    tuple<double, double, double> targetPosition(10,6,PI/6);
    travel(robotPosition, targetPosition);
    return 0;
}