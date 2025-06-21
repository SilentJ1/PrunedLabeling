# 图处理与查询项目

本项目主要用于处理图数据，通过构建索引实现高效的图查询功能。项目采用 C++ 编写，支持强连通分量（SCC）计算、索引构建和查询等操作。


# 各部分功能说明

.vscode 目录：包含 VSCode 的配置文件，用于设置文件关联、调试和编译任务。
include 目录：存放头文件，定义了图和索引的类结构。
Graph.h：定义了 Graph 类，包含图的基本操作和属性。
PrunedLabeling.h：定义了索引构建和查询的基类和派生类。
src 目录：存放源文件，实现了图处理和查询的具体功能。
PrunedLabeling.cpp：实现了索引构建和查询的具体算法。
main.cpp：项目的入口文件，负责读取图文件和查询文件，构建索引并执行查询。
Graph.cpp：实现了 Graph 类的成员函数。
output 目录：用于存放编译生成的可执行文件。
Makefile：用于自动化编译项目，支持调试和发布模式。
README.md：项目的说明文档，提供项目的详细信息和使用方法。

# 编译和运行

## 编译

项目使用 Makefile 进行编译

$ make

## 运行

编译成功后，可执行文件将生成在 output 目录下。运行程序前，请确保已经准备好图文件和查询文件。

$ ./output/main.exe

## 清理

如果需要清理编译生成的文件，可以使用以下命令：
清理 .o 文件：
make clean
清理 .o 文件和可执行文件：
make clean_all

# 配置文件说明

.vscode/settings.json：指定了多种文件类型关联为 C++ 文件，确保代码编辑器能正确识别和处理这些文件。
.vscode/launch.json：配置了 VSCode 的调试环境，指定可执行文件路径、调试器路径等信息，方便在 VSCode 中进行调试。
.vscode/tasks.json：定义了一个名为 build 的任务，使用 make 命令以调试模式编译项目，支持并行编译。

# 代码说明

Graph 类
Graph 类用于表示图，包含图的基本操作和属性，如读取图文件、计算 SCC 图、设置度值和顺序等。
PrunedLabelingBase 类及派生类?
PrunedLabelingBase 是一个抽象基类，定义了索引构建和查询的接口。RQPrunedLandmarkLabeling 和 RQPrunedPathLabeling 是其派生类，实现了具体的索引构建和查询算法。
main.cpp
项目的入口文件，负责读取图文件和查询文件，构建索引并执行查询，输出索引构建时间、索引大小和查询结果等信息。

# 注意事项

请确保在运行程序前已经安装了 g++ 编译器。
图文件和查询文件的路径需要在 main.cpp 中进行配置。
项目支持 Windows 和 Linux 平台

# 论文
Fast and scalable reachability queries on graphs by pruned labeling with landmarks and paths.
