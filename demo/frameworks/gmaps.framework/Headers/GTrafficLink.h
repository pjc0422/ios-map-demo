//
//  GTrafficLink.h
//  gmaps
//
//  Created by KT on 2020/02/17.
//  Copyright © 2020 kt. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>


@interface GTrafficLink : NSObject
@property (readonly) UIColor* color;
@property (readonly) NSArray* linkShape;
@property (readonly) NSNumber* linkId;

-(instancetype) init:(NSArray*) linkShape color:(UIColor*) color;
-(instancetype) init:(NSArray*) linkShape color:(UIColor*) color linkId:(NSNumber*) linkId;


@end


