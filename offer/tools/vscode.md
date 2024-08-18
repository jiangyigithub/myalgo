# vscode tutorial

## c++
**compiler**
- linux: gcc/g++
- window: Mingw/cl
- configure g++ with cmake tools on linux --> [Get started with CMake Tools on Linux](https://code.visualstudio.com/docs/cpp/cmake-linux)

**debuger**
- linux: GDB
- configure GDB with cmake tools on linux --> [Get started with CMake Tools on Linux](https://code.visualstudio.com/docs/cpp/cmake-linux)

**intelliSense**
- "intelliSenseMode": "linux-gcc-x64" -->(c_cpp_properties.json)
- These configuration settings are stored in your project's c_cpp_properties.json file. To edit this file, in VS Code, select C/C++: Edit Configurations (UI) from the Command Palette (`Ctrl+Shift+P`).

**semantic colorization**
- Selecting the Color Theme. You can also use the keyboard shortcut `Ctrl+K Ctrl+T` to display the picker.

**formatting**
- The C/C++ extension for Visual Studio Code supports source code formatting using clang-format which is included with the extension.
You can format an entire file with Format Document by keyboard shortcut `Ctrl+Shift+I` 

**linting**
- "C_Cpp.errorSquiggles": "Enabled" -->(setting.json)
- from the Command Palette (Ctrl+Shift+P)-->C/C++:Enable Error Squiggles

**edit**
- Ctrl+K Ctrl+S -->Keybord Shortcuts
- Ctrl+` -->Toggle Terminal
- Ctrl+\ -->Split Editor
- Ctrl+P -->File Go-to
- Ctrl+Shift+P -->Commands
- Ctrl+/ -->Comment
- Ctrl+K Ctrl+T -->Color Theme
- Ctrl+Shift+V -->Markdown Preview
- Ctrl+W --> Close 
- Ctrl+B --> toggle Side bar Visibility
- Ctrl+Z --> undo
- Ctrl+Shift+I --> Formatting
- Ctrl+G --> Go Line


**extension**
- C/C++
- CMake Tools

**more**
- unit test --> gtest
- collaboration --> library
- muti-files --> cmake
- iteration/version control --> git

## python
**interpreter**
- Python is an interpreted language, and in order to run Python code and get Python IntelliSense, you must tell VS Code which interpreter to use.
- From within VS Code, select a Python3 interpreter by opening the Command Palette (Ctrl+Shift+P), start typing the Python: Select Interpreter command to search, then select the command. 
- There are three ways you can run Python code within VS Code:
  Click the Run Python File in Terminal play button in the top-right side of the editor.
  Right-click anywhere in the editor window and select Run Python File in Terminal. 
  Select one or more lines, then press Shift+Enter or right-click and select Run Selection/Line in Python Terminal.

**debuger**
- Start the debugger by clicking on the down-arrow next to the run button on the editor, and selecting Debug Python File in Terminal.

**formatter**
- You can also use the keyboard shortcut (Ctrl+Shift+I)-Linux or (Shift+Alt+F)-Window
  The Python extension supports source code formatting using either autopep8 (the default), black, or yapf.

**linting**
- "python.linting.enabled": true -->(setting.json)
- To enable linters other than the default PyLint, open the Command Palette (Ctrl+Shift+P) and select the Python: Select Linter command. This command adds "python.linting.<linter>Enabled": true to your settings, where <linter> is the name of the chosen linter. 

**extension**
- Python
- Pylance

**more**
- unit test --> pytest("python.testing.pytestEnabled": true -->(setting.json))
- package --> pip install
- packages-management/environment --> conda

## references
1. [Using C++ on Linux in VS Code](https://code.visualstudio.com/docs/cpp/config-linux)
2. [Edit C++ in Visual Studio Code](https://code.visualstudio.com/docs/cpp/cpp-ide)
3. [Get started with CMake Tools on Linux](https://code.visualstudio.com/docs/cpp/cmake-linux)
4. [Editing Python in Visual Studio Code](https://code.visualstudio.com/docs/python/python-tutorial)
5. [Python testing in Visual Studio Code](https://code.visualstudio.com/docs/python/testing)
6. About .json file
    - `tasks.json` (compiler build settings) --> [g++](https://www.cs.bu.edu/fac/gkollios/cs113/Usingg++.html)
    ```json
    // tasks.json
    "tasks": [
      {
        "label": "C/C++: g++ build active file",
        "args": ["-o","${workspaceFolder}/build/${fileBasenameNoExtension}"]
      }
    ]
    ```
    - `launch.json` (debugger settings)
    ```json
    // launch.json
    "configurations": [
      {
          "name": "g++ - Build and debug active file",
          "program": "${workspaceFolder}/build/${fileBasenameNoExtension}"
      }
    ]
    ```
    - `c_cpp_properties.json` (includePath, compiler path and IntelliSense settings)
    ```json
    // c_cpp_properties.json
    "configurations": [
        {
            "name": "Linux",
            "includePath": [
                "${default}"
            ]
        }
    ]
    ```
    - `setting.json` (Ctrl+Shift+P --> Open Workspaces Settings (JSON) command)
    ```json
    // setting.json
    {
      "python.linting.enabled": true,
      "python.testing.pytestArgs": [
          "python"
      ],
      "python.testing.unittestEnabled": false,
      "python.testing.pytestEnabled": true,
      "C_Cpp.errorSquiggles": "Enabled"
    }
    ```  

