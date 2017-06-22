# this one works, but no framework is copied. if we do that manually, we still get a bizarre error.
make LDFLAGS="-arch i386"

# none of the following works (best case, I get the same result as above).
make LDFLAGS="-I/Users/jeronimo/Downloads/of_v0.9.8_osx_release/addons/ofxSyphon/libs/Syphon -F/Users/jeronimo/Downloads/of_v0.9.8_osx_release/addons/ofxSyphon/libs/Syphon/lib/osx -framework Syphon"

make LDFLAGS="-lglut -I/Users/jeronimo/Downloads/of_v0.9.8_osx_release/addons/ofxSyphon/libs/Syphon -F/Users/jeronimo/Downloads/of_v0.9.8_osx_release/addons/ofxSyphon/libs/Syphon/lib/osx -framework Syphon -arch i386"

make LDFLAGS="-framework Accelerate -framework AGL -framework AppKit -framework ApplicationServices -framework AudioToolbox -framework AVFoundation -framework Cocoa -framework CoreAudio -framework CoreFoundation -framework CoreMedia -framework CoreServices -framework CoreVideo -framework IOKit -framework OpenGL -framework QuartzCore -framework QuickTime -framework QTKit -framework GLUT -I/Users/jeronimo/Downloads/of_v0.9.8_osx_release/addons/ofxSyphon/libs/Syphon -F/Users/jeronimo/Downloads/of_v0.9.8_osx_release/addons/ofxSyphon/libs/Syphon/lib/osx -framework Syphon"

make LDFLAGS="-framework Accelerate -framework AGL -framework AppKit -framework ApplicationServices -framework AudioToolbox -framework AVFoundation -framework Cocoa -framework CoreAudio -framework CoreFoundation -framework CoreMedia -framework CoreServices -framework CoreVideo -framework IOKit -framework OpenGL -framework QuartzCore -framework QuickTime -framework QTKit -framework GLUT -I/Users/jeronimo/Downloads/of_v0.9.8_osx_release/addons/ofxSyphon/ -F/Users/jeronimo/Downloads/of_v0.9.8_osx_release/addons/ofxSyphon/libs/Syphon/lib/osx -framework Syphon -arch i386"

make LDFLAGS="-I/$(HEADER_SEARCH_PATHS) -F/$(FRAMEWORK_SEARCH_PATHS) -framework Accelerate -framework AGL -framework AppKit -framework ApplicationServices -framework AudioToolbox -framework AVFoundation -framework Cocoa -framework CoreAudio -framework CoreFoundation -framework CoreMedia -framework CoreServices -framework CoreVideo -framework IOKit -framework OpenGL -framework QuartzCore -framework QuickTime -framework QTKit -framework GLUT -framework Syphon -arch i386"

make LDFLAGS="-framework OpenGL -framework GLUT -I/Users/jeronimo/Downloads/of_v0.9.8_osx_release/addons/ofxSyphon/libs/Syphon -F/Users/jeronimo/Downloads/of_v0.9.8_osx_release/addons/ofxSyphon/libs/Syphon/lib/osx -framework Syphon -arch i386"

make LDFLAGS="-framework Accelerate -framework AGL -framework AppKit -framework ApplicationServices -framework AudioToolbox -framework AVFoundation -framework Cocoa -framework CoreAudio -framework CoreFoundation -framework CoreMedia -framework CoreServices -framework CoreVideo -framework IOKit -framework OpenGL -framework QuartzCore -framework QuickTime -framework QTKit -framework GLUT -F/Users/jeronimo/Downloads/of_v0.9.8_osx_release/libs/glut/lib/osx  -F/Users/jeronimo/Downloads/of_v0.9.8_osx_release/addons/ofxSyphon/libs/Syphon/lib/osx -framework Syphon -arch i386"
