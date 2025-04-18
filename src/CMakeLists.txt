# basic build target for libcnano
#
# (c) 2025 by Matthias Arndt <marndt@final-memory.org>
#
# The MIT License applies. See COPYING for details.
#
# Check if the PROJECT_NAME variable is defined
if(NOT DEFINED PROJECT_NAME)
    project(libcnano)
endif()


include_directories(${CMAKE_CURRENT_LIST_DIR})

add_library(cnano
	libcnano.h
	MemCpy32.c
	StrCmp.c
	StrCpy.c
	StrLeft.c
	StrLen.c
	StrTrim.c
)
