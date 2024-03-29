# -*- coding: utf-8 -*-

"""
OpenCvSharp for IronPython.

* Environment variable 'IRONPYTHON_HOME' is required. It is the installation location of IronPython.
* "OpenCvSharp.dll", "OpenCvSharp.Extensions.dll", "wk_util_opencvsharp.dll" is required.
"""

__author__  = "Nishida Takehito <takehito.nishida@gmail.com>"
__version__ = "0.9.3.0"
__date__    = "2022/08/16"

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

IPY_LIB = path.join(IRONPYTHON_HOME, "Lib")
IPY_DLLS = path.join(IRONPYTHON_HOME, "DLLs")
IPY_OPENCVSHARP = path.join(IRONPYTHON_HOME, "Lib\\opencvsharp")
IPY_OPENCVSHARPDLL = path.join(IRONPYTHON_HOME, "Lib\\opencvsharp\\dll")

_lstPath = []
_lstPath.append(IPY_LIB)
_lstPath.append(IPY_DLLS)
_lstPath.append(IPY_OPENCVSHARP)
_lstPath.append(IPY_OPENCVSHARPDLL)

for i in _lstPath:
    if os.path.exists(i):
        systemPath.append(i)
    else:
        raise Exception("There is no '" + i + "'.")

#
# Import modules.
#
import clr
clr.AddReferenceByPartialName("System.Drawing")
clr.AddReferenceToFile("OpenCvSharp.dll")
clr.AddReferenceToFile("OpenCvSharp.Extensions.dll")
clr.AddReferenceToFile("wk_util_opencvsharp.dll")
import OpenCvSharp
from OpenCvSharp import Cv2
from OpenCvSharp import Mat
from wk_util_opencvsharp import Cv2Util
from wk_util_opencvsharp import LockBitmap
from System.Drawing import Bitmap
from System.Drawing.Imaging import PixelFormat
ToBitmap = OpenCvSharp.Extensions.BitmapConverter.ToBitmap
ToMat = OpenCvSharp.Extensions.BitmapConverter.ToMat
