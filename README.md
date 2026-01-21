# Example of "OpenCvSharp" for IronPython (.NET 8.0)

このプロジェクトは、IronPython (.NET 8.0) 環境において OpenCvSharp4 をシームレスに利用するためのパッケージ構成例および補助ライブラリです。

## 特徴
* .NET 8.0 対応: Microsoft.WindowsDesktop.App 8.0 ランタイムの最新版を自動的にパス解決します。
* 環境構築の自動化: `__init__.py` により、各種 DLL 参照やネイティブ DLL の PATH 通しを自動で実行します。
* C# 補助関数 (wk_opencvsharp.dll): Python 側で低速になりがちな処理やポインタ操作をサポートするヘルパーを提供します。

## 動作要件
* Visual Studio 2022
* .NET 8.0 SDK / Runtime
* IronPython 3.4+ (.NET 8.0 互換バージョン)
* 環境変数 IRONPYTHON_HOME: IronPython のインストールディレクトリを指すように設定してください。

## セットアップとビルド
1. wk_opencvsharp.slnx を Visual Studio 2022 で開きます。
2. NuGet パッケージ (OpenCvSharp4, OpenCvSharp4.Windows, OpenCvSharp4.Extensions) をリストアします。
3. プロジェクトをビルドします（x64 構成を推奨）。
4. 出力された内容を、IronPython の Lib フォルダ内に opencvsharp という名前のディレクトリとして配置してください。

## 使い方 (Python)
パッケージとしてインポートするだけで、OpenCvSharp の主要な機能と補助関数にアクセスできます。

```python
import opencvsharp
from opencvsharp import Cv2, Mat, ToBitmap

# 画像の読み込み
src = Cv2.ImRead("lena.jpg")
if not src.Empty():
    # OpenCVの処理
    dst = Mat()
    Cv2.Sobel(src, dst, src.Depth(), 1, 1)
    
    # 補助関数を使用したBitmap変換
    bmp = ToBitmap(dst)
    
    Cv2.ImShow("Sobel Result", dst)
    Cv2.WaitKey(0)
```

## 提供される補助機能
C# 側で実装されている以下の機能が opencvsharp モジュールから直接利用可能です。

* Memcopy(IntPtr src, IntPtr dst, int size): Buffer.MemoryCopy を使用した高速なメモリ転送。引数の順序が標準の memcpy とは逆（Source, Destination）であることに注意してください。
* LockBitmap クラス: Bitmap のポインタ操作を安全に行うためのラッパーです。Python の with 文（IDisposable）に対応しています。
* GrayscalePalette(Bitmap bitmap): 8bit グレースケール画像用のカラーパレットを高速に適用します。
* DoEvents(): WinForms の Application.DoEvents() を呼び出し、処理中の画面更新を維持します。
