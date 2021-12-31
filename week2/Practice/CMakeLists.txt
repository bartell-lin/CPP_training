cmake_minimum_required(VERSION 3.14)
project(my_project)

# GoogleTest requires at least C++11
set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)


enable_testing()

add_library(BigNumber BigNumber.cpp)
add_library(Calandar Calandar.cpp)

add_executable(
  hello_test
  test.cpp
  BigNumber
  BigNumber.cpp
  Calandar
  Calandar.cpp
  "${PROJECT_BINARY_DIR}"
  "${PROJECT_SOURCE_DIR}/BigNumber"
  "${PROJECT_SOURCE_DIR}/Calandar"
)
target_link_libraries(
  hello_test
  BigNumber
  Calandar
  gtest_main
)

include(GoogleTest)
gtest_discover_tests(hello_test)