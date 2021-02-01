Index
=====

Object
------

The ``json_object_get_*_by_index`` get a value from the ``object`` at ``index``
and set ``*value`` at index. If the index is out of the bound or the type
doesn't match, the function fails.

**Return value:**

* On failure ``JSON_EF``
* On success ``JSON_ES``

.. doxygengroup:: GettersIndexObject

Array
-----

The ``json_array_get_*_by_index`` get a value from the ``array`` at ``index``
and set  ``*value`` with it. If the index is out of the bound or the type
doesn't match, the function fails.

**Return value:**

* On failure ``JSON_EF``
* On success ``JSON_ES``

.. doxygengroup:: GettersIndexArray
