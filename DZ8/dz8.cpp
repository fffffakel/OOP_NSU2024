#include <iostream>

// Общий родитель
class GenericCreature {
public:
    void breathe() {
        std::cout << "Breathing..." << std::endl;
    }
};

// Океанское существо, умеющее плавать
class OceanCreature : public GenericCreature {
public:
    void swim() {
        std::cout << "Swimming..." << std::endl;
    }
};

// Амфибия, умеющая плавать и ходить
class Amphibious : public OceanCreature {
public:
    void walk() {
        std::cout << "Walking..." << std::endl;
    }
};

// Наземное существо, не умеющее плавать, но умеющее ходить
class TerrestrialCreature : public GenericCreature {
public:
    void walk() {
        std::cout << "Walking..." << std::endl;
    }
};

// Птица, умеющая ходить и летать
class Bird : public TerrestrialCreature {
public:
    void fly() {
        std::cout << "Flying..." << std::endl;
    }
};

// Водоплавающая птица, умеющая ходить, летать и плавать
class Waterfowl : public Bird, public OceanCreature {
public:
    void swim() {
        OceanCreature::swim();
    }
};

int main() {
    GenericCreature generic;
    OceanCreature ocean;
    Amphibious amphibious;
    TerrestrialCreature terrestrial;
    Bird bird;
    Waterfowl waterfowl;

    generic.breathe();
    ocean.swim();
    amphibious.walk();
    amphibious.swim();
    terrestrial.walk();
    bird.fly();
    waterfowl.swim();
    waterfowl.walk();
    waterfowl.fly();

    return 0;
}