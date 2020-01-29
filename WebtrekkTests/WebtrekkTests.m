//
//  WebtrekkTests.m
//  WebtrekkTests
//
//  Created by Stefan Stevanovic on 1/3/20.
//  Copyright © 2020 Stefan Stevanovic. All rights reserved.
//

#import <XCTest/XCTest.h>
#import <Webrekk/PersistanceLayer/WebtrekkDefaultConfig.h>

@interface WebtrekkTests : XCTestCase

@property WebtrekkDefaultConfig *configToTest;

@end

@implementation WebtrekkTests

- (void)setUp {
    // Put setup code here. This method is called before the invocation of each test method in the class.
    _configToTest = [[WebtrekkDefaultConfig alloc] init];
}

- (void)tearDown {
    // Put teardown code here. This method is called after the invocation of each test method in the class.
}

- (void)testWebtrekkInitWithDictionary {
    // This is an example of a functional test case.
    // Use XCTAssert and related functions to verify your tests produce the correct results.
}

- (void)testPerformanceExample {
    // This is an example of a performance test case.
    [self measureBlock:^{
        // Put the code you want to measure the time of here.
    }];
}

@end
