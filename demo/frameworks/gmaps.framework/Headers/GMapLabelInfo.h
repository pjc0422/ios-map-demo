//
//  GMapLabelInfo.h
//  gmaps
//
//  Created by KT on 2020/06/17.
//  Copyright © 2020 kt. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol GCoord;

@interface GMapLabelInfo : NSObject

@property (nonatomic, copy, readonly) NSString *labelName;
@property (nonatomic, copy, readonly) NSString *labelId;
@property (nonatomic, copy, readonly) id<GCoord> position;
@property (nonatomic, copy, readonly) NSNumber *categoryId;

+ (GMapLabelInfo*) name:(NSString*) labelName position:(id<GCoord>) position labelId:(NSString*) labelId categoryId:(int) catId;
@end
