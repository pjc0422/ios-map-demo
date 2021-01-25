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
 * @class GPolygon
 *  GPolygon 는 지도에 폴리곤을 그리기 위한 클래스로 4개 이상의 연속된 점들로 구성되어있다. GOverlay 구현 클래스
 */
@interface GPolygon : GOverlay

/**
 *  선의 두께. 지정하지 않을 경우 기본값은 1.
 * @throws NSInvalidArgumentException <code>width</code>가 1 미만인 경우
 */
@property (nonatomic, assign) int strokeWidth;

/**
 *  선의 색상. 기본값은 투명.
 */
@property (nonatomic, assign) UIColor *strokeColor;

/**
 *  선의 색상. 기본값은 투명.
 */
@property (nonatomic, assign) UIColor *fillColor;

/**
 *  선을 이루는 점의 목록. GCoord array.
 * @throws NSInvalidArgumentException <code>points</code>의 점의 갯수가 4 미만인 경우<br/>
 *                                    <code>points</code>에 GCoord 이외의 오브젝트가 포함 된 경우
 */
@property (nonatomic, copy) NSArray *points;

/**
 *  폴리곤 홀 리스트 GCoord array의 array형태
 * @throws NSInvalidArgumentException <code>hole</code>에 GCoord 이외의 오브젝트가 포함 된 경우
 */
@property (nonatomic, copy) NSArray *holes;

/**
 *  멀티 폴리곤(연속된 다각형)의 면적을 구하는 함수
 */
-(double) getArea ;

/**
 *  점의 목록을 이용하여 GPolygon 객체를 생성한다.
 * @return 생성된 GPolygon 객체
 * @throws NSInvalidArgumentException <code>points</code>의 점의 갯수가 2 미만일 경우
 *
 * @code
 * GUtmk *c1 = [[GUtmk alloc]initWithX:957590.0 y:1941834.0];
 * GUtmk *c2 = [[GUtmk alloc]initWithX:959640.0 y:1943858.0];
 * GUtmk *c3 = [[GUtmk alloc]initWithX:959540.0 y:1943658.0];
 * NSArray *points = [NSArray arrayWithObjects: c1, c2, c3, nil];
 * GPolygon *polygon = [GPolygon polygonWithPoints:points];
 * [mapView addOverlay:polygon];
 * @endcode
 */
+ (instancetype)polygonWithPoints:(NSArray *)points;

/**
 *  생성옵션을 이용한 GPolygon 생성자
 * @param options GPolygon 생성 옵션
 *        Key       |   valueType
 * ---------------- | -------------
 * visible          |   (bool)
 * strokeWidth      |   (int)
 * strokeColor      |   (NSString *UIColor *)
 * fillColor        |   (NSString *UIColor *)
 * points           |   (NSArray *)
 * @return 생성된 GPolygon 객체
 * @throws NSInvalidArgumentException <code>points</code>의 점의 갯수가 4 미만일 경우<br/>
 *                                    <code>points</code>에 GCoord 이외의 오브젝트가 포함 된 경우<br/>
 *                                    <code>strokeWidth</code>가 1 미만일 경우
 *
 * @code
 * GUtmk *c1 = [[GUtmk alloc]initWithX:957590.0 y:1941834.0];
 * GUtmk *c2 = [[GUtmk alloc]initWithX:959640.0 y:1943858.0];
 * GUtmk *c3 = [[GUtmk alloc]initWithX:959540.0 y:1943658.0];
 * GUtmk *c4 = [[GUtmk alloc]initWithX:958540.0 y:1943658.0];
 * NSArray *points = [NSArray arrayWithObjects: c1, c2, c3, c4, nil];
 * NSDictionary *options = @{
 *                      @"strokeColor":[UIColor redColor],
 *                           @"points":points
 *                         };
 * GPolygon *polygon = [GPolygon polygonWithOptions:options];
 * [mapView addOverlay:polygon];
 * @endcode
 */
+ (instancetype)polygonWithOptions:(NSDictionary *)options;

@end
