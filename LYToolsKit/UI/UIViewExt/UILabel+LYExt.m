//
//  UILabel+LYExt.m
//  Tools
//
//  Created by 似水灵修 on 16/3/11.
//  Copyright © 2016年 似水灵修. All rights reserved.
//

#import "UILabel+LYExt.h"

@implementation UILabel (LYExt)

+ (instancetype)ly_labelWithTitle:(NSString *)title font:(UIFont *)font titleColor:(UIColor *)titleColor {
    UILabel *label = [[self alloc] init];
    label.textColor = titleColor;
    label.font = font;
    label.text = title;
    return label;
}

@end
