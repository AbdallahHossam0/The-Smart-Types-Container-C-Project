#ifndef _BOX_CONTAINER_H_
#define _BOX_CONTAINER_H_

#include <memory>
#include <ostream>

template <typename T>
class BoxContainer {
  public:
    BoxContainer();
    BoxContainer(const std::initializer_list<T> &values);
    BoxContainer(const BoxContainer &rhs);
    BoxContainer &operator=(const BoxContainer &rhs);

    ~BoxContainer() = default;

    void operator+=(const BoxContainer &container1);
    T &operator[](size_t index) const;

    size_t capacity() const { return m_capacity; }
    size_t size() const { return m_size; }

    void addItem(T item);
    bool removeItem(T item);
    void removeAll(T item);
    void empty(void) const;

  private:
    void editCapacity(size_t value);

    std::unique_ptr<T[]> m_data;
    size_t m_size{0};
    size_t m_capacity{1};
};

/* ################################################################################################## */
template <typename T>
std::ostream &operator<<(std::ostream &out, const BoxContainer<T> &container);

template <typename T>
BoxContainer<T> operator+(const BoxContainer<T> &container1, const BoxContainer<T> &container2);

template <typename T>
BoxContainer<T>::BoxContainer() : m_capacity{1}, m_size{0}, m_data{std::make_unique<T[]>(1)} {}

template <typename T>
BoxContainer<T>::BoxContainer(const std::initializer_list<T> &values) : BoxContainer() {
    for(const int &value : values) {
        this->addItem(value);
    }
}

template <typename T>
BoxContainer<T> &BoxContainer<T>::operator=(const BoxContainer<T> &rhs) {
    if(this == &rhs) {
        return *this;
    }
    m_size = rhs.size();
    m_capacity = rhs.capacity();
    int *arr = new T[m_capacity];
    m_data.reset(arr);
    for(size_t i{}; i < size(); ++i) {
        m_data[i] = rhs[i];
    }
    return *this;
}

template <typename T>
BoxContainer<T>::BoxContainer(const BoxContainer<T> &rhs) {
    *this = rhs;
}

template <typename T>
void BoxContainer<T>::addItem(T item) {
    if(size() == capacity()) {
        editCapacity(size() << 1);
    }
    m_data[m_size++] = item;
}

template <typename T>
bool BoxContainer<T>::removeItem(T item) {
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

template <typename T>
void BoxContainer<T>::removeAll(T item) {
    while(removeItem(item)) {
    }
}

template <typename T>
void BoxContainer<T>::empty(void) const {
    m_size = 0;
    m_capacity = 1;
    std::unique_ptr<T[]> arr = std::make_unique<int[]>(0);
    m_data = std::move(arr);
}

template <typename T>
void BoxContainer<T>::editCapacity(size_t value) {
    std::unique_ptr<T[]> arr = std::make_unique<T[]>(value);
    for(size_t i{}; i < size(); ++i) {
        arr[i] = m_data[i];
    }
    m_data = std::move(arr);
    m_capacity = value;
}

template <typename T>
std::ostream &operator<<(std::ostream &out, const BoxContainer<T> &container) {
    out << "BoxContainer: " << std::endl;
    out << "Size: " << container.size();
    out << ", Capacity: " << container.capacity() << std::endl;
    out << "Elements: ";
    for(size_t i{}; i < container.size(); ++i) {
        out << container[i] << "\t";
    }
    return out;
}

template <typename T>
BoxContainer<T> operator+(const BoxContainer<T> &container1, const BoxContainer<T> &container2) {
    BoxContainer<T> container;
    for(int i{}; i < container1.size(); ++i) {
        container.addItem(container1[i]);
    }
    for(int i{}; i < container2.size(); ++i) {
        container.addItem(container2[i]);
    }
    return container;
}

template <typename T>
T &BoxContainer<T>::operator[](size_t index) const {
    if(index >= size() || index < 0) {
        throw 0;
    }
    return m_data[index];
}

template <typename T>
void BoxContainer<T>::operator+=(const BoxContainer<T> &container1) {
    for(int i = 0; i < container1.size(); ++i) {
        this->addItem(container1[i]);
    }
}

#endif /* _BOX_CONTAINER_H_ */
