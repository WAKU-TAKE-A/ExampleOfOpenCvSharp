// wk_util.h

#pragma once

using namespace System;
using namespace OpenCvSharp;
using namespace System::Drawing;
using namespace System::Drawing::Imaging;
using namespace System::Windows::Threading;

namespace wk_util_opencvsharp
{
	public ref class Cv2Util
	{
	public:
		static void Memcopy(IntPtr src, IntPtr dst, int num);
		static Byte GetByteValue(Mat^ mat, int index);
		static void SetByteValue(Mat^ mat, int index, Byte value);
		static void GrayscalePalette(Bitmap^ bmp);
		static int SizeOfSbyte();
		static int SizeOfByte();
		static int SizeOfShort();
		static int SizeOfUshort();
		static int SizeOfInt();
		static int SizeOfUint();
		static int SizeOfLong();
		static int SizeOfUlong();
		static int SizeOfChar();
		static int SizeOfFloat();
		static int SizeOfDouble();
		static int SizeOfDecimal();
		static int SizeOfBool();
		static void DoEvents();
	};

	public ref class LockBitmap
	{
	private:
		System::Drawing::Bitmap^ _src;
		System::Drawing::Imaging::BitmapData^ _srcData;
		System::Drawing::Imaging::PixelFormat _pf;
		int _w;
		int _h;
		int _st;
		IntPtr _ip;

	public:
		LockBitmap(System::Drawing::Bitmap^ ini);

		void Free();

		property IntPtr Ptr
		{
			IntPtr get()
			{
				return _ip;
			}
		}
	};
}
