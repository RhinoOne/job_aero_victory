# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#

cmake_minimum_required (VERSION 3.9)

# Enable Testing
enable_testing()

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("project_cmd" VERSION 0.0.1)

# Include sub-projects.
add_subdirectory ("project_cmd")
add_subdirectory ("project_cmd_test")