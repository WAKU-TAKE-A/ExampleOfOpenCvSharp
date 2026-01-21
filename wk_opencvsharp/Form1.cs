using System;
using System.Drawing;
using System.Windows.Forms;
using OpenCvSharp;

namespace wk_opencvsharp
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            // コンストラクタは初期化のみに留めます
            InitializeComponent();
        }

        /// <summary>
        /// 画面ロード時に実行されるイベント。
        /// ここであればデザイナーをクラッシュさせずに OpenCV の処理を実行できます。
        /// </summary>
        protected override void OnLoad(EventArgs e)
        {
            base.OnLoad(e);

            // デザインモード（Visual Studio 上での表示時）は実行しない
            if (this.DesignMode || System.ComponentModel.LicenseManager.UsageMode == System.ComponentModel.LicenseUsageMode.Designtime)
            {
                return;
            }

            try
            {
                RunImageProcessing();
            }
            catch (Exception ex)
            {
                MessageBox.Show($"Error: {ex.Message}");
            }
        }

        private void RunImageProcessing()
        {
            // 画像の読み込み
            using Mat src = Cv2.ImRead("./examples/lena.jpg");
            if (src.Empty())
            {
                MessageBox.Show("Image 'lena.jpg' not found in output directory.");
                return;
            }

            // 処理後画像の準備
            using Mat dst = new Mat(new OpenCvSharp.Size(src.Cols, src.Rows), src.Type());

            // Sobelフィルタの適用
            Cv2.Sobel(src, dst, src.Depth(), 1, 1);

            // 表示
            Cv2.ImShow("Original Source", src);
            Cv2.ImShow("Processed Destination", dst);

            // キー入力待機
            Cv2.WaitKey(0);

            Application.Exit();
        }
    }
}
