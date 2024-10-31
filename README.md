# Zephyr VSCode Template

This repo provides a Zephyr project template configured to be used in with a Visual Studio Code developing environment. The project remains compatible with command-line interaction, if preferred.

The source code for this project [can be found on Github](https://github.com/damianolodi/zephyr-vscode-template).

## Table of Contents

- [About the Project](#about-the-project)
- [Project Status](#project-status)
- [Getting Started](#getting-started)
    - [Dependencies](#dependencies)
    - [Getting the Source](#getting-the-source)
        - [Cloning with West](#cloning-with-west)
        - [Cloning with Git](#cloning-with-git)
    - [Dependency Management](#dependency-management)
    - [Configuration](#configuration)
    - [Building and Flashing](#building-and-flashing)
- [Template Features](#template-features)
    - [VSCode Configuration](#vscode-configuration)
        - [Recommended Extensions](#recommended-extensions)
        - [Settings](#settings)
        - [Tasks](#tasks)
        - [Debugging](#debugging)
        - [Snippets](#snippets)
    - [Git Configuration](#git-configuration)
        - [Git LFS](#git-lfs)
        - [Conventional Commits](#conventional-commits)
    - [Code Formatting](#code-formatting)
    - [Code Analysis](#code-analysis)
    - [Doxygen Support](#doxygen-support)
- [Contributing](#contributing)
- [Further Reading](#further-reading)
- [License](#license)

## About the Project

The necessity for this template ...
Other than being a working Zephyr template, this is the author's personal template. For this reason the proje

Here you can provide more details about the project
* What features does your project provide?
* Short motivation for the project? (Don't be too long winded)
* Links to the project site

**[Back to top](#table-of-contents)**

## Project Status

This project is the author's personal template. For this reason, the project is under constant development and it is subject to change following the author's workflow and workspace preferences.

Nonetheless, the template should be in a working state at every commit and you should be abel to use the template whenever you need it.

There are no planned releases or a defined release cycle.

**[Back to top](#table-of-contents)**

## Getting Started

The project uses the [Zephyr workspace application](https://docs.zephyrproject.org/latest/develop/application/index.html#zephyr-workspace-application) architecture, so that all Zephyr dependencies are managed by the `west` tool.

In the following, you can find instructions to get a working copy of the project template.

### Dependencies

The only required dependencies are the one [listed by the Zephyr project.](https://docs.zephyrproject.org/latest/develop/getting_started/index.html) In particular, you should need:

- Git &rarr; required to clone the repository.
    - The project has a configuration file for `git-lfs` but this dependency is not require.
- Python &rarr; required to manage project dependencies.
- CMake &rarr; required to build the project.
- [Zephyr SDK](https://docs.zephyrproject.org/latest/develop/getting_started/index.html#install-the-zephyr-sdk) &rarr; required to build the project.

Follow the official guide for more information about the installation process.

### Getting the Source

The source code can be either cloned using `git` or using `west`.

#### Cloning with West

This is the easiest way to clone and initialize the project correctly.

```bash
west init -m https://github.com/damianolodi/zephyr-vscode-template.git <project_directory>
```

This command will clone the repo in `<project_directory>/app` and initialize the `west` workspace.

#### Cloning with Git

If you want to clone (and initialize) the project using plain git you need the following commands.

```bash
# Clone
git clone https://github.com/damianolodi/zephyr-vscode-template.git <project_directory>/app

# Move into app folder
cd <project_directory>/app

# Initialize west workspace
west init -l .
```

Be sure to clone into `<project_directory>/app` since the `<project_directory>` will be populated by `west` with all the app dependencies.

**[Back to top](#table-of-contents)**

### Dependency Management

Once the project is initialized, one needs to download all project dependencies. My suggestion is to use a Python virtual environment.

```bash
# Move into project directory
cd <project_directory>

# Create and activate Python virtual environment
python3 -m venv .venv
source .venv/bin/activate

# Move into app directory
cd app

# Download zephyr and dependencies using west
west update

# Install additional Python dependencies
pip install -r ../zephyr/scripts/requirements.txt
```

Zephyr and additional project dependencies are listed in `<project_directory>/app/west.yml`.

> If you need a different version of Zephyr or you need additional dependencies, modify the `west.yml` before using the `west dependencies` command.

**[Back to top](#table-of-contents)**

### Configuration

The project build system is based on CMake and it follows the structure suggested by Zephyr.

Different CMake configurations are stored in the `CMakePresets.json` file. The authors's preference is to create and name configurations after board name and CMake build type. Nonetheless, the preset file can be refactored following personal preferences.

When refactoring, consider the following points:

- always set the `BOARD` variables
- set the `FILE_SUFFIX` variable to the configuration name
    - The assigned value can be different from the usual `debug`, `release` (etc.) value required by CMake.
    - The build system will look into the `boards` directory for a project configuration file named using the `BOARD` and `FILE_SUFFIX` values.

Once the presets are defined, the project can be configured using either CMake.

```bash
cmake --preset <configure_preset_name>
```

Configuration using `west` is also possible, but not suggested since all presets variables should be defined manually when giving the command.

**[Back to top](#table-of-contents)**

### Building and Flashing

Once configured, the project can be built using CMake.

```bash
cmake --build --preset <build_preset_name>
```

The board can be flashed calling the respective target.

```bash
cmake --build --preset <build_preset_name> --target flash
```

> **NOTE:** additional hardware driver must be installed depending on the used flashing hardware.

**[Back to top](#table-of-contents)**

## Template Features

This template contains various features with the goal of easing some common developer actions and workflows.

In the following, each feature is described in detail.

### VSCode Configuration


#### Recommended Extensions

The VSCode integration requires some extensions to work properly. The list of all the author's recommended extensions is stored in `.vscode/extensions.json`.

While some extensions are nice but superfluous, the following ones are mandatory:

- *C/C++* (`ms-vscode.cpptools`)
- *CMake Tools* (`ms-vscode.cmake-tools`)
- *Cortex-Debug* (`marus25.cortex-debug`)

#### Settings

The workspace settings are stored in `.vscode/setting.json`. Configuration values are grouped based on the category/extension for which they have effect.

#### Tasks

The list of available tasks is stored in `.vscode/tasks.json`. It contains all the common tasks required by the developer to interact with the project (e.g. CMake configuration, building, flashing, ...).

In addition, the list contains some of the less common (but useful) commands that are easily forgettable (e.g. Zephyr's `guiconfig`).

#### Debugging

Debugging configuration is store in `.vscode/launch.json`, and uses the excellent *Cortex-Debug* extension. This extension extends the VSCode debugger to embedded systems.

Multiple configurations can be added. In particular, for the current template version, a new configuration should be added for every board.

You can find more information about the debugger configuration on the [Cortex-Debug's Github page](https://github.com/Marus/cortex-debug).

#### Snippets

A list of author's favorite snippet is stored in `.vscode/snippets.code-snippets`. See [VSCode documentation](https://code.visualstudio.com/docs/editor/userdefinedsnippets) to know how to define you own.

**[Back to top](#table-of-contents)**

### Git Configuration

#### Git LFS

#### Conventional Commits

**[Back to top](#table-of-contents)**

### Code Formatting

Code formatting is supported through *Clang Format* and the configuration is stored in `.clang-format`.

VSCode is configured to apply formatting every time the user save the current file.

At the time of writing, no other way to apply Clang Format is supported by the template.

**[Back to top](#table-of-contents)**

### Code Analysis

Code analysis is supported through *Clan Tidy* and the configuration is stored in `.clang-tidy`.

VSCode is configured to analyze the current file every time it is saved.

At the time of writing, no other analyzer is supported.

**[Back to top](#table-of-contents)**

### Doxygen Support

**[Back to top](#table-of-contents)**

## Contributing

Considering the fact that this is a personal template, contribution to this project is not supported. The author's will not accept any submitted pull request.

Nonetheless, if you spot any error or you have ideas on how to improve the template functionalities, feel free to contact the author and submit you feedbacks.

**[Back to top](#table-of-contents)**

## Further Reading

TBC

**[Back to top](#table-of-contents)**

## License

Copyright (c) 2024 [Damiano Lodi](https://www.damianolodi.com/)

This project is licensed under the XXXXXX License - see [LICENSE.md](LICENSE.md) file for details.

> **TL;DR**
> - You **can** take any piece of this template and modify it to make it suits your workflow and preferences.
> - You **cannot** take this exact template and say it is yours.
> - If you use part of this template for a public project and you want to mention this repo, it will be greatly appreciated.

**[Back to top](#table-of-contents)**
