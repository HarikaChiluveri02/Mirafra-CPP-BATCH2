#include<iostream>
using namespace std;

template <typename T>
class WeakPtr;

template <typename T>
class SharedPtr {
private:
    T* ptr;
    int* shared;
    int* weak;
    //friend class WeakPtr<T>
public:SharedPtr() : ptr(nullptr), shared(nullptr), weak(nullptr) {}

    explicit SharedPtr(T* p)
        : ptr(p), shared(new int(1)), weak(new int(0)) {}

    SharedPtr(const SharedPtr& other)
        : ptr(other.ptr), shared(other.shared), weak(other.weak) {
        if (shared) ++(*shared);
    }

    ~SharedPtr() {
        if (!shared) return;

        if (--(*shared) == 0) {
            delete ptr;
            ptr = nullptr;

            if (*weak == 0) {
                delete shared;
                delete weak;
            }
        }
    }

    
};
template <typename T>
class WeakPtr {
public:
    T* ptr;
    int* shared;
    int* weak;

    WeakPtr() : ptr(nullptr), shared(nullptr), weak(nullptr) {}

    // from SharedPtr
    WeakPtr(const SharedPtr<T>& sp)
        : ptr(sp.ptr), shared(sp.shared), weak(sp.weak) {
        if (weak) ++(*weak);
    }

    // copy constructor
    WeakPtr(const WeakPtr& other)
        : ptr(other.ptr), shared(other.shared), weak(other.weak) {
        if (weak) ++(*weak);
    }

    // copy assignment
    WeakPtr& operator=(const WeakPtr& other) {
        if (this != &other) {
            release();
            ptr = other.ptr;
            shared = other.shared;
            weak = other.weak;
            if (weak) ++(*weak);
        }
        return *this;
    }

    ~WeakPtr() {
        release();
    }

    void release() {
        if (!weak) return;

        if (--(*weak) == 0 && *shared == 0) {
            delete shared;
            delete weak;
        }
    }

    bool expired() const {
        return !shared || *shared == 0;
    }

    SharedPtr<T> lock() const {
        if (expired())
            return SharedPtr<T>();

        ++(*shared);
        SharedPtr<T> sp;
        sp.ptr = ptr;
        sp.shared = shared;
        sp.weak = weak;
        return sp;
    }
};

int main() {
    cout << "Create shared pointer\n";
    SharedPtr<int> sp(new int(42));

    cout << "Create weak pointer\n";
    WeakPtr<int> wp(sp);

    cout << "Expired? "  << (wp.expired()?"true":"false") << "\n";
    {
        cout << "Lock weak pointer\n";
        SharedPtr<int> sp2 = wp.lock();
        if (sp2.ptr) {
            cout << "Value: " << *sp2.ptr << "\n";
        }
    } // sp2 destroyed here

    cout << "Destroy original shared pointer\n";
    sp = SharedPtr<int>();   // release ownership

    cout << "Expired after shared destruction? "
              << (wp.expired()?"true":"false") << "\n";

    cout << "Try locking after expiration\n";
    SharedPtr<int> sp3 = wp.lock();
    if (!sp3.ptr) {
        cout << "Lock failed (object expired)\n";
    }

    cout << "End of program\n";
}

