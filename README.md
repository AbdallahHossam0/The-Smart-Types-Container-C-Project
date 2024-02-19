# BoxContainer C++ Project

## Overview

The **BoxContainer** project is a versatile C++ container class designed for dynamic storage of integers. It provides functionalities such as dynamic resizing, element addition/removal, and efficient memory management.

## Features

### 1. Dynamic Resizing
- Utilizes smart pointers and modern C++ features to dynamically resize the container based on the number of elements.

### 2. Element Manipulation
- Supports adding and removing elements efficiently.
- Utilizes standard algorithms to handle element removal.

### 3. Memory Management
- Implements efficient memory allocation and de-allocation strategies for optimal performance.

### 4. Utilized Modern C++ features
- Smart pointers, C++20 concepts, and Operator Overloading

### 5.Iterator Support
- The class supports iterator functionality, allowing you to iterate over the elements in the container using range-based for loops or standard algorithms.

### 5. Compatible with STL algorithms
- Ypu can apply the STL algorithms and ranges algorithms on it

## Usage

### Initializing a BoxContainer
```cpp
BoxContainer container; // Initializes an empty BoxContainer
```

### Adding Elements
```cpp
container.addItem(42); // Adds the element 42 to the container
```

### Removing Elements
```cpp
container.removeItem(42); // Removes the first occurrence of the element 42
```

### Operating on Multiple Containers
```cpp
BoxContainer container1, container2;
....
....
container1 += container2; // Combines elements of container2 into container1
```

### Iterating Over Elements
```cpp
for (const auto& element : container) {
    // Process each element
}
```

### Swapping Containers
```cpp
BoxContainer container1, container2;
....
container1.swap(container2); // Swaps the contents of container1 and container2
```

<<<<<<< HEAD
With these enhancements, the BoxContainer class becomes even more powerful and easier to use in various applications.


## Example Usage
```cpp
// Create a BoxContainer object and add some elements
BoxContainer<int> container;
container.push_back(10);
container.push_back(20);
container.push_back(30);

// Iterate over the elements using a range-based for loop
for (const auto& element : container) {
    std::cout << element << " ";
}
// Output: 10 20 30

// Accessing elements using the subscript operator
std::cout << container[1];  // Output: 20

// Check if the container contains a specific element
bool containsTwenty = container.contains(20);  // true

// Concatenate two containers
BoxContainer<int> otherContainer;
otherContainer.push_back(40);
otherContainer.push_back(50);
BoxContainer<int> concatenated = container + otherContainer;

// Output the concatenated container
std::cout << concatenated;
// Output:
// BoxContainer:
// Size: 5, Capacity: 8
// Elements: 10 20 30 40 50
```
### You can find more in the main.cpp file

With these enhancements, the BoxContainer class becomes even more powerful and easier to use in various applications.

