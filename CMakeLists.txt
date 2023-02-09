cmake_minimum_required(VERSION 3.18)
project(CPP_Exercices)

add_subdirectory(extern/Catch2)
include(CTest)
include(Catch)

<<<<<<< HEAD
add_executable(test-00
    tests/test-00.cpp
)

set(all_tests ${all_tests} test-00)

set(plush_tests
    test-01
    test-02
    test-03
    test-04
    test-05
    test-06
    test-07
    test-08
    test-09
    test-10
    test-11
    test-12
    test-13
    test-14
)

foreach(this_test ${plush_tests})

    add_executable(${this_test}
        tests/${this_test}.cpp
        src/Plush.hpp
        src/PlushStore.hpp
        src/Kid.hpp
    )

    set(all_tests ${all_tests} ${this_test})

endforeach()

foreach(this_test ${all_tests})

    target_include_directories(${this_test} PRIVATE src/)
    target_link_libraries(${this_test} PRIVATE Catch2::Catch2WithMain)

    target_compile_features(${this_test} PRIVATE cxx_std_17)
    target_compile_options(${this_test} PRIVATE
=======
file(GLOB all_tests tests/Test-*.cpp)

foreach(test_file ${all_tests})

    get_filename_component(test_name ${test_file} NAME_WE)
    add_executable(${test_name}
        ${test_file}
        src/PC.cpp
        src/PC.h
        src/Pokeball.cpp
        src/Pokeball.h
        src/Pokedex.cpp
        src/Pokedex.h
        src/Pokemon.cpp
        src/Pokemon.h
        src/Trainer.cpp
        src/Trainer.h
    )

    target_include_directories(${test_name} PRIVATE src/)
    target_link_libraries(${test_name} PRIVATE Catch2::Catch2WithMain)

    target_compile_features(${test_name} PRIVATE cxx_std_17)
    target_compile_options(${test_name} PRIVATE
>>>>>>> ff47e74572b48bf2843cabd6f8b413a94188bd04
        -Wall
        -Wextra
        -Werror
        -Wno-uninitialized
    )

<<<<<<< HEAD
    add_custom_target(run-${this_test} COMMAND ./${this_test} DEPENDS ${this_test})
    catch_discover_tests(${this_test})
=======
    add_custom_target(run-${test_name} COMMAND ./${test_name} DEPENDS ${test_name})
    catch_discover_tests(${test_name})
>>>>>>> ff47e74572b48bf2843cabd6f8b413a94188bd04

endforeach()
