# Example of OpenCvSharp (for 64bit)

Example of OpenCvSharp in Ironpython script.  
The library of C# is used.

## File

* `wk_opencvsharp.sln`
  * To install OpenCvSharp.
  * To generate `opencvsharp` package.

## Notes on execution

* Open `wk_opencvsharp.sln`.
* Install OpenCvSharp with NuGet.
* Build.
* Copy the `x64/debug/opencvsharp` or `x64/release/opencvsharp` folder to IronPython's `Lib` folder.
* What is needed is only the `__init__.py`, `dll` folder, `OpenCvSharp.Blob.dll`, `OpenCvSharp.dll`, `OpenCvSharp.Extensions.dll`, `OpenCvSharp.UserInterface.dll` and `wk_util.dll`.
* `example.py` and `example.exe` are example program.

## about wk_util.dll
* Cv2Util in the dll has C# functions.
* Mat.DataPointer can not be used on IronPython. Use Cv2Util.GetIntPtrFromMat(Mat).
* To access the elements of Mat, use Cv2Util.GetByteValue(Mat mat, int index).
* To change to an element of Mat, please use Cv2Util.SetByteValue(Mat mat, int index).
* Cv2Util.Memcopy(IntPtr src, IntPtr dst, int size) is memcpy. Be aware that src and dst are in reverse order of Memcpy.