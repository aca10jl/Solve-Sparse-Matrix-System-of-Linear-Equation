#
#

SET (CTEST_CUSTOM_MAXIMUM_NUMBER_OF_ERRORS   50)
SET (CTEST_CUSTOM_MAXIMUM_NUMBER_OF_WARNINGS 50)

SET(CTEST_CUSTOM_COVERAGE_EXCLUDE
 

 # Exclude try_compile sources from coverage results:
 "/CMakeFiles/CMakeTmp/"

 # Exclude files from the Testing directories
 ".*/Testing/.*"
 )

SET(CTEST_CUSTOM_WARNING_EXCEPTION
  
 )
