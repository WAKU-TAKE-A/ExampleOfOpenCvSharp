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
using OpenCvSharp;
using System.Drawing.Imaging;
using wk_util_opencvsharp;

namespace wk_opencvsharp
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();

            // Read an image from a file.
            Mat src = Cv2.ImRead("lena.jpg");

            // Prepare the processed image.
            OpenCvSharp.Size size = new OpenCvSharp.Size(src.Cols, src.Rows);
            Mat dst = new Mat(size, OpenCvSharp.MatType.CV_8UC3);

            // Run Sobel filter.
            Cv2.Sobel(src, dst, src.Depth(), 1, 1);

            // Display the original image.
            Cv2.ImShow("src", src);

            // Display the processed image.
            OpenCvSharp.Cv2.ImShow("dst", dst);

            // Wait for key input.
            OpenCvSharp.Cv2.WaitKey(0);

            Environment.Exit(0);
        }
    }
}
