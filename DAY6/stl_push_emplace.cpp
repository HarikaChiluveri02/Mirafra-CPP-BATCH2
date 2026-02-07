#include<vector>
#include<string>
#include<iostream>
using namespace std;

struct Student {
string name;
int age;

Student(std::string n,int a) :name(n),age(a) {
        cout <<"Constructor\n";
    }

Student(const Student&) {
        cout <<"Copy constructor\n";
    }

Student(Student&&)noexcept {
        cout <<"Move constructor\n";
    }
};

int main() {
    vector<Student> v;

    cout <<"push_back:\n";
    v.push_back(Student("Alice",30)); // 1 2

    cout <<"\n1emplace_back:\n";
    v.emplace_back("Bob",25);
    cout <<"\n2emplace_back:\n";
     v.emplace_back("Sam",35);
     cout <<"\n3 emplace_back:\n";
     v.emplace_back("Joy",36);
     cout <<"\n4 emblace_back:\n";
      v.emplace_back("John",36); // cap =8 , ele =5
    cout<<"\n5 emplace back:\n"; 
  v.emplace_back("Jovin",36); //constructor
     //cout <<"\npush_back:\n";
     //v.push_back(Student("Alvin",30)); //constru + mov
}


