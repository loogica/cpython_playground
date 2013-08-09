#include <Python.h>

static PyObject*
my_new_dict(PyObject *self, PyObject *args) {
    PyObject *dict = PyDict_New();
    PyObject *number = Py_BuildValue("i", 10);
    Py_INCREF(number);
    Py_INCREF(dict);

    PyDict_SetItemString(dict, "tester", number);

    return dict;
}

static PyMethodDef playground_dict_methods[] = {
    {"my_new_dict", my_new_dict, METH_NOARGS, "my new dict"},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef playground_dict_module = {
    PyModuleDef_HEAD_INIT,
    "dict_playground",
    "learn python c-api",
    -1,
    playground_dict_methods,
    NULL, NULL, NULL, NULL
};

PyMODINIT_FUNC
PyInit_dict_playground(void)
{
    return PyModule_Create(&playground_dict_module);
}


