#include <iostream>
using namespace std;

template <typename T>
class WeakPtr;

template <typename T>
class SharedPtr {
private:
    T* ptr;        // actual object
    int* shared;   // shared count
    int* weak;     // weak count

    // Allow WeakPtr to access private members
    friend class WeakPtr<T>;

public:
    // Default constructor
    SharedPtr() : ptr(nullptr), shared(nullptr), weak(nullptr) {}

    // Constructor from raw pointer
    explicit SharedPtr(T* p)
        : ptr(p), shared(new int(1)), weak(new int(0)) {}

    // Copy constructor
    SharedPtr(const SharedPtr& other)
        : ptr(other.ptr), shared(other.shared), weak(other.weak) {
        if (shared) 
        ++(*shared);
    }
    SharedPtr& operator=(const SharedPtr& other) {
    if (this != &other) {
        // release current ownership
        if (shared) {
            if (--(*shared) == 0) {
                delete ptr;
                if (*weak == 0) {
                    delete shared;
                    delete weak;
                }
            }
        }

        // copy from other
        ptr = other.ptr;
        shared = other.shared;
        weak = other.weak;
        if (shared) i
        ++(*shared);
    }
    return *this;
}


    // Destructor
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
   T* get() const {
    return ptr;
}

};

template <typename T>
class WeakPtr {
private:
    T* ptr;
    int* shared;
    int* weak;

public:
    // Default constructor
    WeakPtr() : ptr(nullptr), shared(nullptr), weak(nullptr) {}

    // Construct from SharedPtr
    WeakPtr(const SharedPtr<T>& sp)
        : ptr(sp.ptr), shared(sp.shared), weak(sp.weak) {
        if (weak) 
        ++(*weak);
    }

    // Copy constructor
    WeakPtr(const WeakPtr& other)
        : ptr(other.ptr), shared(other.shared), weak(other.weak) {
        if (weak) 
        ++(*weak);
    }

    // Copy assignment
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

    // Destructor
    ~WeakPtr() { release(); }

    // Check if object is destroyed
    bool expired() const {
        return !shared || *shared == 0;
    }

    // Lock weak pointer to get SharedPtr
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

private:
    // releasing weak pointer
    void release() {
        if (!weak) return;

        if (--(*weak) == 0 && *shared == 0) {
            delete shared;
            delete weak;
        }
    }
};

int main() {
    SharedPtr<int> sp(new int(42));
    WeakPtr<int> wp(sp);

    cout << "Expired? " << (wp.expired()?"true":"false") << "\n";

    {
        SharedPtr<int> sp2 = wp.lock();
        if (sp2.get()) 
        cout << "Value: " << *sp2.get() << "\n";
    }

    sp = SharedPtr<int>();   // releases object

    cout << "Expired after shared destruction? " << (wp.expired()?"true":"false") << "\n";

    SharedPtr<int> sp3 = wp.lock();
    if (!sp3.get()) 
    cout << "Lock failed (object expired)\n";
}

