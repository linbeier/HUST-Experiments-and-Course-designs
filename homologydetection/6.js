/* find out more about jslint: http:
"use strict";  
function MyGame() {
     
    this.kBgClip = "assets/sounds/BGClip.mp3";
    this.kCue = "assets/sounds/MyGame_cue.wav";
    
    this.mCamera = null;
    
    this.mHero = null;
    this.mSupport = null;
}
gEngine.Core.inheritPrototype(MyGame, Scene);
MyGame.prototype.loadScene = function () {
   
    gEngine.AudioClips.loadAudio(this.kBgClip);
    gEngine.AudioClips.loadAudio(this.kCue);
};
MyGame.prototype.unloadScene = function() {
    
    
    gEngine.AudioClips.stopBackgroundAudio();
    
    
    
    
    gEngine.AudioClips.unloadAudio(this.kCue);
    
    
    var nextLevel = new BlueLevel();  
    gEngine.Core.startScene(nextLevel);
};
MyGame.prototype.initialize = function () {
    
    this.mCamera = new Camera(
        vec2.fromValues(20, 60),   
        20,                        
        [20, 40, 600, 300]         
        );
    this.mCamera.setBackgroundColor([0.8, 0.8, 0.8, 1]);
            
    
    this.mSupport = new Renderable(gEngine.DefaultResources.getConstColorShader());
    this.mSupport.setColor([0.8, 0.2, 0.2, 1]);
    this.mSupport.getXform().setPosition(20, 60);
    this.mSupport.getXform().setSize(5, 5);
    
    this.mHero = new Renderable(gEngine.DefaultResources.getConstColorShader());
    this.mHero.setColor([0, 0, 1, 1]);
    this.mHero.getXform().setPosition(20, 60);
    this.mHero.getXform().setSize(2, 3);
    
    gEngine.AudioClips.playBackgroundAudio(this.kBgClip);
};
MyGame.prototype.draw = function () {
    
    gEngine.Core.clearCanvas([0.9, 0.9, 0.9, 1.0]); 
    
    this.mCamera.setupViewProjection();
    
    this.mSupport.draw(this.mCamera.getVPMatrix());
    this.mHero.draw(this.mCamera.getVPMatrix());
};
MyGame.prototype.update = function () {
    
    
    
    var deltaX = 0.05;
    var xform = this.mHero.getXform();
    
    if (gEngine.Input.isKeyPressed(gEngine.Input.keys.Right)) {
        gEngine.AudioClips.playACue(this.kCue);
        xform.incXPosBy(deltaX);
        if (xform.getXPos() > 30) { 
            xform.setPosition(12, 60);
        }
    }
    if (gEngine.Input.isKeyPressed(gEngine.Input.keys.Left)) {
        gEngine.AudioClips.playACue(this.kCue);
        xform.incXPosBy(-deltaX);
        if (xform.getXPos() < 11) {  
            gEngine.GameLoop.stop();
        }
    }
};
