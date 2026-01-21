# -*- coding: utf-8 -*-
from opencvsharp import *
from pathlib import Path

CURRENT_DIR = Path(__file__).resolve().parent

def run():
    image_path = CURRENT_DIR / "lena.jpg"
    src = Cv2.ImRead(str(image_path))
    bmp = ToBitmap(src)
    dst = ToMat(bmp)
    Cv2.ImShow("src -> bmp -> dst", dst)
    Cv2.WaitKey(0)   
    dst.Dispose()
    bmp.Dispose()
    src.Dispose()

if __name__ == '__main__':
    run()
