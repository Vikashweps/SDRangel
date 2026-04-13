project(hello)

set(HELLO_SOURCES
    demodhello.cpp
)

set(HELLO_HEADERS
    demodhello.h
    
)
include_directories(
    ${CMAKE_SOURCE_DIR}/swagger/sdrangel/code/qt5/client
)


if(NOT SERVER_MODE)
    set(HELLO_SOURCES
        ${HELLO_SOURCES}
        # demodhellogui.cpp
        # demodhellogui.ui
    )
    set(HELLO_HEADERS
        ${HELLO_HEADERS}
        # demodhellogui.h
    )

    set(TARGET_NAME ${PLUGINS_PREFIX}hello)
    set(TARGET_LIB Qt::Widgets Qt::Quick Qt::QuickWidgets Qt::Positioning Qt::Charts)
    if(Qt${QT_DEFAULT_MAJOR_VERSION}Location_FOUND)
        list(APPEND TARGET_LIB Qt::Location)
    endif()
    if(Qt${QT_DEFAULT_MAJOR_VERSION}TextToSpeech_FOUND)
        list(APPEND TARGET_LIB Qt::TextToSpeech)
    endif()
    set(TARGET_LIB_GUI "sdrgui")
    set(INSTALL_FOLDER ${INSTALL_PLUGINS_DIR})
else()
    set(TARGET_NAME ${PLUGINSSRV_PREFIX}hellosrv)
    set(TARGET_LIB "")
    set(TARGET_LIB_GUI "")
    set(INSTALL_FOLDER ${INSTALL_PLUGINSSRV_DIR})
endif()

if(NOT Qt6_FOUND)
    add_library(${TARGET_NAME} ${HELLO_SOURCES})
else()
    qt_add_plugin(${TARGET_NAME} CLASS_NAME helloPlugin ${HELLO_SOURCES})
endif()

if(NOT BUILD_SHARED_LIBS)
    set_property(GLOBAL APPEND PROPERTY STATIC_PLUGINS_PROPERTY ${TARGET_NAME})
endif()

target_link_libraries(${TARGET_NAME} PRIVATE
    Qt::Core
    ${TARGET_LIB}
    sdrbase
    ${TARGET_LIB_GUI}
    swagger
)

install(TARGETS ${TARGET_NAME} DESTINATION ${INSTALL_FOLDER})
