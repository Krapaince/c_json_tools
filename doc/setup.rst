Setup
=====

Prerequisites
-------------

The library is supported on Linux.

Building from source
--------------------

.. code-block:: bash

   mkdir build && cd build
   cmake ..
   make

Installing
----------

.. WARNING::

   There isn't any install official script yet because the library is not meant
   to be used in real project for now. See `here <https://github.com/Krapaince/c_json_tools#context--/>`_
   for the why.

The library can still be installed even without it. Once build the library can
be found in the following folder: **build/lib/**.

To go with the library you may need the header files to. They are located in
the **include/** directory.

Usage
-----

To compile your project with the library, you need to make sure to:

1. Add the include directory to the header search path
2. Link your library to your executable
