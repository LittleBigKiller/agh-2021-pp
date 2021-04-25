cmake_minimum_required(VERSION 3.17)
project(agh_2021_pp C)

set(CMAKE_C_STANDARD 11)

#add_compile_options(-Wall)
add_compile_options(-Wall -Wextra -pedantic -Werror)

# 2021-03-05
#add_executable(2021-03-05_zad1 2021-03-05/zad1.c)
#add_executable(2021-03-05_zad2 2021-03-05/zad2.c)
#add_executable(2021-03-05_zad3 2021-03-05/zad3.c)
#add_executable(2021-03-05_zad4 2021-03-05/zad4.c)
#add_executable(2021-03-05_zad5 2021-03-05/zad5.c)
#add_executable(2021-03-05_zad6 2021-03-05/zad6.c)
#add_executable(2021-03-05_zad7 2021-03-05/zad7.c)
#add_executable(2021-03-05_zad8 2021-03-05/zad8.c)

# 2021-03-12
#add_executable(2021-03-12_zad1 2021-03-12/zad1.c)
#add_executable(2021-03-12_zad2 2021-03-12/zad2.c)
#add_executable(2021-03-12_zad3 2021-03-12/zad3.c)

# 2021-03-26
#add_executable(2021-03-26_zad1 2021-03-26/zad1.c)
#add_executable(2021-03-26_zad2 2021-03-26/zad2.c)
#add_executable(2021-03-26_zad3 2021-03-26/zad3.c)

# 2021-04-09
#add_executable(2021-04-09_zad1 2021-04-09/zad1.c)
#add_executable(2021-04-09_zad2 2021-04-09/zad2.c)
#add_executable(2021-04-09_zad3 2021-04-09/zad3.c)

# 2021-04-16
#add_executable(2021-04-16_zad1 2021-04-16/zad1.c)
#add_executable(2021-04-16_zad2 2021-04-16/zad2.c)

# 2021-04-23
add_executable(2021-04-23_zad1 2021-04-23/zad1.c)
add_executable(2021-04-23_zad2 2021-04-23/zad2.c)
add_executable(2021-04-23_zad3 2021-04-23/zad3.c)

# 2021-03-05
#target_include_directories(2021-03-05_zad1 PUBLIC "${PROJECT_BINARY_DIR}")
#target_include_directories(2021-03-05_zad2 PUBLIC "${PROJECT_BINARY_DIR}")
#target_include_directories(2021-03-05_zad3 PUBLIC "${PROJECT_BINARY_DIR}")
#target_include_directories(2021-03-05_zad4 PUBLIC "${PROJECT_BINARY_DIR}")
#target_include_directories(2021-03-05_zad5 PUBLIC "${PROJECT_BINARY_DIR}")
#target_include_directories(2021-03-05_zad6 PUBLIC "${PROJECT_BINARY_DIR}")
#target_include_directories(2021-03-05_zad7 PUBLIC "${PROJECT_BINARY_DIR}")
#target_include_directories(2021-03-05_zad8 PUBLIC "${PROJECT_BINARY_DIR}")

# 2021-03-12
#target_include_directories(2021-03-12_zad1 PUBLIC "${PROJECT_BINARY_DIR}")
#target_include_directories(2021-03-12_zad2 PUBLIC "${PROJECT_BINARY_DIR}")
#target_include_directories(2021-03-12_zad3 PUBLIC "${PROJECT_BINARY_DIR}")

# 2021-03-26
#target_include_directories(2021-03-26_zad1 PUBLIC "${PROJECT_BINARY_DIR}")
#target_include_directories(2021-03-26_zad2 PUBLIC "${PROJECT_BINARY_DIR}")
#target_include_directories(2021-03-26_zad3 PUBLIC "${PROJECT_BINARY_DIR}")

# 2021-04-09
#target_include_directories(2021-04-09_zad1 PUBLIC "${PROJECT_BINARY_DIR}")
#target_include_directories(2021-04-09_zad2 PUBLIC "${PROJECT_BINARY_DIR}")
#target_include_directories(2021-04-09_zad3 PUBLIC "${PROJECT_BINARY_DIR}")

# 2021-04-16
#target_include_directories(2021-04-16_zad1 PUBLIC "${PROJECT_BINARY_DIR}")
#target_include_directories(2021-04-16_zad2 PUBLIC "${PROJECT_BINARY_DIR}")

# 2021-04-23
target_include_directories(2021-04-23_zad1 PUBLIC "${PROJECT_BINARY_DIR}")
target_include_directories(2021-04-23_zad2 PUBLIC "${PROJECT_BINARY_DIR}")
target_include_directories(2021-04-23_zad3 PUBLIC "${PROJECT_BINARY_DIR}")