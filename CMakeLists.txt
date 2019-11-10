cmake_minimum_required(VERSION 3.10)

project(a-star)

set(SRCS
        "${CMAKE_CURRENT_SOURCE_DIR}/srcs/main.cpp"
)


add_executable(
        ${PROJECT_NAME}
        ${SRCS}
)


target_link_libraries(
        ${PROJECT_NAME}
        sfml-system
        sfml-graphics
        sfml-window
        pthread
        spdlog
)

