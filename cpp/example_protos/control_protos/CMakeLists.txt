set(PROTO_CMD ${CMAKE_SOURCE_DIR}/protoc/protoc)
set(PROTO_SRC ${PROJECT_SOURCE_DIR}/include/control_protos)
set(PROTO_RAW ${PROJECT_SOURCE_DIR}/control_protos/raw)
set(protocol_header_files "")
set(protocol_src_files "")

if (NOT EXISTS ${PROTO_SRC})
	file(MAKE_DIRECTORY ${PROTO_SRC})
endif()

message(STATUS "Building control protos.....")

file(GLOB_RECURSE proto_files ${PROTO_RAW}/*.proto)
foreach(msg ${proto_files})
	get_filename_component(FIL_WE ${msg} NAME_WE)

	list(APPEND protocol_header_files ${PROTO_SRC}/${FIL_WE}.pb.h)
	list(APPEND protocol_src_files ${PROTO_SRC}/${FIL_WE}.pb.cc)

	execute_process(
		COMMAND ${PROTO_CMD} --cpp_out ${PROTO_SRC} -I ${PROTO_RAW} ${msg}
		WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
		RESULT_VARIABLE result_value
	)

	if(NOT ${result_value} STREQUAL "0")
		message(FATAL_ERROR "Building control protos failed! ${PROTO_CMD}: ${result_value}")
	endif()
endforeach()

set_source_files_properties(${protocol_src_files} ${protocol_header_files} PROPERTIES GENERATED TRUE)



# install configuration
set(output_dirs ${MY_OUTPUT_ROOT})

if(${USE_WS_LIB})
	list(APPEND output_dirs ${BIGREPO_OUTPUT})
endif()

foreach( dir ${output_dirs})
	foreach(single_file ${protocol_header_files})
		get_filename_component(FIL_WE ${single_file} NAME_WE)
		string(CONCAT install_dir ${dir} "/include/config/")
#		message("${install_dir}")
		install(FILES ${single_file} DESTINATION ${install_dir})
	endforeach(single_file)
endforeach()
