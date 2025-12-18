cmake_minimum_required( VERSION 3.16 )
project( add42 )

# bibliothèque
add_library( mymaths src/mymaths.cpp )
target_include_directories( mymaths  PUBLIC include )

# exécutable
find_package(Drogon CONFIG REQUIRED)
set(CMAKE_CXX_STANDARD 20)
add_executable( add42.out app/main.cpp )
target_link_libraries( add42.out PRIVATE mymaths Drogon::Drogon )
install( TARGETS add42.out DESTINATION bin )

# tests
find_package( Catch2 REQUIRED )
add_executable( test.out test/mymaths-test.cpp )
target_link_libraries( test.out PRIVATE mymaths Catch2::Catch2WithMain )
enable_testing()
add_test( NAME test COMMAND test.out )

