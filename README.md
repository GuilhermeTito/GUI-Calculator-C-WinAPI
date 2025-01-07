# GUI Calculator (C - Windows API)

A simple GUI calculator written in C with the Windows API.

## How to use

This project is configured to be built by CMake with the gcc compiler. Other
compilers may require manual configuration.

### Configuring, building and running

Navigate to the project's source directory on the command line and run the
following commands:

To configure the project:

```
cmake -G "MinGW Makefiles" -D CMAKE_C_COMPILER=gcc -D CMAKE_CXX_COMPILER=g++ .
```

To build the executable:

```
cmake --build .
```

To run the executable:

```
.\bin\Calculator.exe
```