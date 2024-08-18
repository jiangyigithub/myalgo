`serialization and deserialization` --> mdf-exporter

`replay` --> selena

`visulization` --> plotstr

`evaluation` --> snoopy


https://inside-docupedia.bosch.com/confluence/display/DP/SELENA+Build+System

(关于vfc和DADDY)
https://inside-docupedia.bosch.com/confluence/display/CMCI2NextGen2018/VFC+library+and+Functional+Safety

(关于openCV 和Eigen)
https://inside-docupedia.bosch.com/confluence/display/ROSE/CVA+and+CVA-Bridge

## R2D2做了哪些事
1. 生成代码，生成cmake file
- 解析配置文件 `.config` `.xml` `.ini`
- 根据FLUX生成.cmake文件
- scom PAD生成代码
- 根据runnable的头文件生成selena的仿真代码
2. 根据cmake file构建代码
---

## root CMakeList.txt的文件结构
line 124 include(${dc_cmake_DIR}/utils/dc_utils.cmake)
line 127 include(${dc_cmake_DIR}/target/dc_configure_target.cmake)
line 130 include(${DADDY_DIR}/src/libs.cmake)
        `component includes` include(${DC_ROOT_DIR}/dc_fw/components.cmake)
line 169 fw_component_hook()
        `component includes` include(${APL_DIR}/components.cmake)
line 171 target_component_hook()
        `target selena` add_dependencies(DC_DEFAULT_TARGET ALL) --> 生成selena target
line 194 target_final_hook()
line 195 compiler_final_hook()

---
## How-to LIB库，如boost,daddy怎么在编译系统里被cmake调用
1. boost qt5在哪被include
`BOOST` `QT5` `MATLAB`
```(ip_dc\dc_tools\CMakeLists.txt)
  line 7 include(${dc_cmake_DIR}/libs/dc_configure_boost.cmake)
  line 8 include(${dc_cmake_DIR}/libs/dc_configure_qt5.cmake)
  line 9 include(${dc_cmake_DIR}/libs/dc_configure_matlab.cmake)
```
2. DADDY库在哪被调用
`DADDY`
```(ip_dc\CMakeLists.txt)
line 130 include(${DADDY_DIR}/src/libs.cmake)
```
---
## 系统里怎么include dc_fw的component.cmake
1. root CMakeLists.txt
`line 169` fw_component_hook()
2. `fw_component_hook`
```(ip_dc\dc_tools\cmake\utils\dc_utils.cmake)
macro(fw_component_hook)
    # This macro can be overwritten by specialized config.
	if(NOT SELENA_TEST)
        include(${DC_ROOT_DIR}/dc_fw/components.cmake)
    endif(NOT SELENA_TEST)
endmacro()
```
---
## 系统里怎么include APL 部分的component.cmake
1. root CMakeLists.txt
`line 171` target_component_hook()
2. 
```(ip_dc\dc_tools\cmake\target\dc_configure_target.cmake)
macro(target_component_hook)
    # This macro can be overwritten by specialized config.
    # It should register additional components
	if(NOT SELENA_TEST)
        include(${APL_DIR}/components.cmake)
	else()
	    include(${dc_tools_DIR}/selena/test/components.cmake)
	endif(NOT SELENA_TEST)
endmacro()
```
3. others
```(apl_bjev\components.cmake)
include(${APL_DIR}/component/fal/components.cmake)
```
4. APL 部分CMakeList.txt 
set(FLUX_IMPLEMENTATION_COMPONENT_NAME "ad_fw") ad_fw.cmake (生成的)

---
## root CMakeList.txt 调用了哪些CMAKE
1. dacore 项目自定义的 cmake函数库，主要在ip_dc\dc_tools\cmake\utils 中的.cmake文件
2. apl 和dc_fw 的component.cmake ,通过`dc_add_component` 调用各子系统的CMakeList.txt，如ip_dc\dc_fw\src\per\CMakeLists.txt
3. ip_dc\dc_tools 有两部分，selena需要的lib，selena自己的CMakeList.txt
总结来说，通过cmake的command的，以及bosch 自定义了一些cmake command(如`dc_add_component`)，将target需要 的dacore代码，selena代码，还有外部依赖库(daddy,boost,qt5等)组织起来，最终生成root CMakeList.txt 的 目标文件`selena.exe`

---
## cmake 常见command
`set`
cmake中的参数声明

`include`
cmake中的函数声明

`include_directories`

`add_dependencies`
```生成target
./ip_dc/dc_tools/cmake/target/dc_target_selena.cmake:    add_dependencies(DC_DEFAULT_TARGET selena)
```

`find_package`
QT5 提供find_package机制，怎么加QT5的libaray，只需要include_directories加入该库提供的环境变量

