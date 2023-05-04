#include <iostream>
#include <string>

#include "libtable.h"

auto main() -> int {    
    // Initialize the empty table
    tst_lib_table table;
    i32_lib_table_initialize_table(&table);

    // add header to the table
    i32_lib_table_add_row(&table, 3, "Name", "Country", "User ID");

    // add a few rows.
    // this example just adds the same user 100 times
    for (int i = 0; i < 50; ++i) {
        i32_lib_table_add_row(&table, 3, "John Doe", "USA", std::to_string(i).c_str());
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
    return 0;
}