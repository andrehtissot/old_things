/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package tissotFramework;

import java.io.IOException;
import javax.microedition.lcdui.Graphics;
import javax.microedition.lcdui.Image;

/**
 * @author André Tissot
 */
public class GameSplashScreen extends GameController {

    public GameSplashScreen(GameController nextScreen, long msToSwitch, String imagePath) throws IOException {
        this(nextScreen, msToSwitch, Image.createImage(imagePath));
    }

    public GameSplashScreen(GameController nextScreen, long msToSwitch, Image image) {
        super(new Screen(image));
        MainController.getInstance.switchActiveController(nextScreen, msToSwitch);
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
