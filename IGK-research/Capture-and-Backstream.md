# Capture and backstream
Here, I cover research on:
1. **Efficient capturing**: How to efficiently capture a TV video and manipulate it via code?
2. **Efficient backstream**: How to efficiently stream the manipulated video back to the internet/Raspberry PI?

## Efficient capturing
### Baldtrump
Ben Snell used the black magic device for the capture. His result was awesome!
https://github.com/bensnell/samson

His code used Kyle McDonald’s add-on ofxBlackmagic:
https://github.com/kylemcdonald/ofxBlackmagic

Problem: Need to buy this device that costs around 181 dollars.  :(

### ofxVideoPipe
Another alternative would be to create a pipe via ffmpeg directly to openframeworks. Maybe this lib could help on this:
https://github.com/heisters/ofxVideoPipe

An interesting question would be: can we do the other way around, and avoid Syphon in our way back for the streamming?


### [PROBLEM] ofxStreamer
This was the first option I tried:
https://github.com/HalfdanJ/ofxStreamer

The library seems a bit outdated. It took me a while to be able to run the examples (about this, if you ever try this path again, remember to include CoreFoundation.framework, CoreVideo.framework, and VideoDecodeAcceleration.framework inside your project, so that compilation works).

Now I'm facing problems in properly encoding the video using ofxStreamerSender.

The problem seems to be in function:
```
bool ofxStreamerSender::sendFrame(unsigned char *data, int data_length);
```

I particular, in the line...
```
//Convert to YUV format
sws_scale(imgctx, (const uint8_t* const*) &data, &stride, 0, height, frame->data, frame->linesize);
```
If the line above is uncommented, the system compiles all right, but it crashes after a few seconds.

If I comment this line, the system does not crashes, but: (a) I get the warning: "[warning] No encoded frame to send, make sure to call encodeFrame"; and (b) Data seems to be received by the receiver, but all I get is a green screen.

This seems to be a bug in ofxStreamer. Just found details in this link:
https://github.com/HalfdanJ/ofxStreamer/issues/2?_pjax=%23js-repo-pjax-container

### [PROBLEM] ofxIPVideoGrabber
Link: https://github.com/bakercp/ofxIPVideoGrabber

Not really what we're looking for, made for IP cameras.

### [PROBLEM] ofxVLCVideoPlayer
Link: https://github.com/jnakanojp/ofxVLCVideoPlayer

Seems to work only with local files, and not with networked video streams. At least in theory, supporting networked streams could be possible by using [libvlc](https://wiki.videolan.org/LibVLC). However, this would require studying libvlc.... :(

### Others
Potentially useful links:
- https://github.com/arturoc/ofxGStreamer
- https://github.com/arturoc/ofxGstV4L2Sink (linux only?)
- https://github.com/jvcleave/ofxOMXPlayer (processing needs to be done in the raspberry pi?)
- https://github.com/chrippa/livestreamer

<!--
These options are so far outdated:
- http://stackoverflow.com/questions/21081867/ffplay-openframeworks-ar-parrot-drone-tcp-video
- https://github.com/arturoc/ofxGSTRTP
-->

## Efficient backstream
### FFmpeg screen capture
So far, this approach is working fine! Seems reliable and multiplatform!

### Baldtrump
Ben Snell used Syphon to stream from the manipulated video from oF to youtube. The result was again awesome!

Apparently, it is possible to integrate syphon with ffmpeg:
http://v002.info/forums/topic/syphon-piped-to-ffmpeg/
