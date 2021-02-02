# C JSON Tools

This project is a C library which provide tools to parse, edit and generate
`json` file.

## :books: Documenation
You can find the documentation
[here](https://c-json-tools.readthedocs.io/en/latest/). If you want an offline,
version have a look
[here](https://github.com/Krapaince/c_json_tools#api-documentation--).

## Context

This project was realised during my second year of study at Epitech. It helps
me build a network project that you can find
[here](https://github.com/Zumtak/NWP_MyTeams_Epitech).

I have update the library since so the version used in the network project is
outdated.

## :warning: Warning
This project doesn't conform with [RFC 7159](https://tools.ietf.org/html/rfc7159
). If you want a project that feat this usage, please see
[c-json](https://github.com/json-c/json-c).

## Prerequisites

- [CMake](https://cmake.org)
- Linux
- [GCC](https://gcc.gnu.org/), [Clang](https://clang.llvm.org) or another C
    compiler

If you want to build the documentation
- [Sphinx](https://www.sphinx-doc.org/en/master/)
- [Doxygen](https://www.doxygen.nl/index.html)

If you want to build the unit tests
- [Criterion](https://criterion.readthedocs.io/en/master/intro.html)
- [Gcovr](https://gcovr.com/en/stable/)

## :hammer: Build

:warning: **Before building anything**, CMake's setup must be done

At the root of the project run
```bash
mkdir build && cd build
cmake ..
```

### Build the library
```bash
make
```
The library can then be found in the following directory: `build/lib/`.

### Build the documentation
```bash
ccmake .. # Then set the BUILD_DOC option on 'ON'
make Sphinx
```
The location of the generated documentation index can then be found here: `build/doc/Sphinx/index.html`.

### Build the unit tests
```bash
make tests_run # To run the unit tests
make gcovr # To generate a coverage report
```
The generated coverage report is in the HTML format. The index can be found here:
`build/coverage/c_json_tools.html`.

## Know issues
- Typedef system like
- Parser read to many characters in fd

## :warning: Notes

Please keep in mind that this project was done a few years ago and that it
doesn't meet my today's quality standards.
