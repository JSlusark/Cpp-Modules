cpp templates

**A template** in C++ is a recipe used for creating generic reusable code, they are type agnostic blueprints, meaning that they enable you to create functions and classes that can operate with any data type without being tied to a specific one.
They are compile-time code generators. Instead of writing overloads yourself, the compiler writes them for you.
This is particularly useful for creating algorithms and data structures that can work with different types of data.


---

### Why templates exist

Without templates, you repeat logic for each type:

```cpp
int max_int(int a, int b) { return a > b ? a : b; }
float max_float(float a, float b) { return a > b ? a : b; }
char max_char(char a, char b) { return a > b ? a : b; }

```

With a template:

```cpp
template <typename T> // tells the compiler " I'm defining the template. In this template, there is a placeholder called T that will be replaced with a real type when the function is used."
T max(T a, T b) // T: the placeholder return type. It means the function will return whatever type T is. Max: name of the function. (T a, T b): parameters of type T, meaning thta A and B will be of the same type T (T can be float, int, char, etc.)
{ return a > b ? a : b; }

```

Now the compiler generates `max<int>`, `max<float>`, `max<char>` automatically when you call it.
```int main() {
    std::cout << max(3, 7) << std::endl;        // T = int
    std::cout << max(2.5, 3.14) << std::endl;   // T = double
    std::cout << max("abc", "xyz") << std::endl; // T = const char*
    std::cout << max(3, 2.5) << std::endl;      // ERROR: T params have to have the same type, here one is int and one double?
}
```


---

### 1. Function templates

A **function template** describes a family of functions:

```cpp
template <typename T>
T min(T a, T b) {
    return a < b ? a : b;
}

int x = min(3, 7);       // compiler generates min<int>
double y = min(2.5, 1.5); // compiler generates min<double>

```
**Default template arguments**
You define a template with defaults:

```cpp
template <typename T = double> // default type is double and to trigger this you the template in this way identity<>(5), so the compiler will see 5 as a double, explicit instantiation
T identity(T x) { return x; } // whiel identity(5) will deduce T as int because 5 is an int, implicit instantiation
```
- `identity(5)` → deduces `int`, so result is `int`. Works only for function templates and not for class templates.
- `identity<>(5)` → uses default, result is `double`.
- `identity<>('a')` → uses default, result is `double` (char promoted to int, then converted to double).


- **Explicit instantiation**: `min<int>(a, b)`, needed when compiler can’t deduce T and you want a particular type.
	```
		min(3, 2.5);  // error: one int, one double
		min<int>(3, 2.5); // works, but 2.5 will be converted to int, causing ambiguities
	```
- **Implicit instantiation**: `min(a, b)` (compiler deduces `T`), used when compiler can deduce T directly from the arguments.
	```
		min(3, 7);        // both int → T = int
		min(2.5, 1.5);    // both double → T = double
		min('a', 'z');    // both char → T = char
	```

---

### 2. Class templates

A **class template** is a recipe for generating classes:

```cpp
template <typename T>
class Box {
    T value;
public:
    Box(T v) : value(v) {}
    T get() const { return value; }
};

Box<int> bi(42);      // compiler makes a Box<int>
Box<std::string> bs("hi"); // compiler makes a Box<std::string>

```

Think of it like: *“I want the same class, but with different types plugged in.”*

---

### 3. Default template arguments

You can give templates defaults:

```cpp
template <typename T = float>
class Vertex {
    T x, y, z;
public:
    Vertex(T a, T b, T c) : x(a), y(b), z(c) {}
};

Vertex<> v1(1, 2, 3);      // becomes Vertex<float>, because of default
Vertex<int> v2(1, 2, 3);   // explicitly Vertex<int>
Vertex v3(1,2,3);      // error: no default for class templates, implicit instantantion wont work here but i will work for function templates.

```

---

### 5. Specialization

Templates are generic, but sometimes you need a special case.

**Full specialization**: rewrite the template for exact types:

```cpp
template <typename T>
class Printer { public: void print(T v) { std::cout << v << "\n"; } };

template <>
class Printer<bool> { public: void print(bool v) { std::cout << (v ? "true" : "false") << "\n"; } };

```

**Partial specialization** (classes only): customize for a subset of cases:

```cpp
template <typename T, typename U>
class Pair { /* generic */ };

template <typename U>
class Pair<int, U> { /* special case when first type is int */ };

```

---

### 6. Key differences from macros

Macros just paste text → dangerous and error-prone.

Templates generate **real functions and classes**, so:

- type-safe
- only instantiated when used
- no duplicate side effects (`foo(x)` only called once)

---

### 7. Rules to remember

- A template by itself does not create code. Code is generated only when instantiated.
- Templates must be visible in every file that uses them → put definitions in headers (`.hpp` or `.tpp`).
- You can overload templates just like normal functions.
- Too much template use can confuse compilation errors, because messages get long.

___
Do you want me to make you a **step-by-step minimal cheatsheet** (with code) that covers: function templates, class templates, defaults, and specialization, all in ~1 page? That way you’ll have a compact reference for Module 07.