`add_subdirectory`




```(ip_dc\dc_tools\cmake\target\dc_configure_target.cmake)
macro(target_final_hook)
 # This macro can be overwritten by specialized config.
 # It should execute code that needs to be run after adding components.
 add_dependencies(DC_DEFAULT_TARGET ALL)
endmacro()
```
---
## compiler_final_hook
1. default
```(ip_dc\dc_tools\cmake\compiler\dc_configure_compiler.cmake)
macro(compiler_final_hook)
# This macro can be overwritten by specialized config.
# It should execute code that needs to be run after adding components.
endmacro()
```
2. MSVC
```(ip_dc\dc_tools\cmake\compiler\dc_compiler_msvc.cmake)
macro(compiler_final_hook)
    ###########################
    # Perform Checks
    ###########################
    if(MSVC_VERSION LESS 1600)
        # To be safe regarding the flags used above (e.g. /MP)
        message(FATAL_ERROR "Need MSVC++ toolset 10.0 or higher")
    endif()
    if (NOT MSVC_VERSION LESS 1800) # Ignore C++11 for MSVC 2010 or earlier
        check_compiler_compatibility()
    endif()

    set(DC_FW_WARNING_FLAGS /WX)

    if(NOT SELENA_TEST)
# Treating warnings as errors is only supported in PER so far.
#       target_compile_options(dc_fw_per_lib PRIVATE     ${DC_FW_WARNING_FLAGS})
#       target_compile_options(dc_fw_rpm_lib PRIVATE     ${DC_FW_WARNING_FLAGS})
#       target_compile_options(dc_fw_dsm_lib PRIVATE     ${DC_FW_WARNING_FLAGS})
#       target_compile_options(dc_fw_sit_lib PRIVATE     ${DC_FW_WARNING_FLAGS})
#       target_compile_options(dc_fw_ccd_lib PRIVATE     ${DC_FW_WARNING_FLAGS})
#       target_compile_options(dc_fw_modules_lib PRIVATE ${DC_FW_WARNING_FLAGS})
    endif(NOT SELENA_TEST)

    if(TARGET gtest)
        set(ADDITIONAL_NON_QUALIFIED_GTEST_DEFINES -DGTEST_HAS_DEATH_TEST -DGTEST_HAS_FILTER)
        target_compile_options(gtest      PRIVATE ${ADDITIONAL_NON_QUALIFIED_GTEST_DEFINES})
        target_compile_options(gtest_main PRIVATE ${ADDITIONAL_NON_QUALIFIED_GTEST_DEFINES})
        target_compile_options(gmock      PRIVATE ${ADDITIONAL_NON_QUALIFIED_GTEST_DEFINES})
        target_compile_options(gmock_main PRIVATE ${ADDITIONAL_NON_QUALIFIED_GTEST_DEFINES})
    endif()

endmacro()
```

