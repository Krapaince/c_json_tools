Append
======

The ``json_*_append_*`` appends a value at the end of the object/array.

**Return value:**

* On failure ``JSON_EF``
* On success ``JSON_ES``

Object
------

.. NOTE::
   If the key already exist in the object the function fails and `json_errno` is
   set to **JSON_E_KEY_ALREADY_EXIST**.

.. doxygengroup:: EditorAppendObject

Array
-----
.. doxygengroup:: EditorAppendArray
