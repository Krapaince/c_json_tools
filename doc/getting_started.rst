Getting started
===============

The library provides two famillies of function:

* json_array
* json_object

For each of this famillies those operations are available:

* Append
* Create
* Destroy
* Extract
* Generator
* Get
* Parse
* Set
* Unset


Example
-------

A simple program which uses the library:

file.json:

.. code-block:: json

   {
       "nb": 34,
       "bool": true,
       "str": "string",
       "null": null,
       "obj": {},
       "arr": []
   }

.. code-block:: C

   #include <unistd.h>

   #include <json/json.h>

   int main(void)
   {
      json_object_t* obj = json_object_parse_from_filepath("file.json");

      if (obj == NULL)
      {
          json_print_error(stdout);
          return 1;
      }
      json_object_generate_to_fd(obj, STDOUT_FILENO, NULL);
      json_object_destroy(obj);
      return 0;
   }