---
## How-to 跳过代码生成和cmake生成，通过bash脚本完成项目selena_build
```bash
echo $PATH
python R2D2.py -m $script_dir/apl_bjev/main/selena/config/cmake/ROSDADDY_PER_SIT_RPM_FCT.config -skip_codegen -skip_dinx -nb -notests

cd build/ROSDADDY_PER_SIT_RPM_FCT/dc_tools/selena/src/main
cmake --build . --config RelWithDebInfo --target selena
```
---
## 配置文件ROSDADDY_PER_SIT_RPM_FCT.config里还包含哪些配置文件
（apl_bjev\main\selena\config\cmake\ROSDADDY_PER_SIT_RPM_FCT.config）
1.`fbg2dcbuild .ini`
```(apl_bjev\main\selena\config\fbg2dcbuild\selena_build_config.ini)
set(FBG2DCBUILD_INI_FILE "${APL_DIR}/main/selena/config/fbg2dcbuild/selena_build_config.ini")
```
2.`selena target .cmake`
```(ip_dc\dc_tools\cmake\target\dc_target_selena.cmake)
set(DC_TARGET_CONFIG "${dc_cmake_DIR}/target/dc_target_selena.cmake")
```
3.`build time .xml`
```(apl_bjev\main\selena\config\buildtime\ROSDADDY_PER_SIT_RPM_FCT.xml)
set(SELENA_BUILD_CONFIG_FILE "${APL_DIR}/main/selena/config/buildtime/ROSDADDY_PER_SIT_RPM_FCT.xml")
```
4.`a2lTable.txt`
```(apl_bjev\main\selena\config\buildtime\ROSDADDY_PER_SIT_RPM_FCT.xml)
<a2ltable path="../../../apl_bjev/main/selena/config/mapping/bjev_a2lTable_updated.txt"/>
```
---
## selena可执行文件在哪定义生成,即怎么集成dc_fw和dc_tools 2大部分
1. root CMakeList 在ip_dc下 通过调用dc_target_selena.cmake中的target_final_hook来生成可执行文件
```(ip_dc\dc_tools\cmake\target\dc_target_selena.cmake)
macro(target_final_hook)
    trigger_selena_gen()
    # pseudo target which allows to link against all defined modules
    add_library(dc_components INTERFACE)
    target_link_libraries(dc_components INTERFACE ${DC_ACTIVE_COMPONENTS})

    # This macro can be overwritten by specialized config.
    # It should execute code that needs to be run after adding components.
    add_subdirectory(${CMAKE_CGEN_DIR}/nogen ${CMAKE_BINARY_DIR}/nogen/)
    add_subdirectory(${DC_ROOT_DIR}/dc_fw/src)
    # include SELENA target
    add_subdirectory(${DC_ROOT_DIR}/dc_tools)

    # This macro can be overwritten by specialized config.

    # It should execute code that needs to be run after adding components.
    add_dependencies(DC_DEFAULT_TARGET selena)
```
---
## How to怎么跳过 代码生成，FLUX.cmake 生成，UT,make 
1. 跳过生成dinx,生成selena runnable wrapper code等步骤
`R2D2.py`
-skip_dinx 
-skip_codegen 
2. 跳过UT build，跳过 make step
`R2D2.py`
-notests
-nb 
3. 跳过 生成FLUX.cmake,生成scom,生成GEN_PAD_PARAMS
`ROSDADDY_PER_SIT_RPM_FCT.config`
if (WIN32)
    execute_process(
        COMMAND cmd /c "python3 -u ${DC_ROOT_DIR}/../cmp_common/tools/fbg2dcbuild/fbg2dcbuild.py ${FBG2DCBUILD_INI_FILE}"
        RESULT_VARIABLE retcode
    )

if (WIN32)
    execute_process(    
        COMMAND cmd /c "${APL_DIR}/tools/builder/generate_scom.bat"
        RESULT_VARIABLE retcode
    )

if (WIN32)
    execute_process(    
        COMMAND cmd /c "${APL_DIR}/tools/builder/cmake/GEN_PAD_PARAMS.bat CNGDIR"
        RESULT_VARIABLE retcode
    )

---
## How-to Python 怎么调用cmake命令行，各cmake的config参数在哪
1. 通过Python 的subprocess.Popen命令调用cmake
proc = subprocess.Popen(cmake_args, cwd=build_dir_path,stdout=subprocess.PIPE, stderr=subprocess.STDOUT, bufsize=0)
cmake_args = [ 'cmake', self.cmake_path,
    '-DRB_PROJECT_TARGET={0}'.format(self.project_target),
    '-DCMAKE_EXPORT_COMPILE_COMMANDS=ON',
    '-DDC_CMAKE_CONFIG=%s' % config_file_path,
    '-DSELENA_SKIP_DINXPARSER=%s' % ('true' if self.skip_dinx_parser else 'false'),
    '-DSELENA_SKIP_NOGEN=%s' % ('true' if self.skip_node_gen else 'false') ]

2. 在log文件中可以查看 实际cmake各个调用参数， 如：`DC_ENABLE_TESTING`
// `cmake_args ` Calling CMake with arguments '['cmake', 'C:/ICV/ICV/icv_innofund_dasy/ip_dc', '-DRB_PROJECT_TARGET=selena', '-DCMAKE_EXPORT_COMPILE_COMMANDS=ON', '-DDC_CMAKE_CONFIG=C:/ICV/ICV/icv_innofund_dasy/apl_bjev/main/selena/config/cmake/ROSDADDY_PER_SIT_RPM_FCT.config', '-DSELENA_SKIP_DINXPARSER=true', '-DSELENA_SKIP_NOGEN=true', '-DSELENA_USE_MATLAB_TRANSFER=FALSE', '-DSELENA_BUILD_EMULATION_CONTAINER=FALSE', '-DSELENA_GHS_MATH=FALSE', '-DDC_ENABLE_TESTING=OFF', '-DDC_ENABLE_COVERAGE=OFF', '-DSELENA_WITH_DEBUG_STATES=TRUE', '-DSELENA_WITH_INTERNAL_STATES=TRUE', '-GVisual Studio 14 2015 Win64', '-Tv140', '-DBOOST_ROOT_DIR=C:\\TCC\\Tools\\boost\\1.63.0_WIN64']'

