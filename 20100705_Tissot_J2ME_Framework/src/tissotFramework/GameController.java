package tissotFramework;

import javax.microedition.lcdui.Command;
import javax.microedition.lcdui.Displayable;
import javax.microedition.lcdui.game.GameCanvas;

/** @author André Tissot */
public abstract class GameController extends GameCanvas implements Controller {

    private Thread keyboardListener;
    public GameKeyboardListener keyboard;
    public static int WIDTH;
    public static int HEIGHT;
    protected GameView gameView;
    private Thread drawerThread;

    public void switchActiveControllerExtraCommands() {
        gameView.runDrawer = false;
    }

    public GameController(GameView gameView) {
        super(true);
        this.gameView = gameView;
        gameView.setController(this);
        gameView.graph = getGraphics();
        gameView.loadResources();
        setFullScreenMode(true);
        WIDTH = getWidth();
        HEIGHT = getHeight();
        keyboard = new GameKeyboardListener(this);
    }

    public GameView getView() {
        return gameView;
    }

    public void onStartApp() {
        setFullScreenMode(true);
        keyboard.listen = true;
        keyboardListener = new Thread(keyboard);
        keyboardListener.start();
        gameView.runDrawer = true;
        drawerThread = new Thread(gameView);
        drawerThread.start();
    }

    public void onPauseApp() {
        gameView.runDrawer = false;
        keyboard.listen = false;
    }

    public void onDestroyApp(boolean unconditional) {
        gameView.runDrawer = false;
        keyboard.listen = false;
    }

    public void changeView(GameView newGameview, long milisToChange) {
        new viewsChanger(this, newGameview, milisToChange);
    }

    private class viewsChanger implements Runnable {

        private GameView newGameView;
        private long milisToChange;
        private GameController father;

        public viewsChanger(GameController father, GameView newGameview, long milisToChange) {
            this.newGameView = newGameview;
            this.milisToChange = milisToChange;
            this.father = father;
            (new Thread(this)).start();
        }

        public void run() {
            try {
                Thread.sleep(milisToChange);
                gameView.runDrawer = false;
                drawerThread.join();
            } catch (InterruptedException ex) {
                System.out.println("Error on GameView run method execution!: \n" + ex.getMessage());
                ex.printStackTrace();
            }
            gameView = newGameView;
            gameView.setController(father);
            gameView.graph = getGraphics();
            gameView.loadResources();
            onStartApp();
        }
    }

    public void commandAction(Command c, Displayable d) {
    }

    public void keyboardClicked() {
    }

    public void keyboardPressed() {
    }

    public void keyboardReleased() {
    }

    public void fireKeyClicked() {
    }

    public void fireKeyPressed() {
    }

    public void fireKeyReleased() {
    }

    public void upKeyClicked() {
    }

    public void upKeyPressed() {
    }

    public void upKeyReleased() {
    }

    public void downKeyClicked() {
    }

    public void downKeyPressed() {
    }

    public void downKeyReleased() {
    }

    public void rightKeyClicked() {
    }

    public void rightKeyPressed() {
    }

    public void rightKeyReleased() {
    }

    public void leftKeyClicked() {
    }

    public void leftKeyPressed() {
    }

    public void leftKeyReleased() {
    }

    public void gameAKeyClicked() {
    }

    public void gameAKeyPressed() {
    }

    public void gameAKeyReleased() {
    }

    public void gameBKeyClicked() {
    }

    public void gameBKeyPressed() {
    }

    public void gameBKeyReleased() {
    }

    public void gameCKeyClicked() {
    }

    public void gameCKeyPressed() {
    }

    public void gameCKeyReleased() {
    }

    public void gameDKeyClicked() {
    }

    public void gameDKeyPressed() {
    }

    public void gameDKeyReleased() {
    }
}
