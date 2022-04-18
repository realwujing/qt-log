## Doxygen生成接口文档
1. 安装环境
```bash
sudo apt-get install doxygen graphviz
```
2. 生成配置文件
```bash
Doxygen –g
```
3. 打开Doxyfile，递归遍历当前目录的子目录，寻找被文档化的程序源文件，修改如下：
```bash
sed -i 's/RECURSIVE.*= NO/RECURSIVE = YES/' Doxyfile
```

4. OUTPUT_DIRECTORY       = 替换为 OUTPUT_DIRECTORY       = build/doxygen
```bash
sed -i 's/OUTPUT_DIRECTORY.*=/OUTPUT_DIRECTORY = build\/doxygen/' Doxyfile
```

5. 文档生成
```bash
doxygen Doxyfile
```

6. 简化上述流程
```bash
./doxygen.sh
```

7. More
+ [ubuntu 下使用doxygen为C/C++工程生成pdf版的API](https://blog.csdn.net/jinking01/article/details/102809414)
+ [linux下的doxygen的使用](https://blog.csdn.net/yunjingguang/article/details/28266115)
+ [Doxygen快速入门](https://zhuanlan.zhihu.com/p/100223113)

## Code Coverage Test

1. 安装环境

```bash
sudo apt install gcovr
```

1. cmake添加编译参数，用来生成coverage文件
   add --coverage in CMakeLists.txt

```bash
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} --coverage")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage")
```

3. 一键生成代码行覆盖率可视化报告
   use gcov、lcov to generate convert html report, make shure at the top level of the project

```bash
./code_coverage.sh
```

4. More
+ [C++语言的单元测试与代码覆盖率](https://paul.pub/gtest-and-coverage/)
+ [Gtest集成Lcov代码覆盖率测试](https://www.codeleading.com/article/93614362313/)
