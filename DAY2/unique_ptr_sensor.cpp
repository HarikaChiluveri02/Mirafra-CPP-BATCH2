#include <iostream>

class Sensor {
public:
    explicit Sensor(int id) : id_(id), value_(0.0) {
        std::cout << "Sensor " << id_ << " created." << std::endl;
    }
    ~Sensor() {
        std::cout << "Sensor " << id_ << " destroyed." << std::endl;
    }
    void setValue(double value) { value_ = value; }
    double getValue() const { return value_; }
    int getId() const { return id_; }

private:
    int id_;
    double value_;
};

void modifySensorData(Sensor* sensorPtr, double newValue) {
    if (sensorPtr != nullptr) {
        std::cout << "Modifying sensor " << sensorPtr->getId() << " data..." << std::endl;
        sensorPtr->setValue(newValue);
        std::cout << "New value set to: " << sensorPtr->getValue() << std::endl;
    } else {
        std::cout << "Error: Sensor pointer is null." << std::endl;
    }
}

int main() {
    Sensor* mySensor = new Sensor(101);
    std::cout << "Original sensor value: " << mySensor->getValue() << std::endl;

    modifySensorData(mySensor, 42.5);
    std::cout << "Sensor value after modification: " << mySensor->getValue() << std::endl;

    delete mySensor;
    return 0;
}

