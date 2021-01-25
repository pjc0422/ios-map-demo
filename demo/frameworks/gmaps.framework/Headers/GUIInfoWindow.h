/*
 * Copyright (c) 2015 kt corp. All rights reserved.
 *
 * This is a proprietary software of kt corp, and you may not use this file
 * except in compliance with license agreement with kt corp. Any redistribution
 * or use of this software, with or without modification shall be strictly
 * prohibited without prior written approval of kt corp, and the copyright
 * notice above does not evidence any actual or intended publication of such
 * software.
 */

#import <UIKit/UIKit.h>

@interface GUIInfoWindow : UIView {
    UIImageView *background;
    UIImageView *arrow;
    UILabel *titleLabel;
    UILabel *subTitleLabel;
}

- (id)initWithFrame:(CGRect)frame
              title:(NSString *)title
           subTitle:(NSString *)subTitle;
@end
