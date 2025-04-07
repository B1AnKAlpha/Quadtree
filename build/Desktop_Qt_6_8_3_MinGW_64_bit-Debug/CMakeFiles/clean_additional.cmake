# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\WidgetQuadtree_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\WidgetQuadtree_autogen.dir\\ParseCache.txt"
  "WidgetQuadtree_autogen"
  )
endif()
