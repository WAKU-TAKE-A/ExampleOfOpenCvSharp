# -*- coding: utf-8 -*-

"""
OpenCvSharp4 for IronPython (.NET 8.0)
"""

__author__  = "WAKU-TAKE-A <waku-take-a@ymail.ne.jp>"
__version__ = "0.9.4.0"
__date__    = "2026/01/21"

#
# append path.
#
from pathlib import Path
from sys import path as systemPath
from System import Environment as env

DOTNET_SHARED = sorted(Path(r"C:\Program Files\dotnet\shared\Microsoft.WindowsDesktop.App").glob("8.0.*"))[-1]
IRONPYTHON_HOME = env.GetEnvironmentVariable("IRONPYTHON_HOME")

if IRONPYTHON_HOME is None:
    raise Exception("Error : Set path of IRONPYTHON_HOME.")

CURRENT_DIR = Path(__file__).resolve().parent
IRONPYTHON_HOME_PATH = Path(IRONPYTHON_HOME)

_lstPath = [
    DOTNET_SHARED,
    CURRENT_DIR,
    IRONPYTHON_HOME_PATH / "Lib",
    IRONPYTHON_HOME_PATH / "DLLs"
]

for i in _lstPath:
    if not i.exists():
        raise FileNotFoundError("Required directory not found: {0}".format(i))
    if str(i) not in systemPath:
        systemPath.append(str(i))

import os

_native_dll_path = [
    CURRENT_DIR,
    CURRENT_DIR / "runtimes" / "win-x64" / "native",
]

for i in _native_dll_path:
    if i.exists():
        if str(i) not in os.environ['PATH']:
            os.environ['PATH'] = str(i) + ";" + os.environ['PATH']

#
# Import modules.
#
import clr

dlls = [
    DOTNET_SHARED / "System.Drawing.Common.dll",
    DOTNET_SHARED / "Microsoft.Win32.SystemEvents.dll", 
    CURRENT_DIR / "OpenCvSharp.dll",
    CURRENT_DIR / "OpenCvSharp.Extensions.dll",
    CURRENT_DIR / "wk_opencvsharp.dll"
]

for dll in dlls:
    if dll.exists():
        clr.AddReferenceToFileAndPath(str(dll))

import OpenCvSharp
from OpenCvSharp import Cv2, Mat, Vec3b
from wk_opencvsharp import Cv2Util, LockBitmap
from System.Drawing import Bitmap
from System.Drawing.Imaging import PixelFormat

ToBitmap = OpenCvSharp.Extensions.BitmapConverter.ToBitmap
ToMat = OpenCvSharp.Extensions.BitmapConverter.ToMat
Memcopy = Cv2Util.Memcopy
GrayscalePalette = Cv2Util.GrayscalePalette
DoEvents = Cv2Util.DoEvents
