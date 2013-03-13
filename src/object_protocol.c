#include <Python.h>

static PyObject *
not_impl(PyObject *self, PyObject *args)
{
    Py_RETURN_NOTIMPLEMENTED;
}

/*
 * Check All exceptions
 * http://docs.python.org/2/c-api/exceptions.html#standard-exceptions
 */
static PyObject *
raise_not_implemented(PyObject *self, PyObject *args)
{
    PyErr_SetString(PyExc_NotImplementedError, "Not Implemented");
    return NULL;
}


static PyObject *
print(PyObject *self, PyObject *args)
{
    PyObject_Print(args, stdout, 0);

    Py_RETURN_NONE;
}

/*
 * Alternate:
 * PyObject* PyObject_GetAttrString(PyObject *o, const char *attr_name)
*/

static PyObject *
hasattr(PyObject *self, PyObject *args)
{
    int rc;
    PyObject *obj, *attr_name;

    if (!PyArg_ParseTuple(args, "OO", &obj, &attr_name))
        return NULL;

    rc = PyObject_HasAttr(obj, attr_name);

    if (rc > 0)
        return Py_True;
    return Py_False;
}

/*
 * Alternate:
 * PyObject* PyObject_GetAttrString(PyObject *o, const char *attr_name)
*/

static PyObject *
getattr(PyObject *self, PyObject *args)
{
    PyObject *attr, *obj, *attr_name;

    if (!PyArg_ParseTuple(args, "OO", &obj, &attr_name))
        return NULL;

    attr = PyObject_GetAttr(obj, attr_name);
    //TODO check null
    Py_INCREF(attr);
    return attr;
}



static PyMethodDef playground_obj_methods[] = {
    {"not_impl", not_impl, METH_VARARGS, "Not Implemented"},
    {"raise_not_implemented", raise_not_implemented, METH_NOARGS, 
                                                     "Raise Not Implemented"},
    {"print", print, METH_VARARGS, "PyObject_Print"},
    {"hasattr", hasattr, METH_VARARGS, "PyObject_HasAttr"},
    {"getattr", getattr, METH_VARARGS, "PyObject_GetAttr"},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef playground_obj_module = {
    PyModuleDef_HEAD_INIT,
    "object_protocol_playground",
    "Playground to Learn Abstract Protocols",
    -1,
    playground_obj_methods,
    NULL, NULL, NULL, NULL
};

PyMODINIT_FUNC
PyInit_object_protocol_playground(void)
{
    return PyModule_Create(&playground_obj_module);
}