---
## How-to R2D2.py 是怎么工作的
1. 通过Python 的subprocess.Popen命令调用cmake和make命令行来编译
2. 脚本的函数结构为：
`main`
  - `CMakeEntry().run`
    - `determine_cmake_version`
    - `call_cmake`
    - `call_make`
---
## How-to selena 生成的代码怎么被编译到系统里
```(/ip_dc/dc_tools/CMakeLists.txt)
set(CORE_CGEN_DIR ${CMAKE_CGEN_DIR}/nogen/ros_nodes/selena/src) 
```
---
## HOW-TO fbg2dcbuild 生成的.cmake文件怎么被调用
1. apl_bjev\components.cmake中dc_add_component 根据DIR ${} 去找所在目录的CMakeList.txt文件
``` (apl_bjev\components.cmake)
dc_add_component(NAME bjev_per_run_spp_rss           DIR ${FAL_DIR}/per/runnables/spp_rss
```

2. 在 DIR中的CMakeList.txt文件通过dc_include去包含通过fbg2dcbuild生成的.cmake文件
``` (apl_bjev\component\fal\per\runnables\spp_rss\CMakeLists.txt)
dc_include(${FBG2DCBUILD_SELENA_DIR}/cmake/${FLUX_IMPLEMENTATION_COMPONENT_NAME}.cmake)
```
---

## selena log文件 `logfile_r2d2.txt` 的结构
1. 
apl_bjev\main\selena\config\cmake\ROSDADDY_PER_SIT_RPM_FCT.config
`message(" ### Paths set in SELENA buildtime config file ####")`

[R2D2 (cmake)] Run `fbg2dcbuild` to generate component cmake files from flux model 
  - COMMAND bash "-c" "python3 -u ${DC_ROOT_DIR}/../cmp_common/tools/fbg2dcbuild/fbg2dcbuild.py ${FBG2DCBUILD_INI_FILE}"
[R2D2 (cmake)] Starting generation of the SCOM 
  - COMMAND bash -c "${APL_DIR}/tools/builder/generate_scom.sh"
[R2D2 (cmake)] Starting generation of PAD parameters 
  - COMMAND bash -c "${APL_DIR}/tools/builder/cmake/GEN_PAD_PARAMS.sh"

2. 
ip_dc\dc_tools\cmake\utils\dc_configure_vbindings.cmake
line 113 -->`message(STATUS "Currently selected vbindings:")`
3. 
components.cmake
    ip_dc\dc_fw\components.cmake
    apl_bjev\component\fal\components.cmake
    apl_bjev\components.cmake
line 118 -->`[R2D2 (cmake)] Adding component`
[R2D2 (cmake)] `Adding component`(./cmake/utils/dc_dependencies.cmake:    message("Adding component ")
4. 
ip_dc\dc_tools\CMakeLists.txt
  - ip_dc\dc_tools\cmake\utils\dc_selena_utils.cmake
  line 216 -->`message("Running Dinx header creator (dinx_header_creator.py) ...")`

[R2D2 (cmake)] Running Dinx parser (dinxxmlparser.py) `selena/config/buildtime/ROSDADDY_PER_SIT_RPM_FCT.xml`
[R2D2 (cmake)] Running NoGen (generateRosDaddyNode.py)
5. 
ip_dc\CMakeLists.txt
`message("CMake build configuration process finished (${END_TIME})")`

---

## cmake variable 重要的环境变量
`dc_fw_DIR`
set(dc_fw_DIR ${DC_ROOT_DIR}/dc_fw)

`dc_tools_DIR`
set(dc_tools_DIR ${DC_ROOT_DIR}/dc_tools)

`FBG2DCBUILD_SELENA_DIR`
set(FBG2DCBUILD_SELENA_DIR "${CMAKE_BINARY_DIR}/../fbg2dcbuild/selena")

`CMAKE_BINARY_DIR`

`CMAKE_CGEN_DIR`
set(CMAKE_CGEN_DIR ${CMAKE_BINARY_DIR}/generated_src)

`CORE_CGEN_DIR`
```(./ip_dc/dc_tools/CMakeLists.txt)
set(CORE_CGEN_DIR ${CMAKE_CGEN_DIR}/nogen/ros_nodes/selena/src) 
```
---

## bosch 自定了哪些cmake command
1. dc_create_component(ip_dc\dc_tools\cmake\utils\dc_dependencies.cmake)

## package download 
* [QT](https://download.qt.io/new_archive/qt/5.8/5.8.0/)
* [BOOST](https://sourceforge.net/projects/boost/files/boost-binaries/1.63.0/)

## 环境变量的设置 environment variable setting
```bash
export BOOST_ROOT="$BOOST_ROOT C:/TCC/Tools/boost/1.63.0_WIN64"
echo $BOOST_ROOT
```
