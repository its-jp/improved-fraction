cmake_minimum_required(VERSION 3.15...4.0)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
project(
  improved-fraction
  VERSION 0.5
  DESCRIPTION "A improved fraction class from my class"
  LANGUAGES CXX)

# 1️⃣ Procura todos os arquivos .inl dentro da pasta src/lib (ajuste conforme
# seu projeto)
file(GLOB_RECURSE INL_FILES "${CMAKE_SOURCE_DIR}/lib/*.inl")

# 2️⃣ Cria uma biblioteca OBJECT dummy com todos os .inl encontrados
if(INL_FILES)
  add_library(inline_dummy OBJECT ${INL_FILES})
  set_target_properties(
    inline_dummy PROPERTIES EXCLUDE_FROM_ALL TRUE # não compila para o binário
                                                  # final
  )
endif()

add_library(fractionlib lib/fraction.cpp lib/fraction.hpp)
add_executable(fraction main.cpp lib/fraction.cpp)
