#include "box_container.h"
#include <iostream>

using namespace std;

int main(void) {
    BoxContainer<int> box1;
    cout << box1 << endl;

    cout << "--------------------------------" << endl;

    BoxContainer box2{15};
    cout << box2 << endl;

    cout << "--------------------------------" << endl;

    BoxContainer box3{1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << box3 << endl;

    cout << "--------------------------------" << endl;

    BoxContainer box4{box3 + box3 + box2};
    cout << box4 << endl;

    cout << "--------------------------------" << endl;

    BoxContainer box5{box4};
    BoxContainer<int> box6;
    box6 = box4;

    cout << "--------------------------------" << endl;

    BoxContainer<int> box7{};
    box7 += box1;
    cout << box7 << endl;

    cout << "--------------------------------" << endl;

    box3.removeItem(5);
    cout << box3 << endl;

    cout << "--------------------------------" << endl;

    box3.addItem(5);
    cout << box3 << endl;

    cout << "--------------------------------" << endl;

    box6.removeAll(5);
    cout << box6 << endl;

    box6.removeAll(5);
    cout << box6 << endl;

    box6.removeAll(3);
    cout << box6 << endl;

    cout << "--------------------------------" << endl;

    box4 = box2 = box6;
    cout << box6 << endl;
    cout << box2 << endl;
    cout << box4 << endl;

    cout << "######################################" << endl;
    cout << "######################################" << endl;
    cout << "######################################" << endl;

    BoxContainer<int> box8{15, 13, 2};
    box8.at(2) = 19;
    BoxContainer<int> box9{move(box8)};

    cout << box8 << endl;
    cout << box9 << endl;

    cout << "--------------------------------" << endl;

    BoxContainer<int> box10{};
    box10 = move(box9);

    cout << box8 << endl;
    cout << box9 << endl;
    cout << box10 << endl;

    cout << "--------------------------------" << endl;

    cout << "######################################" << endl;
    cout << "######## work with iterators #########" << endl;
    cout << "######################################" << endl;

    for(const auto &i : box10) {
        cout << i << endl;
    }

    cout << "--------------------------------" << endl;

    BoxContainer box11{15, 31, 99};
    const BoxContainer<int> box12{54, 51, 48, 22};

    cout << "Forward iteration:" << endl;
    for(auto it = box11.begin(); it != box11.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    cout << "Forward iteration:" << endl;
    for(auto it = box11.cbegin(); it != box11.cend(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    cout << "Const forward iteration:" << endl;
    for(auto it = box12.begin(); it != box12.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    cout << "Reverse iteration:" << endl;
    for(auto it = box11.rbegin(); it != box11.rend(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    cout << "Const reverse iteration:" << endl;
    for(auto it = box11.crbegin(); it != box11.crend(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    cout << "Const reverse iteration:" << endl;
    for(auto it = box12.rbegin(); it != box12.rend(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    cout << "######################################" << endl;
    cout << "######################################" << endl;
    cout << "######################################" << endl;

    BoxContainer box13{1, 5, 3, 1, 9};

    cout << box13.front() << endl;
    cout << box13.back() << endl;

    box13.push_back(15);
    cout << box13 << endl;
    cout << box13.pop_back() << endl;
    cout << box13 << endl;

    box13.insert(box13.begin() + 2, 47);
    cout << box13 << endl;

    cout << "Empty: " << box13.empty() << endl;
    box13.clear();
    cout << "Empty: " << box13.empty() << endl;

    cout << box13.data() << endl;
    box13.push_back(15);
    cout << box13.data()[0] << endl;

    BoxContainer<int> box14{15, 13};
    BoxContainer<int> box15{33, 15, 12};

    cout << box14 << endl;
    cout << box15 << endl;

    box14.swap(box15);

    cout << box14 << endl;
    cout << box15 << endl;

    cout << box14.contains(12) << endl;
    cout << box14.contains(13) << endl;

    // Ability to be used with STL containers

    BoxContainer<int> box16{19, 33, 15, 16, 12};

    cout << box16 << endl;

    ranges::sort(box16);

    cout << box16 << endl;

    return 0;
}