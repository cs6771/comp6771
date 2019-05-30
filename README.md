# Option 1
Download my virtual machine I've created for you. It has everything set up. Run it with virtualbox. The password is "comp6771".

# Option 2
sudo apt install clang-format

## Clion (optional, but recommended)
We will be using clion during the lectures. Use a different IDE or editor if you prefer, but do so at your own risk.

Download and install clion 2018.3.4 (bazel plugin doesn’t support newer versions) from [jetbrains website](https://www.jetbrains.com/clion/download/previous.html). Sign up using your student email to get a free copy.

## Installing bazel
* [Download and install bazel](https://docs.bazel.build/versions/master/install-ubuntu.html)
* Install bazel plugin for clion
  * Configure > plugins
    * Install bazel, clang-tidy, and clang-format.
  * If they don't appear, make sure you have clion 2018.3.4 installed and not a newer version.
* Restart clion
* Settings > bazel settings > bazel binary > set location to your bazel you downloaded
* Run `chmod a+x ~/.CLion2018.3/config/plugins/clwb/gdb/gdbserver`
* Restore my settings (file > import settings)


## C++ Compiler
Should be preinstalled. Version should be gcc 8. Needs to support C++17.

# Importing the project
* File > import bazel project > course repository

Things you may want to modify on the VM:
* Enable ideavim

# Windows 10
* Make sure that you have the 19H1 update installed
  * Might work on older version, but you need to transform linux paths to windows paths
  * Tested using the Ubuntu distro for WSL
## Setting Up Environment
* Install Visual Studio Code - Insiders
* Install these VS Code Extensions:
  * C/C++
  * vscode-bazel
  * Remote Development
* Follow these getting started guide:
  * https://code.visualstudio.com/docs/cpp/config-wsl
    * Up until the 'Set up your Linux environment', but feel free to read the whole thing
  * https://code.visualstudio.com/docs/remote/wsl
    * Just the 'Getting Started' section should be sufficient.
* Install Bazel on WSL:
  * https://docs.bazel.build/versions/master/install-ubuntu.html
## Editing
* On WSL:
  * Clone this git repo
  * cd to cloned repo directory
  * code-insiders ./
## Building
* Open command palette (Ctrl + Shift + P), type "bazel"
* Select "Bazel: Build Package" if you want to build a package.
  * Example: building //lectures/week1 will build every single target listed in the BUILD file
* Select "Bazel: Build Package Recursively" if you want to build a package recursively.
  * Example: building //lectures will build //lectures/week1, //lectures/week2, etc.
* Select "Bazel: Build Target" if you want to build single targets.
## Running
* Open terminal
* Navigate to the root of the repository
* Go to `./bazel-bin/{$path_to_executable_dir}` and run the appropriate binary 
* Example: 
  ```bash
    cd ./bazel-bin/lectures/week1
    ./factorial
  ```

## Debugging
* Go to root of the repository
* Create a directory called ".vscode" (e.g. `mkdir .vscode`)
* Inside the newly created directory create these files, "launch.json" and "tasks.json"
* The following is an example on how to set the files up for debugging `//lectures/week1:factorial_test`
  * It should be easy enough to extend them for other targets
* On "tasks.json"
  ```javascript
  {
    // See https://go.microsoft.com/fwlink/?LinkId=733558
    // for the documentation about the tasks.json format
    "version": "2.0.0",
    "tasks": [
        {
            // to build in debug, open command pallete and select "Run Tasks"
            // and select the appropriate label (e.g. "build_factorial_test_debug"). 
            // add more to 'tasks' as required
            "label": "build_factorial_test_debug",
            "type": "shell",
            "command": "bazel",
            "args": ["build", "//lectures/week1:factorial_test", "--compilation_mode=dbg"],
            "group": {
                "kind": "build",
                "isDefault": true
            },
            "problemMatcher": [
                "$gcc"
            ]
        }
    ]
  }

  ```
* On "launch.json"
  ```javascript
  {
    // Use IntelliSense to learn about possible attributes.
    // Hover to view descriptions of existing attributes.
    // For more information, visit: https://go.microsoft.com/fwlink/?linkid=830387
    "version": "0.2.0",
    "configurations": [
        {
            // to debug, open command palette and select "Debug: Select and Start Debugging"
            // and pick the appropriate name (e.g. (gdb) factorial_test)
            // add more to 'configurations' as required.
            "name": "(gdb) factorial_test",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}/bazel-bin/lectures/week1/factorial_test",
            "args": [],
            "stopAtEntry": true,
            "cwd": "${workspaceFolder}",
            "environment": [],
            "externalConsole": false,
            "MIMode": "gdb",
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ]
        }
    ]
  }
  ```