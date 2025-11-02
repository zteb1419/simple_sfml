cmake_minimum_required(VERSION 3.28)
project(CMakeSFMLProject LANGUAGES CXX)


include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.2
    GIT_SHALLOW OFF)
FetchContent_MakeAvailable(SFML)

add_executable(main main.cpp Player.cpp Ball.cpp)
target_compile_features(main PRIVATE cxx_std_11)
target_link_libraries(main PRIVATE SFML::Graphics SFML::Audio)

add_custom_target(copy_resources ALL
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    ${PROJECT_SOURCE_DIR}/pong.wav
    ${PROJECT_BINARY_DIR}/pong.wav

    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    ${PROJECT_SOURCE_DIR}/gamemusic.mp3
    ${PROJECT_BINARY_DIR}/gamemusic.mp3

    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    ${PROJECT_SOURCE_DIR}/SupremeSpike-KVO8D.otf
    ${PROJECT_BINARY_DIR}/SupremeSpike-KVO8D.otf
)
add_dependencies(main copy_resources)