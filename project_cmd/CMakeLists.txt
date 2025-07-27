set(SourceFiles main.cpp 
				aggregating.cpp )

set(HeaderFiles aggregating.hpp)

add_executable (project_cmd ${SourceFiles})	

target_include_directories(project_cmd PRIVATE ${HeaderFiles})

