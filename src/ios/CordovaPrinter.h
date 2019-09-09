//
//  CordovaPrinter.h
//  HelloCordova
//
//  Created by JobSoltero on 09/09/2019.
//
//

#import <Cordova/CDVPlugin.h>

@interface CordovaPrinter : CDVPlugin
- (void) cordovaPrint :(CDVInvokedUrlCommand *)command;
- (void) cordovaGetPrinters :(CDVInvokedUrlCommand *)command;
@end
