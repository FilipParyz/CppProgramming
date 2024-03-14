#include <stdio.h>

struct Point {
    double x;
    double y;
};

void changeCoordinates(struct Point* point, double newX, double newY) {
    point->x = newX;
    point->y = newY;
}

struct Rectangle {
    struct Point topLeft;
    struct Point bottomRight;
    double width;
    double height;
};

void calculateWidthAndHeight(struct Rectangle* rectangle) {
    rectangle->width = rectangle->bottomRight.x - rectangle->topLeft.x;
    rectangle->height = rectangle->topLeft.y - rectangle->bottomRight.y;
}

double calculateArea(struct Rectangle rectangle) {
    return rectangle.width * rectangle.height;
}

double calculatePerimeter(struct Rectangle rectangle) {
    return 2 * (rectangle.width + rectangle.height);
}

int main() {
    struct Point point;
    point.x = 0.0;
    point.y = 0.0;

    changeCoordinates(&point, 21.0, 37.0);

    printf("Zmienione wspolrzedne punktu: (%.2f, %.2f)\n", point.x, point.y);

    struct Rectangle rectangle;
    rectangle.topLeft.x = 0;
    rectangle.topLeft.y = 17.28;
    rectangle.bottomRight.x = 1.218;
    rectangle.bottomRight.y = 0;

    calculateWidthAndHeight(&rectangle);
    double area = calculateArea(rectangle);
    double perimeter = calculatePerimeter(rectangle);

    printf("Pole prostokata: %.1f[j]^2\n", area);
    printf("Obwod prostokata: %.1f[j]\n", perimeter);

    return 0;
}