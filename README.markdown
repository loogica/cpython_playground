# CPython Playground - Python 3.3 **only**

## Learn Python C-API

CPython Playground is an environment make easy start hacking on the
Python C-API. It's also the code from my Portuguese(pt-BR) lessons on the
Abstract Objects Layer.

## Requirements

* Python 3.3 (or newer)
* Test Runner (pytest or nose)

## Running and Testing

```sh
python setup.py install
py.test -v tests/
```

or

```sh
python setup.py install
nosetests tests/
```

## Protocols

Soon, we expect to provide working examples for:

* Object Protocol
* Number Protocol
* Sequence Protocol
* Mapping Protocol
* Iterator Protocol

### Object Protocol

Implemented Examples:

```c
Py_RETURN_NOTIMPLEMENTED;

int PyObject_Print(PyObject *o, FILE *fp, int flags);

int PyObject_HasAttr(PyObject *o, PyObject *attr_name);

PyObject* PyObject_GetAttr(PyObject *o, PyObject *attr_name);
```

# License

```
Copyright (c) 2012, Felipe Cruz/Loogica
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of the Loogica nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL Felipe Cruz/Loogica BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
```

# Contact

felipecruz@loogica.net
