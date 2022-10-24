# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Lab2Pysarenkov_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Lab2Pysarenkov_autogen.dir\\ParseCache.txt"
  "Lab2Pysarenkov_autogen"
  )
endif()
