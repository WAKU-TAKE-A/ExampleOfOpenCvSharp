// これは メイン DLL ファイルです。

#include "stdafx.h"
#include "wk_util.h"
#include <string.h>

IntPtr WkUtil::Cv2Util::GetIntPtrFromMat(Mat^ mat)
{
	return (IntPtr)mat->DataPointer;
}

void WkUtil::Cv2Util::Memcopy(IntPtr src, IntPtr dst, int num)
{
	memcpy((void*)dst, (void*)src, num);
}

Byte WkUtil::Cv2Util::GetByteValue(Mat^ mat, int index)
{
	return *(mat->DataPointer + index);
}

void WkUtil::Cv2Util::SetByteValue(Mat^ mat, int index, Byte value)
{
	*(mat->DataPointer + index) = value;
}

void WkUtil::Cv2Util::GrayscalePalette(Bitmap^ bmp)
{
	ColorPalette^ pal = bmp->Palette;

	for (int i = 0; i < 256; i++)
	{
		pal->Entries[i] = Color::FromArgb(i, i, i);
	}		
}

int WkUtil::Cv2Util::SizeOfSbyte()
{
	return sizeof(System::SByte);
}

int WkUtil::Cv2Util::SizeOfByte()
{
	return sizeof(System::Byte);
}

int WkUtil::Cv2Util::SizeOfShort()
{
	return sizeof(System::Int16);
}

int WkUtil::Cv2Util::SizeOfUshort()
{
	return sizeof(System::UInt16);
}

int WkUtil::Cv2Util::SizeOfInt()
{
	return sizeof(System::Int32);
}

int WkUtil::Cv2Util::SizeOfUint()
{
	return sizeof(System::UInt32);
}

int WkUtil::Cv2Util::SizeOfLong()
{
	return sizeof(System::Int64);
}

int WkUtil::Cv2Util::SizeOfUlong()
{
	return sizeof(System::UInt64);
}

int WkUtil::Cv2Util::SizeOfChar()
{
	return sizeof(System::Char);
}

int WkUtil::Cv2Util::SizeOfFloat()
{
	return sizeof(System::Single);
}

int WkUtil::Cv2Util::SizeOfDouble()
{
	return sizeof(System::Double);
}

int WkUtil::Cv2Util::SizeOfDecimal()
{
	return sizeof(System::Decimal);
}

int WkUtil::Cv2Util::SizeOfBool()
{
	return sizeof(System::Boolean);
}

System::Object^ ExitFrames(System::Object^ obj)
{
	DispatcherFrame^ dis = (DispatcherFrame^)obj;
	dis->Continue = false;
	return nullptr;
}

void WkUtil::Cv2Util::DoEvents()
{
	DispatcherFrame^ frame = gcnew DispatcherFrame();
	DispatcherOperationCallback^ callback = gcnew DispatcherOperationCallback(ExitFrames);
	Dispatcher^ dis_cur = Dispatcher::CurrentDispatcher;
	dis_cur->BeginInvoke(DispatcherPriority::Background, callback, frame);
	Dispatcher::PushFrame(frame);
}

WkUtil::LockBitmap::LockBitmap(System::Drawing::Bitmap^ ini)
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

void WkUtil::LockBitmap::Free()
{
	if (_src == nullptr)
		return;

	_src->UnlockBits(_srcData);

	_src = nullptr;
	_w = _h = _st = 0;
	_ip = IntPtr::Zero;
}

