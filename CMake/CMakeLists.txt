CMake_Minimum_Required ( VERSION 2.8 )
Project ( PhatChat )

Add_Definitions ( -std=c++0x )

Include_Directories ( "${CMAKE_CURRENT_LIST_DIR}/../Source" "${CMAKE_CURRENT_LIST_DIR}/../Dependencies/Include" )
Link_Directories ( "${CMAKE_CURRENT_LIST_DIR}/../Dependencies/Libraries" )

File ( GLOB CORE_SOURCE "${CMAKE_CURRENT_LIST_DIR}/../Source/PhatChat/Core/*" )
File ( GLOB SERVER_SOURCE "${CMAKE_CURRENT_LIST_DIR}/../Source/PhatChat/Server/*" )
File ( GLOB CLIENT_SOURCE "${CMAKE_CURRENT_LIST_DIR}/../Source/PhatChat/Client/*" )

Add_Library ( Core ${CORE_SOURCE} )
Target_Link_Libraries ( Core sfml-network )

Add_Executable ( Server ${SERVER_SOURCE} )
Target_Link_Libraries ( Server Core sfml-system sfml-network )

Add_Executable ( Client ${CLIENT_SOURCE} )
Target_Link_Libraries ( Client Core sfml-system sfml-network fltk )
