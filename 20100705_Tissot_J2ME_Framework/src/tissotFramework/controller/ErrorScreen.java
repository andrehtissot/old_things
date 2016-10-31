/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package tissotFramework.controller;

import javax.microedition.lcdui.Graphics;
import javax.microedition.lcdui.game.GameCanvas;
import tissotFramework.core.MainController;

/**
 * @author André Tissot
 */
public class ErrorScreen extends GameCanvas implements Runnable {

    private String message;

    public ErrorScreen(String message) {
        super(true);
        MainController.getInstance.error = this;
        this.message = message;
        new Thread(this).start();
    }

    public void run() {
        Graphics g = this.getGraphics();
        g.setColor(0, 0, 0);
        g.fillRect(0, 0, getWidth(), getHeight());
        g.setColor(255, 255, 255);
        g.drawString(message, 0, 0, Graphics.TOP | Graphics.LEFT);
        this.flushGraphics();
        try {
            Thread.sleep(2000);
        } catch (InterruptedException ex) {
        }
        MainController.getInstance.notifyDestroyed();
    }
}
