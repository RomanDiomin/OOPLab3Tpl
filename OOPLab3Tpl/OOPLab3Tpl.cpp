#include <iostream>
#include <cmath>
#include <stdexcept>
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
    float x, y, z;
    int state; //  0 - нормальний, 1 - помилка

public:
    static int objectCount;

    Vector() : x(0), y(0), z(0), state(0) {
        objectCount++;
    }

    Vector(float value) : x(value), y(value), z(value), state(0) {
        objectCount++;
    }

    Vector(float* arr) : state(0) {
        if (arr == nullptr) {
            state = 1;
        }
        else {
            x = arr[0];
            y = arr[1];
            z = arr[2];
        }
        objectCount++;
    }

    ~Vector() {
        objectCount--;
    }

    void setValue(float value, char field = 'x') {
        switch (field) {
        case 'x':
            x = value;
            break;
        case 'y':
            y = value;
            break;
        case 'z':
            z = value;
            break;
        default:
            cout << "Invalid field specified!" << endl;
            break;
        }
    }

    float getValue(char field = 'x') const {
        switch (field) {
        case 'x':
            return x;
        case 'y':
            return y;
        case 'z':
            return z;
        default:
            cout << "Invalid field specified!" << endl;
            return 0;
        }
    }

    Vector(const Vector& other) {
        x = other.x;
        y = other.y;
        z = other.z;
        state = other.state;
        objectCount++;
    }

    Vector& operator=(const Vector& other) {
        if (this == &other)
            return *this;
        x = other.x;
        y = other.y;
        z = other.z;
        state = other.state;
        return *this;
    }

    void print() const {
        cout << "Vector: (" << x << ", " << y << ", " << z << ")" << endl;
    }

    Vector add(const Vector& other) const {
        Vector result;
        result.x = x + other.x;
        result.y = y + other.y;
        result.z = z + other.z;
        return result;
    }

    Vector subtract(const Vector& other) const {
        Vector result;
        result.x = x - other.x;
        result.y = y - other.y;
        result.z = z - other.z;
        return result;
    }

    Vector crossProduct(const Vector& other) const {
        Vector result;
        result.x = y * other.z - z * other.y;
        result.y = z * other.x - x * other.z;
        result.z = x * other.y - y * other.x;
        return result;
    }

    void divide(short divisor) {
        if (divisor == 0) {
            state = 1;
        }
        else {
            x /= divisor;
            y /= divisor;
            z /= divisor;
        }
    }

    bool isEqual(const Vector& other) const {
        return x == other.x && y == other.y && z == other.z;
    }

    bool isGreater(const Vector& other) const {
        return magnitude() > other.magnitude();
    }

    bool isLess(const Vector& other) const {
        return magnitude() < other.magnitude();
    }

    float magnitude() const {
        return sqrt(x * x + y * y + z * z);
    }
};

int Vector::objectCount = 0;

int main() {
    int task;
    cout << "Enter task: ";
    cin >> task;
    switch (task)
    {
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
        Vector vec1;
        vec1.print();
        float arr[] = { 1.1, 2.2, 3.3 };
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

    }
    return 0;
}
