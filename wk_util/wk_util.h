// wk_util.h

#pragma once

using namespace System;
using namespace OpenCvSharp;

namespace wk_util {

	public ref class Cv2Util
	{
	public:
		static IntPtr GetIntPtrFromMat(Mat^ mat);
		static void Memcopy(IntPtr src, IntPtr dst, int num);
		static Byte GetByteValue(Mat^ mat, int index);
		static void SetByteValue(Mat^ mat, int index, Byte value);
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
	};
}
