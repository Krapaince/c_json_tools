Function reference
==================

Object
------

Append
^^^^^^

The ``json_object_append_*`` append ``value`` at the end of the object.

**Return value:**

* On failure **JSON_EF**
* On success **JSON_ES**

.. NOTE::
   If the key already exists in the object the function fails and ``json_errno``
   is set to **JSON_E_KEY_ALREADY_EXIST**.

.. doxygengroup:: EditorAppendObject


Create
^^^^^^

.. doxygengroup:: EditorCreateObject


Destroy
^^^^^^^

.. doxygengroup:: EditorDestroyObject


Extract
^^^^^^^

The ``json_object_extract_*_by_index`` extract the ``value`` from the
``object`` and sets ``*value`` with it. The ``object``'s element is then set to
**JSON_NULL** type. If the ``index`` is out of bound or the ``value``'s type at
``index`` doesn't match, the function fails and both ``value`` and ``object``
are left untouched.

**Return value:**

* On failure **JSON_EF**
* On success **JSON_ES**

.. doxygengroup:: EditorExtractIndexObject


The ``json_object_extract_*_by_key`` extract the ``value`` from the ``object``
and sets ``*value`` with it. The ``object`` element is then set to **JSON_NULL**
type. If the ``key`` is invalid or the ``value``'s type at ``index`` doesn't
match, the function fails and both ``value`` and ``object`` are left untouched.

**Return value:**

* On failure **JSON_EF**
* On success **JSON_ES**

.. doxygengroup:: EditorExtractKeyObject


Generator
^^^^^^^^^

.. doxygengroup:: GeneratorObject


Getters
^^^^^^^

The ``json_object_get_*_by_index`` get a value from the ``object`` at ``index``
and set ``*value`` at index. If the index is out of the bound or the type
doesn't match, the function fails.

**Return value:**

* On failure **JSON_EF**
* On success **JSON_ES**

.. doxygengroup:: GettersIndexObject


The ``json_object_get_*_by_key`` get the value which match the ``key`` from the
``object``. If the ``key`` isn't set in the object or the type doesn't match,
the function fails.

**Return value:**

* On failure **JSON_EF**
* On success **JSON_ES**

.. doxygengroup:: GettersKeyObject


Parser
^^^^^^

.. doxygengroup:: ParserObject


Set
^^^

The ``json_object_set_*_by_key`` sets ``value`` at ``key``. If the
``key`` already exist the ``value`` is replace. Otherwise an element is created
at the end of ``object``.

**Return value:**

* On failure **JSON_EF**
* On success **JSON_ES**

.. doxygengroup:: EditorSetKeyObject


Unset
^^^^^

The ``json_object_unset_element_by_key`` function unsets the element at ``key``
and remove it from the ``object``.
Return the number of unset elements.

.. doxygengroup:: EditorUnsetObjectKey


The ``json_object_unset_element_by_index`` function unsets the element at
``index`` and remove it from the ``object``.
Return the number of unset elements.

.. doxygengroup:: EditorUnsetObjectIndex





Array
-----

Append
^^^^^^

The ``json_array_append_*`` append ``value`` at the end of the array.

**Return value:**

* On failure **JSON_EF**
* On success **JSON_ES**

.. doxygengroup:: EditorAppendArray


Create
^^^^^^

.. doxygengroup:: EditorCreateArray


Destroy
^^^^^^^

.. doxygengroup:: EditorDestroyArray


Extract
^^^^^^^

The ``json_array_extract_*_by_index`` extract the ``value`` from the ``array``
and set ``*value`` with it. The ``array`` value is then set to **JSON_NULL**
type. If the ``index`` is out of bound or the ``value``'s type at ``index``
doesn't match, the function fails and both ``value`` and ``array`` are left
untouched.

**Return value:**

* On failure ``JSON_EF``
* On success ``JSON_ES``


.. doxygengroup:: EditorExtractIndexArray


Generator
^^^^^^^^^

.. doxygengroup:: GeneratorArray


Getters
^^^^^^^

The ``json_array_get_*_by_index`` get a value from the ``array`` at ``index``
and set ``*value`` at index. If the index is out of the bound or the type
doesn't match, the function fails.

**Return value:**

* On failure **JSON_EF**
* On success **JSON_ES**

.. doxygengroup:: GettersIndexArray


Parser
^^^^^^

.. doxygengroup:: ParserArray


Set
^^^

The ``json_array_set_*_by_index`` set the ``value`` at ``index`` in the
``array``. If the ``index`` is out of the bound the function succeeds.
Otherwise, the function fails and ``array`` if left untouched.

**Return value:**

* On failure **JSON_EF**
* On success **JSON_ES**

.. doxygengroup:: EditorSetIndexArray


Unset
^^^^^

The ``json_array_unset_element_by_index`` function unsets the element at
``index`` and remove it from the ``array``.
Return the number of unset element.

.. doxygengroup:: EditorUnsetArrayIndex


The ``json_array_unset_element_by_value_*`` functions unset all elements which
match ``value`` and remove them from the ``array``.
Return the number of unset element(s).

.. doxygengroup:: EditorUnsetArrayValue
