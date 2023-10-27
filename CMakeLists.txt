cmake_minimum_required(VERSION 3.20)

project(GxAnyPluginExample)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (NOT BUILD_SHARED_LIBS)
    option(BUILD_SHARED_LIBS "build shared libs" ON)
endif ()

if (NOT CMAKE_SIZEOF_VOID_P)
    if (CMAKE_CL_64)
        set(CMAKE_SIZEOF_VOID_P 8)
    else ()
        set(CMAKE_SIZEOF_VOID_P 4)
    endif ()
endif ()

if (NOT CMAKE_BUILD_TYPE)
    message(WARNING "CMAKE_BUILD_TYPE must be a valid value")
    set(CMAKE_BUILD_TYPE Release)
endif ()

if (CMAKE_SYSTEM_NAME MATCHES "Linux")
    SET(CMAKE_CXX_FLAGS "-fPIC ${CMAKE_CXX_FLAGS}")
    SET(CMAKE_C_FLAGS "-fPIC ${CMAKE_C_FLAGS}")
endif ()

# Macos Intel M1 通用解决方案
if (CMAKE_SYSTEM_NAME MATCHES "Darwin")
    set(CMAKE_OSX_ARCHITECTURES "arm64;x86_64")
endif ()

if (MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /utf-8")

    if (BUILD_MODE_MT)
        add_compile_options(
                $<$<CONFIG:>:/MT>
                $<$<CONFIG:Debug>:/MTd>
                $<$<CONFIG:Release>:/MT>
        )
    else ()
        add_compile_options(
                $<$<CONFIG:>:/MD>
                $<$<CONFIG:Debug>:/MDd>
                $<$<CONFIG:Release>:/MD>
        )
    endif ()
endif ()


set(T_EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
set(T_LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${T_EXECUTABLE_OUTPUT_PATH})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${T_EXECUTABLE_OUTPUT_PATH})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELWITHDEBINFO ${T_EXECUTABLE_OUTPUT_PATH})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_MINSIZEREL ${T_EXECUTABLE_OUTPUT_PATH})

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${T_LIBRARY_OUTPUT_PATH})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${T_LIBRARY_OUTPUT_PATH})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELWITHDEBINFO ${T_LIBRARY_OUTPUT_PATH})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_MINSIZEREL ${T_LIBRARY_OUTPUT_PATH})

if (NOT WIN32)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${T_LIBRARY_OUTPUT_PATH})
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${T_LIBRARY_OUTPUT_PATH})
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELWITHDEBINFO ${T_LIBRARY_OUTPUT_PATH})
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_MINSIZEREL ${T_LIBRARY_OUTPUT_PATH})
endif ()

set(GX_LIBS_INSTALL_DIR ${CMAKE_BINARY_DIR}/dev)


include(cmake/GetGitDep.cmake)

GetGitDependency(git@github.com:giarld/GxAny.git ${CMAKE_CURRENT_SOURCE_DIR}/deps GxAny main)

add_subdirectory(deps/GxAny/gany-interface)
add_subdirectory(deps/GxAny/gany-core)


add_subdirectory(modules/test_plug)
add_subdirectory(main)
