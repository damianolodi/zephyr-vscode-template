# Zephyr VSCode Template

This repo provides a Zephyr project template configured to be used in with a Visual Studio Code developing environment. The project remains compatible with command-line interaction, if preferred.

The source code for this project [can be found on Github](https://github.com/damianolodi/zephyr-vscode-template).

## Table of Contents

- [About the Project](#about-the-project)
- [Project Status](#project-status)
- [Getting Started](#getting-started)
    - [Dependencies](#dependencies)
    - [Getting the Source](#getting-the-source)
        - [Template Duplication](#template-duplication)
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

The necessity for this template originate from the lack of feature-rich templates dedicated to Zephyr RTOS. While it is very easy to find simple project skeletons, the normal developer workflow consists of much more than a single `CMakeLists.txt` repo.

With this template, the author hopes to share a rather complete developer environment, with features that spans from repository configuration to complete integration with the Visual Studio Code editor.

Other than being a working Zephyr template, this is the author's personal template. This is by no mean a complete or perfect working environment: it simply is the template that best suites the author's need and workflow.

**[Back to top](#table-of-contents)**

## Project Status

This project is the author's personal template. For this reason, the project is under constant development and it is subject to change following the author's workflow and workspace preferences.

Nonetheless, the template should be in a working state at every commit and you should be able to use the template whenever you need it.

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

#### Template Duplication

The project source code is [stored on Github](https://github.com/damianolodi/zephyr-vscode-template). The repo is marked as template, so that a green *Use this template* button is available in the top-right of the page.

Using this button, Github will create a new repository (with its own history) in the user account.

> **IMPORTANT:** if you decide to move to the following sections without using the template button, remember to *delete the `.git` directory in the project folder and re-initialize a new repo using the `git init` command.*

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

The Git LFS configuration file (`.gitattributes`) is already provided, filled with the most common files extensions. Nonetheless, when Git LFS is required in the repo, it must be initialized by the user.

```bash
git lfs install
```

If not required, feel free to delete the `.gitattributes` file. More detailed informations are [available in the documentation](https://git-lfs.com/).

#### Conventional Commits

When creating commits, the authors preference is following the *[Conventional Commits](https://www.conventionalcommits.org/en/v1.0.0/)* standard. To avoid accidental errors in commit messages, the standard can be enforced using pre-commit Git hooks.

Quick and easy Git hook setup for this repo is provided by [husky](https://typicode.github.io/husky/), and *npm* package. After installing *npm*, follow this instructions to enforce the *Conventional Commits.*

```bash
# Move into the tools folder
cd <project_directory>/tools

# Install dependencies and initialize hooks
npm install
```

The *npm* package that enforces the commit standard is called [commitlint](https://commitlint.js.org/), while its configuration is stored into `tools/commitlint.config.js`. Follow the documentation to customize the configuration.

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

TBC.

**[Back to top](#table-of-contents)**

## Contributing

Considering the fact that this is a personal template, contribution to this project is not supported. The author's will not accept any submitted pull request.

Nonetheless, if you spot any error or you have ideas on how to improve the template functionalities, feel free to contact the author and submit you feedbacks.

**[Back to top](#table-of-contents)**

## Further Reading

When possible, links to the used tools have been added. In the following, a collection of related and useful websites is provided:

- [Documentation for the Zephyr RTOS](https://docs.zephyrproject.org/latest/index.html)
- [Devicetree Standard Specification](https://www.devicetree.org/)

**[Back to top](#table-of-contents)**

## License

Copyright (c) 2024 [Damiano Lodi](https://www.damianolodi.com/)

This project is licensed under the MIT License - see [LICENSE.md](LICENSE.md) file for details.

> **TL;DR**
> - :white_check_mark: You **can** take any piece of this template and modify it to make it suits your workflow and preferences.
> - :x: You **cannot** take this exact template and say it is yours.
> - :pray: If you use part of this template for a public project and you want to mention this repo, it will be greatly appreciated.

**[Back to top](#table-of-contents)**
