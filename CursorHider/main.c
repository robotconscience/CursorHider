//
//  main.cpp
//  CursorHider
//
// Thanks, stackoverflow: http://stackoverflow.com/questions/3885896/globally-hiding-cursor-from-background-app
//  Created by Brett Renfer on 6/12/12.
//

#include <ApplicationServices/ApplicationServices.h>

int main(void)
{
    void CGSSetConnectionProperty(int, int, CFStringRef, CFBooleanRef);
    int _CGSDefaultConnection();
    CFStringRef propertyString;
    
    // Hack to make background cursor setting work
    propertyString = CFStringCreateWithCString(NULL, "SetsCursorInBackground", kCFStringEncodingUTF8);
    CGSSetConnectionProperty(_CGSDefaultConnection(), _CGSDefaultConnection(), propertyString, kCFBooleanTrue);
    CFRelease(propertyString);
    // Hide the cursor and wait
    while(1){
        CGDisplayHideCursor(kCGDirectMainDisplay);
        sleep(1);
    }
    return 0;
}