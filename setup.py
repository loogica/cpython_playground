from distutils.core import setup, Extension

object_protocol = Extension('object_protocol_playground',
                            sources=['src/object_protocol.c'])

number_protocol = Extension('number_protocol_playground',
                            sources=['src/number_protocol.c'])

setup(name='protocol_playground',
      version='1.0',
      description='For Educational Purposes',
      ext_modules=[number_protocol, object_protocol])
