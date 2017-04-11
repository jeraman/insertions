
# Tutorial
This system is OS X-only and was tested in a OS X 10.11.6. Let me know if you ever test this in another version/distribution, I'd love to know!

## Dependencies
To start, we need to install the following software:
- [webInsertion software](https://www.dropbox.com/sh/iiwf8gqqzjp75fn/AAB8OtNXv44U7p0Vcwti85aOa?dl=0): Software that allows you to modify the incoming video using a friendly programming languages, as if it was a webcam. Make sure you download the right version for you platform (i.e. 32 or 64 bits). In addition, because this software is not Apple certified, there’s a chance you might have a security-related problem (*"this application is damaged and cannot be opened"* or something like that). In this case, follow [this link](http://osxdaily.com/2016/09/27/allow-apps-from-anywhere-macos-gatekeeper/) to solve the problem;
- [Youtube-dl](https://github.com/rg3/youtube-dl/): Command line tool that allows you to extract an m3u8 file from several resources, such as Youtube Live and others;
- [Open-broadcast software](https://obsproject.com/): Software tool that allows you to broadcast videos to several services such as Youtube and Facebook Live;

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
The image below summarizes the process. After selecting your video target (picture (a)), you will process it locally on openframwroks and Obs (picture (b)). The result is going to be streamed back to whatever service you'd like, such as the youtube (picture (c)).

![Setup](assets/setup.png)

## Step 1
In the beginning, you need to choose the live video stream you want to target. This video is represented in the picture above by (a).

For this, you only need to copy the URL and paste it in a text file called "video.txt", inside the folder "data" (this folder comes along with the webInsertion software you downloaded).

When you're done, you can open the webInsertion software you just downloaded.

![Screenshot](assets/webInsertion-screenshot.png)

At any time, you can change the target video by modifying the "video.txt" and by clicking on "reload URL from file" inside the application.

If you're having problems, make sure you have picked a valid video, and that its link is correctly pasted into the "video.txt file".
