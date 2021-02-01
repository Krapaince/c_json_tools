Extract
=======

Object
------

Index
^^^^^

The ``json_object_extract_*_by_index`` extracts the ``value`` from the
``object`` and sets ``*value`` with it. The ``object`` element is then set to
``JSON_NULL`` type. If the ``index`` is out of bound or the ``value``'s type at
``index`` doesn't match, the function fails and both ``value`` and ``object``
are left untouched.

**Return value:**

* On failure ``JSON_EF``
* On success ``JSON_ES``

.. doxygengroup:: EditorExtractIndexObject

Key
^^^

The ``json_object_extract_*_by_key`` extracts the ``value`` from the ``object``
and sets ``*value`` with it. The ``object`` element is then set to ``JSON_NULL``
type. If the ``key`` is invalid or the ``value``'s type at ``index`` doesn't
match, the function fails and both ``value`` and ``object`` are left untouched.

**Return value:**

* On failure ``JSON_EF``
* On success ``JSON_ES``

.. doxygengroup:: EditorExtractKeyObject

Array
-----

Index
^^^^^

The ``json_array_extract_*_by_index`` extracts the ``value`` from the ``array``
and sets ``*value`` with it. The ``array`` value is then set to ``JSON_NULL``
type. If the ``index`` is out of bound or the ``value``'s type at ``index``
doesn't match, the function fails and both ``value`` and ``array`` are left
untouched.

**Return value:**

* On failure ``JSON_EF``
* On success ``JSON_ES``


.. doxygengroup:: EditorExtractIndexArray
