# vwcn

Project Name: vwcn

Created by: Lightnet

License: MIT

Programs:
 * Visual Studio Code 1.16.0
 * Python 2.7.13
  * Scons 2.5.1 (script builds)
 * VS2017 Window 10 (compiler tool)

Information: By using the Python Scons script or command to compile build for c/c++ application. By using Visual Studio Code to run task builds. Using bare minimal editor for easy testing.

There are two main packages for testing. SDL2 and GLFW for window application. That is still testing.

Notes:
 * Same functions from package will cause an error that is in conflict with current dir from script base of same functions scripts. (need to fixed or test for code builds.)
 * `#undef main` SDL2 for main entery point
 * Example files are just test build for api or third parties to check for packages breaking.
 * Firewall or security programs can block builds and compilers.
 * vsbuild.bat is for default note if your on window. Need call vcvars32.bat first and second
 * vsbuild_debug.bat to config for vs2017
 * vsbuild_release.bat is to config for vs2017

Third Parties / API:
 * Imgui 1.51
 * SDL2 2.0.6
 * gl3w
 * glew 2.1.0
 * glfw 3.2.1
 * glad v0.1.14a0
 * glm 0.9.8.5

[Scons Builds]:

Default build VS2017 Window 10 32bit

[window 10 | viusal studio]

   `scons mode=release`

[Linux]

    Need SDL2, Python 2.7, Scons to be install. (apt-get install)

   `scons` 

   `./project_vwen` (run program)

Refs:
  * ...