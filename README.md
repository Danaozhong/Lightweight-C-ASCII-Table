# Lightweight ASCII Table

```bash
╔══════════════╦═══════╦═══════╗
║Name          ║Country║User ID║
╠══════════════╬═══════╬═══════╣
║Max Mustermann║GER    ║4124   ║
╠══════════════╬═══════╬═══════╣
║John Doe      ║USA    ║5240   ║
╚══════════════╩═══════╩═══════╝
```
This is a C library to generate ASCII tables.

## Why yet another ASCII Table Library?
I tried to use existing ASCII table libraries, but these didn't work for me on systems with very little RAM (e.g. IoT or low-powered microcontrollers), as none of the existing libraries are memory efficient. This library was written to support ASCII tables with minimum RAM usage.

## Design
Libtable is a lightweight C library to draw ASCII tables, especially designed for system with very litte RAM/flash. RAM usage is kept to an absolute minimum.
To further reduce memory footprint, the library supports printing out tables line by line, therefore allowing outputting large table without the need of buffering the entire formatted table in memory.

Only one table design is supported. The column width is automatically calculated based on the content size.
No dynamic memory allocations are used. All allocations are static, making this library therefore suitable for automotive / safety critical environments.

To be portable, it is a C library.

## How to Use this Library?

Have a look at the example below:
```cpp
// Initialize the table
tst_lib_table table;
i32_lib_table_initialize_table(&table);

// add header to the table
i32_lib_table_add_row(&table, 3, "Name", "Country", "User ID");

// add a few rows.
// this example just adds the same user 100 times
for (int i = 0; i < 100; ++i) {
    i32_lib_table_add_row(&table, 3, "John Doe", "USA", "1234");
}
  
// print it out using a 128-byte small buffer. Note that there is no
// need to allocate a large buffer for the entire table. Instead,
// the small 128 bytes are sufficient to print out the entire table.
char buffer[128];
int32_t i32_ret_val = 1;
uint32_t u32_offet = 0u;
while(1 == i32_ret_val) {
    // draw the current sub-part of the table...
    i32_ret_val = i32_lib_table_draw_table(&table, buffer, 128, u32_offet);
    
    // ...and push it out to stdout
    std::cout << buffer;

    // for the next run, push out the next 127 (or less) bytes.
    u32_offet += 127;
}
```

## Example Output

This is an example on how the table looks like when printed:
```bash
╔═════════╦═══════╦════╦═════╦═════════╦════╦═══════════════╗
║Module ID║Excp ID║Misc║Count║Timestamp║Line║File           ║
╠═════════╬═══════╬════╬═════╬═════════╬════╬═══════════════╣
║5        ║105    ║-22 ║1    ║0l       ║124 ║xcp_handler.cpp║
╠═════════╬═══════╬════╬═════╬═════════╬════╬═══════════════╣
║120      ║102    ║0   ║1    ║536890776║79  ║eol/src/eol.cpp║
╠═════════╬═══════╬════╬═════╬═════════╬════╬═══════════════╣
║120      ║204    ║0   ║1    ║134441564║110 ║application.cpp║
╠═════════╬═══════╬════╬═════╬═════════╬════╬═══════════════╣
║110      ║300    ║0   ║1    ║536889112║123 ║application.cpp║
╚═════════╩═══════╩════╩═════╩═════════╩════╩═══════════════╝
```

## How to Use This Library
The library is basicially just two files. Just include them in your project, or integrate the CMake file, such as:
```cmake
add_subdirectory(misc/libs/libtable)
target_link_libraries(${CMAKE_PROJECT_NAME} libtable)
```

The library is currently in a very early stage of development. There might be small issues left.

Feel free to use this library in any project of your choice. You can modify the code as you like, and use it in your projects (free / commercial), without having to mention me.
