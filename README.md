# C JSON Tools

This project is a C library which provide tools to parse, edit and generate
`json` file.

`file.json`:
```json
{
    "nb": 34,
    "bool": true,
    "str": "string",
    "null": null,
    "obj": {},
    "arr": []
}
```
```c
# A simple program which uses the library

#include <unistd.h>

#include <json/json.h>

int main(void)
{
    json_object_t* obj = json_object_parse_from_filepath("file.json");

    if (obj == NULL)
    {
        json_print_error(stdout);
        return 1;
    }
    json_object_generate_to_fd(obj, STDOUT_FILENO, NULL);
    json_object_destroy(obj);
    return 0;
}

```

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

## :ant: Know issues
- Typedef ending with `_t`

Have a look [here](https://stackoverflow.com/questions/231760/what-does-a-type-followed-by-t-underscore-t-represent/12727104#12727104).

- Parsing: `json_*_parse_from_fd`

```json
{
    "a_json_object": 34
} Some extra characters after final bracket
```
If there is characters after the fianl closing bracket, they will be read by the
parser since it uses `getline()`.

- Documentation consistency

The function index page of the documentation doesn't use the same layout.
During the creation of the documentation I was testing the different options

- Documentation in header which will be extracted by Doxygen
- Documentation in `.rst` file which will be parsed by Sphinx

## :warning: Notes

Please keep in mind that this project was done a few years ago and that it
doesn't meet my today's quality standards.
