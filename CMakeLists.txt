cmake_minimum_required(VERSION 3.13.4)

# project name
project( hex2asm )

# find all source files
aux_source_directory(. DIR)

# target for result
add_executable( hex2asm ${DIR} )

# add link library
target_link_libraries( hex2asm m )
