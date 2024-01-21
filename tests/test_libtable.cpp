
#include <iostream>

#include "gtest/gtest.h"

#include "libtable.h"

TEST(PrintTable, SimpleTest) {
  tst_lib_table table;
  EXPECT_EQ(0, i32_lib_table_initialize_table(&table));

  // Create a large table with dummy data
  i32_lib_table_add_row(&table, 3, "Name", "Address", "Age");
  for (int i = 0; i != 10; ++i) {
    i32_lib_table_add_row(&table, 3, "John Doe", "Schwanheim, Frankfurt, Germany", std::to_string(i + 30 % 70));
  }

  // simulate a situation with a very small output buffer.
  {
    const int buffer_size = 128;
    char buffer[128] = { 0 };
    int32_t i32_ret_val = 1;
    uint32_t u32_offet = 0u;
    while(1 == i32_ret_val)
    {
        i32_ret_val = i32_lib_table_draw_table(&table, buffer, buffer_size, u32_offet);
        u32_offet += sizeof(buffer);
        std::cout << buffer;
    }
  }

  // try the same using a larger buffer.
  {
    const int buffer_size = 1000;
    char buffer[1000] = { 0 };
    int32_t i32_ret_val = 1;
    uint32_t u32_offet = 0u;
    while(1 == i32_ret_val)
    {
        i32_ret_val = i32_lib_table_draw_table(&table, buffer, buffer_size, u32_offet);
        u32_offet += sizeof(buffer);
        std::cout << buffer;
    }
  }
}
