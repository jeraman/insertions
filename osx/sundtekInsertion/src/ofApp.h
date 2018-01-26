#pragma once

#include "ofMain.h"
#include "ofxVLCVideoPlayer.h"
#include "ofxSyphon.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{
    
public:
    
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    //void setupGui();
    //void drawDebug();
    
    ofxVLCVideoPlayer player;
    ofxSyphonServer mainOutputSyphonServer;
    
    //ofxPanel gui;
    //ofxToggle show_debug_tgl;
    //ofxButton load_video_btn;
    
    bool hide_video;
    
};

