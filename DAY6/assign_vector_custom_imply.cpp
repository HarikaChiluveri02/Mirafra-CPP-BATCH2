#include<iostream>
using namespace std;

template<typename T>
class My_Vector
{
T* ptr;
int sz;
int cap;
public:
My_Vector():ptr(NULL),sz(0),cap(0) {}

~My_Vector()
{
delete[] ptr;
}
//copy constructor
My_Vector(const My_Vector& obj)
{
sz=obj.sz;
cap=obj.cap;
ptr=new T[cap];
for(int i=0;i<sz;i++)
ptr[i]=obj.ptr[i];
}

//copy assignment 
My_Vector& operator=(const My_Vector& obj)
{
if(this!=&obj)
{
delete[] ptr;
sz=obj.sz;
cap=obj.cap;
ptr=new T[sz];
for(int i=0;i<sz;i++)
ptr[i]=obj.ptr[i];
}
return *this;
}

//Move Constructor
My_Vector(My_Vector&& obj)
{
sz=obj.sz;
cap=obj.cap;
ptr=obj.ptr;
obj.sz=0;
obj.cap=0;
obj.ptr=NULL;
}

//Move Assignment operator
My_Vector& operator=(My_Vector&& obj)
{
if(this!=&obj)
{
delete[] ptr;
sz=obj.sz;
cap=obj.cap;
ptr=obj.ptr;
obj.sz=0;
obj.cap=0;
obj.ptr=NULL;
}
return *this;
}


void push_back(T val)
{
if(sz==cap)
grow();
ptr[sz++]=val;
}

void pop_back()
{
if(sz>0)
{
ptr[sz-1]=0;
sz--;
}
}
T& front()
{
return ptr[0];
}

T& back()
{
return ptr[sz-1];
}
bool empty()
{
return sz==0;
}
T& operator[](int index)
{
if(index>=sz)
throw out_of_range("Vector AT:");
return ptr[index];
}

int size()const
{
return sz;
}

int capacity()const
{
return cap;
}

T* begin()
{
return ptr;
}

T* end()
{
return ptr+sz;
}

void shrink_to_fit()
{
if(sz==cap)
return;

T* p=new T[sz];
for(int i=0;i<sz;i++)
p[i]=ptr[i];
delete[] ptr;
data=p;
cap=sz;
}

private:

void grow()
{
int newCap=(cap==0)?1:(cap*2);
T* newData=new T(newCap);

//copying data to new memory location
for(int i=0;i<sz;i++)
{
newData[i]=ptr[i];
}
delete[] ptr;
ptr=newData;
cap=newCap;
}

};




int main()
{
    // 1. Default constructor + push_back
    My_Vector<int> v;
    cout << "Empty? " << v.empty() << endl;

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    cout << "v elements: ";
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;

    // 2. front & back
    cout << "Front: " << v.front() << endl;
    cout << "Back: " << v.back() << endl;

    // 3. Copy constructor
    My_Vector<int> v2(v);
    cout << "v2 (copy constructed): ";
    for (int i = 0; i < v2.size(); i++)
        cout << v2[i] << " ";
    cout << endl;

    // 4. Copy assignment
    My_Vector<int> v3;
    v3 = v;
    cout << "v3 (copy assigned): ";
    for (int i = 0; i < v3.size(); i++)
        cout << v3[i] << " ";
    cout << endl;

    // 5. Move constructor
    My_Vector<int> v4(move(v));
    cout << "v4 (move constructed): ";
    for (int i = 0; i < v4.size(); i++)
        cout << v4[i] << " ";
    cout << endl;

    cout << "v size after move: " << v.size() << endl;

    // 6. Move assignment
    My_Vector<int> v5;
    v5 = move(v2);
    cout << "v5 (move assigned): ";
    for (int i = 0; i < v5.size(); i++)
        cout << v5[i] << " ";
    cout << endl;

    cout << "v2 size after move: " << v2.size() << endl;

    // 7. pop_back
    v5.pop_back();
    cout << "v5 after pop_back: ";
    for (int i = 0; i < v5.size(); i++)
        cout << v5[i] << " ";
    cout << endl;

    // 8. Iterators
    cout << "Iterating using begin/end: ";
    for (int* it = v5.begin(); it != v5.end(); ++it)
        cout << *it << " ";
    cout << endl;

    return 0;
}























