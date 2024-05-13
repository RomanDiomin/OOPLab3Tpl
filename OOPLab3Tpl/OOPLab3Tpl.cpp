#include <iostream>
#include <cmath>
#include <stdexcept>
#include <vector>

using namespace std;

class Rhombus {
private:
    double side;
    double diagonal;
    string color;

public:
    Rhombus(double s, double d, const string& c) : side(s), diagonal(d), color(c) {
        if (s <= 0 || d <= 0) {
            throw invalid_argument("Side and diagonal must be positive numbers.");
        }
    }

    Rhombus() : side(0), diagonal(0), color("black") {}

    double area() const {
        return 0.5 * side * diagonal;
    }

    double perimeter() const {
        return 4 * side;
    }

    void setSide(double s) {
        if (s <= 0) {
            throw invalid_argument("Side must be a positive number.");
        }
        side = s;
    }

    void setDiagonal(double d) {
        if (d <= 0) {
            throw invalid_argument("Diagonal must be a positive number.");
        }
        diagonal = d;
    }

    void setColor(const string& c) {
        color = c;
    }

    double getSide() const {
        return side;
    }

    double getDiagonal() const {
        return diagonal;
    }

    string getColor() const {
        return color;
    }

    void print() const {
        cout << "Side: " << side << ", Diagonal: " << diagonal << ", Color: " << color << endl;
    }
};

class Vector {
private:
    std::vector<double> elements;

public:
    static int objectCount;

    Vector() {
        objectCount++;
    }

    Vector(const double* arr) : elements(arr, arr + sizeof(arr) / sizeof(arr[0])) {
        objectCount++;
    }

    Vector(double val) : elements(1, val) {
        objectCount++;
    }

    Vector(const Vector& other) : elements(other.elements) {
        objectCount++;
    }

    ~Vector() {
        objectCount--;
    }

    void print() const {
        for (const auto& element : elements) {
            cout << element << " ";
        }
        cout << endl;
    }
};

int Vector::objectCount = 0;

int main() {
    int task;
    cout << "Enter task: ";
    cin >> task;
    switch (task) {
    case 1: {
        Rhombus rhombus1;
        rhombus1.print();
        rhombus1.setSide(5.0);
        rhombus1.setDiagonal(6.0);
        rhombus1.setColor("red");
        cout << "Area: " << rhombus1.area() << endl;
        cout << "Perimeter: " << rhombus1.perimeter() << endl;
        rhombus1.print();
        break;
    }
    case 2: {
        double arr[] = { 1.1, 2.2, 3.3 };
        Vector vec1;
        vec1.print();
        Vector vec2(arr);
        vec2.print();
        Vector vec3(5.5);
        vec3.print();
        Vector vec4 = vec1;
        vec4.print();
        Vector vec5;
        vec5 = vec2;
        vec5.print();
        cout << "Vector object count: " << Vector::objectCount << endl;
        break;
    }
    default:
        cout << "Invalid task number." << endl;
        break;
    }
    return 0;
}
