#include <iostream>
#include <stdexcept>

class Time {
public:
    Time(int hours = 0, int minutes = 0, int seconds = 0) {
        if (hours < 0 || minutes < 0 || seconds < 0) {
            throw std::invalid_argument("Time values cannot be negative");
        }
        this->hours = hours;
        this->minutes = minutes;
        this->seconds = seconds;
    }

    int getHours() const { return hours; }
    int getMinutes() const { return minutes; }
    int getSeconds() const { return seconds; }

    void setHours(int hours) {
        if (hours < 0) {
            throw std::invalid_argument("Hours cannot be negative");
        }
        this->hours = hours;
    }

    void setMinutes(int minutes) {
        if (minutes < 0) {
            throw std::invalid_argument("Minutes cannot be negative");
        }
        this->minutes = minutes;
    }

    void setSeconds(int seconds) {
        if (seconds < 0) {
            throw std::invalid_argument("Seconds cannot be negative");
        }
        this->seconds = seconds;
    }

private:
    int hours;
    int minutes;
    int seconds;
};

int main() {
    try {
        Time time(-1, 2, 3); //исключение
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try {
        Time time(10, 15, 30);
        std::cout << "Time: " << time.getHours() << ":"
            << time.getMinutes() << ":" << time.getSeconds() << std::endl;

    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}