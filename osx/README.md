
# Tutorial
This system is OS X-only and was tested in a OS X 10.11.6. Let me know if you ever test this in another version/distribution, I'd love to know!

## Dependencies
To start, we need to install the following software:
- [webInsertion software](https://www.dropbox.com/sh/iiwf8gqqzjp75fn/AAB8OtNXv44U7p0Vcwti85aOa?dl=0): Software that allows you to modify the incoming video using a friendly programming languages, as if it was a webcam. Make sure you download the right version for you platform (i.e. 32 or 64 bits). In addition, because this software is not Apple certified, there’s a chance you might have a security-related problem (*"this application is damaged and cannot be opened"* or something like that). In this case, follow [this link](http://osxdaily.com/2016/09/27/allow-apps-from-anywhere-macos-gatekeeper/) to solve the problem;
- [Youtube-dl](https://github.com/rg3/youtube-dl/): Command line tool that allows you to extract an m3u8 file from several resources, such as Youtube Live and others;
- [Open-broadcast software (OBS)](https://obsproject.com/): Software tool that allows you to broadcast videos to several services such as Youtube and Facebook Live;
- [Soundflower](https://soundflower.en.softonic.com/mac): Software tool that allows you to route whatever you're hearing in your speakers as a "virtual michrophone" to feed external software.

### Only for developers
If you are familiar with C++/Openframeworks, and want to modify the source-code by yourself, you're also going to need:
- openFrameworks ([version 0.9.8](http://openframeworks.cc/download/));
- xCode (get started on using xCode with openFrameworks [here](http://openframeworks.cc/setup/xcode/));
- The [webInsertion's source](https://github.com/jeraman/insertions/tree/master/osx/webInsertion).

...and install the following oF addons:
- https://github.com/jvcleave/ofxAvFoundationHLSPlayer
- https://github.com/astellato/ofxSyphon

If you're not a developer, nevermind. Just skip this step and go directly to the following subsection.

## Process
The image below summarizes the process. After selecting your video target (picture (a)), you will process it locally on openFrameworks and OBS (picture (b)). The result is going to be streamed back to whatever service you'd like, such as the youtube (picture (c)).

![Setup](assets/setup.png)

## Step 1: From the internet to your computer
In the beginning, you need to choose the live video stream you want to target. This video is represented in the picture above by (a). For example, you can go to the [Youtube Live](https://www.youtube.com/live), open the video you want to modify, and copy its URL.

Once you copied this URL, you only need paste it inside a text file called "video.txt". This file is placed inside the folder "data" that comes along with the webInsertion software you downloaded. As follows:

![Screenshot](assets/modify-video-txt.png)

When you're done, you can open the webInsertion software you just downloaded. If you see the video playing, everything should be OK!

![Screenshot](assets/webInsertion-screenshot.png)

At any time, you can change the target video by modifying the "video.txt" and by clicking on "reload URL from file" inside the application.

If you're having problems, make sure you have picked a valid video, and that its link is correctly pasted into the "video.txt" file.

## Step 2: Modify it!
For this step, you'll need first to configure both *video* and *audio*. Then, you will be able to insert basic media on the video such as overlaying images and sound. This step is represented by picture (b).

### Configuring video
Here, we are going to use the Open-broadcast software (OBS). A full explanation of OBS is beyond the scope of this tutorial, you can find [several on youtube](https://www.youtube.com/watch?v=LX04mw_xG6A). It's enough to say here that it is:
1. **Open source** (i.e. free, and community driven);
2. **Powerful** (i.e. allows you to easily add images, sound, and other things to your video); and
3. **Easy to use** (you can learn how to use only by trying it out).

Roughly, the more familiar you are with it, the more sophisticated are the insertions you can do with it. In this tutorial, we'll stick to very the basics.

This is how OBS should look like:

![obs-part-0](assets/obs-part-0.png)

To import your video inside OBS you'll need first to go to *"Sources"*, and click in *"+"*:

![obs-part-1](assets/obs-part-1.png)

Then, click on *"Game Capture Syphon"*, and then on *"Create new"*:

![obs-part-2](assets/obs-part-2.png)

Go in *"Source"* and choose *"[webInsertion] Insertion output"*. It's **essential** that the webInsertion app is up and running before this options is available to you (see Step 1 if it's not):

![obs-part-3](assets/obs-part-3.png)

By now, you should be seeing the video output inside OBS. That's great! You only need to adjust the size according to the output window provided by OBS.

![obs-part-4](assets/obs-part-4.png)

### Configuring audio
To import your audio inside OBS you'll need to:
1. Go to *System preferences* > *Sound* > *Output*;
2. Select Soundflower as default output.

By them you should notice that you can (should?) no longer hear your speakers. Everything now is being routed by default to Soundflower. This allows you to import the routed audio inside external applications as if your speakers were a microphone. Actually, this is exactly what we are going to do inside OBS by:
3. Clicking on *Desktop Audio settings* (i.e. the wheels) > *properties;*
4. Choose *Soundflower (2ch)* as device.

If everything is fine, you should be able to see the green volume line moving in your Desktop Audio options. You should also make sure the Mix/Aux is properly muted. As follows:

![configuring-audio](assets/configuring-audio.png)


### Basic overlaying!
Finally, it's time to make some modifications in our video!


# Advanced insertions (only for developers)
If you're comfortable, you can play around with the video before sending it to OBS. This gives you the possibility of doing things more complex than basic overlaying.

The major thing to keep in mind in this case is that whatever you draw in the screen before the command *"mainOutputSyphonServer.publishScreen()"* is going to get sent to OBS. Thus, for example:

```cpp
ofDrawCircle(150,150,100);
mainOutputSyphonServer.publishScreen();
```
In this first case, the circle *will* be sent to OBS. However, here:

```cpp
mainOutputSyphonServer.publishScreen();
ofDrawCircle(150,150,100);
```
The circle *won't* be sent to OBS.

Have fun!

--

[Jeraman](https://jeraman.info), 2017.
