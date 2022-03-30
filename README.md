# Flint Stone Engine

*This barebone game engine was made in the context of the "Game Engine Series" of "The Cherno" on YouTube.*

## Features
* Entry Point. Takes control of the start of the application and the loop in a way other applications can implement features to the game loop. 
* Logging. A simple logging functionality using the `spdlog` library. There are different logging levels (Trace, Info, Error, etc.) which print colored text in the console.
* Event System. A dedicated dsipatcher is used to emit events that other subsystems of the game engine can react on. In this way it's possible to loosely couple systems.
* Window Events. With the help of `GLFW` window events were implemented. In this way we can react on certain user-actions like resizing the window, clicking mouse- or keyboard-key etc. Essentially the window events make use of the event system that was implemented earlier.
