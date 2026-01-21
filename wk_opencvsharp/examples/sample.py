# -*- coding: utf-8 -*-
from opencvsharp import *
from pathlib import Path

CURRENT_DIR = Path(__file__).resolve().parent

def run():
    image_path = CURRENT_DIR / "lena.jpg"
    src = Cv2.ImRead(str(image_path))
    if src.Empty():
        print("Image not found.")
        return
        
    dst = Mat()
    Cv2.Sobel(src, dst, src.Depth(), 1, 1)
    Cv2.ImShow("example.py - Sobel", dst)
    Cv2.WaitKey(0)
    
    src.Dispose()
    dst.Dispose()

if __name__ == '__main__':
    run()
