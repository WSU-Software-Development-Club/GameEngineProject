# GameEngineProject

## Project Overview
A Custom 2D Game Engine.

The key technologies include:

* **SDL3**: Simple DirectMedia Layer (SDL) is a cross-platform development library designed to provide low-level access to audio, keyboard, mouse, and graphics hardware via OpenGL and Direct3D. SDL3 improves upon previous versions by offering enhanced modularity, better multi-threading support, and improved rendering capabilities, making it a solid choice for game development.

## System Requirements
* **Hardware**: The hardware requirements have not been tested but the majority of modern computers with at least 4GB of RAM should suffice.
* **Software**: Visual Studio Code 2022 installed.

## Prerequisites
1. **Download SDL**: Go to the [SDL](https://www.libsdl.org/) website and download the latest stable release in the top right corner (the current stable release as of writing is **version 3.2.4**).
2. **Install Visual Studio 2022**: Download and install [Visual Studio 2022](https://visualstudio.microsoft.com/vs/).
3. **Clone Repository**:
```bash
git clone https://github.com/WSU-Software-Development-Club/GameEngineProject.git
```
5. **File Explorer**:
* Open the SDL folder and Repository folder from the steps above in your computer's file explorer
* In the SDL folder find the x64 folder (~/SDL3-3.2.4/lib/x64)
* Copy the contents of the x64 folder (SDL3.dll, SDL3.lib, SDL3.pdb, SDL3_test.lib) and paste it within the x64 folder in the repository (~/SDLProject/x64)
6. **Open Repository**:
* Open the repository in Visual Studio 2022
* In the top left click on **Project > Properties**
* At the top make sure that configuration is set to **All Configurations** and Platform is set to **All Platforms**
* Navigate to **C/C++ > General > Additional Include Directories > Edit** and make sure that (~/SDL/include) is referenced
* Navigate to **Linker > General > Additional Library Directories > Edit** and make sure that (~/SDLProject/x64) is referenced
* Navigate to **Linker > Input > Additional Dependencies > Edit** and make sure the following is referenced:
```bash
SDL3.lib
SDL3_test.lib
```
* Finally click apply to apply changes

## Usage
1. Set the solution configuration to Debug and the Solution Platform to x64
2. Start the program by clicking on the run debugger button or by the keyboard shortcut f5

## Troubleshooting Tips
* For any linking problems follow this [video](https://www.youtube.com/watch?v=Fy_4ACtmt7A)
* If other problems arise send a message in the #help-discussion on discord
