/*#include<iostream>
#include<memory>
using namespace std;
class gpio
{
bool state;
public:
gpio(int val)
{
state=val;
}

bool operator()(bool b)
{
if(state==1)
return 1;
return 0;
}

};

int main()
{

gpio obj1(0);
bool result=obj1(1);
if(result==1)
cout<<"LED ON"<<endl;
else
cout<<"LED OFF"<<endl;

}
*/


#include <iostream>
#include <memory>
#include <unistd.h> // For close()
using namespace std;

//Define the Functor
struct GpioDeleter {
    void operator()(int* fd) const {
        if (fd != nullptr) {
            cout << "Releasing GPIO pin: " << *fd <<endl;
            close(*fd); // GPIO release
            delete fd;
        }
    }
};

// Use unique_ptr with the custom deleter
void setupGPIO() {
    // Assume fd 10 was opened
    int* gpioFd = new int(10);
    unique_ptr<int, GpioDeleter> managedGpio(gpioFd);
    
    // GPIO is used here
    cout << "Using GPIO pin: " << *managedGpio <<endl;
} // managedGpio goes out of scope, GpioDeleter called automatically

int main() {
    setupGPIO();
    return 0;
}







