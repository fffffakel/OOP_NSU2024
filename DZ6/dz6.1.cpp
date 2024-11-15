#include <iostream>
#include <vector>
#include <list>
#include <memory>

class Time {
public:
    Time(int h = 0, int m = 0, int s = 0) : hour(h), minute(m), second(s) {
        std::cout << "Constructor: Time(" << hour << ", " << minute << ", " << second << ")" << std::endl;
    }

    ~Time() {
        std::cout << "Destructor: Time(" << hour << ", " << minute << ", " << second << ")" << std::endl;
    }

    int getHour() const { return hour; }
    int getMinute() const { return minute; }
    int getSecond() const { return second; }

private:
    int hour;
    int minute;
    int second;
};

int main() {

    // Один экземпляр:
    Time* time1 = new Time(10, 20, 30);
    std::cout << "Time1: " << time1->getHour() << ":" << time1->getMinute() << ":" << time1->getSecond() << std::endl;
    delete time1; 

    // Массив:
    Time* timeArray = new Time[3];
    timeArray[0] = Time(1, 2, 3);
    timeArray[1] = Time(4, 5, 6);
    timeArray[2] = Time(7, 8, 9);
    delete[] timeArray; 

    // --- Стандартные контейнеры ---

    // vector:
    std::vector<Time> timeVector;
    timeVector.push_back(Time(10, 20, 30));
    timeVector.push_back(Time(11, 12, 13));

    // list:
    std::list<Time> timeList;
    timeList.push_back(Time(14, 15, 16));
    timeList.push_back(Time(17, 18, 19));

    // --- Умные указатели ---

    // shared_ptr:
    std::shared_ptr<Time> timeSharedPtr(new Time(10, 20, 30));
    std::cout << "Time: " << timeSharedPtr->getHour() << ":" << timeSharedPtr->getMinute() << ":" << timeSharedPtr->getSecond() << std::endl;

    // unique_ptr:
    std::unique_ptr<Time> timeUniquePtr(new Time(11, 12, 13));

    return 0;
}