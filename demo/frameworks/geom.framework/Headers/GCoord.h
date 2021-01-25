//
//  GCoord.h
//  geom
//
//  Created by gisdev on 2015. 1. 29..
//  Copyright (c) 2015년 kt. All rights reserved.
//

#import <Foundation/Foundation.h>

@class CRS;
@class ProjCoordinate;

/**
  지도상의 특정 위치(좌표)를 나타내는 프로토콜.
 반드시 GCoord 를 구현하는 클래스(예. GUtmk, GLatLng 등) 를 이용하여 원하는 좌표계로 변환하여 사용해야 한다.
 */
@protocol GCoord<NSObject>

@required

- (CRS *)getCRS;

- (ProjCoordinate *)toProjCoordinate;

@end
