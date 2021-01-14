#include <vector>
#include <iostream>
#include <sstream>
#include <functional>
#include <string>
#include <memory>

using std::vector;
using std::cout;
using std::endl;
using std::stringstream;
using std::string;
using std::to_string;
using std::function;


class A {
public:
    A() : x(0), y(1), z(2) {}
    int x;
    void setY(int val) {
        y = val;
    }

    int getX() const {
        return x;
    }
    int getY() const {
        return y;
    }
    int getZ() const {
        return z;
    }


private:
    int y;
    int z;


friend void printObj(const A &obj);
friend class B;
};


void printObj(const A &obj) {
    cout << obj.y << endl;
}

class B : private A {
public:
    int getX() {
        return x;
    }
};



int main() {
    std::unique_ptr<A> up = std::make_unique<A>();
    std::shared_ptr<A> sp = std::make_shared<A>();

}
