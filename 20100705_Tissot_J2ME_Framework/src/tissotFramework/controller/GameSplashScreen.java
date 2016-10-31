/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package tissotFramework.controller;

import tissotFramework.view.GameView;
import java.io.IOException;
import javax.microedition.lcdui.Graphics;
import javax.microedition.lcdui.Image;
import tissotFramework.core.MainController;

/**
 * @author André Tissot
 */
public class GameSplashScreen extends GameController {

    private Screen screen = null;

    public GameSplashScreen(GameController nextScreen, long msToSwitch, String imagePath) throws IOException {
        this(nextScreen, msToSwitch, Image.createImage(imagePath));
    }

    public GameSplashScreen(GameController nextScreen, long msToSwitch, Image image) {
        this.screen = new Screen(image);
        MainController.getInstance.switchActiveController(nextScreen, msToSwitch);
    }

    public GameView getGameView() {
        return this.screen;
    }
}

class Screen extends GameView {

    public Image image;

    public Screen(Image image) {
        this.image = image;
    }

    public void loadResources() {
    }

    public void drawScreen() {
        graph.drawImage(image, 0, 0, Graphics.TOP | Graphics.LEFT);
    }
}
