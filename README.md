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

