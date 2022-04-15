## Doxygen生成pdf接口文档

1. 安装中文latex环境

```bash
sudo apt-get install doxygen graphviz texlive-full latex-cjk-chinese* cjk-latex
```

2. 生成配置文件

```bash
Doxygen –g
```

3. 打开Doxyfile，递归遍历当前目录的子目录，寻找被文档化的程序源文件，修改如下：

```plain
RECURSIVE              = YES
```

4. 文档生成

```bash
doxygen Doxyfile
```

5.进入到latex目录

```bash
cd latex
```

6. 修改前面doxygen Doxyfile生成的latex文件：refman.tex
   将其中的:

```plain
\begin{document}
```

改为：

```plain
\usepackage{CJKutf8}
\begin{document}
\begin{CJK}{UTF8}{gbsn}
```

并将其中的:

```plain
\end{document}
```

改为：

```plain
\end{CJK}
\end{document}
```

8. 生成pdf文件

```bash
make -j
```

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
