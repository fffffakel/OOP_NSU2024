#include <iostream>
#include <iomanip>

class Time {
private:
    int hours;
    int minutes;
    int seconds;

public:
    Time(int h = 0, int m = 0, int s = 0) : hours(h), minutes(m), seconds(s) {}

    friend class SimpleWatch; 
    friend void showTime(const Time& t, bool is24HourFormat); 
    friend void setTime(Time& t, int h, int m, int s); 

    void displayTime(bool is24HourFormat) const {
        showTime(*this, is24HourFormat); 
    }
};

class SimpleWatch {
private:
    bool is24HourFormat;

public:
    SimpleWatch(bool is24 = true) : is24HourFormat(is24) {}

    void showTime(const Time& t) const {
        if (is24HourFormat) {
            std::cout << std::setfill('0') << std::setw(2) << t.hours << ":"
                << std::setfill('0') << std::setw(2) << t.minutes << ":"
                << std::setfill('0') << std::setw(2) << t.seconds << std::endl;
        }
        else {
            int displayHours = (t.hours == 0 || t.hours == 12) ? 12 : t.hours % 12;
            std::string period = (t.hours < 12) ? "AM" : "PM";
            std::cout << std::setfill('0') << std::setw(2) << displayHours << ":"
                << std::setfill('0') << std::setw(2) << t.minutes << ":"
                << std::setfill('0') << std::setw(2) << t.seconds << period << std::endl;
        }
    }


    void setTime(Time& t, int h, int m, int s) {
        t.hours = h;
        t.minutes = m;
        t.seconds = s;
    }

    void set24HourFormat(bool is24) {
        is24HourFormat = is24;
    }
};

void showTime(const Time& t, bool is24HourFormat) {
    if (is24HourFormat) {
        std::cout << std::setfill('0') << std::setw(2) << t.hours << ":"
            << std::setfill('0') << std::setw(2) << t.minutes << ":"
            << std::setfill('0') << std::setw(2) << t.seconds << std::endl;
    }
    else {
        int displayHours = (t.hours == 0 || t.hours == 12) ? 12 : t.hours % 12;
        std::string period = (t.hours < 12) ? "AM" : "PM";
        std::cout << std::setfill('0') << std::setw(2) << displayHours << ":"
            << std::setfill('0') << std::setw(2) << t.minutes << ":"
            << std::setfill('0') << std::setw(2) << t.seconds << period << std::endl;
    }
}

void setTime(Time& t, int h, int m, int s) {
    t.hours = h;
    t.minutes = m;
    t.seconds = s;
}


int main() {
    Time t(15, 30, 45);

    SimpleWatch sw(false); 
    sw.showTime(t);      

    sw.set24HourFormat(true); // Change to 24-hour format
    sw.showTime(t);      

    sw.setTime(t, 10, 0, 0);
    sw.showTime(t);      

    Time t2(20, 15, 0);
    showTime(t2, true);
    setTime(t2, 7, 30, 0);
    showTime(t2, false);  

    return 0;
}