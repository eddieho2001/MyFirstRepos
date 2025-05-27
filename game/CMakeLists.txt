message(STATUS "game --> CMAKE_CURRENT_SOURCE_DIR : ${CMAKE_CURRENT_SOURCE_DIR}")
#3. build the executable target
add_executable(${LIGHTYEARS_GAME_EXE_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)

#Remark: because the linking of lib files to application belong here, so that copy them to here 
#4. After fetch lib we also  need to setup the linking 
target_link_libraries(${LIGHTYEARS_GAME_EXE_NAME} PUBLIC sfml-graphics)
target_link_libraries(${LIGHTYEARS_GAME_EXE_NAME} PUBLIC sfml-audio)
target_link_libraries(${LIGHTYEARS_GAME_EXE_NAME} PUBLIC sfml-main)
target_link_libraries(${LIGHTYEARS_GAME_EXE_NAME} PUBLIC sfml-network)
target_link_libraries(${LIGHTYEARS_GAME_EXE_NAME} PUBLIC sfml-system)
target_link_libraries(${LIGHTYEARS_GAME_EXE_NAME} PUBLIC sfml-window)

#5. we also need to add a copy of dll file to runtime directory for avoid manually copy referenced libraries
#add_custom_command(TARGET ${LIGHTYEARS_GAME_EXE_NAME} 
#	POST_BUILD
#	COMMAND
#	${CMAKE_COMMAND} -E copy_if_different
#	$<TARGET_FILE:sfml-window>
#	$<TARGET_FILE:sfml-graphics>
#	$<TARGET_FILE:sfml-audio>
#	$<TARGET_FILE:sfml-system>
#	$<TARGET_FILE:sfml-network>
#	$<TARGET_FILE_DIR:${LIGHTYEARS_GAME_EXE_NAME}>)

function(CopyLibToTarget LIB_NAME TARGET_NAME)
	add_custom_command(TARGET ${TARGET_NAME} 
	POST_BUILD
	COMMAND
	${CMAKE_COMMAND} -E copy_if_different
	$<TARGET_FILE:${LIB_NAME}>
	$<TARGET_FILE_DIR:${TARGET_NAME}>)
endfunction()

CopyLibToTarget(sfml-graphics ${LIGHTYEARS_GAME_EXE_NAME})
CopyLibToTarget(sfml-audio ${LIGHTYEARS_GAME_EXE_NAME})
CopyLibToTarget(sfml-network ${LIGHTYEARS_GAME_EXE_NAME})
CopyLibToTarget(sfml-system ${LIGHTYEARS_GAME_EXE_NAME})
CopyLibToTarget(sfml-window ${LIGHTYEARS_GAME_EXE_NAME})