# -*- coding: utf-8 -*-

"""
OpenCvSharp for IronPython.

* Environment variable 'IRONPYTHON_HOME' is required. It is the installation location of IronPython.
* "OpenCvSharp.dll", "OpenCvSharp.Blob.dll", "OpenCvSharp.Extensions.dll", "OpenCvSharp.UserInterface.dll", "OpenCvSharp.Extensions.dll", "wk_util.dll" is required.
"""

__author__  = "Nishida Takehito <takehito.nishida@gmail.com>"
__version__ = "0.9.1.0"
__date__    = "2018/11/01"

#
# append path.
#
import os
import os.path as path
from sys import path as systemPath
from System import Environment as env
IRONPYTHON_HOME = env.GetEnvironmentVariable("IRONPYTHON_HOME")

if IRONPYTHON_HOME is None:
    raise Exception("Error : Set path of IRONPYTHON_HOME.")

IRONPYTHON_LIB = path.join(IRONPYTHON_HOME, "Lib")
IRONPYTHON_DLLS = path.join(IRONPYTHON_HOME, "DLLs")
IRONPYTHON_OPENCVSHARP = path.join(IRONPYTHON_HOME, "Lib\\opencvsharp")
IRONPYTHON_OPENCVSHARPDLL = path.join(IRONPYTHON_HOME, "Lib\\opencvsharp\\dll")

_lstPath = []
_lstPath.append(IRONPYTHON_LIB)
_lstPath.append(IRONPYTHON_DLLS)
_lstPath.append(IRONPYTHON_OPENCVSHARP)
_lstPath.append(IRONPYTHON_OPENCVSHARPDLL)

_checkPath = True

for i in _lstPath:
    if os.path.exists(i):
        systemPath.append(i)
    else:
        _checkPath = False
        print("There is no '" + i + "'.")

if _checkPath == False:
	raise Exception("Error occured.")

#
# Import modules.
#
import sys
import clr
import shutil
clr.AddReferenceByPartialName("System.Drawing")
clr.AddReferenceToFile("OpenCvSharp.dll")
clr.AddReferenceToFile("OpenCvSharp.Blob.dll")
clr.AddReferenceToFile("OpenCvSharp.Extensions.dll")
clr.AddReferenceToFile("OpenCvSharp.UserInterface.dll")
clr.AddReferenceToFile("wk_util.dll")
import OpenCvSharp
from OpenCvSharp import Cv2
from OpenCvSharp import Mat
from wk_util import Cv2Util
from wk_util import LockBitmap
from System.Drawing import Bitmap
from System.Drawing.Imaging import PixelFormat
