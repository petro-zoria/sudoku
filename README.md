# 🏯 Sudoku

🧑‍🤝‍🧑 Team Members

Petro Zoria

Ivan Yanhol

Danylo Sokolovsky

✨ Project name and Short description

Project name: Sudoku

Short description: We have created the classic Japanese logic puzzle game, "Sudoku". The goal is to fill a 9x9 grid with numbers from 1 to 9 so that each row, each column, and each of the nine 3x3 subgrids contains all of the digits from 1 to 9 exactly once.

🚀 Getting Started

These instructions will guide you through setting up and running the project on your local machine.

Prerequisites

To successfully build and run this application, you need the following tools installed:

Compiler: GCC or equivalent C compiler.

Build Tool: Make.

Building and Running

The project uses a standard Makefile for compilation.

1. Clone the Repository

git clone https://github.com/petro-zoria/intro_to_programming_2025.git

cd sudoku


1. Build the Project

The make command compiles the source code and creates the executable file named ./sudoku.

make


3. Run the Game

Execute the binary to start the interactive console game.


⚠️ Encoding and Terminal Compatibility

This application uses UTF-8 encoding to properly display the Sudoku grid, borders, and special characters in the console.

Windows Users: The executable includes specific logic to detect the Windows environment and attempts to automatically configure the console for UTF-8 compatibility. If display issues remain, make sure your terminal is explicitly set to use the UTF-8 codepage (e.g., by manually running the command chcp 65001 before launching the game).

Linux/macOS Users: Ensure your terminal locale is set to a UTF-8 environment.

🛠️ Built With

Primary Language: C

Build System: Makefiles