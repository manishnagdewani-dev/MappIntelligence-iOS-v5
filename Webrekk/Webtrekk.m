//
//  Webrekk.m
//  Webrekk
//
//  Created by Stefan Stevanovic on 1/3/20.
//  Copyright © 2020 Stefan Stevanovic. All rights reserved.
//

#import "Webtrekk.h"
#import "WebtrekkDataService.h"
#import "WebtrekkDefaultConfig.h"
#import "WebtrekkLogger.h"

@interface Webtrekk()

@property WebtrekkDataService *dataService;

@property WebtrekkDefaultConfig * configuration;

@end

@implementation Webtrekk
static Webtrekk *sharedInstance = nil;
static WebtrekkDefaultConfig * config = nil;
+(id) sharedWebtrek {
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        sharedInstance = [[self alloc] init];
    });
    return sharedInstance;
}

+(void) initWithDictionary: (NSDictionary *) dictionary {
    config = [[WebtrekkDefaultConfig alloc] initWithDictionary: dictionary];
}

-(id) init {
    if (!sharedInstance) {
        sharedInstance = [super init];
        _dataService = [[WebtrekkDataService alloc]init];
    }
    return sharedInstance;
}

@end
