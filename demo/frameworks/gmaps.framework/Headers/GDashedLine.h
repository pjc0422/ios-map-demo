/*
 * Copyright (c) 2014 kt corp. All rights reserved.
 *
 * This is a proprietary software of kt corp, and you may not use this file
 * except in compliance with license agreement with kt corp. Any redistribution
 * or use of this software, with or without modification shall be strictly
 * prohibited without prior written approval of kt corp, and the copyright
 * notice above does not evidence any actual or intended publication of such
 * software.
 */
#import <UIKit/UIKit.h>

#import "GOverlay.h"
@protocol GCoord;

/**
 * @class GDashedLine
 *  GDashedLine 은 지도에 점선을 그리기 위한 클래스이며 2개 이상의 연속된 점들로 구성되어있다. GOverlay 구현 클래스
 */
@interface GDashedLine : GOverlay

/**
 *  점선의 두께. 지정하지 않을 경우 기본값은 1.
 * @throws NSInvalidArgumentException <code>width</code>가 1 미만일 경우 NSInvalidArgumentException 발생
 */
@property (nonatomic, assign) int width;

/**
 *  점선의 간격. 지정하지 않을 경우 기본값은 1.
 * @throws NSInvalidArgumentException <code>interval</code>이 1 미만일 경우 NSInvalidArgumentException 발생
 */
@property (nonatomic, assign) int interval;

/**
 *  선의 색상. 기본값은 Black.
 */
@property (nonatomic, assign) UIColor *color;

/**
 *  선을 이루는 점의 목록. GCoord array.
 * @throws NSInvalidArgumentException <code>points</code>의 점의 갯수가 2 미만인 경우<br/>
 *                                    <code>points</code>에 GCoord 이외의 오브젝트가 포함 된 경우
 */
@property (nonatomic, copy) NSArray *points;

/**
 *  점의 목록을 이용하여 GDashedLine 객체를 생성한다.
 * @return 생성된 GDashedLine 객체
 * @throws NSInvalidArgumentException <code>points</code>의 점의 갯수가 2 미만인 경우<br/>
 *                                    <code>points</code>에 GCoord 이외의 오브젝트가 포함 된 경우
 *
 * @code
 * GUtmk *c1 = [[GUtmk alloc]initWithX:957590.0 y:1941834.0];
 * GUtmk *c2 = [[GUtmk alloc]initWithX:959640.0 y:1943858.0];
 * GUtmk *c3 = [[GUtmk alloc]initWithX:959540.0 y:1943658.0];
 * NSArray *points = [NSArray arrayWithObjects: c1, c2, c3, nil];
 * GDashedLine *dashedLine = [GDashedLine dashedLineWithPoints:points];
 * [mapView addOverlay:dashedLine];
 * @endcode
 */
+ (instancetype)dashedLineWithPoints:(NSArray *)points;

/**
 *  생성옵션을 이용한 GDashedLine 생성자
 * @param options GDashedLine 생성 옵션
 *        Key       |   valueType
 * ---------------- | -------------
 * visible          |   (bool)
 * width            |   (int)
 * color            |   (NSString *UIColor *)
 * points           |   (NSArray *)
 * interval         |   (int)
 * @return 생성된 GDashedLine 객체
 * @throws NSInvalidArgumentException <code>points</code>의 점의 갯수가 2 미만인 경우 <br/>
 *                                    <code>points</code>에 GCoord 이외의 오브젝트가 포함 된 경우<br/>
 *                                    <code>width</code>가 1 미만인 경우<br/>
 *                                    <code>interval</code>이 1 미만인 경우
 *
 * @code
 * GUtmk *c1 = [[GUtmk alloc]initWithX:957590.0 y:1941834.0];
 * GUtmk *c2 = [[GUtmk alloc]initWithX:959640.0 y:1943858.0];
 * GUtmk *c3 = [[GUtmk alloc]initWithX:959540.0 y:1943658.0];
 * NSArray *points = [NSArray arrayWithObjects: c1, c2, c3, nil];
 * NSDictionary *options = @{
 *                          @"color":[UIColor redColor],
 *                         @"points":points,
 *                       @"interval":@2
 *                         };
 * GDashedLine *dashedLine = [GDashedLine dashedLineWithOptions:options];
 * [mapView addOverlay:dashedLine];
 * @endcode
 */
+ (instancetype)dashedLineWithOptions:(NSDictionary *)options;
@end

