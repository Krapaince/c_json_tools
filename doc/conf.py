# Configuration file for the Sphinx documentation builder.
#
# This file only contains a selection of the most common options. For a full
# list see the documentation:
# https://www.sphinx-doc.org/en/master/usage/configuration.html

# -- Path setup --------------------------------------------------------------

# If extensions (or modules to document with autodoc) are in another directory,
# add these directories to sys.path here. If the directory is relative to the
# documentation root, use os.path.abspath to make it absolute, like shown here.
#
import os, subprocess
import sys
import sphinx_rtd_theme
# sys.path.insert(0, os.path.abspath('.'))

# Readthedocs.io
def configureDoxyfile(input_dir, output_dir, inc_path):
    with open('Doxyfile.in', 'r') as file :
        filedata = file.read()

    filedata = filedata.replace('@DOXYGEN_INPUT_DIR@', input_dir)
    filedata = filedata.replace('@DOXYGEN_OUTPUT_DIR@', output_dir)
    filedata = filedata.replace('@DOXYGEN_INC_PATH@', inc_path)

    with open('Doxyfile', 'w') as file :
        file.write(filedata)

read_the_docs_build = os.environ.get('READTHEDOCS', None) == 'True'

breathe_projects = {}

if read_the_docs_build:
    input_dir = '../src ../include'
    output_dir = 'build'
    inc_path = '../include'
    configureDoxyfile(input_dir, output_dir, inc_path)
    subprocess.call('doxygen', shell=True)
    subprocess.call('cat Doxyfile', shell=True)
    subprocess.call('ls -la .', shell=True)
    subprocess.call('ls -la ./build', shell=True)
    subprocess.call('ls -la ./build/xml', shell=True)
    breathe_projects = { "krapaince_c_json_tools": output_dir + '/xml' }
    print(breathe_projects)

# -- Project information -----------------------------------------------------

project = 'krapaince_c_json_tools'
copyright = '2021, Mathieu Pointecouteau'
author = 'Mathieu Pointecouteau'

# The full version, including alpha/beta/rc tags
release = '0.9'

# -- General configuration ---------------------------------------------------

# Add any Sphinx extension module names here, as strings. They can be
# extensions coming with Sphinx (named 'sphinx.ext.*') or your custom
# ones.
extensions = [
    "breathe",
    "sphinx_rtd_theme",
]

# Add any paths that contain templates here, relative to this directory.
templates_path = ['_templates']

# List of patterns, relative to source directory, that match files and
# directories to ignore when looking for source files.
# This pattern also affects html_static_path and html_extra_path.
exclude_patterns = ['_build', 'Thumbs.db', '.DS_Store']


# -- Options for HTML output -------------------------------------------------

# The theme to use for HTML and HTML Help pages.  See the documentation for
# a list of builtin themes.
#

html_theme = "sphinx_rtd_theme"

# Add any paths that contain custom static files (such as style sheets) here,
# relative to this directory. They are copied after the builtin static files,
# so a file named "default.css" will overwrite the builtin "default.css".
html_static_path = ['_static']

breathe_default_project = "krapaince_c_json_tools"
