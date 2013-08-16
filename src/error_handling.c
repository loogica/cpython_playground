#include <Python.h>

static PyObject*
exec_unraisable_exception(PyObject *self, PyObject *args)
{
    PyObject *message;

    PyErr_WriteUnraisable(args);

    Py_RETURN_NONE;
}

static PyMethodDef error_handling_methods[] = {
    {"exec_unraisable_exception", exec_unraisable_exception, METH_VARARGS, ""},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef error_handling_module = {
    PyModuleDef_HEAD_INIT,
    "exec_unraisable_exception",
    "lern error handling c-api",
    -1,
    error_handling_methods,
    NULL, NULL, NULL, NULL,
};

PyMODINIT_FUNC
PyInit_error_handling(void)
{
    return PyModule_Create(&error_handling_module);
}
