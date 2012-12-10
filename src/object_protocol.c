#include <Python.h>

static PyObject *
not_impl(PyObject *self, PyObject *args)
{
    Py_RETURN_NOTIMPLEMENTED;
}


static PyObject *
print(PyObject *self, PyObject *args)
{
    PyObject_Print(args, stdout, 0);

    Py_RETURN_NONE;
}

static PyObject *
hasattr(PyObject *self, PyObject *args)
{
    int rc;
    PyObject *obj, *attr_name;

    if (!PyArg_ParseTuple(args, "OO", &obj, &attr_name)) {
        return NULL;
    }

    rc = PyObject_HasAttr(obj, attr_name);

    if (rc > 0)
        return Py_True;
    return Py_False;
}

static PyObject *
getattr(PyObject *self, PyObject *args)
{
    PyObject *attr, *obj, *attr_name;

    if (!PyArg_ParseTuple(args, "OO", &obj, &attr_name)) {
        return NULL;
    }

    attr = PyObject_GetAttr(obj, attr_name);
    Py_INCREF(attr);
    return attr;
}

/*
int PyObject_Print(PyObject *o, FILE *fp, int flags)
int PyObject_HasAttr(PyObject *o, PyObject *attr_name)
int PyObject_HasAttrString(PyObject *o, const char *attr_name)
PyObject* PyObject_GetAttr(PyObject *o, PyObject *attr_name)
PyObject* PyObject_GetAttrString(PyObject *o, const char *attr_name)
*/


static PyMethodDef playground_obj_methods[] = {
    {"not_impl", not_impl, METH_VARARGS, "Not Implemented"},
    {"print", print, METH_VARARGS, ""},
    {"hasattr", hasattr, METH_VARARGS, ""},
    {"getattr", getattr, METH_VARARGS, ""},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef playground_obj_module = {
    PyModuleDef_HEAD_INIT,
    "object_protocol_playground",
    "Playground to Leardn Abstract Protocols",
    -1,
    playground_obj_methods,
    NULL, NULL, NULL, NULL
};

PyMODINIT_FUNC
PyInit_object_protocol_playground(void)
{
    return PyModule_Create(&playground_obj_module);
}
