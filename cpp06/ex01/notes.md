EX01
Serialization is the process of converting an object or data into a format that can be stored or transferred and then reconstructed (deserialized) back into the original form.


serialization is about turning complex in-memory objects into a portable sequence of bytes (binary, JSON, XML, etc.).

In C++, serialization is often used for:
- Saving objects to files or databases
- Sending objects over a network
- Inter-process communication
- Caching objects in memory
- Deep copying objects
- Logging and debugging
- Remote procedure calls (RPC)
- Game state saving and loading
- Configuration management
- Data interchange between different systems or programming languages
- Persisting application state
- Object cloning
- Data migration between different versions of an application
- Testing and mocking objects
- Implementing undo/redo functionality
- Data compression and encryption

difference between serialization and deserialization:
- Serialization is the process of converting an object or data structure into a format that can be easily stored or transmitted.
- Deserialization is the reverse process of converting the serialized data back into its original object or data structure.

in the exercise we do not serialise the contents of the struct but the address of the struct in memory (tthe pointer to the struct).
This is a very simple form of serialization, but it is not portable or safe for long-term storage or transmission, as memory addresses can change between program executions and different systems.