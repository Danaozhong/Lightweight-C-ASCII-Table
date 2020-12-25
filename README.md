# Lightweight ASCII Table

Libtable is a lightweight C library to draw ASCII tables, especially designed for system with very litte RAM/flash. RAM usage is kept to an absolute minimum.
To further reduce memory footprint, the library supports printing out data line by line, therefore allowing printing large tables via UART without the need of creating large buffers.
The key to reduce RAM footprint is to not buffer the entire table in RAM, but draw it and push it out line-by-line. It is therefore sufficient to allocate only one single line of the table!

Only one standard-design is supported. column width is automatically calculated based on the content size.
No dynamic memory allocations are used. All allocations are static, making this library therefore suitable for automotive / safety critical environments.

To be portable, it is a C library.

# How to use it?

Have a look at the example below:
```cpp
tst_lib_table table;
i32_lib_table_initialize_table(&table);

// add data to the table
i32_lib_table_add_row(&table, 7, "Module ID", "Excp ID", "Misc", "Count", "Timestamp", "Line", "File");
for (....)
{
    i32_lib_table_add_row(&table, 7, ac_module_id, ac_excp_id, ac_misc, ac_count, ac_timestamp, ac_line, itr->m_ai8_file);
}
  
// print it out using a 128-byte small buffer
char buffer[128];
int32_t i32_ret_val = 1;
uint32_t u32_offet = 0u;
while(1 == i32_ret_val)
{
    i32_ret_val = i32_lib_table_draw_table(&table, buffer, 128, u32_offet);
    u32_offet += 127;
    std::cout << buffer;
}
```

# How does it look like?


This is an example on how the table looks like when printed:
```cpp
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

# How to Integrate?
The library is basicially just two files. Just include them in your project, or integrate the CMake file, such as:
```cmake
add_subdirectory(misc/libs/libtable)
target_link_libraries(${CMAKE_PROJECT_NAME} libtable)
```

The library is currently in a very early stage of development. There might be small issues left.

Feel free to use this library in any project of your choice. You can modify the code as you like, and use it in your projects (free / commercial), without having to mention me.
