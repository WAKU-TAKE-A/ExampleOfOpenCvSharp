// これは メイン DLL ファイルです。

#include "stdafx.h"
#include "wk_util.h"
#include <string.h>

IntPtr wk_util::Cv2Util::GetIntPtrFromMat(Mat^ mat)
{
	return (IntPtr)mat->DataPointer;
}

void wk_util::Cv2Util::Memcopy(IntPtr src, IntPtr dst, int num)
{
	memcpy((void*)dst, (void*)src, num);
}

Byte wk_util::Cv2Util::GetByteValue(Mat^ mat, int index)
{
	return *(mat->DataPointer + index);
}

void wk_util::Cv2Util::SetByteValue(Mat^ mat, int index, Byte value)
{
	*(mat->DataPointer + index) = value;
}

int wk_util::Cv2Util::SizeOfSbyte()
{
	return sizeof(System::SByte);
}

int wk_util::Cv2Util::SizeOfByte()
{
	return sizeof(System::Byte);
}

int wk_util::Cv2Util::SizeOfShort()
{
	return sizeof(System::Int16);
}

int wk_util::Cv2Util::SizeOfUshort()
{
	return sizeof(System::UInt16);
}

int wk_util::Cv2Util::SizeOfInt()
{
	return sizeof(System::Int32);
}

int wk_util::Cv2Util::SizeOfUint()
{
	return sizeof(System::UInt32);
}

int wk_util::Cv2Util::SizeOfLong()
{
	return sizeof(System::Int64);
}

int wk_util::Cv2Util::SizeOfUlong()
{
	return sizeof(System::UInt64);
}

int wk_util::Cv2Util::SizeOfChar()
{
	return sizeof(System::Char);
}

int wk_util::Cv2Util::SizeOfFloat()
{
	return sizeof(System::Single);
}

int wk_util::Cv2Util::SizeOfDouble()
{
	return sizeof(System::Double);
}

int wk_util::Cv2Util::SizeOfDecimal()
{
	return sizeof(System::Decimal);
}

int wk_util::Cv2Util::SizeOfBool()
{
	return sizeof(System::Boolean);
}

