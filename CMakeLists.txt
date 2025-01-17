cmake_minimum_required(VERSION 3.0)
project(puzzles)

file(GLOB_RECURSE sources  *.cpp *.h)
file(GLOB_RECURSE tests    *-test.cpp)
list(REMOVE_ITEM sources ${tests})

###############################################################################
## target definitions #########################################################
###############################################################################

add_executable(puzzles ${sources})

# Just for example add some compiler flags.
target_compile_options(puzzles PUBLIC -std=c++1y -Wall -Wfloat-conversion)

# This allows to include files relative to the root of the src directory with a <> pair
target_include_directories(puzzles PUBLIC src/)

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

# This is for our testing framework,
# we don't add REQUIRED because it's just for testing.
# People who might want to build the project to use it should not be required
# to install testing dependencies.
find_package(GTest)

if(GTEST_FOUND)
  add_executable(unit_tests ${test} ${sources})

  # This define is added to prevent collision with the main.
  # It might be better solved by not adding the source with the main to the
  # testing target.
  target_compile_definitions(unit_tests PUBLIC UNIT_TESTS)

  # This allows us to use the executable as a link library, and inherit all
  # linker options and library dependencies from it, by simply adding it as dependency.
  set_target_properties(puzzles PROPERTIES ENABLE_EXPORTS on)

  target_link_libraries(unit_tests PUBLIC
    ${GTEST_BOTH_LIBRARIES}
    puzzles
  )

  target_include_directories(unit_tests PUBLIC
    ${GTEST_INCLUDE_DIRS}
  )

endif()
