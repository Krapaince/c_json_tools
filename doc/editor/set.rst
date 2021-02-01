Set
===

Object
------

Key
^^^

The ``json_object_set_*_by_key`` sets ``value`` at ``key``. If the
``key`` already exist the ``value`` is replace. Otherwise an element is created
at the end of ``object``.

**Return value:**

* On failure ``JSON_EF``
* On success ``JSON_ES``

.. doxygengroup:: EditorSetKeyObject

Array
-----

Index
^^^^^

The ``json_array_set_*_by_index`` sets the ``value`` at ``index`` in the
``array``. If the ``index`` is out of the bound the function succeed. Otherwise,
the function fails and ``array`` if left untouched.

**Return value:**

* On failure ``JSON_EF``
* On success ``JSON_ES``

.. doxygengroup:: EditorSetIndexArray
