#ifndef _BOX_CONTAINER_H_
#define _BOX_CONTAINER_H_

#include <algorithm>
#include <concepts>
#include <iterator>
#include <memory>
#include <ostream>

template <std::default_initializable T>
class BoxContainer {
  public:
    using iterator = T *;
    using const_iterator = const T *;

    BoxContainer();
    BoxContainer(const std::initializer_list<T> &values);

    BoxContainer(const BoxContainer &rhs);
    BoxContainer &operator=(const BoxContainer &rhs);

    BoxContainer(BoxContainer &&rhs);
    BoxContainer &operator=(BoxContainer &&rhs);

    ~BoxContainer() = default;

    void operator+=(const BoxContainer &container1);

    T &at(size_t index) const;
    T &operator[](size_t index) const noexcept;

    size_t capacity() const { return m_capacity; }
    size_t size() const { return m_size; }

    void addItem(T item);
    bool removeItem(T item);
    void removeAll(T item);

    T front() const;
    T back() const;

    T *data() const;

    bool empty() const;

    void push_back(T item);
    T pop_back();

    void clear();

    void insert(iterator it, T value);

    void swap(BoxContainer<T> &rhs);

    bool contains(const T &value) const;

    using reverse_iterator = std::reverse_iterator<iterator>;
    using const_reverse_iterator = const reverse_iterator;

    iterator begin() noexcept { return m_data.get(); }
    iterator end() noexcept { return m_data.get() + m_size; }

    const_iterator begin() const noexcept { return m_data.get(); }
    const_iterator end() const noexcept { return m_data.get() + m_size; }

    const_iterator cbegin() const noexcept { return m_data.get(); }
    const_iterator cend() const noexcept { return m_data.get() + m_size; }

    reverse_iterator rbegin() noexcept { return reverse_iterator(end()); }
    reverse_iterator rend() noexcept { return reverse_iterator(begin()); }

    const_reverse_iterator rbegin() const noexcept { return const_reverse_iterator(m_data.get() + m_size); }
    const_reverse_iterator rend() const noexcept { return const_reverse_iterator(m_data.get()); }

    const_reverse_iterator crbegin() const noexcept { return const_reverse_iterator(m_data.get() + m_size); }
    const_reverse_iterator crend() const noexcept { return const_reverse_iterator(m_data.get()); }

  private:
    void editCapacity(size_t value);
    size_t findNextPowerOfTwo(size_t size);

    std::unique_ptr<T[]> m_data;
    size_t m_size{0};
    size_t m_capacity{1};
};

/* ################################################################################################## */
template <typename T>
std::ostream &operator<<(std::ostream &out, const BoxContainer<T> &container);

template <std::default_initializable T>
BoxContainer<T> operator+(const BoxContainer<T> &container1, const BoxContainer<T> &container2);

template <std::default_initializable T>
BoxContainer<T>::BoxContainer() : m_capacity{1}, m_size{0}, m_data{std::make_unique<T[]>(1)} {}

template <std::default_initializable T>
BoxContainer<T>::BoxContainer(const std::initializer_list<T> &values) : BoxContainer() {
    for(const int &value : values) {
        this->addItem(value);
    }
}

template <std::default_initializable T>
BoxContainer<T>::BoxContainer(const BoxContainer<T> &rhs) {
    *this = rhs;
}

template <std::default_initializable T>
BoxContainer<T> &BoxContainer<T>::operator=(const BoxContainer<T> &rhs) {
    if(this != &rhs) {
        m_size = rhs.size();
        m_capacity = rhs.capacity();
        int *arr = new T[m_capacity];
        m_data.reset(arr);
        for(size_t i{}; i < size(); ++i) {
            m_data[i] = rhs[i];
        }
    }
    return *this;
}

template <std::default_initializable T>
BoxContainer<T>::BoxContainer(BoxContainer<T> &&rhs) : m_size{rhs.m_size},
                                                       m_capacity{rhs.m_capacity},
                                                       m_data{std::move(rhs.m_data)} {
    rhs.m_capacity = 0;
    rhs.m_size = 0;
}

template <std::default_initializable T>
BoxContainer<T> &BoxContainer<T>::operator=(BoxContainer<T> &&rhs) {
    if(this != &rhs) {
        m_size = rhs.size();
        m_capacity = rhs.capacity();
        m_data = std::move(rhs.m_data);
        rhs.m_size = 0;
        rhs.m_capacity = 0;
    }
    return *this;
}

template <std::default_initializable T>
void BoxContainer<T>::addItem(T item) {
    if(size() == capacity()) {
        editCapacity(size() << 1);
    }
    m_data[m_size++] = item;
}

template <std::default_initializable T>
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

template <std::default_initializable T>
void BoxContainer<T>::removeAll(T item) {
    while(removeItem(item)) {
    }
}

template <std::default_initializable T>
void BoxContainer<T>::clear(void) {
    m_size = 0;
    m_capacity = 1;
    std::unique_ptr<T[]> arr = std::make_unique<int[]>(0);
    m_data = std::move(arr);
}

template <std::default_initializable T>
bool BoxContainer<T>::empty(void) const {
    return m_size == 0;
}

template <std::default_initializable T>
void BoxContainer<T>::editCapacity(size_t value) {
    std::unique_ptr<T[]> arr = std::make_unique<T[]>(value);
    for(size_t i{}; i < size(); ++i) {
        arr[i] = m_data[i];
    }
    m_data = std::move(arr);
    m_capacity = value;
}

template <std::default_initializable T>
size_t BoxContainer<T>::findNextPowerOfTwo(size_t size) {
    if(size == 0) {
        return 1;
    }
    size--;
    for(size_t i = 1; i < (sizeof(size_t) << 3); i <<= 1) {
        size |= size >> i;
    }
    return ++size;
}

template <std::default_initializable T>
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

template <std::default_initializable T>
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

template <std::default_initializable T>
T &BoxContainer<T>::at(size_t index) const {
    if(index >= size() || index < 0) {
        throw 0;
    }
    return m_data[index];
}

template <std::default_initializable T>
T &BoxContainer<T>::operator[](size_t index) const noexcept {
    return m_data[index];
}

template <std::default_initializable T>
void BoxContainer<T>::operator+=(const BoxContainer<T> &container1) {
    for(int i = 0; i < container1.size(); ++i) {
        this->addItem(container1[i]);
    }
}

template <std::default_initializable T>
T BoxContainer<T>::front() const {
    return m_data[0];
}
template <std::default_initializable T>
T BoxContainer<T>::back() const {
    return m_data[m_size - 1];
}
template <std::default_initializable T>
T *BoxContainer<T>::data() const {
    return m_data.get();
}

template <std::default_initializable T>
void BoxContainer<T>::push_back(T item) {
    this->addItem(item);
}
template <std::default_initializable T>
T BoxContainer<T>::pop_back() {
    return m_data[--m_size];
}

template <std::default_initializable T>
void BoxContainer<T>::insert(iterator it, T value) {
    T temp;
    while(it != end()) {
        temp = *it;
        *it = value;
        ++it;
        value = temp;
    }
    m_size++;
}

template <std::default_initializable T>
void BoxContainer<T>::swap(BoxContainer<T> &rhs) {
    BoxContainer temp{std::move(*this)};
    *this = std::move(rhs);
    rhs = std::move(temp);
}

template <std::default_initializable T>
bool BoxContainer<T>::contains(const T &value) const {
    return std::find_if(begin(), end(), [&](const T &element) {
               return element == value;
           }) == end();
}

#endif /* _BOX_CONTAINER_H_ */
