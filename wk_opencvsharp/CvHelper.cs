using System;
using System.Drawing;
using System.Drawing.Imaging;
using System.Runtime.InteropServices;
using System.Windows.Forms;

namespace wk_opencvsharp
{
    public static class Cv2Util
    {
        private const int GRAYSCALE_PALETTE_SIZE = 256;

        public static void Memcopy(IntPtr source, IntPtr destination, int length)
        {
            unsafe
            {
                Buffer.MemoryCopy(source.ToPointer(), destination.ToPointer(), (long)length, (long)length);
            }
        }

        public static void GrayscalePalette(Bitmap bitmap)
        {
            ColorPalette palette = bitmap.Palette;
            for (int i = 0; i < GRAYSCALE_PALETTE_SIZE; i++)
            {
                palette.Entries[i] = Color.FromArgb(i, i, i);
            }
            bitmap.Palette = palette;
        }

        public static void DoEvents()
        {
            Application.DoEvents();
        }
    }

    public class LockBitmap : IDisposable
    {
        private readonly Bitmap _bitmap;
        private BitmapData? _bitmapData;
        private bool _isDisposed;

        public LockBitmap(Bitmap bitmap)
        {
            _bitmap = bitmap ?? throw new ArgumentNullException(nameof(bitmap));
            Lock();
        }

        private void Lock()
        {
            Rectangle rect = new Rectangle(0, 0, _bitmap.Width, _bitmap.Height);
            _bitmapData = _bitmap.LockBits(rect, ImageLockMode.ReadWrite, _bitmap.PixelFormat);
        }

        public IntPtr Ptr => _bitmapData?.Scan0 ?? IntPtr.Zero;

        public void Free()
        {
            if (_bitmapData != null)
            {
                _bitmap.UnlockBits(_bitmapData);
                _bitmapData = null;
            }
        }

        public void Dispose()
        {
            if (!_isDisposed)
            {
                Free();
                _isDisposed = true;
                GC.SuppressFinalize(this);
            }
        }
    }
}
