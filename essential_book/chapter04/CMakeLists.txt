cmake_minimum_required ( VERSION 3.15.0 )

project ( multifiles CXX )

set ( PRJ_SRC_LIST )
set ( PRJ_HEADER_LIST )
set ( PRJ_LIBRARIES )
set ( PRJ_INCLUDE_DIRS )

file ( GLOB root_header_files "${CMAKE_CURRENT_SOURCE_DIR}/*.hpp" )
file ( GLOB root_src_files "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp" )
message ( STATUS "root_header_files =  ${root_header_files}")
message ( STATUS "root_src_files =  ${root_src_files}")

list ( APPEND PRJ_HEADER_LIST ${root_header_files} )
list ( APPEND PRJ_SRC_LIST ${root_src_files} )

add_executable ( ${PROJECT_NAME} ${PRJ_SRC_LIST} ${PRJ_HEADER_LIST} )

target_include_directories ( ${PROJECT_NAME}
	PRIVATE
		${PRJ_INCLUDE_DIRS}
)

target_compile_features ( ${PROJECT_NAME} 
	PUBLIC 
		cxx_std_17
)


target_link_libraries ( ${PROJECT_NAME} 
    PRIVATE 
        ${PRJ_LIBRARIES}
)