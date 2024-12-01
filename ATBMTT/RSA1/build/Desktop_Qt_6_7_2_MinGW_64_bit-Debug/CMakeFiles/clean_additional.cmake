# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\RSA1_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\RSA1_autogen.dir\\ParseCache.txt"
  "RSA1_autogen"
  )
endif()
