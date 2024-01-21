#ifndef _BOX_CONTAINER_H_
#define _BOX_CONTAINER_H_

#include <memory>
#include <ostream>

class BoxContainer {
  public:
    BoxContainer();
    BoxContainer(const std::initializer_list<int> &values);
    BoxContainer(const BoxContainer &rhs);
    BoxContainer &operator=(const BoxContainer &rhs);

    ~BoxContainer() = default;

    void operator+=(const BoxContainer &container1);
    int &operator[](size_t index) const;

    size_t capacity() const { return m_capacity; }
    size_t size() const { return m_size; }

    void addItem(int item);
    bool removeItem(int item);
    void removeAll(int item);
    void empty(void);

  private:
    void editCapacity(size_t value);

    std::unique_ptr<int[]> m_data;
    size_t m_size{0};
    size_t m_capacity{1};
};

std::ostream &operator<<(std::ostream &out, const BoxContainer &container);
BoxContainer operator+(const BoxContainer &container1, const BoxContainer &container2);

#endif /* _BOX_CONTAINER_H_ */
