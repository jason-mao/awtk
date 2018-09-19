
/**
 * File:   awtk_config.h
 * Author: AWTK Develop Team
 * Brief:  config
 *
 * Copyright (c) 2018 - 2018  Guangzhou ZHIYUAN Electronics Co.,Ltd.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * License file for more details.
 *
 */

/**
 * History:
 * ================================================================
 * 2018-09-12 Li XianJing <xianjimli@hotmail.com> created
 *
 */

#ifndef AWTK_CONFIG_H
#define AWTK_CONFIG_H

/**
 * 嵌入式系统有自己的main函数时，请定义本宏。
 *
 * #define USE_GUI_MAIN 1
 */

/**
 * 如果需要支持预先解码的图片，请定义本宏。一般只在RAM极小时，才启用本宏。
 * #define WITH_BITMAP_FONT 1
 */

/**
 * 如果支持png/jpeg图片，请定义本宏
 *
 * #define WITH_STB_IMAGE 1
 */

/**
 * 如果支持Truetype字体，请定义本宏
 *
 * #define WITH_STB_FONT 1
 */

/**
 * 如果支持从文件系统加载资源，请定义本宏
 *
 * #define WITH_FS_RES 1
 */

/**
 * 如果定义本宏，使用标准的UNICODE换行算法，除非资源极为有限，请定义本宏。
 *
 * #define WITH_UNICODE_BREAK 1
 */

/**
 * 如果定义本宏，将图片解码成BGRA8888格式，否则解码成RGBA8888的格式。
 *
 * #define WITH_BITMAP_BGRA 1
 */

/**
 * 如果定义本宏，将不透明的PNG图片解码成RGB565格式，建议定义。
 *
 * #define WITH_BITMAP_RGB565 1
 */

/**
 * 如果不需输入法，请定义本宏
 *
 * #define WITH_NULL_IM 1
 */

/**
 * 如果支持极速模式，请定义本宏。极速模式不支持控件透明半透明效果，只有在CPU配置极低时启用。
 *
 * #define USE_FAST_MODE 1
 */

/**
 * 如果FLASH空间较小，不足以放大字体文件时，请定义本宏
 *
 * #define WITH_MINI_FONT 1
 */

/**
 * 如果有标准的malloc/free/calloc等函数，请定义本宏
 *
 * #define HAS_STD_MALLOC 1
 */

/**
 * 如果有优化版本的memcpy函数，请定义本宏
 *
 * #define HAS_FAST_MEMCPY 1
 */

/**
 * 如果启用STM32 G2D硬件加速，请定义本宏
 *
 * #define WITH_STM32_G2D 1
 */

/**
 * 如果启用NXP PXP硬件加速，请定义本宏
 *
 * #define WITH_PXP_G2D 1
 */

#endif /*AWTK_CONFIG_H*/