if(EXISTS "/home/thatdaleguy03/projects/homework/c455/homework4/cmake-build-debug/test/unit_tests[1]_tests.cmake")
  include("/home/thatdaleguy03/projects/homework/c455/homework4/cmake-build-debug/test/unit_tests[1]_tests.cmake")
else()
  add_test(unit_tests_NOT_BUILT unit_tests_NOT_BUILT)
endif()
