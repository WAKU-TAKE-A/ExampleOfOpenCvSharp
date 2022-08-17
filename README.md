# Example of "OpenCvSharp" (for 64bit)

Example of "OpenCvSharp" in Ironpython script.  
The library of C# is used. Requires VisualStudio 2022.

## Notes on execution

* Open "wk_opencvsharp.sln".
* Install "OpenCvSharp4.Windows" with NuGet.
* Install "OpenCvSharp4.Extensions" with NuGet.
* Build.
* Copy the "x64/debug/opencvsharp" or "x64/release/opencvsharp" folder to IronPython's "Lib" folder.
* Environment variable "IRONPYTHON_HOME" is required. It is the installation location of IronPython.
* "example.py" and "example.exe" are example program.

```
import opencvsharp
import example
example.RunExample()
```

## about wk_util_opencvsharp.dll
* "wk_util_opencvsharp.dll" is C# functions.
* `Cv2Util.Memcopy(IntPtr src, IntPtr dst, int size)` is memcpy. Be aware that src and dst are in reverse order of Memcpy.
