cmake_minimum_required(VERSION 3.25)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
project(puzzles)

file(GLOB_RECURSE sources  src/*.cpp src/*.h)
file(GLOB_RECURSE tests    src/*-test.cpp)
list(REMOVE_ITEM sources ${tests})

include(CMakePrintHelpers)
cmake_print_variables(sources)
cmake_print_variables(tests)

###############################################################################
## target definitions #########################################################
###############################################################################

# add_executable(puzzles ${sources})

# Just for example add some compiler flags.
# target_compile_options(puzzles PUBLIC -std=c++1y -Wall -Wfloat-conversion)

# This allows to include files relative to the root of the src directory with a <> pair
# target_include_directories(puzzles PUBLIC src/)

###############################################################################
## dependencies ###############################################################
###############################################################################

# find_package(Boost 1.36.0 COMPONENTS filesystem system REQUIRED)

# target_link_libraries(example PUBLIC
#  ${Boost_LIBRARIES}
  # here you can add any library dependencies
# )

###############################################################################
## testing ####################################################################
###############################################################################


include(CTest)

enable_testing()

find_package(GTest REQUIRED CONFIG)
find_package(GMock)

include(GoogleTest)

add_executable(unit_tests ${tests} ${sources})

# This define is added to prevent collision with the main.
# It might be better solved by not adding the source with the main to the
# testing target.
target_compile_definitions(unit_tests PUBLIC UNIT_TESTS)

# This allows us to use the executable as a link library, and inherit all
# linker options and library dependencies from it, by simply adding it as dependency.
# set_target_properties(puzzles PROPERTIES ENABLE_EXPORTS on)

target_link_libraries(unit_tests PUBLIC
  ${GTEST_BOTH_LIBRARIES}
  ${GMOCK_LIBRARIES}
  # puzzles
)

target_include_directories(unit_tests PUBLIC
  ${GTEST_INCLUDE_DIRS}
  ${GMOCK_INCLUDE_DIRS}
)

gtest_discover_tests(unit_tests)
