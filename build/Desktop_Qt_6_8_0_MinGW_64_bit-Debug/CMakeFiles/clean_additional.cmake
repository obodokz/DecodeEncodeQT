# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\EncodeText_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\EncodeText_autogen.dir\\ParseCache.txt"
  "EncodeText_autogen"
  )
endif()
