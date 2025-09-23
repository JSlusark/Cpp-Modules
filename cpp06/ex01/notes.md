EX01

This exercise is about understanding pointer casting and address round-tripping. We don’t serialize the struct contents yet, just the address.
The key takeaway is how to use reinterpret_cast safely and why uintptr_t exists for this purpose. In real serialization, we would walk through each field of the struct and store its values in a format like JSON or binary, so the data can be stored or transmitted.


### 🔹 What is serialization?
Serialization is the process of converting an object or data structure into a format that can be **stored or transmitted** and later reconstructed (deserialized) back into its original form.

In practice, this usually means turning complex in-memory objects into a **portable sequence of bytes** (binary, JSON, XML, etc.).

Typical use cases in C++ include:

- Saving objects to files or databases
- Sending objects over a network
- Inter-process communication
- Caching, logging, and debugging
- Remote procedure calls (RPC)
- Game state saving/loading
- Configuration management
- Undo/redo systems
- Object cloning and migration between app versions

### 🔹 Serialization vs. Deserialization

- **Serialization**: is the process of converting an object into  into a format that can be easily stored or transmitted.
- **Deserialization**: is the reverse process of converting the serialized data back into its original object or data structure.

Serialized forms might look like:

- **Binary:** `[00 00 00 2A] [05] [48 65 6C 6C 6F]`

    → id=42, length=5, string “Hello”

- **Text (JSON):** `{"id":42,"name":"Hello"}`

These can then be:

- Written to disk
- Sent over the network
- Stored in a database
- Reconstructed into a new `Data` objec

### 🔹 What this exercise actually does

In **EX01**, we are not serializing the *contents* of the struct.

Instead, we serialize the **pointer** (the memory address) of the struct into an integer type, and then deserialize it back:

- `serialize()` converts `Data*` → `uintptr_t`
- `deserialize()` converts `uintptr_t` → `Data*`

This demonstrates:

- A pointer is just an address, which can be represented as an integer.
- Using `reinterpret_cast` with the correct type (`uintptr_t`), you can safely round-trip:

    `pointer → integer → pointer`

- After deserialization, you still point to the *same* object in memory.

In the exercise we do not serialise the contents of the struct but the address of the struct in memory (tthe pointer to the struct).
This is a very simple form of serialization, but it is not portable or safe for long-term storage or transmission, as memory addresses can change between program executions and different systems.