# MPEG-TS support
Markus said that the Sundtek USB tuner outputs MPEG-TS video streams only. However, our webInsertion app accepts only HLS streams.

Because of this, I needed to make the WebInsertion application MPEG-TS compatible.

## LibVLC
I was able to add MPEG-TS support using [LibVLC](https://wiki.videolan.org/LibVLC/).

LibVLC is the framework behind [VLC](http://www.videolan.org/) and implements several multimedia formats, including both HLS and MPEG-TS.

There is an Openframeworks wrapper for LibVLC, called ofxVLCVideoPlayer:
https://github.com/jnakanojp/ofxVLCVideoPlayer
https://www.youtube.com/watch?v=mskKMztBIzM

I was able to compile and run the ofxVLCVideoPlayer's example. The current version supports only local files, and not URL (as required by MPEG-TS and HLS). Therefore, I needed to modify the code to work with URLs as well.

The MPEG-TS support seems to be working fine so far. However, the HLS support here doesn't seem to work 100%. For instance, any of the following URLs gave me problems:
```
//player.loadMovie("https://devimages.apple.com.edgekey.net/samplecode/avfoundationMedia/AVFoundationQueuePlayer_HLS2/master.m3u8");
player.loadMovie("https://manifest.googlevideo.com/api/manifest/hls_playlist/id/0h9nqVtbUaw.1/itag/95/source/yt_live_broadcast/requiressl/yes/ratebypass/yes/live/1/cmbypass/yes/goi/160/sgoap/gir%3Dyes%3Bitag%3D140/sgovp/gir%3Dyes%3Bitag%3D136/hls_chunk_host/r5---sn-cxaaj5o5q5-t0as.googlevideo.com/ei/5SJMWb_9LIa6uwLThY_oDQ/playlist_type/LIVE/gcr/ca/mm/32/mn/sn-cxaaj5o5q5-t0as/ms/lv/mv/m/pl/22/dover/6/mt/1498161865/ip/69.159.171.201/ipbits/0/expire/1498183493/sparams/ip,ipbits,expire,id,itag,source,requiressl,ratebypass,live,cmbypass,goi,sgoap,sgovp,hls_chunk_host,ei,playlist_type,gcr,mm,mn,ms,mv,pl/signature/6752726824320AB439152958036A53874EA3282B.53D4B2F8163D914E40AD7A5DB1389F2B6788FB04/key/dg_yt0/playlist/index.m3u8");
```
This one worked fine though:
```
player.loadMovie("http://devimages.apple.com/iphone/samples/bipbop/bipbopall.m3u8");
```

Don't know why this is happening. I need to further investigate this sometime.

## Transcode from MPEG-TS to HLS
Instead of using LibVLC, a second approach would be to explore tools able to transcode from MPEG-TS to HLS. For instance:
https://github.com/sdrsdr/HLS-Segmenter
http://www.ioncannon.net/projects/http-live-video-stream-segmenter-and-distributor/

Because the first attempt worked fine, I haven't tested this approach yet.
