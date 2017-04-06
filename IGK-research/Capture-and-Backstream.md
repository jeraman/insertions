Here, I cover research on:
1. **Efficient capturing**: How to efficiently capture a TV video and manipulate it via code;
2. **Efficient backstream**: How to efficiently stream the manipulated video back to the internet/Raspberry PI?

# Efficient capturing
## Baldtrump
Ben Snell used the black magic device for the capture. His result was awesome!
https://github.com/bensnell/samson

His code used Kyle McDonald’s add-on ofxBlackmagic:
https://github.com/kylemcdonald/ofxBlackmagic

## ofxVideoPipe
Another alternative would be to create a pipe via ffmpeg directly to openframeworks. Maybe this lib could help on this:
https://github.com/heisters/ofxVideoPipe

An interesting question would be: can we do the other way around, and avoid Syphon in our way back for the streamming?

## Others
Potentially useful links:
https://github.com/HalfdanJ/ofxStreamer
https://github.com/bakercp/ofxIPVideoGrabber
http://stackoverflow.com/questions/21081867/ffplay-openframeworks-ar-parrot-drone-tcp-video
https://github.com/arturoc/ofxGStreamer
https://github.com/arturoc/ofxGSTRTP

# Efficient backstream
## FFmpeg screen capture
So far, this approach is working fine! Seems reliable and multiplatform!

## Baldtrump
Ben Snell used Syphon to stream from the manipulated video from oF to youtube. The result was again awesome!

Apparently, it is possible to integrate syphon with ffmpeg:
http://v002.info/forums/topic/syphon-piped-to-ffmpeg/
