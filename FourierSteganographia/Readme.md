# Fourier Steganographia

傅里叶变换频域隐写

## 要点

- 频域隐写时，必须保证隐写后频谱仍然对称，这样逆变换后不会出现虚部，从而能正常显示图片
- 由于灰度图片只能存储为整数，逆变换后会出现浮点数，不可避免的有误差。要保证水印不能太小。

## Requirements

- opencv-python
- numpy 

## 使用

1. 将src.png(表面图片)和flag.png(隐写)准备好,flag.png对角线长度应小于src.png的一半,不宜太小。
2. 运行encode.py获得隐写后的图片
3. 运行decode.py获得flag

## 其他

- 未经测试

![Demo](./example/question.png)
