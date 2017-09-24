cmake_minimum_required(VERSION 3.2)
project(ESPSsyncFlashWebServer)

include(CMakeListsPrivate.txt)

add_custom_target(
    PLATFORMIO_BUILD ALL
    COMMAND ${PLATFORMIO_CMD} -f -c clion run
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

add_custom_target(
    PLATFORMIO_UPLOAD ALL
    COMMAND ${PLATFORMIO_CMD} -f -c clion run --target upload
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

add_custom_target(
        PLATFORMIO_UPLOAD_HUZZAH ALL
        COMMAND ${PLATFORMIO_CMD} -f -c clion run --target upload --environment huzzah
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)
add_custom_target(
        PLATFORMIO_UPLOAD_NODEMCUV2 ALL
        COMMAND ${PLATFORMIO_CMD} -f -c clion run --target upload --environment nodemcuv2
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)
add_custom_target(
        PLATFORMIO_UPLOAD_ESP01 ALL
        COMMAND ${PLATFORMIO_CMD} -f -c clion run --target upload --environment esp01
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)
add_custom_target(
        PLATFORMIO_UPLOAD_ESP01_1M ALL
        COMMAND ${PLATFORMIO_CMD} -f -c clion run --target upload --environment esp01_1m
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

add_custom_target(
    PLATFORMIO_CLEAN ALL
    COMMAND ${PLATFORMIO_CMD} -f -c clion run --target clean
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

add_custom_target(
    PLATFORMIO_TEST ALL
    COMMAND ${PLATFORMIO_CMD} -f -c clion test
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

add_custom_target(
    PLATFORMIO_PROGRAM ALL
    COMMAND ${PLATFORMIO_CMD} -f -c clion run --target program
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

add_custom_target(
    PLATFORMIO_UPLOADFS ALL
    COMMAND ${PLATFORMIO_CMD} -f -c clion run --target uploadfs
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

add_custom_target(
        PLATFORMIO_UPLOADFS_HUZZAH ALL
        COMMAND ${PLATFORMIO_CMD} -f -c clion run --target uploadfs --environment huzzah
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)
add_custom_target(
        PLATFORMIO_UPLOADFS_NODEMCUV2 ALL
        COMMAND ${PLATFORMIO_CMD} -f -c clion run --target uploadfs --environment nodemcuv2
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)
add_custom_target(
        PLATFORMIO_UPLOADFS_ESP01 ALL
        COMMAND ${PLATFORMIO_CMD} -f -c clion run --target uploadfs --environment esp01
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)
add_custom_target(
        PLATFORMIO_UPLOADFS_ESP01_1M ALL
        COMMAND ${PLATFORMIO_CMD} -f -c clion run --target uploadfs --environment esp01_1m
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

add_custom_target(
    PLATFORMIO_UPDATE_ALL ALL
    COMMAND ${PLATFORMIO_CMD} -f -c clion update
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

add_custom_target(
    PLATFORMIO_REBUILD_PROJECT_INDEX ALL
    COMMAND ${PLATFORMIO_CMD} -f -c clion init --ide clion
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

add_executable(${PROJECT_NAME} ${SRC_LIST})
