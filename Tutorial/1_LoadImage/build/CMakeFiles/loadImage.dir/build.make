# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/g/src/opencv_project/OpenCV_Tutorial/1_LoadImage

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/g/src/opencv_project/OpenCV_Tutorial/1_LoadImage/build

# Include any dependencies generated for this target.
include CMakeFiles/loadImage.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/loadImage.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/loadImage.dir/flags.make

CMakeFiles/loadImage.dir/loadImage.cpp.o: CMakeFiles/loadImage.dir/flags.make
CMakeFiles/loadImage.dir/loadImage.cpp.o: ../loadImage.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/g/src/opencv_project/OpenCV_Tutorial/1_LoadImage/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/loadImage.dir/loadImage.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/loadImage.dir/loadImage.cpp.o -c /mnt/g/src/opencv_project/OpenCV_Tutorial/1_LoadImage/loadImage.cpp

CMakeFiles/loadImage.dir/loadImage.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/loadImage.dir/loadImage.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/g/src/opencv_project/OpenCV_Tutorial/1_LoadImage/loadImage.cpp > CMakeFiles/loadImage.dir/loadImage.cpp.i

CMakeFiles/loadImage.dir/loadImage.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/loadImage.dir/loadImage.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/g/src/opencv_project/OpenCV_Tutorial/1_LoadImage/loadImage.cpp -o CMakeFiles/loadImage.dir/loadImage.cpp.s

# Object files for target loadImage
loadImage_OBJECTS = \
"CMakeFiles/loadImage.dir/loadImage.cpp.o"

# External object files for target loadImage
loadImage_EXTERNAL_OBJECTS =

loadImage: CMakeFiles/loadImage.dir/loadImage.cpp.o
loadImage: CMakeFiles/loadImage.dir/build.make
loadImage: /usr/local/lib/libopencv_dnn.so.4.5.0
loadImage: /usr/local/lib/libopencv_gapi.so.4.5.0
loadImage: /usr/local/lib/libopencv_highgui.so.4.5.0
loadImage: /usr/local/lib/libopencv_ml.so.4.5.0
loadImage: /usr/local/lib/libopencv_objdetect.so.4.5.0
loadImage: /usr/local/lib/libopencv_photo.so.4.5.0
loadImage: /usr/local/lib/libopencv_stitching.so.4.5.0
loadImage: /usr/local/lib/libopencv_video.so.4.5.0
loadImage: /usr/local/lib/libopencv_videoio.so.4.5.0
loadImage: /usr/local/lib/libopencv_imgcodecs.so.4.5.0
loadImage: /usr/local/lib/libopencv_calib3d.so.4.5.0
loadImage: /usr/local/lib/libopencv_features2d.so.4.5.0
loadImage: /usr/local/lib/libopencv_flann.so.4.5.0
loadImage: /usr/local/lib/libopencv_imgproc.so.4.5.0
loadImage: /usr/local/lib/libopencv_core.so.4.5.0
loadImage: CMakeFiles/loadImage.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/g/src/opencv_project/OpenCV_Tutorial/1_LoadImage/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable loadImage"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/loadImage.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/loadImage.dir/build: loadImage

.PHONY : CMakeFiles/loadImage.dir/build

CMakeFiles/loadImage.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/loadImage.dir/cmake_clean.cmake
.PHONY : CMakeFiles/loadImage.dir/clean

CMakeFiles/loadImage.dir/depend:
	cd /mnt/g/src/opencv_project/OpenCV_Tutorial/1_LoadImage/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/g/src/opencv_project/OpenCV_Tutorial/1_LoadImage /mnt/g/src/opencv_project/OpenCV_Tutorial/1_LoadImage /mnt/g/src/opencv_project/OpenCV_Tutorial/1_LoadImage/build /mnt/g/src/opencv_project/OpenCV_Tutorial/1_LoadImage/build /mnt/g/src/opencv_project/OpenCV_Tutorial/1_LoadImage/build/CMakeFiles/loadImage.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/loadImage.dir/depend

