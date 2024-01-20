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
- Smart pointers and Operator Overloading

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

### Adding Elements
```cpp
container.addItem(42); // Adds the element 42 to the container
```

### Adding Elements
```cpp
container.addItem(42); // Adds the element 42 to the container
```