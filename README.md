# 地理信息系统原理-四叉树管理系统

![Qt](https://img.shields.io/badge/Qt-5%2F6-green.svg) ![C++](https://img.shields.io/badge/C++-17-blue.svg) ![License](https://img.shields.io/badge/License-Educational-green.svg) ![Status](https://img.shields.io/badge/Status-Complete-success.svg)

西南交通大学《地理信息系统原理》课程设计项目，基于 Qt 实现的 GPS 数据四叉树空间索引管理系统。

## 项目简介

本项目使用 C++ 和 Qt 框架实现了四叉树（Quadtree）数据结构，用于高效管理和查询 GPS 空间数据：
- 四叉树空间索引构建
- GPS 数据点插入与存储
- 矩形区域范围查询
- 时间范围数据筛选
- 可视化界面展示

## 目录结构

```
.
├── quadtree.h/cpp           # 四叉树核心数据结构
├── common.h/cpp             # 通用工具函数
├── mainwindow.h/cpp/ui      # 主窗口界面
├── drawwidget.h/cpp         # 绘图组件
├── overlaywidget.h/cpp      # 覆盖层组件
├── mian.cpp                 # 程序入口
├── CMakeLists.txt           # CMake 构建配置
├── thepic.qrc               # Qt 资源文件
└── README.md                # 项目说明文档
```

## 功能特性

### 核心功能

**四叉树数据结构**  
- 递归四分空间划分
- 自适应节点分裂
- 高效空间索引管理

**GPS 数据管理**  
- 支持经纬度坐标存储
- 时间戳数据记录
- 批量数据导入

**空间查询**  
- 矩形区域范围查询
- 点位精确查找
- 时间段数据筛选

**可视化界面**  
- 实时数据点绘制
- 交互式区域选择
- 查询结果可视化展示

## 使用方法

### 环境要求
- Qt 5.x 或 Qt 6.x
- C++17 或更高版本
- CMake 3.16+
- Qt Creator（推荐）

### 编译运行

```bash
# 使用 CMake 构建
mkdir build
cd build
cmake ..
cmake --build .

# 或使用 Qt Creator
# 打开 CMakeLists.txt，直接运行项目
```

### 操作说明

1. **加载数据**：点击"加载数据"按钮导入 GPS 数据文件
2. **构建四叉树**：系统自动将数据插入四叉树索引
3. **区域查询**：在可视化界面框选矩形区域进行查询
4. **时间筛选**：设置时间范围过滤数据点
5. **结果展示**：查询结果在界面中高亮显示

## 技术说明

**四叉树索引原理**  
将二维空间递归划分为四个象限（左上、左下、右上、右下），根据数据点分布动态构建树结构，实现 O(log n) 级别的查询效率。

**空间数据结构**  
- `GPSdata`：存储 GPS 数据点（ID、时间、经纬度）
- `Rectangle`：定义矩形空间范围
- `QuadNode`：四叉树节点，包含子节点和数据列表

**可视化技术**  
使用 Qt Graphics Framework 实现数据点绘制和交互式查询界面。

**项目文档**

详细的设计文档和实验报告请参见：
- `地理信息系统原理-六组-四叉树管理系统.pdf`

## 致谢

- 原始项目：[firmmabu/Quadtree](https://github.com/firmmabu/Quadtree)
- 开发工具：Qt Creator

## 许可

本项目仅用于教学和学习目的。
