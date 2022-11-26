# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/adarw/esp/esp-idf/components/bootloader/subproject"
  "/media/adarw/Data/Documents/Programing/cpp/robot/esp/espCodeIdf/espcode/espCode/espCode/build/bootloader"
  "/media/adarw/Data/Documents/Programing/cpp/robot/esp/espCodeIdf/espcode/espCode/espCode/build/bootloader-prefix"
  "/media/adarw/Data/Documents/Programing/cpp/robot/esp/espCodeIdf/espcode/espCode/espCode/build/bootloader-prefix/tmp"
  "/media/adarw/Data/Documents/Programing/cpp/robot/esp/espCodeIdf/espcode/espCode/espCode/build/bootloader-prefix/src/bootloader-stamp"
  "/media/adarw/Data/Documents/Programing/cpp/robot/esp/espCodeIdf/espcode/espCode/espCode/build/bootloader-prefix/src"
  "/media/adarw/Data/Documents/Programing/cpp/robot/esp/espCodeIdf/espcode/espCode/espCode/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/media/adarw/Data/Documents/Programing/cpp/robot/esp/espCodeIdf/espcode/espCode/espCode/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
