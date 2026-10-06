#include <iostream>
#include <string>
#include <vector>

// Предварительное объявление
class Box; 

class Ball {
    std::string color;
    Box* box;
public:
    Ball(std::string c) : color(c), box(nullptr) {}
    void set_box(Box* b) { box = b; }
    std::string get_color() const { return color; }
    void report() const; // Только объявление
};

class Box {
    std::string name;
    std::vector<Ball*> balls;
public:
    Box(std::string n) : name(n) {}
    
    void add(Ball* b) {
        balls.push_back(b);
        b->set_box(this);
    }
    
    std::string get_name() const { return name; }
    
    void report() const {
        std::cout << "Коробка '" << name << "' содержит: ";
        for (auto b : balls) std::cout << b->get_color() << " ";
        std::cout << "\n";
    }
};

// Реализация после полного описания класса Box
void Ball::report() const {
    if (box) std::cout << "Шарик '" << color << "' в коробке '" << box->get_name() << "'.\n";
    else     std::cout << "Шарик '" << color << "' не в коробке\n";
}

int main() {
    Ball b1("Красный"), b2("Синий"), b3("Зеленый");
    Box box1("Коробка А"), box2("Коробка Б");

    box1.add(&b1);
    box1.add(&b2);
    box2.add(&b3);

    b1.report();
    b2.report();
    b3.report();

    box1.report();
    box2.report();

    return 0;
}