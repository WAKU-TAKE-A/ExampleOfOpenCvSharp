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

void wk_util::Cv2Util::GrayscalePalette(Bitmap^ bmp)
{
	ColorPalette^ pal = bmp->Palette;

	for (int i = 0; i < 256; i++)
	{
		pal->Entries[i] = Color::FromArgb(i, i, i);
	}		
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

wk_util::LockBitmap::LockBitmap(System::Drawing::Bitmap^ ini)
{
	if (ini == nullptr)
		return;

	if (_src != nullptr)
		this->Free();

	_src = ini;
	_w = _src->Width;
	_h = _src->Height;
	_pf = _src->PixelFormat;

	System::Drawing::Rectangle rect = System::Drawing::Rectangle(0, 0, _w, _h);
	_srcData = _src->LockBits(rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, _pf);

	_st = _srcData->Stride;
	_ip = _srcData->Scan0;
}

void wk_util::LockBitmap::Free()
{
	if (_src == nullptr)
		return;

	_src->UnlockBits(_srcData);

	_src = nullptr;
	_w = _h = _st = 0;
	_ip = IntPtr::Zero;
}

