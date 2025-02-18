#include <iostream>
#include <cmath>

void count_radius(double& front_left_rad, double& rear_left_rad, double& front_right_rad, double& rear_right_rad, 
                double angle, double width, double left, char direction) {
    double angle_rad = angle * M_PI / 180.0;
    double sin_a = sin(angle_rad);
    double tan_a = tan(angle_rad);

    switch (direction) {
        case 'r':
            front_right_rad = left / sin_a;
            rear_right_rad = left / tan_a;
            front_left_rad = front_right_rad + width;
            rear_left_rad = rear_right_rad + width;
            break;
        case 'l':
            front_left_rad = left / sin_a;
            rear_left_rad = left / tan_a;
            front_right_rad = front_left_rad + width;
            rear_right_rad = rear_left_rad + width;
            break;
        default:
            std::cerr << "Invalid direction! Use 'r' for right or 'l' for left.\n";
            return;
    }

    std::cout << "Front left wheel radius: " << front_left_rad << "\n";
    std::cout << "Rear left wheel radius: " << rear_left_rad << "\n";
    std::cout << "Front right wheel radius: " << front_right_rad << "\n";
    std::cout << "Rear right wheel radius: " << rear_right_rad << "\n";
}

int main() {
    double angle, width, length;
    char direction;

    std::cout << "Enter steering wheel angle (degrees): ";
    std::cin >> angle;
    std::cout << "Enter car width: ";
    std::cin >> width;
    std::cout << "Enter car length: ";
    std::cin >> length;
    std::cout << "Enter turn direction ('r' for right, 'l' for left): ";
    std::cin >> direction;

    double front_left_rad = 0, rear_left_rad = 0, front_right_rad = 0, rear_right_rad = 0;
    count_radius(front_left_rad, rear_left_rad, front_right_rad, rear_right_rad, angle, width, length, direction);

    return 0;
}