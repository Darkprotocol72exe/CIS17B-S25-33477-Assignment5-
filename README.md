1) Define a type-name helper

- Creates a typeName<T>() function that returns a human-readable name (“int,” “double,” or “string”) for those three types, falling back on the compiler’s name for anything else.

2) Implement a generic Package

- Package<T> holds one item of type T.

- Its label() prints “Generic package containing: X,” where X is the readable name of T.

3) Specialize Package for strings

- Package<string> overrides label() to print “Book package: X,” where X is the actual string value.

4) Partially specialize Package for pointers

- Package<T*> marks the contents as fragile, printing “Fragile package for pointer to type: X,” with X the pointed-to type’s name.

5) Create a fixed-size Box

- Box<T,Size> uses an array<T,Size> to store up to Size items.

- addItem() adds one item until the box is full, otherwise reports an error.

- printItems() lists all stored items.

6) Define a shipping function template

- shipItem<T>() prints “Shipping item of type: X.”

- A special version for double prints “Shipping temperature-controlled item: Y°F,” where Y is the double value.

7) Demonstrate in main()

- Packages an int, a string, and a double*, calling each label().

- Fills a Box<string,3> with three titles and prints its contents.

- Calls shipItem() on an int, a string, and a double to show both generic and specialized behavior.