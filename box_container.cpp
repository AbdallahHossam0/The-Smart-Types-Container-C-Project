#include "box_container.h"

BoxContainer::BoxContainer() : m_capacity{1}, m_size{0}, m_data{std::make_unique<int[]>(1)} {}

BoxContainer::BoxContainer(const std::initializer_list<int> &values) : BoxContainer() {
    for(const int &value : values) {
        this->addItem(value);
    }
}

void BoxContainer::operator=(const BoxContainer &rhs) {
    if(this == &rhs) {
        return;
    }
    m_size = rhs.size();
    m_capacity = rhs.capacity();
    int *arr = new int[m_capacity];
    m_data.reset(arr);
    for(size_t i{}; i < size(); ++i) {
        m_data[i] = rhs[i];
    }
}

BoxContainer::BoxContainer(const BoxContainer &rhs) {
    *this = rhs;
}

void BoxContainer::addItem(int item) {
    if(size() == capacity()) {
        editCapacity(size() << 1);
    }
    m_data[m_size++] = item;
}

bool BoxContainer::removeItem(int item) {
    for(size_t i{}; i < size(); ++i) {
        if(m_data[i] == item) {
            m_data[i] = m_data[--m_size];
            if(m_capacity >> 1 >= m_size) {
                editCapacity(m_capacity >> 1);
            }
            return true;
        }
    }
    return false;
}

void BoxContainer::removeAll(int item) {
    while(removeItem(item)) {
    }
}

void BoxContainer::empty(void) {
    m_size = 0;
    m_capacity = 1;
    std::unique_ptr<int[]> arr = std::make_unique<int[]>(0);
    m_data = std::move(arr);
}

void BoxContainer::editCapacity(size_t value) {
    std::unique_ptr<int[]> arr = std::make_unique<int[]>(value);
    for(size_t i{}; i < size(); ++i) {
        arr[i] = m_data[i];
    }
    m_data = std::move(arr);
    m_capacity = value;
}

std::ostream &operator<<(std::ostream &out, const BoxContainer &container) {
    out << "BoxContainer: " << std::endl;
    out << "Size: " << container.size();
    out << ", Capacity: " << container.capacity() << std::endl;
    out << "Elements: ";
    for(size_t i{}; i < container.size(); ++i) {
        out << container[i] << "\t";
    }
    return out;
}

BoxContainer operator+(const BoxContainer &container1, const BoxContainer &container2) {
    BoxContainer container;
    for(int i{}; i < container1.size(); ++i) {
        container.addItem(container1[i]);
    }
    for(int i{}; i < container2.size(); ++i) {
        container.addItem(container2[i]);
    }
    return container;
}

int &BoxContainer::operator[](size_t index) const {
    if(index >= size() || index < 0) {
        throw 0;
    }
    return m_data[index];
}

void BoxContainer::operator+=(const BoxContainer &container1) {
    for(int i = 0; i < container1.size(); ++i) {
        this->addItem(container1[i]);
    }
}
