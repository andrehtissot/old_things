package tissotFramework;

/** @author André Tissot */
public abstract class TouchGameController extends GameController {

    public int pressed_x = 0;
    public int pressed_y = 0;
    public int dragged_x = 0;
    public int dragged_y = 0;
    public int released_x = 0;
    public int released_y = 0;

    public TouchGameController(TouchGameView gameView) {
        super(gameView);
    }

    protected void pointerPressed(int x, int y) {
        pressed_x = x;
        pressed_y = y;
    }

    protected void pointerDragged(int x, int y) {
        dragged_x = x;
        dragged_y = y;
    }

    protected void pointerReleased(int x, int y) {
        released_x = x;
        released_y = y;
    }
}
