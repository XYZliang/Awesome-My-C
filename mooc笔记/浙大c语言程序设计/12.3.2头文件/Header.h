//
//  Header.h
//  ZL's C-Project
//
//  Created by 张亮 on 2020/2/1.
//  Copyright © 2020 张亮. All rights reserved.
//
//避免重复引用:条件编译:
#ifndef Header_h
#define Header_h
int plus(int a,int b);

#endif /* Header_h */
//也被称为标准头文件结构,保证它只被引用一次
#pragma once//同样的效果,但是某些编译器不支持
int plus(int a,int b);
