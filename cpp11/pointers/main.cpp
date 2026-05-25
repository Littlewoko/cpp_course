#include <iostream>
// required for using any smart pointer (probably included in other headers but should be explicit)
#include <memory>

using namespace std;

class T {
    public:
        T() {
            cout << "created" << endl;
        }

        void greet() {
            cout << "hello" << endl;
        }

        ~T() {
            cout << "destroyed" << endl;
        }
};

// can use smart pointers to remove need for destructor
// shared pointers are similar but delete resources once all pointers to obj go out of scope
// shared pointers can't be used for arrays
int main() {

    // smart pointers automatically cleanup heap memory when they leave scope
    unique_ptr<int> pT(new int);
    *pT = 7;
    cout << *pT << endl;
    {
        unique_ptr<T> pT1(new T);
        pT1->greet();
    }

    // deletes assigned bugger and all T objects when it leaves scope
    unique_ptr<T[]> pArr(new T[5]);
    pArr[3].greet();

    cout << "finished" << endl;

    return 0;
}