#include <Python.h>

/* Why Py_RETURN_*?
 * http://docs.python.org/2/c-api/bool.html#Py_RETURN_TRUE
 */

static PyObject *
check(PyObject *self, PyObject *args)
{
    int rc;
    PyObject *number;

    if (!PyArg_ParseTuple(args, "O", &number)) {
        return NULL;
    }

    rc = PyNumber_Check(number);

    if (rc > 0)
        Py_RETURN_TRUE;
    Py_RETURN_FALSE;
}

static PyObject *
add(PyObject *self, PyObject *args)
{
    PyObject *result, *obj, *obj2;

    if (!PyArg_ParseTuple(args, "OO", &obj, &obj2)) {
        return NULL;
    }

    result = PyNumber_Add(obj, obj2);
    Py_INCREF(result);

    return result;
}


static PyMethodDef playground_obj_methods[] = {
    {"check", check, METH_VARARGS, "PyNumber_Check"},
    {"add", add, METH_VARARGS, "PyNumber_Add"},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef playground_obj_module = {
    PyModuleDef_HEAD_INIT,
    "number_protocol_playground",
    "Playground to Learn Abstract Protocols - Number",
    -1,
    playground_obj_methods,
    NULL, NULL, NULL, NULL
};

PyMODINIT_FUNC
PyInit_number_protocol_playground(void)
{
    return PyModule_Create(&playground_obj_module);
}
