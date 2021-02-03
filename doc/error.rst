Handling Error
==============

Errno json values
-----------------

Like the C library, this library uses an ``errno`` to indicate what went wrrong.
The ``json_errno``'s value is significant only when the return value of the
call indicated an error (e.g. \b JSON_EF).

.. doxygengroup:: ErrorErrno
.. doxygengroup:: ErrorErrnoValues
