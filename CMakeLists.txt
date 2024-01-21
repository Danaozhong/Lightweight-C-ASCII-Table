
cmake_minimum_required(VERSION 3.20)
project(
  libtable
  VERSION 0.1
  DESCRIPTION "A super lightweight library to draw ASCII tables"
  LANGUAGES CXX C)

add_subdirectory(libtable)
add_subdirectory(samples)

# Disable if testing is not intended
if (true)
  set(CMAKE_CXX_STANDARD 20)
  set(CMAKE_CXX_STANDARD_REQUIRED ON)

	include(CTest)

	include(FetchContent)
	FetchContent_Declare(
	  googletest
	  # Specify the commit you depend on and update it regularly.
	  URL https://github.com/google/googletest/archive/f8d7d77c06936315286eb55f8de22cd23c188571.zip
	)
	# For Windows: Prevent overriding the parent project's compiler/linker settings
	set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
	FetchContent_MakeAvailable(googletest)

	add_executable(libtable_test 
	  tests/test_libtable.cpp
	)

	target_link_libraries(libtable_test 
	PRIVATE 
	  libtable
	  GTest::gtest
	  GTest::gtest_main
	)

	include(GoogleTest)
	gtest_discover_tests(libtable_test)
endif()