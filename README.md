# Practice_Projects


05/03/17
 - !! there's still issue in cmake. libgtest_main.a is not build. WA - delete lines after add_subdirectory(${GTEST_DIR})
 - mkdir build
 - cd build
 if fresh pulled:
	- do WA!!
	- cmake ..
	- remove WA!!
	- cmake ..
 else
	- cmake ..
 - make

05/07/17
(A)
 - CMake fully functional with GTest
	- add_dependencies() was used to resolve issue above
 	- some cmake macros accepts what was the name in add_library and add_executable. This is true for target_link_libraries()
	- issue encountered in linking with `undefined reference` was because of use of file() assigned the google test libraries. This was fixed by using method above
 - NEXT:
	- create multiple classes and create separate unit test for them. This is per class file UT
	- Also add in ctest() option with <ClassName>Test as their name

(B)
 - Added cmake options for building UT and src
 - Created another Class Palindrome with separate test executable
 - Set cmake to use C++11 to support new Palindrome class
	-Following approach did not work:
		- set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
		- add_definitions("-std=c++11")
 - NEXT:
	- Complete test for Palindrome class
	- Create Class that employ OOP and create UT + Mocks(new)
