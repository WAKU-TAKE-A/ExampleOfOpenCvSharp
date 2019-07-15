# Example of "OpenCvSharp" (for 64bit)

Example of "OpenCvSharp" in Ironpython script.  
The library of C# is used. Requires VisualStudio 2017 or higher.

## File

* "wk_opencvsharp.sln"
  * To install "OpenCvSharp".
  * To generate "opencvsharp" package.

## Notes on execution

* Open "wk_opencvsharp.sln".
* Install "OpenCvSharp" with NuGet.
  * Checked with version 4.0.0.20181129.
  * If you want to use another version, remove the references of "OpenCvSharp.Blob.dll", "OpenCvSharp.dll", "OpenCvSharp.Extensions.dll" and "OpenCvSharp.UserInterface.dll" , refer to them again.
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
* `Mat.DataPointer` can not be used on IronPython. Use `Cv2Util.GetIntPtrFromMat(Mat)`.
* To access the elements of Mat, use `Cv2Util.GetByteValue(Mat mat, int index)`.
* To change to an element of Mat, please use `Cv2Util.SetByteValue(Mat mat, int index, Byte value)`.
* `Cv2Util.Memcopy(IntPtr src, IntPtr dst, int size)` is memcpy. Be aware that src and dst are in reverse order of Memcpy.
