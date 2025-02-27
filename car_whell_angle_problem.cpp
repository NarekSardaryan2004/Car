#include <iostream>
#include <cmath>
#include <string>
#include <limits>

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

template <typename T>
T get_valid_input(const std::string& prompt, T min_val, T max_val) {
    T value;
    while (true) {
        std::cout << prompt;
        std::cin >> value;

        if (std::cin.fail() || value <= min_val || value > max_val) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cerr << "Error: Invalid input. Please enter a valid number (" << min_val << "-" << max_val << ").\n";
        }
        else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
    }

    return value;
}

int main() {
    double angle = get_valid_input("Enter steering wheel angle (degrees): ", 0, 45);
    double width = get_valid_input("Enter car width: ", 0.5, 10.1);
    double length = get_valid_input("Enter distance between wheels (length of car): ", 1.34, 21.1);
    
    std::string direction;
    while (true) {
        std::cout << "Enter turn direction ('r' for right, 'l' for left): ";
        std::cin >> direction;
        if (direction != "r" && direction != "l" && direction != "R" && direction != "L") {
            std::cerr << "Error: Invalid direction. Use 'r' or 'l'.\n";
            continue;
        }
        break;
    }

    double front_left_rad = 0, rear_left_rad = 0, front_right_rad = 0, rear_right_rad = 0;
    count_radius(front_left_rad, rear_left_rad, front_right_rad, rear_right_rad, angle, width, length, direction);

    return 0;
}
