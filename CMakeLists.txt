

cmake_minimum_required(VERSION 3.16)

include("$ENV{VITASDK}/share/vita.cmake")

project(VitaBrowser)

set(VITA_APP_NAME "Vita Browser")
set(VITA_TITLEID "VBRW00001")
set(VITA_VERSION "01.00")

add_executable(${PROJECT_NAME}
    src/main.c
)

target_link_libraries(${PROJECT_NAME}
    vita2d
    SceCtrl_stub
    SceDisplay_stub
    SceGxm_stub
    SceLibKernel_stub
)

vita_create_self(${PROJECT_NAME}.self ${PROJECT_NAME})

vita_create_vpk(${PROJECT_NAME}.vpk
    ${VITA_TITLEID}
    ${PROJECT_NAME}.self
    VERSION ${VITA_VERSION}
    NAME "${VITA_APP_NAME}"
)
