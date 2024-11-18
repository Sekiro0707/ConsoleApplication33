#include <Windows.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Person {
    string name;
    int age;


public:
    Person() : name("NoName"), age(0) {}

    Person(const string& name, int age) : name(name), age(age) {}

    Person(const Person& other) : name(other.name), age(other.age) {}

    ~Person() {}

    void prnt() const {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};


class Apart {
    vector<Person*> people;
    int numapart;
public:
    Apart(int number = 0) : numapart(number) {}

    ~Apart() {
        for (Person* person : people) {
            delete person;
        }
    }

    void person1(const Person& person) {
        people.push_back(new Person(person));
    }

    void prnt() const {
        cout << numapart << endl;
        for (const Person* person : people) {
            person->prnt();
        }
    }
};


class budka {
    vector<Apart*> apartments;
public:
    budka() {}

    ~budka() {
        for (Apart* apart1 : apartments) {
            delete apart1;
        }
    }

    void addern(const Apart& apart1) {
        apartments.push_back(new Apart(apart1));
    }

    void prnt() const {
        for (const Apart* apart1 : apartments) {
            apart1->prnt();
        }
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Person p1("John", 30);
    Person p2("Alice", 25);
    Person p3("Bob", 40);

    Apart a1(101);
    a1.person1(p1);
    a1.person1(p2);

    Apart a2(102);
    a2.person1(p3);
    budka buzing;
    buzing.addern(a1);
    buzing.addern(a2);

    buzing.prnt();

    return 0;
}
