cmake_minimum_required(VERSION 3.10)

project(BattleCity)

file(GLOB_RECURSE BattleCity_SOURCES CONFIGURE_DEPENDS "src/*.cpp")
file(GLOB_RECURSE BattleCity_HEADERS CONFIGURE_DEPENDS "src/*.h")

set(BattleCity_INCLUDE_DIRS "")
foreach (_headerFile ${BattleCity_HEADERS})
	get_filename_component(_dir ${_headerFile} PATH)
	list (APPEND BattleCity_INCLUDE_DIRS ${_dir})
endforeach()
list(REMOVE_DUPLICATES BattleCity_INCLUDE_DIRS)

add_executable(BattleCity ${BattleCity_SOURCES})
target_include_directories(BattleCity PRIVATE ${BattleCity_INCLUDE_DIRS})
#add_executable(BattleCity src/main.cpp)

#Adding SFML
set(SFML_DIR "../vendor/SFML-2.5.1/lib/cmake/SFML")
find_package(SFML 2.5.1 COMPONENTS graphics window audio system REQUIRED)
target_link_libraries(BattleCity sfml-graphics sfml-window sfml-audio sfml-system)

#Adding JsonCpp
target_include_directories(BattleCity PUBLIC "../vendor/jsoncpp/include")

#Specifying C++ Standart
set(CMAKE_CXX_STANDART 17)
set(CMAKE_CXX_STANDART_REQUIRED True)
target_compile_features(BattleCity PRIVATE cxx_std_17)