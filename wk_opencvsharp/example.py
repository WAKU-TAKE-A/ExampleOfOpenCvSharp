# -*- coding: utf-8 -*-

"""
Example of OpenCvSharp (for 64bit)
"""

from opencvsharp import *

def RunExample():
    # Read an image from a file.
    fn = path.join(IPY_OPENCVSHARP, "lena.jpg")
    src = Cv2.ImRead(fn, OpenCvSharp.ImreadModes.Color)
    # Prepare the processed image.
    size = OpenCvSharp.Size(252, 256)
    dst = OpenCvSharp.Mat(size, OpenCvSharp.MatType.CV_8UC3)
    # Run Sobel filter.
    Cv2.Sobel(src, dst, src.Depth(), 1, 1)
    # Display the original image.
    Cv2.ImShow("src", src)
    # Display the processed image.
    Cv2.ImShow("dst", dst)
    # Wait for key input.
    Cv2.WaitKey(0)
    # Dispose
    src.Dispose()
    dst.Dispose()

if __name__ == '__main__':
    RunExample()


