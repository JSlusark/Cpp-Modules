EX00

This project is about understanindg how to explicitly control narrowing/widening conversions, instead of letting the compiler do it implicitly.
We need to convert a string literal to char, int, float and double and before doing that we need to identify first the original type of the literal (char, int, float or double or pseudo).

## Casting
Casting in C and C++ is the way to convert one type to another.
A cast is a **conversion**, which interprets the bits of one type as another type or changes how a value is represented.
C++ provides many types:
- **Primitive types**: `int`, `char`, `float`, `double`, etc.
- **User-defined types**: `class`, `struct`, `enum`
- **Pointers and references**

Each type has its own size and representation in memory.
- Casting does **not depend only on size**. Even if two types use the same number of bits, their representation can differ and information may be lost.
    - Example: `int` (32-bit) to `float` (32-bit) may lose precision because `float` only stores about 24 bits of integer accuracy.
- When converting to a type with smaller range or precision, information may be truncated.
    - Example: `double → float`, `float → int`, `int → char`.
- When converting to a larger type, the value is preserved (promotion).
    - Example: `char → int`, `int → double`.

### Type sizes
The C++ standard only defines **minimum sizes**:
- `char`: 8 bits
- `short`: ≥16 bits
- `int`: ≥16 bits
- `long`: ≥32 bits
- `long long`: ≥64 bits

Typical sizes on modern 64-bit systems (LP64 model, used on Linux/macOS):
- `bool`: 1 byte (not 4 bits)
- `char`, `signed char`, `unsigned char`: 8 bits
- `short`: 16 bits
- `int`: 32 bits
- `float`: 32 bits
- `long`: 64 bits
- `double`: 64 bits
- `long double`: 80 or 128 bits (platform dependent)

- **C-style casts**: `(int)3.14` are explicit but unsafe, because the compiler cannot check semantics.
- **C++ style casts**: `static_cast<int>(3.14)` are safer and clearer because each cast operator has a specific meaning.

### Implicit vs Explicit casts

- **Implicit cast**: Performed automatically by the compiler when needed.
	- Safe and follow semantic rules
	- Easier to read and write
	- Usually promotions (e.g. `int → double`).
- **Explicit cast**: Written by the programmer using cast operators(e.g. static_cast<int>(3.14)).
	- Provides more control and clarity about the intended conversion
	- May lead to undefined behavior if not used carefully (e.g. converting a large double to int may result in overflow).
	- Usually for demotions or when clarity is important.

### Promotions vs Demotions
- **Promotion**: Conversion to a *larger or more precise* type (e.g. `int → double`, `char → int`). Safe, no information lost. Often implicit.
		Promotions are typically **implicit**, but in this project I must use explicit casts to demonstrate control.
- **Demotion**: Conversion to a *smaller or less precise* type (e.g. `double → int`, `float → char`). May lose data through truncation, rounding, or overflow. Requires explicit cast.


### Cast operators in C++

C++ defines four explicit cast operators:
- `static_cast`:
Most common cast: used for converting between related types, such as from int to float, or from a base class pointer to a derived class pointer. It performs compile-time type checking and is generally safe for value conversions (e.g. `int → float`, `double → int`). Required for ex00.
- `dynamic_cast`:
Used only in polymorphic class hierarchies: it performs runtime type checks,  If the conversion is not possible, it returns a null pointer (for pointers) or throws an exception (for references).
- `const_cast`:
Used to add or remove `const` qualifiers. Rarely needed: it is typically used when you need to modify a variable that was originally declared as const. However, modifying a const variable through a const_cast results in undefined behavior.
- `reinterpret_cast`
Used for low-level reinterpretation of bit patterns. It allows you to convert any pointer type to any other pointer type, even if the types are unrelated. It is often used for system-level programming or when dealing with raw memory. However, it should be used with caution, as it can lead to undefined behavior if the types are not compatible.


## **Rule for ex00**

In this project we will be using `static_cast` for all conversions because we are dealing with value conversions (int → float, char → int, etc.)
Why is the most common and safest cast operator for value conversions? Because:	it is checked at compile time and ensures conversions stay within semantic rules.

### Notes

- Detect the input literal type (char, int, float, double, pseudo).
- Convert it explicitly to all four output types.
- Use `static_cast` for all conversions.
- Handle impossible conversions and non-displayable characters with clear error messages.
- Remember that demotions may truncate, overflow, or round, and must always be explicit.


### Pseudo-literals (nan, nanf, +inf, -inf)
Floating-point pseudo-literals are special IEEE-754 values recognized in C++:
- `nan` / `nanf`: *Not a Number*. Result of undefined operations such as `0.0/0.0`.
    - `nan`: double literal
    - `nanf`: float literal
- `inf` / `inff`: Positive infinity. Result of overflow or division by zero such as `1.0/0.0`.
    - `inf`: double literal
    - `inff`: float literal
- `inf` / `inff`: Negative infinity. Same rules, but negative.
    - `inf`: double literal
    - `inff`: float literal
**Conversions**:
- To `float`/`double`: stay as special values.
- To `char`/`int`: undefined behavior by the C++ standard. Compilers may produce sentinel values, but this is not portable. For this project, output `"impossible"` for these cases.

Converting to intergral types give undefined behaviour(return 0x80000000 for int, and 0 for char, but it is not portable), while converting to floating-point types give the same pseudo-literal.
Your parser must recognize them and handle them as exceptions where char and int conversions are impossible.


errno = 0 case example
./ScalarConverter 999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999 4