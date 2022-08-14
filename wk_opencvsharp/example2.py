# -*- coding: utf-8 -*-

"""
Example2 of OpenCvSharp (for 64bit)
"""

from opencvsharp import *

def RunExample():
    # Bitmap -> Mat
    fn = path.join(IPY_OPENCVSHARP, "lena.jpg")
    bmp = Bitmap(fn)
    lck = LockBitmap(bmp)
    mt = Mat(bmp.Height, bmp.Width, OpenCvSharp.MatType.CV_8UC3, lck.Ptr)
    Cv2.ImShow("Bitmap->Mat", mt)
    Cv2.WaitKey(0)
    lck.Free()
    # Mat -> Bitmap
    mt2 = Cv2.ImRead(fn, OpenCvSharp.ImreadModes.Color)
    ip_mt2 = mt2.Data
    bmp2 = Bitmap(mt2.Cols, mt2.Rows, mt2.Cols*3, PixelFormat.Format24bppRgb, ip_mt2)
    # Make sure that bmp2 refer to mt2.
    print("The pixel value of [x, y] = [1, 0].")
    print(bmp2.GetPixel(1,0))
    print("Change the pixel value of Mat.")
    Cv2Util.SetByteValue(mt2, 3, 255)
    Cv2Util.SetByteValue(mt2, 4, 255)
    Cv2Util.SetByteValue(mt2, 5, 255)
    print(bmp2.GetPixel(1,0))
    # Dispose
    mt.Dispose()
    mt2.Dispose()

if __name__ == '__main__':
    RunExample()
