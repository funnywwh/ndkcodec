# ndk配置
1. 下载android-ndk-r14b-windows-x86_64
2. 安装到d:\ndkroot21
3. 运行NDK下的build\tools\make_standalone_toolchain.py
```
make_standalone_toolchain.py --api 21 --force --unified-headers --install-dir d:\ndkroot21 --arch arm
```
4. 设置liteIde的配置，
```
GOOS=android
CGO_ENABLED=1
GOARCH=arm
GOARM=6
NDK_ROOT=d:/ndkroot21
PATH=%NDK_ROOT%/bin;%PATH%
CC=arm-linux-androideabi-gcc.exe
CXX=arm-linux-androideabi-g++.exe
CXXFLAGS="-lstdc++"
```
5. 编译
```
go build
```

## 目前只实现的Encoder
## 用法
```go
encoder := NewNdkCodec()
encoder.Start(true,1280,720,30,1000000)
encoder.QueueInputBuffer(framedata)
encodeData,err := encoder.DequeueOutputBuffer()
encoder.Stop()
encoder.Delete()
```