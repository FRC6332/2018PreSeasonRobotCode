cmake_minimum_required(VERSION 3.3)
project(CAN Talon C++ Robot Code)
set(CMAKE_CXX_STANDARD 14)

file(GLOB_RECURSE SOURCES "src/cpp/*.*")
file(GLOB_RECURSE INCLUDES "src/cpp/*.*" "src/include/*.*")
include_directories(src/cpp)
include_directories(src/include)

file(GLOB_RECURSE DEP_INCLUDES "build/tmp/expandedArchives/athena-2017.2.1.zip_a1c5d1ac57fc30c16b208d97cd38f10b/include/*.*" "build/tmp/expandedArchives/hal-2017.2.1.zip_0441627de4b891b9388ff6a586d43a1c/include/*.*" "build/tmp/expandedArchives/NetworkTables-3.1.7-arm.zip_fd999d4916b982d23b33dfca07d4060c/include/*.*" "build/tmp/expandedArchives/wpiutil-1.0.2-arm.zip_4bf69224c3d16e318c368773c758e7ac/include/*.*" "build/tmp/expandedArchives/cscore-1.0.1-athena-uberzip.zip_826e8d013c0726864fffb07a1701beba/include/*.*" "build/tmp/expandedArchives/Toolsuite-Zip-4.4.1.14.zip_9182309d0eefdf76ea7e93f94022510f/cpp/include/*.*" "build/tmp/expandedArchives/Navx-Zip-3.0.323.zip_c0c6ad9663a15742234636572d09c7b4/roborio/cpp/include/*.*")
include_directories(build/tmp/expandedArchives/athena-2017.2.1.zip_a1c5d1ac57fc30c16b208d97cd38f10b/include)
include_directories(build/tmp/expandedArchives/hal-2017.2.1.zip_0441627de4b891b9388ff6a586d43a1c/include)
include_directories(build/tmp/expandedArchives/NetworkTables-3.1.7-arm.zip_fd999d4916b982d23b33dfca07d4060c/include)
include_directories(build/tmp/expandedArchives/wpiutil-1.0.2-arm.zip_4bf69224c3d16e318c368773c758e7ac/include)
include_directories(build/tmp/expandedArchives/cscore-1.0.1-athena-uberzip.zip_826e8d013c0726864fffb07a1701beba/include)
include_directories(build/tmp/expandedArchives/Toolsuite-Zip-4.4.1.14.zip_9182309d0eefdf76ea7e93f94022510f/cpp/include)
include_directories(build/tmp/expandedArchives/Navx-Zip-3.0.323.zip_c0c6ad9663a15742234636572d09c7b4/roborio/cpp/include)
set(ALL_INCLUDES ${INCLUDES} ${DEP_INCLUDES})

add_executable(fake_frcUserProgram ${SOURCES} ${ALL_INCLUDES})

add_custom_target(frcUserProgram_build ./gradlew build WORKING_DIRECTORY ../ SOURCES ${SOURCES} ${ALL_INCLUDES})
add_custom_target(frcUserProgram_deploy ./gradlew deploy WORKING_DIRECTORY ../ SOURCES ${SOURCES} ${ALL_INCLUDES})
