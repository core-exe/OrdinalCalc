CMAKE_MINIMUM_REQUIRED(VERSION 3.2)
PROJECT(ordinal CXX)

IF(NOT CMAKE_BUILD_TYPE)
    SET(CMAKE_BUILD_TYPE Release)
ENDIF()

SET(ORDINAL_INCLUDES
        include/cnf.hpp
        include/integer.hpp
        include/ordinal.hpp
        )

SET(ORDINAL_SOURCES
        src/cnf.cpp
        src/integer.cpp
        src/ordinal.cpp
        )

SET(CMAKE_CXX_STANDARD 11)

ADD_LIBRARY(${PROJECT_NAME} STATIC ${ORDINAL_INCLUDES} ${ORDINAL_SOURCES})
TARGET_INCLUDE_DIRECTORIES(${PROJECT_NAME} PUBLIC include)
