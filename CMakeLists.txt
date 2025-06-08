cmake_minimum_required(VERSION 3.31)
project(Timber)

set(CMAKE_CXX_STANDARD 26)

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
if (WIN32)
    add_custom_command(
            TARGET Timber
            COMMENT "Copy OpenAL DLL"
            PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:Timber>
            VERBATIM)
endif ()