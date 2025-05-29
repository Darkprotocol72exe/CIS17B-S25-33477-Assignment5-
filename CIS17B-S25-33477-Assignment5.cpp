// Hugo Willis
// CIS-17B-33477
// LMD: 05/27/25
#include <iostream>
#include <string>
#include <array>
#include <typeinfo>

using namespace std;

template<typename T>
string typeName() {
    return typeid(T).name();
}
template<>
string typeName<int>() { return "int"; }
template<>
string typeName<double>() { return "double"; }
template<>
string typeName<string>() { return "string"; }

// Class Template Package<T>
template<typename T>
class Package {
private:
    T item;
public:
    Package(const T& item) : item(item) {}
    void label() const {
        cout << "Generic package containing: " << typeName<T>() << endl;
    }
};

// Specialization for string
template<>
class Package<string> {
private:
    string item;
public:
    Package(const string& item) : item(item) {}
    void label() const {
        cout << "Book package: " << item << endl;
    }
};

// Partial Specialization for pointer types
template<typename T>
class Package<T*> {
private:
    T* item;
public:
    Package(T* item) : item(item) {}
    void label() const {
        cout << "Fragile package for pointer to type: " << typeName<T>() << endl;
    }
};

// Class Template Box<T, Size>
template<typename T, int Size>
class Box {
private:
    array<T, Size> items;
    int count = 0;
public:
    void addItem(const T& item) {
        if (count < Size) items[count++] = item;
        else cout << "Box is full. Cannot add more items." << endl;
    }

    void printItems() const {
        cout << "Box contents:" << endl;
        for (int i = 0; i < count; ++i)
            cout << "- " << items[i] << endl;
    }
};

// Function Template shipItem<T>
template<typename T>
void shipItem(const T& item) {
    cout << "Shipping item of type: " << typeName<T>() << endl;
}

// Specialization for double
template<>
void shipItem<double>(const double& item) {
    cout << "Shipping temperature-controlled item: " << item << "°F" << endl;
}

int main() {
    // Demonstrate Package
    Package<int> intPackage(42);
    intPackage.label();

    Package<string> bookPackage("Mystery Box");
    bookPackage.label();

    double temp = 5.5;
    Package<double*> fragilePackage(&temp);
    fragilePackage.label();

    // Demonstrate Box
    Box<string, 3> bookBox;
    bookBox.addItem("Berserk");
    bookBox.addItem("Harry Potter");
    bookBox.addItem("Game of Thrones");
    bookBox.printItems();

    // Demonstrate shipItem
    shipItem(123);
    shipItem(string("Congo Package"));
    shipItem(32.0);

    return 0;
}
