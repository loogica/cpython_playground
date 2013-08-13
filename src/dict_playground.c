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

static PyObject*
get_keys(PyObject* self, PyObject *args)
{
    PyObject *dict, *key, *value, *ret;
    Py_ssize_t pos = 0;
    int count = 0;

    if (!PyArg_ParseTuple(args, "O", &dict))
        return NULL;

    ret = PyList_New(PyDict_Size(dict));

    while (PyDict_Next(dict, &pos, &key, &value)) {
        PyList_SetItem(ret, count, key);
        count++;
    }

    return ret;
}

static PyObject*
enumerate(PyObject *self, PyObject *args)
{
    PyObject *dict, *key, *value, *list, *tuple;
    Py_ssize_t pos = 0;
    int count = 0;

    if (!PyArg_ParseTuple(args, "O", &dict))
        return NULL;

    list = PyList_New(PyDict_Size(dict));

    while (PyDict_Next(dict, &pos, &key, &value)) {
        tuple = PyTuple_Pack(2, key, value);
        PyList_SetItem(list, count, tuple);
        count++;
    }

    return list;
}

static PyMethodDef playground_dict_methods[] = {
    {"my_new_dict", my_new_dict, METH_NOARGS, "my new dict"},
    {"get_keys", get_keys, METH_VARARGS, "get keys"},
    {"enumerate", enumerate, METH_VARARGS, "enumerate"},
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


