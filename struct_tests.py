from ctypes import cdll, c_double, c_int, c_uint, addressof, POINTER, Structure, byref, pointer
from timeit import timeit
from numpy.ctypeslib import ndpointer, as_ctypes
import numpy as np
from typing import Optional

my_lib = cdll.LoadLibrary("/home/jhellier/projects/cxx_library_tests/add_seven.so")


class TestStruct(Structure):
    _fields_ = [("x", c_double), ("y", c_int)]

    def __init__(self, x: float = 0.0, y: int = 0):
        self.x = x
        self.y = y


class OneArray(Structure):
    _fields_ = [("size", c_uint), ("x", POINTER(c_double))]

    def __init__(self, size: int, x: Optional[np.array] = None):
        self.size = size
        self._x = x
        if x is None:
            self._x = np.zeros(size, dtype="float64")

    @property
    def x(self):
        return as_ctypes(self._x)


class TwoArrays(Structure):
    _fields_ = [("size", c_uint), ("x", POINTER(c_double)), ("y", POINTER(c_double))]

    def __init__(self, size: int, x: Optional[np.array] = None, y: Optional[np.array] = None):
        self.size = size
        self._x = x
        self._y = y
        if x is None:
            self._x = np.zeros(size, dtype="float64")
        if y is None:
            self._y = np.zeros(size, dtype="float64")

    @property
    def x(self):
        return as_ctypes(self._x)

    @property
    def y(self):
        return as_ctypes(self._y)

array_size = 100
one_array = OneArray(array_size, np.linspace(0.0, 100.0, array_size))
two_arrays = TwoArrays(array_size, np.linspace(0.0, 100.0, array_size), np.linspace(10.0, 110.0, array_size))

sum_one_array = my_lib.sum_array
sum_one_array.restype = None
sum_one_array.argtypes = [OneArray, c_double]

x = 0.0
sum_one_array(pointer(one_array), x)

print(x)

sum_two_arrays = my_lib.sum_two_arrays
sum_two_arrays.restype = None
sum_two_arrays.argtypes = [POINTER(TwoArrays), POINTER(OneArray)]

sum_two_arrays(two_arrays, one_array)