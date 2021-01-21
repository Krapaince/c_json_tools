# Look for an executable call 'sphinx-build'
find_program(SPHINX_EXECUTABLE
            NAMES sphinx-build
            DOC "Path to sphinx-build executable")

include(FindPackageHandleStandardArgs)

# Handle standard arguments to find_package
find_package_handle_standard_args(
    Sphinx
    "Failed to find 'sphinx-build' executable"
    SPHINX_EXECUTABLE)

