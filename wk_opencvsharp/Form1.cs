using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

// user add
using System.Runtime.InteropServices;
using OpenCvSharp;
using OpenCvSharp.Extensions;
using System.Drawing.Imaging;

namespace wk_opencvsharp
{
    public partial class Form1 : Form
    {
        /// <summary>
        /// OpenCvSharpのMemoryHelperが使えない時に利用してください。
        /// </summary>
        /// <param name="dst"></param>
        /// <param name="src"></param>
        /// <param name="count"></param>
        [DllImport("kernel32.dll", EntryPoint = "CopyMemory", SetLastError = false)]
        public static extern void CopyMemory(IntPtr dst, IntPtr src, uint count);

        public Form1()
        {
            InitializeComponent();

            // Read an image from a file.
            Mat src = Cv2.ImRead("lena.jpg");

            // Prepare the processed image.
            OpenCvSharp.Size size = new OpenCvSharp.Size(src.Cols, src.Rows);
            Mat dst = new Mat(size, MatType.CV_8UC3);

            // Run Sobel filter.
            Cv2.Sobel(src, dst, src.Depth(), 1, 1);

            // Display the original image.
            Cv2.ImShow("src", src);

            // Display the processed image.
            Cv2.ImShow("dst", dst);           

            // Wait for key input.
            Cv2.WaitKey(0);

            // Dispose
            src.Dispose();
            dst.Dispose();

            Environment.Exit(0);
        }
    }
}
