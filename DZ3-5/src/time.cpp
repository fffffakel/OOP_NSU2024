#include <iostream>

class Time {
private:
    int hours;
    int minutes;
    int seconds;

    static int objectCount;

    void Normalize() {
        if (seconds < 0) {
            minutes += (seconds - 59) / 60;
            seconds = (seconds % 60 + 60) % 60;
        }
        if (seconds >= 60) {
            minutes += seconds / 60;
            seconds %= 60;
        }
        if (minutes < 0) {
            hours += (minutes - 59) / 60;
            minutes = (minutes % 60 + 60) % 60;
        }
        if (minutes >= 60) {
            hours += minutes / 60;
            minutes %= 60;
        }
        if (hours < 0) {
            hours = (hours % 24 + 24) % 24;
        }
        if (hours >= 24) {
            hours %= 24;
        }
    }

public:
    Time(int h = 0, int m = 0, int s = 0) : hours(h), minutes(m), seconds(s) {
        // std::cout << "Time constructor called (object count: " << ++objectCount << ")" << std::endl;
        Normalize();
    }

    ~Time() {
        //std::cout << "Time destructor called (object count: " << --objectCount << ")" << std::endl;
    }


    int ToSeconds() const {
        return hours * 3600 + minutes * 60 + seconds;
    }

    Time operator+(const Time& other) const {
        int totalSeconds = ToSeconds() + other.ToSeconds();
        int h = totalSeconds / 3600;
        int m = (totalSeconds % 3600) / 60;
        int s = totalSeconds % 60;
        Time result(h, m, s);
        result.Normalize();
        return result;
    }

    Time& operator+=(const Time& other) {
        hours += other.hours;
        minutes += other.minutes;
        seconds += other.seconds;
        Normalize();
        return *this;
    }

    Time operator-(const Time& other) const {
        Time result(hours - other.hours, minutes - other.minutes, seconds - other.seconds);
        result.Normalize();
        return result;
    }

    Time& operator-=(const Time& other) {
        hours -= other.hours;
        minutes -= other.minutes;
        seconds -= other.seconds;
        Normalize();
        return *this;
    }

    bool operator==(const Time& other) const {
        return hours == other.hours && minutes == other.minutes && seconds == other.seconds;
    }

    void Print() const {
        std::cout << (hours < 10 ? "0" : "") << hours << ":"
            << (minutes < 10 ? "0" : "") << minutes << ":"
            << (seconds < 10 ? "0" : "") << seconds << std::endl;
    }
};
