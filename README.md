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