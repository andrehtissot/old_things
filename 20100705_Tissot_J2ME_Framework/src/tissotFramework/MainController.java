package tissotFramework;

import javax.microedition.lcdui.Command;
import javax.microedition.lcdui.CommandListener;
import javax.microedition.lcdui.Display;
import javax.microedition.lcdui.Displayable;
import javax.microedition.midlet.MIDlet;

/** @author André Tissot */
public final class MainController extends MIDlet implements CommandListener {

    static public MainController getInstance; //Don't Instantiate more than one Routes!
    public Controller controller;
    public Display display;

    public MainController() {
        getInstance = this;
        controller = Config.FIRST_CONTROLLER;
        display = Display.getDisplay(this);
        controller.setCommandListener(this);
    }

    protected void destroyApp(boolean unconditional) {
        controller.onDestroyApp(unconditional);
    }

    protected void pauseApp() {
        controller.onPauseApp();
    }

    protected void startApp() {
        display.setCurrent((Displayable) controller);
        controller.onStartApp();
    }

    public void commandAction(Command c, Displayable d) {
        controller.commandAction(c, d);
    }

    public void switchActiveController(Controller newController) {
        controller.switchActiveControllerExtraCommands();
        controller = newController;
        controller.setCommandListener(getInstance);
        startApp();
    }

    public void switchActiveController(Controller newController, long milisToChange) {
        new ControllersChanger(newController, milisToChange);
    }

    private class ControllersChanger implements Runnable {

        private Controller newController;
        private long milisToChange;

        public ControllersChanger(Controller newController, long milisToChange) {
            this.newController = newController;
            this.milisToChange = milisToChange;
            (new Thread(this)).start();
        }

        public void run() {
            try {
                Thread.sleep(milisToChange);
            } catch (InterruptedException ex) {
            }
            controller.switchActiveControllerExtraCommands();
            controller = newController;
            controller.setCommandListener(getInstance);
            startApp();
        }
    }
}
