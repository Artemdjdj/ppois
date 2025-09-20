

#ifndef INCLUDE_GEAR_H
#define INCLUDE_GEAR_H
#include <optional>
class Figure {
public:
    virtual ~Figure() {};
    virtual double get_square() = 0;
    virtual double get_perimeter() = 0;
};

class Triangle : public Figure {
private:
    int first_side{0};
    int second_side{0};
    int third_side{0};
public:
    Triangle();
    Triangle(int first_side, int second_side, int third_side);
    bool set_sides(int first_side, int second_side, int third_side);
    std::optional<int> get_one_of_sides(int number_of_side) const;
    double get_square() override;
    double get_perimeter() override;
};

class Circle : public Figure {
private:
    int radius{0};
public:
    Circle();
    Circle(int radius);
    bool set_radius(int radius);
    int get_radius() const;
    double get_square() override;
    double get_perimeter() override;
};

class Detail {
private:
    int thickness{0};
    int density{0};
public:
    Detail();
    Detail(int thickness, int density);
    virtual ~Detail() {};
    bool set_thickness(int thickness);
    int get_thickness() const;
    bool set_density(int density);
    int get_density() const;
    virtual double get_weight() =0;
};

class Prong : public Triangle, Detail {
public:
    Prong();
    Prong(int first_side, int seconde_side, int third_side, int thickness, int density);
    bool set_data_prong(int first_side, int second_side, int third_side, int thickness, int density);
    double get_weight() override;
};

class Rim: public Circle, public Detail {
public:
    Rim();
    Rim(int radius, int thickness, int density);
    bool set_data_rim(int radius, int thickness, int density);
    double get_weight() override;
};

#endif //INCLUDE_GEAR_H
