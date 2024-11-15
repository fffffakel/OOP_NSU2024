#include <iostream>
#include <string>

// Базовый класс для всех часов
class Clock {
public:
    Clock() {
        std::cout << "Constructor: Clock" << std::endl;
    }
    virtual ~Clock() {
        std::cout << "Destructor: Clock" << std::endl;
    }
};

// Класс для часов с кукушкой
class CuckooClock : public Clock {
public:
    CuckooClock() {
        std::cout << "Constructor: CuckooClock" << std::endl;
    }
    ~CuckooClock() {
        std::cout << "Destructor: CuckooClock" << std::endl;
    }
};

// Класс для настенных часов
class WallClock : public Clock {
public:
    WallClock() {
        std::cout << "Constructor: WallClock" << std::endl;
    }
    ~WallClock() {
        std::cout << "Destructor: WallClock" << std::endl;
    }
};

// Класс для наручных часов
class Watch : public Clock {
public:
    Watch() {
        std::cout << "Constructor: Watch" << std::endl;
    }
    ~Watch() {
        std::cout << "Destructor: Watch" << std::endl;
    }
};

// Класс для смарт-часов
class SmartWatch : public Watch {
public:
    SmartWatch() {
        std::cout << "Constructor: SmartWatch" << std::endl;
    }
    ~SmartWatch() {
        std::cout << "Destructor: SmartWatch" << std::endl;
    }
};

int main() {
    // Создание объектов разных классов
    CuckooClock cuckooClock;
    WallClock wallClock;
    Watch watch;
    SmartWatch smartWatch;

    return 0;
}