package tissotFramework.controller;

import tissotFramework.view.GameView;
import tissotFramework.view.TouchGameView;

/** @author André Tissot */
public abstract class TouchGameController extends GameController {

    public int pressed_x = 0;
    public int pressed_y = 0;
    public int dragged_x = 0;
    public int dragged_y = 0;
    public int released_x = 0;
    public int released_y = 0;
    private GameView view = null;

    public TouchGameController(TouchGameView gameView) {
        this.view = gameView;
    }

    public GameView getGameView() {
        return this.view;
    }

    public void pointerPressed(int x, int y) {
        pressed_x = x;
        pressed_y = y;
    }

    public void pointerDragged(int x, int y) {
        dragged_x = x;
        dragged_y = y;
    }

    public void pointerReleased(int x, int y) {
        released_x = x;
        released_y = y;
    }
}
