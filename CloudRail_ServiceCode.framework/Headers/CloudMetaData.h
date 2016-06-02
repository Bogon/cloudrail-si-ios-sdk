//
//  CloudMetaData.h
//  CloudRail_ServiceCode
//
//  Created by Felipe Cesar on 02/05/16.
//  Copyright © 2016 CloudRail. All rights reserved.
//

#import "SandboxObject.h"

@interface CloudMetaData : SandboxObject

@property (nonatomic) NSString * path;

@property (nonatomic) NSString * name;

@property (nonatomic) NSNumber * size;

@property (nonatomic) NSNumber * folder;

@end
