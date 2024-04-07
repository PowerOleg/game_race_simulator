cmake_minimum_required (VERSION 3.8)

project ("vehicles")
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin)
set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY library)
set (SOURCE_DLL Ground_based_vehicle.cpp Air_vehicle.cpp Camel.cpp Centaur.cpp Eagle.cpp Fast_moving_camel.cpp)
add_library (vehiclesDLL SHARED ${SOURCE_DLL})