CMake_Minimum_Required ( VERSION 2.8 )
Project ( APP_NAME )

Add_Definitions ( -std=c++0x )

Include_Directories ( "${CMAKE_CURRENT_LIST_DIR}/../Dependencies/Include" )
Link_Directories ( "${CMAKE_CURRENT_LIST_DIR}/../Dependencies/Libraries" )

File ( GLOB CORE_SOURCE "${CMAKE_CURRENT_LIST_DIR}/../Source/Core/*" )
File ( GLOB SERVER_SOURCE "${CMAKE_CURRENT_LIST_DIR}/../Source/Server/*" )
File ( GLOB CLIENT_SOURCE "${CMAKE_CURRENT_LIST_DIR}/../Source/Client/*" )

Add_Library ( Core ${CORE_SOURCE} )

Add_Executable ( Client ${CLIENT_SOURCE} )
Target_Link_Libraries ( Client Core )

Add_Executable ( Server ${SERVER_SOURCE} )
Target_Link_Libraries ( Server Core )
