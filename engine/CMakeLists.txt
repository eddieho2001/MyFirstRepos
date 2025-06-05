message(STATUS "engine --> CMAKE_CURRENT_SOURCE_DIR : ${CMAKE_CURRENT_SOURCE_DIR}")
#3. build the executable target
add_library(${LIGHTYEARS_ENGINE_TARGET_NAME} STATIC 
	${CMAKE_CURRENT_SOURCE_DIR}/include/framework/application.h
	${CMAKE_CURRENT_SOURCE_DIR}/src/framework/application.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/EntryPoint.h
	${CMAKE_CURRENT_SOURCE_DIR}/src/EntryPoint.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/framework/core.h
	${CMAKE_CURRENT_SOURCE_DIR}/src/framework/core.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/framework/world.h
	${CMAKE_CURRENT_SOURCE_DIR}/src/framework/world.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/framework/actor.h
	${CMAKE_CURRENT_SOURCE_DIR}/src/framework/actor.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/include/framework/object.h
	${CMAKE_CURRENT_SOURCE_DIR}/src/framework/object.cpp


)

#7. start to add application logic to game, we need to tell cmake where to find the included header files by using target_include_directories command
target_include_directories(${LIGHTYEARS_ENGINE_TARGET_NAME}
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_include_directories(${LIGHTYEARS_ENGINE_TARGET_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/${QUILL_LIB_NAME}/include)

#Remark: because the linking of lib files to application belong here, so that copy them to here 
#4. After fetch lib we also  need to setup the linking 
target_link_libraries(${LIGHTYEARS_ENGINE_TARGET_NAME} PUBLIC sfml-graphics)
target_link_libraries(${LIGHTYEARS_ENGINE_TARGET_NAME} PUBLIC sfml-audio)
target_link_libraries(${LIGHTYEARS_ENGINE_TARGET_NAME} PUBLIC sfml-main)
target_link_libraries(${LIGHTYEARS_ENGINE_TARGET_NAME} PUBLIC sfml-network)
target_link_libraries(${LIGHTYEARS_ENGINE_TARGET_NAME} PUBLIC sfml-system)
target_link_libraries(${LIGHTYEARS_ENGINE_TARGET_NAME} PUBLIC sfml-window)
target_link_libraries(${LIGHTYEARS_ENGINE_TARGET_NAME} PUBLIC quill::quill)
#5. we also need to add a copy of dll files to runtime build directory for avoid manually copy referenced dll libraries
#add_custom_command(TARGET ${LIGHTYEARS_ENGINE_TARGET_NAME} 
#	POST_BUILD
#	COMMAND
#	${CMAKE_COMMAND} -E copy_if_different
#	$<TARGET_FILE:sfml-window>
#	$<TARGET_FILE:sfml-graphics>
#	$<TARGET_FILE:sfml-audio>
#	$<TARGET_FILE:sfml-system>
#	$<TARGET_FILE:sfml-network>
#	$<TARGET_FILE_DIR:${LIGHTYEARS_ENGINE_TARGET_NAME}>)

#and because there are more than one runtime dll file need to copy, we create a function to avoid code repeated 
function(CopyLibToTarget LIB_NAME TARGET_NAME)
	add_custom_command(TARGET ${TARGET_NAME} 
	POST_BUILD
	COMMAND
	${CMAKE_COMMAND} -E copy_if_different
	$<TARGET_FILE:${LIB_NAME}>
	$<TARGET_FILE_DIR:${TARGET_NAME}>)
endfunction()
#6.use the function to add required dll files
CopyLibToTarget(sfml-graphics ${LIGHTYEARS_ENGINE_TARGET_NAME})
CopyLibToTarget(sfml-audio ${LIGHTYEARS_ENGINE_TARGET_NAME})
CopyLibToTarget(sfml-network ${LIGHTYEARS_ENGINE_TARGET_NAME})
CopyLibToTarget(sfml-system ${LIGHTYEARS_ENGINE_TARGET_NAME})
CopyLibToTarget(sfml-window ${LIGHTYEARS_ENGINE_TARGET_NAME})

