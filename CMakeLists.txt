cmake_minimum_required(VERSION 3.10)
project(CGame VERSION 1.0)

# Especifica el estándar de C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Establece la ruta de SFML usando una variable de entorno
if(DEFINED ENV{SFML_ROOT})
    set(SFML_DIR $ENV{SFML_ROOT})
else()
    set(SFML_DIR "/home/thiago/Escritorio/Cods/SFML")
endif()

set(SFML_INCLUDE_DIR "${SFML_DIR}/include")
set(SFML_LIBRARY_DIR "${SFML_DIR}/lib")

# Verifica que los directorios necesarios existan
if(NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/src)
    file(MAKE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/src)
endif()

if(NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/include)
    file(MAKE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include)
endif()

# Mueve main.cpp a src si existe en el directorio raíz
if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)
    file(RENAME 
        ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp 
        ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
    )
endif()

# Recoge todos los archivos fuente
file(GLOB_RECURSE SOURCES "src/*.cpp")
file(GLOB_RECURSE HEADERS "include/*.hpp")

# Verifica que haya al menos un archivo fuente
if(NOT SOURCES)
    message(FATAL_ERROR "No source files found in src directory!")
endif()

# Agrega el directorio de include de SFML
include_directories(${SFML_INCLUDE_DIR})
link_directories(${SFML_LIBRARY_DIR})

# Crea el ejecutable
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

# Incluye los directorios de cabecera
target_include_directories(${PROJECT_NAME} PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${SFML_INCLUDE_DIR}
)

# Enlaza con SFML
target_link_libraries(${PROJECT_NAME} PRIVATE 
    sfml-graphics 
    sfml-window
    sfml-system  
)

# Establece el directorio de salida
set_target_properties(${PROJECT_NAME}
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)