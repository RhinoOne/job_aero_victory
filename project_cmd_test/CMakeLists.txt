include(FetchContent)

FetchContent_Declare(
	googletest
	GIT_REPOSITORY https://github.com/google/googletest.git
	GIT_TAG v1.17.0
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

set(AggregatingPath ${PROJECT_SOURCE_DIR}/project_cmd)

set(SourceFiles main.cpp 
				aggregating_test.cpp
				${AggregatingPath}/aggregating.cpp)

set(HeaderFiles aggregating_test.hpp
				${AggregatingPath}/aggregating.hpp)

add_executable(project_cmd_test ${SourceFiles})
target_include_directories(project_cmd_test PRIVATE ${HeaderFiles})

target_include_directories(project_cmd_test PUBLIC ${AggregatingPath})

target_link_libraries(project_cmd_test gtest)
target_link_libraries(project_cmd_test gmock)

include(GoogleTest)

gtest_discover_tests(project_cmd_test)

if (CMAKE_VERSION VERSION_GREATER 3.20)
  set_property(TARGET project_cmd_test PROPERTY CXX_STANDARD 23)
endif()