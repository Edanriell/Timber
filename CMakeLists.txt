cmake_minimum_required(VERSION 3.31)
project(Timber)

set(CMAKE_CXX_STANDARD 23)

# Include FetchContent module
include(FetchContent)

# Fetch SFML
FetchContent_Declare(
        SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 3.0.1  # Use the latest stable version
)

# Make SFML available
FetchContent_MakeAvailable(SFML)

add_executable(Timber main.cpp)

# Link SFML libraries
target_link_libraries(Timber
        sfml-graphics
        sfml-window
        sfml-system
)

# Copy SFML DLLs to output directory on Windows
# On Windows, copy SFML DLLs after build (if they exist)
if (WIN32 AND BUILD_SHARED_LIBS)
    add_custom_command(TARGET Timber POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_FILE:sfml-graphics>
            $<TARGET_FILE:sfml-window>
            $<TARGET_FILE:sfml-system>
            $<TARGET_FILE_DIR:Timber>)
endif ()
