target_sources(
    spore
    PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/spore.h
)

add_subdirectory(container)
add_subdirectory(core)