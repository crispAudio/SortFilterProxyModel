cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_STANDARD 11)

project(SortFilterProxyModel)

find_package(Qt5 REQUIRED
    Core
    Qml
    )

option(BUILD_SORT_FILTER_PROXY_MODEL_AS_PLUGIN "Build a QML Plugin instead of a dynamic library" OFF)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON) # This is to find generated *.moc and *.h files in build dir

set(SOURCES qqmlsortfilterproxymodel.cpp
    filters/filter.cpp
    filters/filtercontainer.cpp
    filters/rolefilter.cpp
    filters/valuefilter.cpp
    filters/indexfilter.cpp
    filters/regexpfilter.cpp
    filters/rangefilter.cpp
    filters/expressionfilter.cpp
    filters/filtercontainerfilter.cpp
    filters/anyoffilter.cpp
    filters/alloffilter.cpp
    filters/filtersqmltypes.cpp
    sorters/sorter.cpp
    sorters/sortercontainer.cpp
    sorters/rolesorter.cpp
    sorters/stringsorter.cpp
    sorters/expressionsorter.cpp
    sorters/sortersqmltypes.cpp
    proxyroles/proxyrole.cpp
    proxyroles/proxyrolecontainer.cpp
    proxyroles/joinrole.cpp
    proxyroles/switchrole.cpp
    proxyroles/expressionrole.cpp
    proxyroles/proxyrolesqmltypes.cpp   
    proxyroles/singlerole.cpp   
    proxyroles/regexprole.cpp
    sorters/filtersorter.cpp
    proxyroles/filterrole.cpp
    )

set(ADDITIONAL_DEFINES "")

if(BUILD_AS_PLUGIN)
    add_library(${PROJECT_NAME}
                SHARED ${SOURCES} qqmlsortfilterproxymodel.cpp)

    target_compile_definitions(${PROJECT_NAME} PRIVATE "-DSORT_FILTER_PROXY_MODEL_LIBRARY_BUILD")
else(BUILD_AS_PLUGIN)
    add_library(${PROJECT_NAME} OBJECT ${SOURCES})
endif(BUILD_AS_PLUGIN)

#target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_LIST_DIR})
target_link_libraries(${PROJECT_NAME} PRIVATE Qt5::Core Qt5::Qml)

if(BUILD_AS_PLUGIN)
    install(${PROJECT_NAME} DESTINATION )
    install(FILES qmldir DESTINATION ${CMAKE_INSTALL_PREFIX}/)
endif(BUILD_AS_PLUGIN)
