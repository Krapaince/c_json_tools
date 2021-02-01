Unset
=====

Object
------

Key
^^^

The ``json_object_unset_element_by_key`` function unsets the element at ``key``
and remove it from the ``object``.
Return the number of unset element.

.. doxygengroup:: EditorUnsetObjectKey

Index
^^^^^

The ``json_object_unset_element_by_index`` function unsets the element at
``index`` and remove it from the ``object``.
Return the number of unset element.

.. doxygengroup:: EditorUnsetObjectIndex

Array
-----

Index
^^^^^

The ``json_array_unset_element_by_index`` function unsets the element at
``index`` and remove it from the ``array``.
Return the number of unset element.

.. doxygengroup:: EditorUnsetArrayIndex


The ``json_array_unset_element_by_value_*`` functions unsets all elements which
match ``value`` and remove them from the ``array``.
Return the number of unset element(s).

.. doxygengroup:: EditorUnsetArrayValue
