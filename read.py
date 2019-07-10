#!/usr/bin/python2.7
'''
Notes: 

When reading a binary file, make sure the data type
correct.

If using np.dtype two methods:
    Use dtype = np.float32 and rearrange the data into a 2d shape

    Use dtype = [("label",np.float32),("label",np.float32).....]
    and using the label name will output the values.

    numpy data types:

    np.float32
    ..
    ..
    ..

'''
import os
import sys 
import numpy as np
import struct

if __name__ == '__main__':

    print("\nReding binary file")

#### METHOD 1

    print("\nMethod 1")
    # Declare a datatype
    my_dtype = np.dtype([("time",np.float32),("x",np.float32),("y",np.float32)]) 
    print("Data type: 3*(32 bit float)")

    # Read binary file
    data = np.fromfile("file.bin",dtype=my_dtype)
    
    # Print the time data
    print(data['time'][0:5])
    
    
#### METHOD2
    print("\nMethod 2")
    
    # data type is just 32 bit float
    my_dtype = np.float32
    print("Data type: 1*(32 bit float)")
   
   # Read binary file
    data = np.fromfile("file.bin",dtype=my_dtype)

    # Get dimensions for data array
    length=len(data)
    columns = 2
    rows = int(length/columns)

    print("Reshaping to a two column array")
    data = data.reshape((rows,columns))
    
    print(data[0:5])
