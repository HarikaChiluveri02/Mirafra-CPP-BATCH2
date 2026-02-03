#include <iostream>
#include <utility>
using namespace std;

class GPIOPin {
private:
    int pinNumber;
    bool* is_active;

public:
    explicit GPIOPin(int pin) : pinNumber(pin) {
        is_active = new bool(false);
        cout << "GPIO " << pinNumber << " initialized.\n";
    }

    ~GPIOPin() {
        if (is_active) {
            cout << "GPIO " << pinNumber << " released.\n";
            delete is_active;
        }
    }

    GPIOPin(const GPIOPin& other)
    {
    cout<<"\ncopy Constructor is called"<<endl;
    this->pinNumber=other.pinNumber;
    this->is_active=new bool(*other.is_active);
    }

    GPIOPin& operator=(const GPIOPin& other)
    {
    cout<<"\nCopy Assignment is called"<<endl;
    if(this!=&other)
    {
    cout<<"Both are different"<<endl;
    if(is_active)
    delete is_active;
    this->pinNumber=other.pinNumber;
    this->is_active=new bool(*other.is_active);
    }
    return *this;
    }

    GPIOPin(GPIOPin&& other) noexcept : pinNumber(other.pinNumber), is_active(other.is_active) {
        cout<<"\nMove constructor is called"<<endl;
        other.is_active = nullptr;
        cout << "GPIO " << pinNumber << " moved to new owner.\n";
    }

    GPIOPin& operator=(GPIOPin&& other) noexcept {
        cout<<"\nmove Assignment operator is called"<<endl;
        if (this != &other) {
            if (is_active) 
		delete is_active;
            pinNumber = other.pinNumber;
            is_active = other.is_active;
            other.is_active = nullptr;
        }
        return *this;
    }

    void write(bool value) {
        if (*is_active!=value) {
            *is_active=value;
             }
            cout << "Writing " << (value ? "HIGH" : "LOW") << " to pin " << pinNumber << "\n";
    }
    void Display()const{
    cout<<"The LED with PinNo: "<<pinNumber<<" is in "<<(*is_active?"HIGH" : "LOW")<<" state"<<endl;
    }
};

int main() {
    //Paramerterised constructor called
    GPIOPin led1(18);
    led1.write(true);
    cout<<"\nLed1 Display"<<endl;
    led1.Display();

    //copy constructor 
    GPIOPin led2=led1;
    cout<<"\nCopy Contructor (led2=led1)"<<endl;
    led2.Display();
    cout<<"\nAddress of led1 "<<&led1<<" Address of led2 "<<&led2<<endl;

    //Copy Assignment operator 
    cout<<"\nLed 3 Intialization"<<endl;
    GPIOPin led3(10);
    cout<<"\nCopy Assignment (led3=led2)"<<endl;
    led3=led2;
    cout<<"\nLed3 Display"<<endl;
    led3.Display();
    led3.write(true);
    cout<<"\nAddress of led1 "<<&led2<<" Address of led2 "<<&led3<<endl;

    //Move Constructor Called
    cout<<"\nMove constructor new_led_owner=move(led3)"<<endl;
    GPIOPin new_led_owner = move(led3);
    cout<<"\nNew owner Display"<<endl;
    new_led_owner.Display();

    //Move Assignment Operator
    cout<<"\nInitialization of led4 and led5"<<endl;
    GPIOPin led4(30),led5(15);
    led4.Display();
    cout<<"\nMove assignment Operator for led4=move(led5)"<<endl;
    led4=move(led5);
    cout<<"\nLed4 Display"<<endl;
    led4.Display();
    return 0;
}

