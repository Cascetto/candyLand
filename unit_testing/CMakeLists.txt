project(test)

add_subdirectory(gtest_src)

set(TEST_SRC_DIRECTOY gtest_src/googletest)


include_directories(${TEST_SRC_DIRECTORY}/include ${TEST_SRC_DIRECTORY})

set(TEST_FILES ../GameLogic/GameEngine.cpp)

add_executable(test ${TEST_FILES})

target_link_libraries(test gtest gtest_main)