#include <iostream>
#include <cmath>
#include <string>

void count_radius(double& front_left_rad, double& rear_left_rad, double& front_right_rad, double& rear_right_rad, 
                  double angle, double width, double length, std::string direction) {

    double angle_rad = angle * M_PI / 180.0;
    double sin_a = sin(angle_rad);
    double tan_a = tan(angle_rad);

    if (direction[0] == 'R' || direction[0] == 'r') {
        front_right_rad = length / sin_a;
        rear_right_rad = length / tan_a;
        front_left_rad = front_right_rad + width;
        rear_left_rad = rear_right_rad + width;
    }
    else if (direction[0] == 'L' || direction[0] == 'l') {
        front_left_rad = length / sin_a;
        rear_left_rad = length / tan_a;
        front_right_rad = front_left_rad + width;
        rear_right_rad = rear_left_rad + width;
    }

    std::cout << "Front length wheel radius: " << front_left_rad << "\n";
    std::cout << "Rear length wheel radius: " << rear_left_rad << "\n";
    std::cout << "Front right wheel radius: " << front_right_rad << "\n";
    std::cout << "Rear right wheel radius: " << rear_right_rad << "\n";
}

int main() {
    double angle = 0, width = 0, length = 0;
    std::string direction;

    while (true) {
        std::cout << "Enter steering wheel angle (degrees): ";
        std::cin >> angle;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cerr << "Error: Invalid input. Please enter a number.\n";
            continue;
        }
        if (angle < 1 || angle > 90) {
            std::cerr << "Error: Steering wheel angle must be between 1 and 90 degrees.\n";
            continue;
        }
        break;
    }

    while (true) {
        std::cout << "Enter car width: ";
        std::cin >> width;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cerr << "Error: Invalid input. Please enter a number.\n";
            continue;
        }
        if (width <= 0) {
            std::cerr << "Error: Car width must be positive.\n";
            continue;
        }
        break;
    }

    while (true) {
        std::cout << "Enter distance between wheels (length of car): ";
        std::cin >> length;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cerr << "Error: Invalid input. Please enter a number.\n";
            continue;
        }
        if (length <= 0) {
            std::cerr << "Error: Car length must be positive.\n";
            continue;
        }
        if (width > length) {
            std::cerr << "Error: Car width cannot be greater than car length.\n";
            continue;
        }
        break;
    }

    while (true) {
        std::cout << "Enter turn direction ('r' for right, 'l' for left): ";
        std::cin >> direction;
        if (direction != "r" && direction != "l" && direction != "R" && direction != "L" && direction.size() != 1) {
            std::cerr << "Error: Invalid direction. Use 'r' or 'l'.\n";
            continue;
        }
        break;
    }

    double front_left_rad = 0, rear_left_rad = 0, front_right_rad = 0, rear_right_rad = 0;
    count_radius(front_left_rad, rear_left_rad, front_right_rad, rear_right_rad, angle, width, length, direction);

    return 0;
}