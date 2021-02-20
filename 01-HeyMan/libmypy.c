#include <Python.h>
#include "libmypy.h"

PyObject * hello(PyObject * self) {
	return PyUnicode_FromFormat("Hello C extension!");
}

PyObject * heyman(PyObject *self, PyObject *args) {
	int num;
	char *name;

	if(!PyArg_ParseTuple(args, "is", &num, &name))
		return NULL;

	return PyUnicode_FromFormat("Hay %s!  You gave me %d.", name, num);
}

int f() {
  int i;
  int total = 0;

  for (i = 0; i < 10; i = i+1) {  // GOOD: comparison could be either true or false.
    total += i;
  }

  for (i = 0; i < 10; i = i+1) {  // BAD: comparison is always true, because i <= 5. 
    i = i % 5;
    total += i;
  }

  return total;
}
