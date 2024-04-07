cmake_minimum_required (VERSION 3.8)

set(CMAKE_CXX_STANDARD_REQUIRED True)

# Включение горячей перезагрузки для компиляторов MSVC, если поддерживается.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project (game)
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY bin)
set (SOURCE_EXE src/main.cpp)
add_executable (game_race_rally ${SOURCE_EXE})
target_link_libraries (game_race_rally vehiclesDLL)
set_property(TARGET game_race_rally PROPERTY CXX_STANDARD 20)

target_compile_definitions (game_race_rally PUBLIC VEHICLE_EXPORTS)

add_subdirectory ("vehicles")
include_directories ("vehicles")

